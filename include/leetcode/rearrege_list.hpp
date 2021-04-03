ListNode<int> *rearrangeLastN(ListNode<int> *l, int n) {
	if (!l)
		return {};
	if (n == 0 || (n == 1 && !l->next))
		return l;
	auto fast = l;
	auto slow = l;
	auto middle = 1;
	auto tail = l;
	auto prev_slow = l;
	while (fast && fast->next) {
		middle++;
		tail = fast->next;
		fast = fast->next->next;
		prev_slow = slow;
		slow = slow->next;
	}
	if (middle == n) {
		tail->next->next = l;
		prev_slow->next = nullptr;
		return slow;
	} else if (middle > n) {
		while (middle != n) {
			middle--;
			prev_slow = slow;
			slow = slow->next;
		}
		if (tail->next) {
			tail->next->next = l;
		} else {
			tail->next = l;
		}
		prev_slow->next = nullptr;
		return slow;
	} else {
		if (n == (middle - 1) * 2)
			return l;
		auto to_walk = middle - (n - middle) - 2;
		slow = l;
		prev_slow = l;
		while (to_walk != 0) {
			to_walk--;
			prev_slow = slow;
			slow = slow->next;
		}
		tail->next = l;
		prev_slow->next = nullptr;
		return slow;
	}
	return l;
}
