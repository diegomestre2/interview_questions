int kthSmallest(vector<vector<int>> &matrix, int k) {
	std::priority_queue<int> queue;
	for (auto vec : matrix) {
		for (auto value : vec) {
			queue.push(value);
			if (queue.size() > k) {
				queue.pop();
			}
		}
	}

	return queue.top();
}