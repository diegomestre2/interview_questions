//
// Created by Diego Gomes Tomé on 20/02/2026.
//

#include "leetcode/recursion.hpp"

#include <list> // double-linked list
#include <unordered_map> // hashtable
#include <cassert>
using key_type = int;
using value_type = int;
using pointer_type = std::list<std::pair<key_type, value_type>>::iterator ;
class LRUCache {
public:
	// Constructor with capacity
	LRUCache(size_t capacity) : cache_size(capacity){
		assert(capacity > 0);

	}
	// Insert given key, value
	void insert_value(const key_type& key, const value_type& value) {
		auto found_key = cache_map.find(key);
		if (found_key != cache_map.end()) {
			// key exists
			found_key->second->second = value; // update new value
			cache_list.splice(cache_list.begin(), cache_list,found_key->second); // move to MRU
			return;
		}
		// key does not exists
		// can we insert it?
		if (cache_map.size() >= cache_size) {
			// no more space
			//delete LRU
			auto to_delete = cache_list.back();
			cache_map.erase(to_delete.first);
			cache_list.pop_back();
		}
		// just insert it
		cache_list.emplace_front(key, value);// in the list
		cache_map[key]= cache_list.begin(); // key + iterator]]
	}
	// Get given a key
	std::optional<value_type> get(const key_type& key) {
		auto found_key = cache_map.find(key);
		if (found_key != cache_map.end()) {
			// key found
			auto value_iter = found_key->second;
			cache_list.splice(cache_list.begin(), cache_list, value_iter);
			return value_iter->second;
		}
		return std::nullopt;
	}
private:
	std::list<std::pair<key_type, value_type>> cache_list;
	std::unordered_map<key_type, pointer_type> cache_map;
	size_t cache_size{0};
};

