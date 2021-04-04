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
	// slow and fast pointer
	while (fast && fast->next) {
		middle++;
		tail = fast->next;
		fast = fast->next->next;
		prev_slow = slow;
		slow = slow->next;
	}
	// we have to either walk forward
	if (middle >= n) {
		auto to_walk = middle - n;
		// point tail to beginning
		if (tail->next) {
			// even
			tail->next->next = l;
		} else {
			// odd
			to_walk--;
			tail->next = l;
		}
		while (to_walk-- != 0 && slow) {
			prev_slow = slow;
			slow = slow->next;
		}

		prev_slow->next = nullptr;
		return slow;
	} else { // or backwards
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
