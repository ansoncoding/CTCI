#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream>
#include <iomanip>
#include <random>
#include "LinkedListQueue.h"

using namespace std;

template <typename T>
struct BTNode {
	BTNode* left = nullptr; 
	BTNode* right = nullptr;
	T data = 0;
	BTNode(T data) {
		this->data = data;
	}
};

template <typename T>
class BinaryTree {
protected:
	void cleanup();
	
	BTNode<T> * copy_helper(const BTNode<T>*other);
	bool find_helper(T data, const BTNode<T>* n) const;
	bool remove_helper(T data, BTNode<T>*& n);
	void insert_helper(T data, BTNode<T>* n);
	T find_leaf_remove(BTNode<T> *& n);
	void copy(const BinaryTree& other);
	void deleteNode(BTNode<T>*& n);
	void print_helper(int space, const BTNode<T>* n) const;

	const int COUNT = 10;
	BTNode<T>* root;

public:
	
	BinaryTree<T>();
	BinaryTree<T>(T * data, int size);
	BinaryTree<T>(const BinaryTree& other);
	BinaryTree<T>& operator=(const BinaryTree& other);
	
	bool isLeaf(const BTNode<T> * n) const;
	bool isNull() const;
	bool remove(T data);
	void insert(T data);
	bool find(T data) const;
	void print() const;
};


template <typename T>
BTNode<T> * BinaryTree<T>::copy_helper(const BTNode<T>* other) {
	
	BTNode<T>* retval = nullptr;

	if (other != nullptr) {
		retval = new BTNode<T>(other->data);
	}
	if (other->left != nullptr) {
		retval->left = copy_helper(other->left);
	}
	if (other->right != nullptr) {
		retval->right = copy_helper(other->right);
	}
	return retval;
}

template <typename T>
void BinaryTree<T>::copy(const BinaryTree<T>& other) {
	root = copy_helper(other.root);
}

template <typename T>
void BinaryTree<T>::deleteNode(BTNode<T>*& n) {
	if (n->left != nullptr) {
		deleteNode(n->left);
		n->left = nullptr;
	}
	if (right != nullptr) {
		deleteNode(n->right);
		n->right = nullptr;
	}
	delete n;
	n = nullptr;
}

template <typename T>
void BinaryTree<T>::cleanup() {
	deleteNode(root);
}

template <typename T>
BinaryTree<T>::BinaryTree() {
	root = nullptr;
}

template <typename T>
BinaryTree<T>& BinaryTree<T>::operator=(const BinaryTree<T>& other) {
	if (&other != this) {
		cleanup();
		copy(other);
	}
	return* this;
}

template <typename T>
BinaryTree<T>::BinaryTree(const BinaryTree<T>& other) {
	copy(other);
}

template <typename T>
BinaryTree<T>::BinaryTree(T* vals, int size) {
	for (int i = 0; i < size; i++) {
		insert(vals[i]);
	}
}

template <typename T>
T BinaryTree<T>::find_leaf_remove(BTNode<T>*& n) {
	if (isLeaf(n)) {
		throw std::invalid_argument("Node is already a leaf");
	}
	if (n->left != nullptr) {
		if (isLeaf(n->left)) {
			T retval = T(n->left->data);
			delete n->left;
			n->left = nullptr;
			return retval;
		}
	}
	if (n->right != nullptr) {
		if (isLeaf(n->right)) {
			T retval = T(n->right->data);
			delete n->right;
			n->right = nullptr;
			return retval;
		}
	}
	int randint = rand();
	if (randint % 2) {
		if (n->left != nullptr) {
			return find_leaf_remove(n->left);
		}
		else {
			return find_leaf_remove(n->right);
		}
	}
	else {
		if (n->right != nullptr) {
			return find_leaf_remove(n->right);
		}
		else {
			return find_leaf_remove(n->left);
		}
	}
}

template <typename T>
bool BinaryTree<T>::remove_helper(T data, BTNode<T> * & n) {
	bool retval = false;
	if (n->data == data) {
		if (isLeaf(n)) {
			delete n;
			n = nullptr;
			//deleteNode(n);
		}
		else {
			n->data = find_leaf_remove(n);
		}
		retval = true;
	}
	if (n != nullptr && n->left != nullptr){// && (data < n->data)) {
		retval |= remove_helper(data, n->left);
	}
	if (n != nullptr && n->right != nullptr){// && (data > n->data)) {
		retval |= remove_helper(data, n->right);
	}
	return retval;
}

template <typename T>
bool BinaryTree<T>::remove(T data) {
	if (root == nullptr) {
		return false;
	}
	return remove_helper(data, root);
}

template <typename T>
bool BinaryTree<T>::isLeaf(const BTNode<T> * n) const {
	return (n->right == nullptr) && (n->left == nullptr);
}

template <typename T>
bool BinaryTree<T>::isNull() const {
	return (root == nullptr);
}

template <typename T>
void BinaryTree<T>::insert_helper(T data, BTNode<T> * n) {
	int randint = rand();
	if (randint % 2) {
		if (n->left == nullptr) {
			n->left = new BTNode<T>(data);
		}
		else if (n->right == nullptr) {
			n->right = new BTNode<T>(data);
		}
		else {
			insert_helper(data, n->left);
		}
	}
	else {
		if (n->right == nullptr) {
			n->right = new BTNode<T>(data);
		}
		else if (n->left == nullptr) {
			n->left = new BTNode<T>(data);
		}
		else {
			insert_helper(data, n->right);
		}
	}
}

template <typename T>
void BinaryTree<T>::insert(T data) {
	if (root == nullptr) {
		root = new BTNode<T>(data);
	}
	else {
		insert_helper(data, root);
	}
}

template <typename T>
bool BinaryTree<T>::find_helper(T data, const BTNode<T>* n) const {
	bool retval = false;
	if (n->data == data) {
		return true;
	}
	else {
		if (n->left != nullptr) {
			retval = find_helper(data, n->left);
		}
		if (!retval && (n->right != nullptr)) {
			retval = find_helper(data, n->right);
		}
		return retval;
	}
}

template <typename T>
bool BinaryTree<T>::find(T data) const {
	if (root == nullptr) {
		return false;
	}
	return find_helper(data, root);
}

template <typename T>
void BinaryTree<T>::print_helper(int space, const BTNode<T> * n) const {
	space += COUNT;

	// Process right child first  
	if (n->right != nullptr)
		print_helper(space, n->right);

	// Print current node after space count  
	cout << endl << setw(space - COUNT) << n->data << endl;

	// Process left child  
	if (n->left != nullptr)
		print_helper(space, n->left);
}

template <typename T>
void BinaryTree<T>::print() const {
	print_helper(0, root);
}


#endif
