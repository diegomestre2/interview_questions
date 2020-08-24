#pragma once
#include <vector>
void duplicateZeros(vector<int> &arr) {
	for (size_t i = 0; i != arr.size(); ++i) {
		if (arr[i] == 0 && (i != (arr.size() - 1))) {
			size_t j = i + 1;
			while (j != (arr.size() - 1)) {
				arr[j + 1] = arr[j];
				++j;
			}
			// arr[j] = 0;
		}
	}
}