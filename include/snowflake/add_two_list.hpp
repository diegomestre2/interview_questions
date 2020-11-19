#pragma once
#include <algorithm>
#include <vector>
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {
	}
};

class Solution {
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		size_t sum{0};
		ListNode *dummy_node = new ListNode(0);
		ListNode *output_list = dummy_node;
		ListNode *head_output = output_list;
		while (l1 != nullptr || l2 != nullptr || sum) {
			if (l1 != nullptr) {
				sum += l1->val;
				l1 = l1->next;
			}
			if (l2 != nullptr) {
				sum += l2->val;
				l2 = l2->next;
			}
			output_list->next = new ListNode(sum % 10);
			sum /= 10;
			output_list = output_list->next;
		}
		return head_output->next;
	}
};

ListNode *mergeKLists(std::vector<ListNode *> &lists) {
	std::vector<int> array;
	for (auto list : lists) { // O(n)
		while (list) {
			array.push_back(list->val);
			list = list->next;
		}
	}
	std::sort(array.begin(), array.end()); // O(nLogn)
	auto head = new ListNode();
	auto point_head = head;
	for (auto val : array) { // O(n)
		point_head->next = new ListNode(val);
		point_head = point_head->next;
	}
	return head->next;
}
