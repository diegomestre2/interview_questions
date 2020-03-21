#include <data_structure/binary_tree.hpp>

BinarySearchTree::BinarySearchTree() {
	root_node = unique_ptr<Node>(new Node());
}

void BinarySearchTree::insert_node(Node *node_to_insert) {
	auto tmp_node = root_node;
	while (tmp_node != nullptr) {
		if (node_to_insert->value > tmp_node->value)
			tmp_node = tmp_node->right;
		else
			tmp_node = tmp_node->left;
	}
	tmp_node = node_to_insert;
}

void BinarySearchTree::remove_node(Node *node_to_remove) {
	Node *prev_node = nullptr;
	auto walk_node = root_node;
	while (walk_node != node_to_remove) {
		if (node_to_remove->value > tmp_node->value)
			walk_node = walk_node->right;
		else
			walk_node = walk_node->left;
	}
	tmp_node = nullptr;
}

void BinarySearchTree::insert_value(Value value) {
	auto new_node = unique_ptr<Node>(value);
	insert_node(move(new_node));
}

void BinarySearchTree::print() {
	tmp_node = root_node;
	while (tmp_node->value != 0)
}