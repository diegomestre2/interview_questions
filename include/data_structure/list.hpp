#pragma once

struct ListNode {
	ListNode(int val_, ListNode *next_) : val(val_), next(next_) {
	}
	int val;
	ListNode *next;
};