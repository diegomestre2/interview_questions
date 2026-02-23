//
// Created by Diego Gomes Tomé on 23/02/2026.
//

#pragma once

#include <stack>
#include <unordered_map>
#include <string>

class Solution {
public:
	bool isValid(std::string s) {
		std::stack<char> st;

		// map closing -> opening
		std::unordered_map<char, char> match{
	            {')', '('},
				{']', '['},
				{'}', '{'}
		};

		for (char c : s) {
			// opening bracket → push
			if (c == '(' || c == '[' || c == '{') {
				st.push(c);
			}
			// closing bracket → check match
			else {
				if (st.empty()) return false;               // nothing to match
				if (st.top() != match[c]) return false;     // mismatch
				st.pop();
			}
		}

		return st.empty();   // no leftover openings
	}
};