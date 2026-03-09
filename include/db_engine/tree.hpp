#pragma once
#include <cassert>
#include <queue>
#include <stdexcept>
#include <vector>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int value) : val(value), left(nullptr), right(nullptr) {
	}
};

using output_t = std::vector<size_t>;
output_t sum_levels(TreeNode *root) {
	output_t output;
	if (root == nullptr) {
		throw std::invalid_argument("Empty input");
	}

	std::queue<TreeNode *> queue;
	queue.push(root);
	while (!queue.empty()) {
		auto level_size = queue.size();
		auto level_sum = 0;
		for (size_t i = 0; i < level_size; ++i) {
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

TreeNode *make_tree(const std::vector<int32_t> &input) {
	assert(input.size() > 0 && "input must have at least one element");

	TreeNode *root = new TreeNode(input[0]);
	std::queue<TreeNode *> queue;
	queue.push(root);
	size_t input_index = 1;
	while (queue.empty() == false) {
		auto current_node = queue.front(); // fetch current_node
		queue.pop();                       // remove it from the queue (process it)
		// process left side
		if (input_index < input.size() && input[input_index] != 0) {
			current_node->left = new TreeNode(input[input_index]);
			queue.push(current_node->left);
		}
		input_index++;
		// process right side
		if (input_index < input.size() && input[input_index] != 0) {
			current_node->right = new TreeNode(input[input_index]);
			queue.push(current_node->right);
		}
		input_index++;
	}
	return root;
}

/*
 *
 * 1. Compute the maximum width of a binary tree
 * Find how many nodes appear on the widest level.
 * Input is a TreeNode* root.
 *
 */

size_t maximum_width(TreeNode *root) {
	if (root == nullptr) {
		throw std::invalid_argument("Empty input");
	}

	std::queue<TreeNode *> queue;
	queue.push(root);
	size_t width = 0;
	while (!queue.empty()) {
		auto level_size = queue.size();
		width = std::max(width, level_size);

		for (size_t i = 0; i < level_size; ++i) {
			auto current_node = queue.front();
			queue.pop();
			if (current_node->left != nullptr) {
				queue.push(current_node->left);
			}
			if (current_node->right != nullptr) {
				queue.push(current_node->right);
			}
		}
	}
	return width;
}
 using sum_type = uint64_t;

std::vector<sum_type> sum_per_level(TreeNode * root) {
	std::vector<sum_type> output;
	if ( root == nullptr) {
		output;
	}
	std::queue<TreeNode *> queue;
	queue.push(root);
	while ( !queue.empty()) {
		auto level_size = queue.size();
		auto level_sum = 0;
		for (size_t i = 0; i < level_size; ++i) {
			auto current_node = queue.front();
			queue.pop();
			level_sum += current_node->val;
			if (current_node->left != nullptr) {
				queue.push(current_node->left);
			}
			if ( current_node->right != nullptr ) {
				queue.push(current_node->right);
			}
			output.push_back(level_sum);
		}
	}

	return output;

}


int32_t is_height_balanced(TreeNode *root) {
	if (root == nullptr) {
		return 0;
	}

	auto left_height = is_height_balanced(root->left);
	if (left_height == -1) return -1;

	auto right_height = is_height_balanced(root->right);
	if (right_height == -1) return -1;

	if (right_height - left_height < 1) return -1;

	return 1 + std::max(left_height, right_height);
}