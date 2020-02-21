#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "BinaryTree.h"

template <typename T>
class BinarySearchTree : public BinaryTree<T> {
private:
	bool find_helper(T data, const BTNode<T>* n) const;
	BTNode<T>* remove_helper(T data, BTNode<T>*& n);
	void insert_helper(T data, BTNode<T>* n);
	BTNode<T>* find_leaf_remove(BTNode<T>* &n);
	T right_min_remove(BTNode<T>*& n);
	BTNode<T>* FindMin(BTNode<T>* n);
public:
	void remove(T data);
};


template <typename T>
void BinarySearchTree<T>::insert_helper(T data, BTNode<T>* n) {
	
	if (data < n->data) {
		if (n->left == nullptr) {
			n->left = new BTNode<T>(data);
		}
		else {
			insert_helper(data, n->left);
		}
	}
	else if (data > n->data) {
		if (n->right == nullptr) {
			n->right = new BTNode<T>(data);
		}
		else {
			insert_helper(data, n->right);
		}
	}
}


template <typename T>
bool BinarySearchTree<T>::find_helper(T data, const BTNode<T>* n) const {

	bool retval = false;

	if (n->data == data) {
		return true;
	}
	else if ((n->left != nullptr) && (data < n->data)) {
		retval = find_helper(data, n->left);
	} else if ((n->right != nullptr) && (data > n->data)) {
		retval = find_helper(data, n->right);
	}
	return retval;
}

// node has right child 
// if the right child is a leaf, delete the right child and return the data
// if the right child has a left child, follow the left child to get min value, delete the min node and return the data
// if the right child has no left child, only a right child, directly assign the passed node to that right child of right childand 
// return the data of right child,
template <typename T>
T BinarySearchTree<T>::right_min_remove(BTNode<T>* &n) {
	if (isLeaf(n->right)) {
		T retval = n->right->data;
		delete n->right;
		n->right = nullptr;
		return retval;
	}
	else if (n->right->left != nullptr) {
		BTNode<T>* temp = n->right->left;
		BTNode<T>* prev = n->right;
		while (temp->left != nullptr) {
			prev = temp;
			temp = temp->left;
		}
		T retval = temp->data;
		if (temp->right != nullptr) {
			prev->left = temp->right;
		}
		delete temp;
		temp = nullptr;
		return retval;
	}
	else if (n->right->right != nullptr) {
		T retval = n->right->data;
		BTNode<T> * temp = n->right->right;
		delete n->right;
		n->right = temp;
		return retval;
	}
}
template <typename T>
BTNode<T>* BinarySearchTree<T>::FindMin(BTNode<T>* n) {
	BTNode<T>* temp = n;
	while (temp->left != nullptr) {
		temp = temp->left;
	}
	return temp;

}
// n has both children.
// find minimum value on right subtree
// return the new root node
template <typename T>
BTNode<T> * BinarySearchTree<T>::find_leaf_remove(BTNode<T>*& n) {
	// the right subtree is actually a leaf
	// copy over the data to n and delete right leaf
	if (isLeaf(n->right)) {
		n->data = n->right->data;
		delete n->right;
		n->right = nullptr;
		return n;
	}
	// the right subtree has no left node
	else if (n->right->right != nullptr && n->right->left == nullptr) {
		n->data = n->right->data;
		BTNode<T>* temp = n->right->right;
		delete n->right;
		n->right = temp;
		return n;
	} 
	// the right subtree has left child, we don't care if it has right child at this point
	// find the left most child and then copy the value to n, also if the left-most child has a right child
	// the previous left child should point to it.
	else {
		BTNode<T>* temp = FindMin(n->right);
		n->data = temp->data;
		remove_helper(temp->data, n->right);
		return n;
	}
	return nullptr;
}

// if the data is equivalent to the node, remove it
// recurse on left and right subtree
template <typename T>
BTNode<T>* BinarySearchTree<T>::remove_helper(T data, BTNode<T>*& n) {

	if (n->data == data) {
		if (isLeaf(n)) {
			delete n;
			return nullptr;
		}
		else if (n->left != nullptr && n->right == nullptr) {
			BTNode<T>* temp = n->left;
			delete n;
			n = temp;
			return n;
		}
		else if (n->left == nullptr && n->right != nullptr) {
			BTNode<T>* temp = n->right;
			delete n;
			n = temp;
			return n;
		}
		else {
			return find_leaf_remove(n);
		}
	}
	if ((n != nullptr) && (n->left != nullptr) && (data < n->data)) {
		n->left = remove_helper(data, n->left);
		return n;
	}
	if ((n != nullptr) && (n->right != nullptr) && (data > n->data)) {
		n->right = remove_helper(data, n->right);
		return n;
	}
	return n;
}

template <typename T>
void BinarySearchTree<T>::remove(T data) {
	if (root == nullptr) {
		return;
	}
	root = remove_helper(data, root);
}

template <typename T>
void insert_array_min_height_bst(T* data, int length, BinarySearchTree<T>& bst) {

	int mid = (length - 1) / 2; //index 2 is mid

	bst.insert(data[mid]); // insert index 2 into bst

	int size = length - 1;
	int size1 = size / 2; // size1 = 2
	int size2 = size - size1; // size2 = 3
	if (size1 > 0) {
		T* first_half = new T[size1];
		for (int i = 0; i < size1; i++) {
			first_half[i] = data[i];
		}
		insert_array_min_height_bst(first_half, size1, bst);
	}
	if (size2 > 0) {
		T* second_half = new T[size2];

		for (int i = mid + 1; i < size + 1; i++) {
			second_half[i - mid - 1] = data[i];
		}
		insert_array_min_height_bst(second_half, size2, bst);
	}
}


#endif