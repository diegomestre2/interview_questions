#pragma once
#include <iostream>
#include <set>
#include <string>

std::string min_remove_to_make_valid(std::string s) {
	size_t counter{0};
	std::string result;
	for (auto ch : s) {
		if (ch == '(')
			counter++;
		if (ch == ')') {
			if (counter > 0) {
				counter--;

			} else {
				continue;
			}
		}
		result += ch;
	}

	if (counter > 0) {
		for (size_t i = result.size() - 1; i != 0; --i) {
			if (result[i] == '(' && counter > 0) {
				result.erase(i, 1);
				counter--;
			}
		}
		if (counter > 0) {
			result.erase(0);
		}
	}
	return result;
}

void run_min_remove_to_make_valid() {
	assert(min_remove_to_make_valid("))((") == "");
}