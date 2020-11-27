#pragma once
#include "tree_node.hpp"

bool isValidBST(TreeNode *root) {
	std::stack<TreeNode *> stack;
	if (not root || (not root->left && not root->right))
		return true;
	int64_t in_order = std::numeric_limits<int64_t>::min();
	while (not stack.empty() || root != nullptr) {
		// add all left children to the stack
		while (root != nullptr) {
			stack.push(root);
			root = root->left;
		}
		root = stack.top();
		stack.pop();
		if (root->val <= in_order)
			return false;
		in_order = root->val;
		root = root->right;
	}
	return true;
}