#pragma once

vector<vector<int>> levelOrder(TreeNode *root) {
	std::queue<TreeNode *> queue[2];
	auto current_queue = &queue[0];
	auto next_queue = &queue[1];
	std::vector<int> level_vals;
	std::vector<vector<int>> result;
	if (not root) {
		return {};
	}
	if (!root->left && !root->right)
		return {{root->val}};
	current_queue->push(root);
	size_t level{0};
	while (not current_queue->empty()) {
		auto node = current_queue->front();
		current_queue->pop();
		level_vals.push_back(node->val);
		if (node->left) {
			next_queue->push(node->left);
		}
		if (node->right) {
			next_queue->push(node->right);
		}
		if (current_queue->empty()) {
			++level;
			result.push_back(level_vals);
			level_vals.clear();
			current_queue = &queue[level % 2];
			next_queue = &queue[(level + 1) % 2];
		}
	}

	return {result};
}