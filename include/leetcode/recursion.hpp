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

ListNode *reverse_list(ListNode *head) {
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
ListNode *reverse_list_recursive(ListNode *head) {
	if (!head || !head->next)
		return head;
	ListNode *previous_node = reverseList(head->next);
	head->next->next = head;
	head->next = nullptr;
	return previous_node;
}

TreeNode *search_BST(TreeNode *root, int val) {
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

int get_num(int row, int col) {
	auto rowCol = key(row, col);

	if (cache.count(rowCol) > 0)
		return cache[rowCol];

	if (row == 0 || col == 0 || row == col)
		return (cache[rowCol] = 1);

	return (cache[rowCol] = getNum(row - 1, col - 1) + getNum(row - 1, col));
}

vector<int> get_row(int rowIndex) {
	vector<int> ans;

	for (int i = 0; i <= rowIndex; i++)
		ans.push_back(get_num(rowIndex, i));

	return ans;
}

int fib(int N) {
	if (N == 0)
		return 0;
	if (N <= 2)
		return 1;
	return fib(N - 1) + fib(N - 2);
}

int climbStairs(int n) {
	auto memo = std::make_unique<int[]>(n + 1);
	return climb_stairs(0, n, memo.get());
}
int climb_stairs(int i, int n, int *memo) {
	if (i > n)
		return 0;
	if (i == n)
		return 1;
	if (memo[i] > 0)
		return memo[i];
	memo[i] = climb_stairs(i + 1, n, memo) + climb_stairs(i + 2, n, memo);
	return memo[i];
}
std::vector<int> pascal_triangle_get_row(int row_idx) {
	std::vector<int> current_row({1});
	if (row_idx == 0)
		return result;
	auto previous_row = pascal_triangle_get_row(row_idx - 1);
	for (size_t i = 1; i != prev.size(); ++i) {
		auto val = previous_row[i] + previous_row[i - 1];
		current_row.push_back(val);
	}
	current_row.push_back(1);
	return current_row;
}

std::map<int, int> memo;
int fib_memoization(int n) {
	int res{0};
	if (n == 0)
		return res;
	auto iter = memo.find(n);
	if (iter != memo.end())
		return iter->second;
	if (n == 2 || n == 1)
		res = 1;
	else
		res = fib(n - 1) + fib(n - 2);
	memo.insert(std::pair<int, int>(n, res));
	return res;
}

int maxDepth(TreeNode *root) {
	if (!root)
		return 0;
	if (!root->left && !root->right)
		return 1;
	auto left_max = maxDepth(root->left);
	auto right_max = maxDepth(root->right);
	return (left_max > right_max) ? (left_max + 1) : (right_max + 1);
}

double myPow(double x, int n) {
	long double result;
	if (n > (-1 * pow(2, 31)) or n < pow(2, 31)) {
		if (x >= 0) {
			result = pow(x, n);
		} else {
			if (n % 2 == 0) {
				result = pow((-(x)), n);
			} else {
				result = (-1) * pow((-(x)), n);
			}
		}
		return result;
	} else {
		return 0;
	}
}

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
	if (!l1)
		return l2;
	else if (!l2)
		return l1;
	ListNode dummy;
	ListNode *tail = &dummy;
	dummy.next = nullptr;
	if (l1->val <= l2->val) {
		tail->next = l1;
		tail->next->next = mergeTwoLists(l1->next, l2);
	} else {
		tail->next = l2;
		tail->next->next = mergeTwoLists(l1, l2->next);
	}
	return dummy.next;
}