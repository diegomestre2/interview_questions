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

unordered_map<size_t, int> cache;

// use a better hashing function like `boost::hash_combine` in the real world.
int key(int i, int j) const {
	size_t hash_i = hash<int>{}(i), hash_j = hash<int>{}(j);
	int hashed = (int)(hash_i ^ (hash_i >> 32));
	return (hashed << 5) - 1 + (int)(hash_j ^ (hash_j >> 32));
}

int getNum(int row, int col) {
	auto rowCol = key(row, col);

	if (cache.count(rowCol) > 0)
		return cache[rowCol];

	if (row == 0 || col == 0 || row == col)
		return (cache[rowCol] = 1);

	return (cache[rowCol] = getNum(row - 1, col - 1) + getNum(row - 1, col));
}

vector<int> getRow(int rowIndex) {
	vector<int> ans;

	for (int i = 0; i <= rowIndex; i++)
		ans.push_back(getNum(rowIndex, i));

	return ans;
}
