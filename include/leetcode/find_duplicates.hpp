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