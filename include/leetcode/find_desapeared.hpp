vector<int> findDisappearedNumbers(vector<int> &nums) {
	std::vector<int> result;

	for (size_t i = 0; i != nums.size(); ++i) {
		auto j = std::abs(nums[i]) - 1;
		nums[j] = std::abs(nums[j]) * -1;
	}
	for (size_t i = 0; i != nums.size(); ++i) {
		if (nums[i] > 0) {
			result.push_back(i + 1);
		}
	}

	return result;
}