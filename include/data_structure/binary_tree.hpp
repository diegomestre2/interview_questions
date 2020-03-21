#pragma once

#include <iostream>
#include <memory>

class BinarySearchTree {
public:
	BinarySearchTree();
	BinarySearchTree(BinarySearchTree &rhs){};
	BinarySearchTree(BinarySearchTree &&rhs) = delete;
	struct Node;
	using Value = uint32_t;
	// methods
	void insert_node(Node *node_to_insert);
	void remove_node(Node *node_to_remove);
	void insert_value(Value value_to_insert);
	void remove_value(Value value_to_remove);
	void print();

private:
	std::unique_ptr<Node> root_node;
};

struct BinarySearchTree::Node {
	Node() {
		value = 0;
		left_node = right_node = nullptr;
	}
	Node(Value value) : value(value) {

		left_node = right_node = nullptr;
	}
	Value value;
	Node *left_node;
	Node *right_node;
};