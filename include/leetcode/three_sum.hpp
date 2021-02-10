#pragma once

#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums) {
	vector<vector<int>> result;
	if (nums.size() == 0)
		return {};
	std::sort(nums.begin(), nums.end());
	for (size_t i = 0; i != nums.size(); ++i) {
		if (nums[i] > 0) {
			break;
		}
		if (i > 0 && nums[i] == nums[i - 1]) {
			continue;
		}
		auto value = -nums[i];
		auto left = i + 1;
		auto right = nums.size() - 1;
		while (left < right) {
			auto two_sum = nums[left] + nums[right];
			if (two_sum == value) {
				result.push_back({-value, nums[left], nums[right]});
				left++;
				right--;
			} else if (two_sum > value) {
				right--;
				continue;
			} else if (two_sum < value) {
				left++;
				continue;
			}
			while (left < right && nums[left] == nums[left - 1])
				left++;
			while (left < right && nums[right] == nums[right + 1])
				right--;
		}
	}
	return result;
}