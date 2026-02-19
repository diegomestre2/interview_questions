#pragma once



/*

Requirements:

- Streaming-friendly (don’t flatten first)

- Keys can repeat across blocks (handle Duplicates)

- Return one row per distinct key

- No unnecessary copies

- Deterministic output (sorted by key ascending)
*/

#include <unordered_map>
#include <stdexcept>
#include <algorithm>
#include <vector>

struct Block {
	std::vector<uint64_t> key;
	std::vector<int64_t> value;
};


using key_type = uint64_t;
using aggregation_type = int64_t;

void validate_block(const Block& block) {
	if (block.key.size() != block.value.size()) {
		throw std::invalid_argument("invalid block size");
	}
}

Block aggregate_sum(const std::vector<Block>& input) {
	// First Pass: Validation of input and size estimation(allocate the correct amount of memory = total_rows)
	uint64_t total_rows{0};
	for (auto & block : input) {
		validate_block(block);
		total_rows += block.key.size();
	}

	// Second Pass: Build a Hashtable (unordered_map, O(1) insertion, O(1) search, O(1) delete/update) where the value is the aggregated_sum of all equal keys
	std::unordered_map<key_type, aggregation_type> hashtable;
	hashtable.reserve(total_rows); // allocate the upper_bound so we avoid collisions
	// build hashtable
	for ( auto & block : input) {
		size_t block_size = block.key.size();
		for (size_t i = 0; i < block_size; ++i) {
			// insert key if not inserted and aggregate value
			hashtable[block.key[i]] += block.value[i];
		}
	}

	// Third Pass: Scan the Hashtable to materialize the results
	// Output (Block (key, sum) sorted by key)
	// Scan the keys from the hashtable and sorte them into a vector
	std::vector<std::pair<key_type, aggregation_type>> key_sum_pair;
	key_sum_pair.reserve(hashtable.size());
	std::for_each(hashtable.begin(), hashtable.end(), [&](const auto& pair) {key_sum_pair.push_back({pair.first, pair.second});});
	std::sort(key_sum_pair.begin(), key_sum_pair.end(),[](auto &a, auto &b){ return a.first < b.first; });


	// Build output
	Block output;
	output.key.reserve(hashtable.size()); // allocate memory for output
	output.value.reserve(hashtable.size()); // allocate memory for output
	for (auto & pair : key_sum_pair) {
		auto key = pair.first;
		auto value = pair.second;
		output.key.push_back(key);
		output.value.push_back(value);
	}

	return output;
}

// Flat Hashtable
// The main limitation of the previous implementation is that the hashtable from the unordered map has a bucket hashtable implementation which requires
// pointer access for every entry and it is not cache efficient since it stores key and payload together


size_t validate_input(const std::vector<Block> & blocks) {
	size_t total_size{0};
	for ( auto&block : blocks) {
		auto key_size = block.key.size();
		auto value_size = block.value.size();
		if (key_size != value_size) {
			throw std::invalid_argument("Block size not correct");
		}
		total_size += key_size;
	}
}

size_t next_power_of_two(size_t n) {
	auto power_of_two{1};
	while (power_of_two < n) {
		power_of_two <<= 1;
	}
	return power_of_two;
}

Block aggregate_sum(const std::vector<Block>& input) {
	// Store keys as a flat vector (better cache locality)
	// Store aggregations as a different vector
	// Have a byte vector to check for occurence of values on each position, avoiding bringing unecessary data into cache

	auto total_size = validate_input(input);
	// Flat hashtable representation
	auto ht_capacity = next_power_of_two(static_cast<size_t>(total_size / 0.7) + 1);
	std::vector<key_type>keys(ht_capacity);
	std::vector<aggregation_type> aggregations(ht_capacity);
	std::vector<uint8_t> occupied(ht_capacity, 0);

	auto mask = ht_capacity - 1;

	auto insert_aggregation = [&] (auto&key_, auto&value_) {
		auto idx = std::hash<key_type>{}(key_) & mask; // get an index within capacity range

		// handle duplicates/conflicts
		while (occupied[idx]) {
			if (key_ == keys[idx]) {
				aggregations[idx] += value_;
				return;
			}
			idx = (idx + 1) & mask; //  linear probing, next free position adjacent
		}
		// free space
		occupied[idx] = 1;
		keys[idx] = key_;
		aggregations[idx] = value_;
	};

	// Hash table build
	for (const auto & block : input) {
		const size_t &rows = block.key.size();
		for (size_t i = 0; i < rows; ++i) {
			insert_aggregation(block.key[i], block.value[i]);
		}
	}

	// Materialize result
	std::vector<std::pair<key_type, aggregation_type>> key_sum_pair;
	key_sum_pair.reserve(ht_capacity);
	for (size_t i = 0; i < ht_capacity; ++i) {
		if (occupied[i]) {
			key_sum_pair.emplace_back(keys[i], aggregations[i]);
		}
	}

	std::sort(key_sum_pair.begin(), key_sum_pair.end(), [](const auto &a, const auto &b) {return a.first < b.first;});

	Block output;
	output.key.reserve(key_sum_pair.size());
	output.value.reserve(key_sum_pair.size());
	for ( auto &[key,sum] : key_sum_pair) {
		output.key.push_back(key);
		output.value.push_back(sum);
	}
	return output;

}