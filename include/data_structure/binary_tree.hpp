#pragma once

#include <iostream>

class BinarySearchTree {
public:
	BinarySearchTree();
	BinarySearchTree(BinarySearchTree &rhs){};
	BinarySearchTree(BinarySearchTree &&rhs) = delete;
	~BinarySearchTree();
	struct Node;
	using Value = uint32_t;
	// methods
	void insert_node(Node *node_to_insert);
	void remove_node(Node *node_to_remove);
	void insert_value(Value value_to_insert);
	void remove_value(Value value_to_remove);
	void print();

private:
	void print_node(Node *root);
	Node *root_node;
};

struct BinarySearchTree::Node {
	Node(Value new_value) {
		value = new_value;
		left_node = nullptr;
		right_node = nullptr;
	}
	Value value;
	Node *left_node;
	Node *right_node;
};