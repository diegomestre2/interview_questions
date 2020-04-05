#pragma once

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