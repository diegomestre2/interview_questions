#pragma once
#include <cassert>
#include <vector>
int find_max_consecutive_ones(std::vector<int> &nums) {
	size_t count{0};
	size_t result{0};
	for (auto num : nums) {
		if (num != 0) {
			count += num;
			continue;
		}
		result = std::max(count, result);
		count = 0;
	}
	return std::max(count, result);
	;
}

void run_max_consecutive_ones() {
std::vector<int> input = {1, 0, 1, 1, 0, 1};
	assert(find_max_consecutive_ones(input) == 3);
}

int findNumbers(std::vector<int> &nums) {
	size_t result{0}, count{0};
	for (auto num : nums) {
		while (num >= 10) {
			num = num / 10;
			count++;
		}
		if (++count % 2 == 0) {
			result++;
		}
		count = 0;
	}
	return result;
}