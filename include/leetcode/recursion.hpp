#pragma once
#include <cstdio>
void print_reverse(const char *string) {
	if (not *string)
		return;

	print_reverse(string + 1);
	std::putchar(*string)
}