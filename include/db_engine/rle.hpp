#include <string>

std::string& compress_rle(std::string& input) {
	if (input.empty()) return input;

	uint64_t read = 0;
	uint64_t write = 0;
	uint8_t counter = 0;
	char current_run = input[0];

	// Start reading from index 0, counting runs
	for (; read < input.length(); ++read) {
		char c = input[read];
		if (c == current_run) {
			++counter;
		} else {
			// Flush previous run
			input[write++] = current_run;
			input[write++] = static_cast<char>(counter);
			// Start new run
			current_run = c;
			counter = 1;
		}
	}

	// Flush final run
	input[write++] = current_run;
	input[write++] = static_cast<char>(counter);

	input.resize(write);
	return input;
}

