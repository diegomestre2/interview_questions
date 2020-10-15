#pragma once
#include <algorithm>
#include <vector>

int findMaxConsecutiveOnes(std::vector<int> &nums) {
	if (nums.size() == 1 && nums[0] == 1)
		return 1;
	size_t count{0}, max{0};
	for (size_t j = 0; j != nums.size(); j++) {
		if (nums[j] != 1) {
			max = std::max(count, max);
			count = 0;
		} else {
			++count;
		}
	}
	return std::max(max, count);
}