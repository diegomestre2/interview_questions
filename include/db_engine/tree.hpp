#pragma once
#include <vector>
#include <stdexcept>
#include <queue>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode (int value) : val(value), left(nullptr), right(nullptr){}
};

using output_t = std::vector<size_t>;
output_t sum_levels(TreeNode *root) {
	output_t output;
	if (root == nullptr) {
		throw std::invalid_argument("Empty input");
	}

	std::queue<TreeNode*> queue;
	queue.push(root);
	while (!queue.empty()) {
		auto level_size = queue.size();
		auto level_sum =0;
	for (size_t i = 0; i < level_size; ++i){
		auto current_node = queue.front();
		queue.pop();
		level_sum += current_node->val;
		// left side?
		if (current_node->left != nullptr) {
			queue.push(current_node->left);
		}
		if (current_node->right != nullptr) {
			queue.push(current_node->right);
		}
	}
		output.push_back(level_sum);
		// right side?
	}

	return output;
}

// 1,0