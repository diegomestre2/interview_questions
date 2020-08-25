#pragma once

#include <vector>
int remove_duplicates(std::vector<int> &nums) {
	size_t count = nums.size();
	if (nums.size() == 0)
		return 0;
	size_t i = 0;
	for (size_t j = 1; j != nums.size(); ++j) {
		if (nums[i] != nums[j]) {
			++i;
			nums[i] = nums[j];
		}
	}
	return i - 1;
}

void run_remove_duplicates() {
	std::vector<int> input({1, 1, 2});
	assert(remove_duplicates(input) == 2);
	assert(input[1] == 2);
}