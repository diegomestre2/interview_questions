#pragma once

#include <iostream>
#include <vector>

void swap(uint32_t &lhs, uint32_t &rhs) {
	uint32_t temp;
	temp = lhs;
	lhs = rhs;
	rhs = temp;
}

uint32_t find_k_largest_element(std::vector<uint32_t> &vec, size_t k) {
	std::vector<uint32_t> vec_desc(vec.size(), 0);
	for (size_t i = 0, j = 0; i != vec.size(); ++i) {
		if (vec[i] > vec_desc[j]) {
			vec_desc[j] = vec[i];
			while (vec_desc[j + 1] > vec_desc[j] && j < k) {
				swap(vec_desc[j + 1], vec_desc[j]);
				j++;
			}
			j = 0;
		}
	}
	return vec_desc[k - 1];
}

void run_kth_largest() {
	std::cout << "Find kth largest" << std::endl;
	std::vector<uint32_t> vec;
	vec = {1, 2, 3, 4, 5};
	uint32_t result = find_k_largest_element(vec, 3);
	for (size_t i = 0; i != vec.size(); ++i) {
		std::cout << vec[i] << " ";
	}
	std::cout << " K: " << result << std::flush;
}