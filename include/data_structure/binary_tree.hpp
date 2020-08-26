#pragma once

#include <iostream>

using Value = uint32_t;
struct Node {
	Node(Value new_value) {
		value = new_value;
		left_node = nullptr;
		right_node = nullptr;
	}
	Value value;
	Node *left_node;
	Node *right_node;
};
class BinarySearchTree {
public:
	BinarySearchTree();
	BinarySearchTree(BinarySearchTree &rhs){};
	BinarySearchTree(BinarySearchTree &&rhs) = delete;
	~BinarySearchTree();

	// methods
	void insert_node(Node *node_to_insert);
	void remove_node(Node *node_to_remove);
	void insert_value(Value value_to_insert);
	void remove_value(Value value_to_remove);
	void print();

private:
	Node *find_successor_node(Node *root_node);
	void print_node(Node *root);
	Node *root_node;
};