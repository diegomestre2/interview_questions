//
// Created by Diego Gomes Tomé on 20/02/2026.
//

#include "leetcode/recursion.hpp"

#include <list>
#include <unordered_map>
using key_type = uint32_t;
using value_type = uint32_t;
using pointer_type = std::list<std::pair<key_type, value_type>>::iterator ;
class LRUCache {
	LRUCache(size_t capacity) {
		map_to_cache.reserve(capacity);
	};
	void insert(key_type key, value_type value) {
		auto iterator = map_to_cache.find(key);
		if ( iterator != map_to_cache.end() ) {
			// key already exists
			iterator->second->second = value;// update value
			// move node to front (MRU)
			cache_list.splice(cache_list.begin(), cache_list, iterator->second);
			return;
		}
		// key does not exists
		// check for space
		if (map_to_cache.size() >= capacity) {
			// no more space
		}
	}



private:
	std::list<std::pair<key_type, value_type>> cache_list;
	std::unordered_map<key_type, pointer_type> map_to_cache;
	size_t capacity;
};

