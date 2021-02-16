#pragma once
#include <algorithm>
#include <vector>

using namespace std;

bool contains_duplicate(vector<int> &nums) {
	if (nums.empty())
		return false;
	std::sort(nums.begin(), nums.end());

	for (size_t i = 0; i != nums.size() - 1; ++i) {
		if (nums[i] == nums[i + 1])
			return true;
	}
	return false;
}

int findDuplicate(vector<int> &nums) {
	auto i = nums[0];
	auto j = nums[0];

	do {
		i = nums[i];
		j = nums[nums[j]];
	} while (i != j);

	i = nums[0];
	while (i != j) {
		i = nums[i];
		j = nums[j];
	}
	return j;
}