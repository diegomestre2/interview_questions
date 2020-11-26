#pragma once
#include <algorithm>
#include <vector>
int missingNumber(std::vector<int> &array) {
	for (auto i = 0; i < array.size(); i++) {
		auto value = array[i];
		if (value >= 0 && value < array.size() - 1 && i != value) {
			std::swap(array[i], array[value]);
			--i; // cover edge case where all the next values are bigger
		}
	}
	for (auto i = 0; i < array.size(); i++) {
		if (array[i] != i) {
			return i;
		}
	}
	return array.size();
}