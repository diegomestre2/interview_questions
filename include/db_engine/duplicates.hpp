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

// 1 2 6 --- 3 5 7


void merge_sorted(std::vector<uint32_t> &input1, std::vector<uint32_t> & input2) {
	input1.resize(input1.size() + input2.size());
	size_t read1 = 0;
	size_t read2 = 0;
	size_t write = 0;

	while(read1 < input1.size()) {
		if (input1[read1] > input2[read2]) {
			std::swap(input1[read1], input2[read2]);
		}
		read1++;
		read2++;

	}
}

uint64_t prefix_sum(std::vector<uint32_t> & input) {
	uint64_t sum =0;

}

void reverse(std::string & words) {

}