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

	BTNode<T>(T data);
	BTNode<T>(const BTNode& other);
	BTNode<T>& operator=(const BTNode& other);
	void copy(const BTNode& other);
	bool find(T data) const;
	bool isLeaf() const;
	bool remove(T data);
	void insert(T data);
	void print(int space);
	T find_leaf_remove();
	void cleanup();
};

template <typename T>
BTNode<T>::BTNode(T data) {
	this->data = data;
}

template <typename T>
BTNode<T>& BTNode<T>::operator=(const BTNode<T>& other) {
	if (&other != this) {
		cleanup();
		copy(other);
	}
	return* this;
}

template <typename T>
BTNode<T>::BTNode(const BTNode<T>& other) {
	copy(other);
}

template <typename T>
void BTNode<T>::copy(const BTNode<T>& other) {
	this->data = other.data;
	left = nullptr;
	right = nullptr;
	if (other.left != nullptr) {
		this->left = new BTNode<T>(*other.left);
	}
	if (other.right != nullptr) {
		this->right = new BTNode<T>(*other.right);
	}
}

template <typename T>
void BTNode<T>::cleanup() {
	if (left != nullptr) {
		
		if (left->isLeaf()) {
			delete left;
			left = nullptr;
		}
		else {
			left->cleanup();
			delete left;
			left = nullptr;
		}
	}
	if (right != nullptr) {

		if (right->isLeaf()) {
			delete right;
			right = nullptr;
		}
		else {
			right->cleanup();
			delete right;
			right = nullptr;
		}
	}
}

template <typename T>
bool BTNode<T>::remove(T data) {
	bool retval = false;
	if (left != nullptr) {
		if (left->data == data) {
			if (left->isLeaf()) {
				delete left;
				left = nullptr;
			}
			else {
				T leaf_val = left->find_leaf_remove();
				left->data = leaf_val;
			}
			retval = true;
		}
	}
	if (right != nullptr) {
		if (right->data == data) {
			if (right->isLeaf()) {
				delete right;
				right = nullptr;
			}
			else {
				T leaf_val = right->find_leaf_remove();
				right->data = leaf_val;
			}
			retval = true;
		}
	}
	if (left != nullptr) {
		retval |= left->remove(data);
	}
	if (right != nullptr) {
		retval |= right->remove(data);
	}
	return retval;
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
bool BTNode<T>::find(T data) const {
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
	cout << endl << setw(space - COUNT) << data << endl;

	// Process left child  
	if (left != nullptr)
		left->print(space);
}
//=================================================================
//=================================================================

template <typename T>
class BinaryTree {
private:
	BTNode<T> * root = nullptr;
	void copy(const BinaryTree<T>& other);
	void cleanup();
	
public:
	BinaryTree();
	BinaryTree(int size, T* data);
	~BinaryTree();
	BinaryTree(const BinaryTree<T>& other);
	BinaryTree<T>& operator=(const BinaryTree<T>& other);
	bool find(T data);
	void insert(T data);
	bool remove(T data);
	void sort();
	void print() const;
	bool isLeaf() const;
	bool isNull() const; //empty tree
};

template <typename T>
void BinaryTree<T>::copy(const BinaryTree<T>& other) {
	if (other.root != nullptr)
		root = new BTNode<T>(*other.root);
	/*if (other->left != nullptr) {
		root->left = other->root->left;
	}
	if (other->right != nullptr) {
		root->right = other->root->right;
	}*/
}

template <typename T>
void BinaryTree<T>::cleanup() {
	if (root == nullptr) {
		return;
	}
	if (root->isLeaf()) {
		delete root;
		root = nullptr;
	}
	else {
		root->cleanup();
		delete root;
		root = nullptr;
	}
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
	cleanup();
}

template <typename T>
bool BinaryTree<T>::isNull() const {
	return (root == nullptr);
}

template <typename T>
bool BinaryTree<T>::isLeaf() const {
	if (root == nullptr)
		return true;
	return (root->right == nullptr) && (root->left == nullptr);
}


template <typename T>
BinaryTree<T>& BinaryTree<T>::operator=(const BinaryTree<T>& other) {
	if (&other != this) {
		cleanup();
		copy(other);
	}
	return *this;
}


template <typename T>
BinaryTree<T>::BinaryTree(const BinaryTree<T>& other) {
	copy(other);
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
bool BinaryTree<T>::remove(T data) {
	bool retval = false;
	if (root == nullptr) {
		return false;
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
		retval = true;
	}
	if (!isNull()) {
		retval |= root->remove(data);
	}
	return retval;
	
}

template <typename T>
void BinaryTree<T>::sort() {

}

template <typename T>
void BinaryTree<T>::print()const
{
	if (isNull()) {
		cout << "Tree is Empty" << endl;
	}
	else {
		root->print(0);
	}
}


#endif