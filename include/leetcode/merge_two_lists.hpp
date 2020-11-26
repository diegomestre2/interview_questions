#pragma once
#include "list_node.hpp"

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {

	auto merged_list = new ListNode(0);
	auto walker = merged_list;
	while (l1 && l2) {
		if (l1->val < l2->val) {
			walker->next = new ListNode(l1->val);
			l1 = l1->next;
		} else {
			walker->next = new ListNode(l2->val);
			l2 = l2->next;
		}
		walker = walker->next;
	}
	// merges the remaining of one list
	if (l1) {
		walker->next = l1;
	} else {
		walker->next = l2;
	}
	return merged_list->next;
}