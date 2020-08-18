#pragma once
#include <vector>
int findMaxConsecutiveOnes(std::vector<int> &nums) {
	size_t count{0};
	size_t result{0};
	for (auto num : nums) {
		if (num != 0) {
			count += num;
		} else {
			result = std::max(count, result);
			count = 0;
		}
	}
	return result;
}

void run_max_consecutive_ones() {

	assert(find_max_consecutive_ones(std::vector<int>({1, 0, 1, 1, 0, 1})) == 3);
}