int maxProduct(vector<int> &nums) {
	if (nums.empty())
		return 0;
	int mx = INT_MIN, mul = 1;
	for (int i = 0; i < nums.size(); i++) {
		mul *= nums[i];
		if (mul > mx)
			mx = mul;
		if (nums[i] == 0)
			mul = 1;
	}

	mul = 1;
	for (int i = nums.size() - 1; i >= 0; i--) {
		mul *= nums[i];
		if (mul > mx)
			mx = mul;
		if (nums[i] == 0)
			mul = 1;
	}

	return mx;
}