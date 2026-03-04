#pragma once
#include <vector>
#include<stdexcept>

void remove_duplicates(std::vector<uint32_t> &input) {
	if (input.empty()) {
		throw std::invalid_argument("Empty input");
	}

	uint32_t current_value = input[0];
	size_t write = 1;

	for (size_t read = 1; read < input.size(); ++read) {
		if (input[read] != current_value) {
			current_value = input[read];
			input[write++] = input[read];
		}
	}

	input.resize(write);
}

//7. Rotate an array k positions to the right in place

void rotate_array(std::vector<uint32_t> &input, size_t k) {
	if (input.size() == 0 || k ==0) {
		return;
	}
	if ( k > input.size()) {
		throw std::invalid_argument("Invalid k, must be < input.size()");
	}
	uint32_t copy_last = input[input.size() -1];
	while (k > 0) {
		for (size_t i = input.size() -1; i > 0; --i) {
			input[i] = input[i-1];
		}
		input[0] = copy_last;
		copy_last = input[input.size() -1];
		--k;
	}
}