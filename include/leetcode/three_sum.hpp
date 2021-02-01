vector<vector<int>> threeSum(vector<int> &nums) {
	vector<vector<int>> result;
	std::unordered_map<int, int> memo;
	if (nums.size() == 0)
		return {};
	auto target = 0 - nums[0];
	for (int j = i + 1; j != nums.size(); ++j) {
		auto complement = target - nums[j];
		auto it = memo.find(complement);
		if (it != memo.end()) {
			result.push_back({nums[0], nums[j], nums[it->second]});
		} else {
			memo.insert(std::make_pair(nums[j], j));
		}
	}
	//}
	return result;
}