#pragma once
#include <cstdio>
#include <vector>
void print_reverse(const char *string) {
	if (not *string)
		return;

	print_reverse(string + 1);
	std::putchar(*string)
}

void reverse_string(std::vector<char> &s) {
	if (s.size() == 0)
		return;
	size_t i{0}, j{s.size() - 1};
	while (i < j) {
		std::swap(s[i++], s[j--]);
	}
}