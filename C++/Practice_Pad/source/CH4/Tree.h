#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <iomanip>
#include <random>

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
	
	
	bool find(T data) {
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
	bool isLeaf() const {
		return (right == nullptr) && (left == nullptr);
	}
	void insert(T data) {
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
	// Function to print binary tree in 2D  
// It does reverse inorder traversal  
	void print2DUtil(int space)
	{
		// Base case  
		
		// Increase distance between levels  
		space += COUNT;

		// Process right child first  
		if (right != nullptr)
			right->print2DUtil(space);

		// Print current node after space  
		// count  
		cout << endl;
		for (int i = COUNT; i < space; i++)
			cout << " ";
		cout << data << "\n";

		// Process left child  
		if (left != nullptr)
			left->print2DUtil(space);
	}

};

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

}

template <typename T>
void BinaryTree<T>::sort() {

}

template <typename T>
void BinaryTree<T>::print()const
{
	// Pass initial space count as 0  
	if (root != nullptr)
		root->print2DUtil(0);
}


#endif