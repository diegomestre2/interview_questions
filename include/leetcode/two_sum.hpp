#pragma once
#include <map>
#include <utility>
#include <vector>
std::vector<int> twoSum(std::vector<int> &nums, int target) {
	int i{0}, j{0};
	for (; i != nums.size(); ++i)
		for (j = i + 1; j != nums.size(); ++j)
			if ((target - nums[i]) == nums[j])
				return std::vector<int>({i, j});
	return std::vector<int>({i, j});
}

std::vector<int> twoSumOpt(std::vector<int> &nums, int target) {
	std::map<int, int> map;
	for (int i = 0; i != nums.size(); ++i) {
		auto complement = target - nums[i];
		auto iter = map.find(complement);
		if (iter != map.end()) {
			return std::vector<int>({iter->second, i});
		}
		map.insert(std::pair<int, int>(nums[i], i));
	}
	return std::vector<int>({});
}

void run_two_sum() {
	auto nums = std::vector<int>({2, 7, 11, 15});
	auto result = std::vector<int>({0, 1});
	auto target = 9;

	assert(twoSum(nums, target) == result);
	assert(twoSumOpt(nums, target) == result);
}