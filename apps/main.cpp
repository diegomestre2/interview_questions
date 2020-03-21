#include <data_structure/binary_tree.hpp>
#include <snowflake/snowflake.hpp>

int main(int argc, char **argv) {
	// Snowflake runner;
	// runner.run_snowflake();
	auto bin_tree = std::unique_ptr<BinarySearchTree>(new BinarySearchTree());
	bin_tree->insert_value(10);
	bin_tree->insert_value(20);
	bin_tree->insert_value(30);
	bin_tree->print();

	return 0;
}