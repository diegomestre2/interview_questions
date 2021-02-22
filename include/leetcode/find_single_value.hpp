int singleNumber(vector<int> &nums) {
	std::unordered_map<int, int> mem;
	int candidate = 0;
	for (size_t i = 0; i != nums.size(); ++i) {
		int to_find = nums[i];
		auto iter = mem.find(to_find);
		if (iter != mem.end()) {
			iter->second++;
		} else {
			mem.insert(std::make_pair(to_find, 1));
		}
	}

	for (auto pair : mem) {
		if (pair.second == 1)
			return pair.first;
	}
	return -1;
}