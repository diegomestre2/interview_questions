int findMin(vector<int> &nums) {
	auto i = 0, j = 1;
	while (j < nums.size()) {
		if (nums[i] > nums[j]) {
			return nums[j];
		}
		i++;
		j++;
	}
	return nums[0];
}