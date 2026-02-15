
#pragma once

class MedianFinder {
public:
	/** initialize your data structure here. */
	MedianFinder() {
	}

	void addNum(int num) {
		max_low.push(num); // add to max heap

		min_high.push(max_low.top()); // balancing step
		max_low.pop();

		if (max_low.size() < min_high.size()) { // maintain equal distribution
			max_low.push(min_high.top());
			min_high.pop();
		}
	}

	double findMedian() {
		return max_low.size() > min_high.size() ? (double)max_low.top()
		                                        : ((double)(max_low.top() + min_high.top()) * 0.5);
	}
	std::priority_queue<int> max_low;                                  // stores the min value with the lowest on top
	std::priority_queue<int, vector<int>, std::greater<int>> min_high; // stores the max values with the highest on top
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */