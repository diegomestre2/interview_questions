#pragma once

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		size_t i{0}, j{0}, count{0};
		set<char> str_set;
		while (i != s.size() && j != s.size()) {
			if (str_set.find(s[j]) == str_set.end()) {
				str_set.insert(s[j++]);
				count = std::max(count, j - i);
			} else {
				str_set.erase(s[i++]);
			}
		}
		return count;
	}
};