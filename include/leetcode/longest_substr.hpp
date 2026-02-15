
#pragma once
#include <cassert>
#include <set>
#include <string>

int length_of_longest_substring(std::string s) {
	std::set<char> sub_str;
	size_t answer{0}, left{0}, right{0};

	while (left < s.size() && right < s.size()) {
		auto iter = sub_str.find(s[right]);
		// item is not in the set
		if (iter == sub_str.end()) {
			// slide the right part
			sub_str.insert(s[right++]);
			answer = std::max(answer, right - left);
		} else { // item is in the set
			// slide the left part
			sub_str.erase(s[left++]);
		}
	}
	return answer;
}

void run_longest_substr() {
	assert(length_of_longest_substring("ynyo") == 3);
}