#pragma once
#include <algorithm>
#include <vector>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {
	}
};

ListNode *mergeKListsOpt(vector<ListNode *> &lists) {
	auto new_list = new ListNode();
	auto pointer = new_list;
	auto p_queue = std::priority_queue<int, std::vector<int>, std::greater<int>>();
	for (auto list : lists) {
		while (list) {
			p_queue.push(list->val);
			list = list->next;
		}
	}
	while (not p_queue.empty()) {
		auto val = p_queue.top();
		p_queue.pop();
		pointer->next = new ListNode(val);
		pointer = pointer->next;
	}
	return new_list->next;
}