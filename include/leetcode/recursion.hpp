#pragma once
#include "data_structure/list.hpp"

#include <cstdio>
#include <vector>
void print_reverse(const char *string) {
	if (not *string)
		return;

	print_reverse(string + 1);
	std::putchar(*string)
}

void reverse_string(std::vector<char> &s) {
	if (s.size() == 0)
		return;
	size_t i{0}, j{s.size() - 1};
	while (i < j) {
		std::swap(s[i++], s[j--]);
	}
}

ListNode *swap_pairs(ListNode *head) {
	// base case
	if (!head || !head->next) {
		return head;
	}
	// pair
	auto first_node = head;
	auto second_node = head->next;
	// swap
	first_node->next = swap_pairs(second_node->next);
	second_node->next = first_node;

	return second_node;
}

ListNode *reverseList(ListNode *head) {
	ListNode *previous_node = nullptr;
	auto current_node = head;
	while (current_node) {
		auto next_node = current_node->next;
		current_node->next = previous_node;
		previous_node = current_node;
		current_node = next_node;
	}
	return previous_node;
}

TreeNode *searchBST(TreeNode *root, int val) {
	if (!root)
		return nullptr;
	if (root->val == val)
		return root;
	if (root->val > val)
		return searchBST(root->left, val);
	return searchBST(root->right, val);
}