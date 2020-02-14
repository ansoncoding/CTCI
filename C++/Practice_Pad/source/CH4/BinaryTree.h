#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream>
#include <iomanip>
#include <random>
#include "LinkedListQueue.h"

using namespace std;

template <typename T>
class BTNode {
public:
	const int COUNT = 10;
	T data;
	BTNode<T>* left = nullptr;
	BTNode<T>* right = nullptr;

	BTNode(T data) {
		this->data = data;
	}
	bool find(T data);
	bool isLeaf() const;
	void remove(T data);
	void insert(T data);
	void print(int space);
	T find_leaf_remove();
};

template <typename T>
void BTNode<T>::remove(T data) {

}

template <typename T>
bool BTNode<T>::isLeaf() const {
	return (right == nullptr) && (left == nullptr);
}

template <typename T>
T BTNode<T>::find_leaf_remove() {
	if (isLeaf()) {
		throw std::invalid_argument("Node is already a leaf");
	}
	if (left != nullptr) {
		if (left->isLeaf()) {
			T retval = T(left->data);
			delete left;
			left = nullptr;
			return retval;
		}
	}
	if (right != nullptr) {
		if (right->isLeaf()) {
			T retval = T(right->data);
			delete right;
			right = nullptr;
			return retval;
		}
	}
	int randint = rand();
	if (randint % 2) {
		if (left != nullptr) {
			return left->find_leaf_remove();
		}
		else {
			return right->find_leaf_remove();
		}
	}
	else {
		if (right != nullptr) {
			return right->find_leaf_remove();
		}
		else {
			return left->find_leaf_remove();
		}
	}
}

template <typename T>
void BTNode<T>::insert(T data) {
	int randint = rand();
	if (randint % 2) {
		if (left == nullptr) {
			left = new BTNode<T>(data);
		}
		else if (right == nullptr) {
			right = new BTNode<T>(data);
		}
		else {
			left->insert(data);
		}
	}
	else {
		if (right == nullptr) {
			right = new BTNode<T>(data);
		}
		else if (left == nullptr) {
			left = new BTNode<T>(data);
		}
		else {
			right->insert(data);
		}
	}
}

template <typename T>
bool BTNode<T>::find(T data) {
	if (this->data == data) {
		return true;
	}
	else {
		bool retval = false;
		if (left != nullptr) {
			retval = left->find(data);
		}
		if (!retval && (right != nullptr)) {
			retval = right->find(data);
		}
		return retval;
	}
}

template <typename T>
void BTNode<T>::print(int space) {
	// Increase distance between levels  
	space += COUNT;

	// Process right child first  
	if (right != nullptr)
		right->print(space);

	// Print current node after space count  
	cout << endl << setw(space - COUNT) << data << "\n";

	// Process left child  
	if (left != nullptr)
		left->print(space);
}

template <typename T>
class BinaryTree {
private:
	BTNode<T> * root = nullptr;
	void copy(const BinaryTree& other);
	void cleanup();
	
public:
	BinaryTree();
	BinaryTree(int size, T* data);
	~BinaryTree();
	BinaryTree(const BinaryTree& other);
	BinaryTree& operator=(const BinaryTree& other);
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
bool BinaryTree<T>::isNull() const {
	return (root == nullptr)
}

template <typename T>
bool BinaryTree<T>::isLeaf() const {
	if (root == nullptr)
		return true;
	return (root->right == nullptr) && (root->left == nullptr);
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
	return root->find(data);
}

template <typename T>
void BinaryTree<T>::insert(T data) {
	if (root == nullptr) {
		root = new BTNode<T>(data);
	}
	else {
		root->insert(data);
	}
}


template <typename T>
void BinaryTree<T>::remove(T data) {
	if (root == nullptr) {
		return;
	}
	if (root->data == data) {
		if (isLeaf()) {
			delete root;
			root = nullptr;
		}
		else {
			T leaf_val = root->find_leaf_remove();
			root->data = leaf_val;
		}
	}
	else {
		root->remove(data);
	}
}

template <typename T>
void BinaryTree<T>::sort() {

}

template <typename T>
void BinaryTree<T>::print()const
{
	// Pass initial space count as 0  
	if (root != nullptr)
		root->print(0);
}


#endif