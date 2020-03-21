#pragma once

using Value = uint32_t;

struct Node {
	Node() {
		value = 0;
	}
	Node(Value) : value(value) {
	}
	Value value;
	Node *left_node{nullptr};
	Node *right_node{nullptr};
};

class BinarySearchTree() {
public:
	BinarySearchTree();
	void insert_node(Node * node_to_insert);
	void remove_node(Node * node_to_remove);
	void insert_value(Value value_to_insert);
	void remove_value(Value value_to_remove);
	void print();

private:
	Node *root_node{nullptr};
};
