#pragma once

#include <vector>


/*

Requirements:

- Streaming-friendly (don’t flatten first)

- Keys can repeat across blocks (handle Duplicates)

- Return one row per distinct key

- No unnecessary copies

- Deterministic output (sorted by key ascending)
*/

#include <unordered_map>
#include <stdexception>
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
		auto block_size = block.key.size();
		for (auto i = 0; i < block_size; ++i) {
			// insert key if not inserted and aggregate value
			hashtable[block.key[i]] += block.value[i];
		}
	}

	// Third Pass: Scan the Hashtable to materialize the results
	// Output (Block (key, sum) sorted by key)
	// Scan the keys from the hashtable and sorte them into a vector
	std::vector<key_type> keys;
	keys.reserve(hashtable.size());
	std::for_each(hashtable.begin(), hashtable.end(), [&](const auto& pair) {keys.push_back(pair.first); });
	std::sort(keys.begin(), keys.end());


	// Build output
	Block output;
	output.key.reserve(hashtable.size()); // allocate memory for output
	output.value.resize(hashtable.size()); // allocate memory for output
	for (auto i = 0; i < hashtable.size(); ++i) {
		auto key = keys[i];
		auto value = hashtable[key];
		output.key.push_back(key);
		output.value.push_back(value);
	}

	return output;
}