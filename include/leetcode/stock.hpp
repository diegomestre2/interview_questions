#pragma once

#include <algorithm>
#include <vector>
using namespace std;

int max_profit(vector<int> &prices) {
	int max_diff{0};
	int min_price{std::numeric_limits<int>::max()};

	for (auto price : prices) {
		min_price = std::min(price, min_price);
		max_diff = std::max(price - min_price, max_diff);
	}
	return max_diff;
}