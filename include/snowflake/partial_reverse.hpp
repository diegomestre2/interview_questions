#pragma once

#include <exception>
#include <hello/hello.hpp>
#include <iostream>
#include <vector>

template <typename T> void partial_reverse(std::vector<T> &vec, size_t a, size_t n) {
	if (a >= n) {
		throw("A should be smaller than N");
	}
	if (n >= vec.size()) {
		throw("N should be smaller than vector size");
	}
	T temp = 0;
	while (a < n) {
		temp = vec[a];
		vec[a++] = vec[n];
		vec[n--] = temp;
	}
}

void run_partial_reverse() {
	std::cout << "Partial Reverse" << std::endl;
	size_t vec_count = 5;
	std::vector<uint32_t> vec;
	for (size_t i = 0; i != vec_count; ++i) {
		vec.push_back(i);
	}

	partial_reverse(vec, 2, 4);
	for (size_t i = 0; i != vec.size(); ++i) {
		std::cout << vec[i] << ' ';
	}
	std::cout << std::endl;
}