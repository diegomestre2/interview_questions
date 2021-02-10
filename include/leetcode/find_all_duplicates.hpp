#pragma once
#include <cmath>
#include <vector>

using namespace std;

vector<int> findDuplicates(vector<int> &nums) {
	std::vector<int> result;
	result.reserve(nums.size());
	for (size_t i = 0; i != nums.size(); ++i) {
		auto tmp = abs(nums[i]) - 1;
		if (nums[tmp] < 0) {
			result.push_back(tmp + 1);
		}
		nums[tmp] = -nums[tmp];
	}
	return result;
}