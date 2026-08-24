#pragma once
#include <vector>
#include <stdio.h>;

template <class T>
class tree_node {
private:
	T node_value;
	tree_node<T>* node_father = nullptr;
	std::vector<tree_node<T>*> child_node;
public:
	~tree_node() {
		if (node_father != nullptr) return;
		for (auto *i : child_node) delete i;
	}
	void set(const T& value_) {
		node_value = value_;
	}
	tree_node<T>& child(int id) {
		while (id >= child_node.size()) {
			tree_node<T>* node = new tree_node<T>;
			node->node_father = this;
			child_node.push_back(node);
		}
		return *child_node[id];
	}
	tree_node<T>& father() {
		return *node_father;
	}
	T& value() {
		return node_value;
	}
	std::vector<tree_node<T>*>& children() {
		return child_node;
	}
	int size() {
		return child_node.size();
	}
};
