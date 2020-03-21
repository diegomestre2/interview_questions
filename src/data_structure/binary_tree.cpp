#include <data_structure/binary_tree.hpp>

BinarySearchTree::BinarySearchTree() {
	root_node = nullptr;
}

void BinarySearchTree::insert_node(Node *node_to_insert) {
	Node *walk_node = root_node;
	// case first node
	if (!walk_node) {
		root_node = std::move(node_to_insert);
		return;
	}
	// other cases
	while (walk_node) {
		if (node_to_insert->value > walk_node->value)
			walk_node = walk_node->right_node;
		else
			walk_node = walk_node->left_node;
	}
	// insert node
	walk_node = std::move(node_to_insert);
}

void BinarySearchTree::remove_node(Node *node_to_remove) {
	Node *prev_node = nullptr;
	auto walk_node = root_node;
	while (walk_node != node_to_remove) {
		prev_node = walk_node;
		if (node_to_remove->value > walk_node->value)
			walk_node = walk_node->right_node;
		else
			walk_node = walk_node->left_node;
	}
	// check if the root should be removed
	if (!prev_node) {
		prev_node = root_node;
	} else {
		prev_node->right_node = walk_node->right_node;
		prev_node->left_node = walk_node->left_node;
	}
	delete walk_node;
}

void BinarySearchTree::insert_value(Value value_to_insert) {
	auto new_node = new Node(value_to_insert);
	insert_node(std::move(new_node));
}
void BinarySearchTree::remove_value(Value value_to_remove) {
}
void BinarySearchTree::print() {
	auto walk_node = root_node;
	if (walk_node == nullptr)
		return;
	while (walk_node->left_node && walk_node->right_node) {
		print_node(walk_node->left_node);
		print_node(walk_node->right_node);
	}
	std::cout << walk_node->value << std::endl;
}

void BinarySearchTree::print_node(Node *root) {
	auto walk_node = root_node;
	if (walk_node == nullptr)
		return;
	while (walk_node->left_node || walk_node->right_node) {
		print_node(walk_node->left_node);
		print_node(walk_node->right_node);
	}
	std::cout << walk_node->value << std::endl;
}

BinarySearchTree::~BinarySearchTree() {
	while (root_node) {
		remove_node(root_node->left_node);
		remove_node(root_node->right_node);
	}
}