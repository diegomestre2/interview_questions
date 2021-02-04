
#include <algorithm>
#include <cassert>
#include <vector>

size_t max_two(std::vector<int> &nums, size_t left, size_t right) {
	size_t max_a{0}, max_b{0}, max_c{0}; // f(n-2), f(n-1), f(n)
	for (size_t i = left; i <= right; ++i) {
		max_c = std::max(max_a + nums[i], max_b);
		max_a = max_b;
		max_b = max_c;
	}
	return max_b;
}

int rob(std::vector<int> &nums) {
	// return rob_helper(nums, nums.size(), 0);
	return std::max(max_two(nums, 0, nums.size() - 2), max_two(nums, 1, nums.size() - 1));
}

void run_rob() {
	std::vector<int> test1 = {2, 3, 2};
	assert(rob(test1) == 3);
	std::cout << rob(test1);

	//! Diego robs house 1 (money = 1) and then robs house 3 (money = 3).
	std::vector<int> test2 = {1, 2, 3, 1};
	assert(rob(test2) == 4);
	std::cout << rob(test2);

	//! As just an honorary brazilian, Mark sucks at robbing and jumps in an empty house
	std::vector<int> test3 = {0};
	assert(rob(test3) != 0);
	std::cout << rob(test3);
}