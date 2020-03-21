#include <data_structure/binary_tree.hpp>

BinarySearchTree::BinarySearchTree() {
	root_node = std::unique_ptr<Node>(new Node());
}

void BinarySearchTree::insert_node(Node *node_to_insert) {
	auto walk_node = root_node.get();
	while (walk_node != nullptr) {
		if (node_to_insert->value > walk_node->value)
			walk_node = walk_node->right_node;
		else
			walk_node = walk_node->left_node;
	}
	walk_node = node_to_insert;
}

void BinarySearchTree::remove_node(Node *node_to_remove) {
	Node *prev_node = nullptr;
	auto walk_node = root_node.get();
	while (walk_node != node_to_remove) {
		prev_node = walk_node;
		if (node_to_remove->value > walk_node->value)
			walk_node = walk_node->right_node;
		else
			walk_node = walk_node->left_node;
	}
	// check if the root should be removed
	if (!prev_node) {
		prev_node = root_node.get();
	}
}

void BinarySearchTree::insert_value(Value value_to_insert) {
	auto new_node = std::unique_ptr<Node>(new Node(value_to_insert));
	insert_node(new_node.get());
}
void BinarySearchTree::remove_value(Value value_to_remove) {
}
void BinarySearchTree::print() {
	auto walk_node = root_node.get();
	while (walk_node->value != 0) {
		std::cout << walk_node->value << ' ';
	}
	std::cout << std::endl;
}