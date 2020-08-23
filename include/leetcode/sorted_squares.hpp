#pragma once
#include <algorithm>
#include <vector>

std::vector<int> sorted_squares(std::vector<int> &A) {
	std::vector<int> result(A.size());
	size_t left{0}, right{A.size()}, idx{A.size() - 1};

	while (left != right) {
		int x = A[left] * A[left];
		int y = A[right - 1] * A[right - 1];

		if (x >= y) {
			result[idx] = x;
			idx--;
			left++;
		} else {
			result[idx] = y;
			idx--;
			right--;
		}
	}
	return result;
}

void run_sorted_squares() {
	auto result = {0, 1, 9, 16, 100};
	auto output = sorted_squares(std::vector<int>({-4, -1, 0, 3, 10}));
	std::equal(result.begin(), result.end(), output.begin());
}