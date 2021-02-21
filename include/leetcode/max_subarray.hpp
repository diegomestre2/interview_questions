int maxSubArray(vector<int> &nums) {

	int max_sum = std::numeric_limits<int>::min();
	int current_sum = 0;
	for (size_t i = 0; i != nums.size(); ++i) {
		current_sum += nums[i];
		current_sum = std::max(current_sum, nums[i]);
		if (current_sum > max_sum) {
			max_sum = current_sum;
		}
	}
	return std::max(max_sum, current_sum);
}