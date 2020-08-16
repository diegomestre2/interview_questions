#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

template <typename T> std::vector<T> find_kth_largest(std::vector<T> &values, size_t k) {
	assert(values.size() > k);
	assert(k > 0);
	// O(nlogn) quicksort
	std::sort(values.begin(), values.end());
	// O(k)
	std::vector<T> largest_values;
	auto iterator = values.rbegin();
	while (k != 0) {
		largest_values.push_back(*iterator++);
		--k;
	}
	return largest_values;
}

template <typename T> std::vector<T> find_kth_largest_opt(std::vector<T> &values, size_t k) {
	assert(values.size() > k);
	assert(k > 0);

	// O(logn) quicksort
	std::priority_queue max_heap(values.begin(), values.end());
	// O(k)
	std::vector<T> largest_values;
	while (k != 0) {
		largest_values.push_back(max_heap.pop());
		--k;
	}
	return largest_values;
}

// To execute C++, please define "int main()"
void run_kth_largest() {
	auto values = std::vector<uint32_t>{1, 2, 3, 4, 5};
	auto k = size_t{2};
	auto largest_values = find_kth_largest(values, k);
	for (auto value : largest_values) {
		std::cout << value << " ";
	}
	return 0;
}
