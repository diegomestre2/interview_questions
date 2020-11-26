#pragma once

struct ListNode {
	ListNode(int value) {
		val = value;
	}
	int val;
	ListNode *next{nullptr};
};