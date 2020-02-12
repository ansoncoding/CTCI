#ifndef TREE_H
#define TREE_H

#include <iostream>


using namespace std;

template <typename T>
class BTNode {
private:
	T data;
	BTNode<T>* left = nullptr;
	BTNode<T>* right = nullptr;
public:
	BTNode(T data) {
		data = data;
	}
	
	void print() const {
		cout << data << '\t';
	}
};

template <typename T>
class BinaryTree {
private:
	BTNode * root = nullptr;
	void copy(const BinaryTree& other);
	void cleanup();
public:
	BinaryTree();
	BinaryTree(int size, T* data);
	~BinaryTree();
	BinaryTree(const BinaryTree& other);
	BinaryTree& operator=(const BinaryTree& other);
	BinaryTree<T> get_left_subtree() const;
	BinaryTree<T> get_right_subtree() const;
	bool find(T data);
	void insert(T data);
	void remove(T data);
	void sort();
	void print() const;
	bool isLeaf() const;
	bool isNull() const; //empty tree
};

template <typename T>
void BinaryTree<T>::copy(const BinaryTree& other) {

}

template <typename T>
void BinaryTree<T>::cleanup() {

}

template <typename T>
BinaryTree<T>::BinaryTree() {
}

template <typename T>
BinaryTree<T>::BinaryTree(int size, T* vals) {
	for (int i = 0; i < size; i++) {
		insert(vals[i]);
	}	
}

template <typename T>
BinaryTree<T>::~BinaryTree() {

}

template <typename T>
BinaryTree<T> BinaryTree<T>::get_left_subtree() const {
	return BinaryTree<T>(root->left);
}

template <typename T>
BinaryTree<T> BinaryTree<T>::get_right_subtree() const {
	return BinaryTree<T>(root->right);
}

template <typename T>
bool BinaryTree<T>::isNull() const {
	if (root == nullptr)
		return true;
	return false;
}

template <typename T>
bool BinaryTree<T>::isLeaf() const {
	if (root == nullptr)
		return true;
	return (root->right == nullptr) && (root->right == nullptr);
}
template <typename T>
BinaryTree<T>::BinaryTree(const BinaryTree& other) {

}

template <typename T>
BinaryTree<T>& BinaryTree<T>::operator=(const BinaryTree& other) {
	if (&other != this) {
		cleanup();
		copy(other);
	}
	return *this;
}

template <typename T>
bool BinaryTree<T>::find(T data) {
	if (root == nullptr)
		return false;
	return root->left->find(data) || root->right->find(data);
}

template <typename T>
void BinaryTree<T>::insert(T data) {
	if (root == nullptr) {
		root = new Node(data);
	}
	else {
		root.insert(data);
	}
}

template <typename T>
void BinaryTree<T>::remove(T data) {

}

template <typename T>
void BinaryTree<T>::sort() {

}

template <typename T>
void BinaryTree<T>::print() const {
	if (root != nullptr) {
		root.print();
	}
}


#endif