#include <iostream>
#include <vector>

/// MERGE K LISTS ///

// You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
// Merge all the linked-lists into one sorted linked-list and return it.

/*
Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output:
[1->1->2->3->4->4->5->6]


Input: lists = []
Output: []

Input: lists = [[]]
Output: []


Constraints:

k == lists.length
0 <= k <= 10^4
0 <= lists[i].length <= 500
lists[i] is sorted in ascending order.

Answers:

Time: O(nlogn)
Space:  O(n)


Time: O(nlogk) or O(kN)
Space: O(k) or O(1)

*/

struct ListNode {
	int value;
	ListNode *next;
	ListNode(int x) : value(x), next(nullptr) {
	}
};

ListNode *merge_lists(ListNode *a, ListNode *b) {

	auto ans = new ListNode(0);
	auto aux = a;
	while (a->next && b->next) {
		if (aux->value > b->value) {
			ans->next = new ListNode(b->value);
			b = b->next;
		} else {
			ans->next = new ListNode(a->value);
			a = a->next;
		}
		ans = ans->next;
	}
	return ans->next;
}

/*
ListNode *merge_k_lists(std::vector<ListNode *> &lists) {
    for (auto i = 0; i != lists.size(); ++i) {
        auto aux_node = lists[i];
        auto aux_node2 = lists[i + 1];

        while () {
            if (aux_node->value > aux_node2->value) {
                std::swap(aux_node, aux_node2);
            }
        }
    }
}*/

int main() {
	ListNode *list1 = new ListNode(1);
	list1->next = new ListNode(3);
	ListNode *list2 = new ListNode(2);
	list2->next = new ListNode(4);

	// auto res = merge_lists(list1, list2);

	/*while (res) {
	    std::cout << res->value << " ";
	    res = res->next;
	}*/
}

/*

[
  1->4->5,
  1->3->4,
  2->6
]


list1 = head1;
list2 = head2;
if list1 < list2
list3 = head3;


*/