#pragma once

#include <iostream>
#include <vector>

void swap(uint32_t &lhs, uint32_t &rhs) {
	uint32_t temp;
	temp = lhs;
	lhs = rhs;
	rhs = temp;
}

void max_heapify(std::vector<uint32_t> &vec, size_t index) {
	uint32_t temp = vec[index];
	size_t j = 2 * index;
}

void build_max_heap(std::vector<uint32_t> &vec) {
	for (size_t i = vec.size() / 2; i >= 1; --i) {
		max_heapify(vec, i);
	}
}

uint32_t find_k_largest_element(std::vector<uint32_t> &vec, size_t k) {
	build_max_heap(vec);
	for (size_t i = 0; i != k; ++i) {
		max_heapify(vec, i);
	}
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