#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "BinaryTree.h"
#include "LinkedListQueue.h"
#include "ArrayList.h" 

template <typename T>
class BinarySearchTree : public BinaryTree<T> {
private:
	bool find_helper(T data, const BTNode<T>* n) const;
	BTNode<T>* remove_helper(T data, BTNode<T>*& n);
	void insert_helper(T data, BTNode<T>* n);
	BTNode<T>* find_leaf_remove(BTNode<T>* &n);
	T right_min_remove(BTNode<T>*& n);
	BTNode<T>* FindMin(BTNode<T>* n);
	vector<vector<T>> print_possible_init_arrays_helper(BTNode<T>* n) const;
public:
	void remove(T data);
	void print_possible_init_arrays() const;
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

//CTCI 4.2
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

template <typename T>
vector<vector<T>> generate_possibles(vector<T> & left, vector<T> & right, vector<T> & prefix) {
	vector<vector<T>> retval = vector<vector<T>>();
	//left = 1, 2
	//right = 5, 6
	// return 1, 2, 5, 6
	//        1, 5, 6, 2
	//        5, 6, 1, 2
	//        5, 1, 2, 6
	//        1, 5, 2, 6
	//        5, 1, 6, 2
	if (left.size() == 0 || right.size() == 0) {
		vector<T> temp = prefix;
		temp.insert(temp.end(), left.begin(), left.end());
		temp.insert(temp.end(), right.begin(), right.end());
		retval.push_back(temp);
		return retval;
	}

	T headLeft = left.at(0);
	prefix.push_back(headLeft);
	left.erase(left.begin());
	vector<vector<T>> resultl = generate_possibles(left, right, prefix);
	retval.insert(retval.end(), resultl.begin(), resultl.end());
	prefix.pop_back();
	left.insert(left.begin(), headLeft);

	T headRight = right.at(0);
	prefix.push_back(headRight);
	right.erase(right.begin());
	vector<vector<T>> resultr = generate_possibles(left, right, prefix);
	retval.insert(retval.end(), resultr.begin(), resultr.end());
	prefix.pop_back();
	right.insert(right.begin(), headRight);

	return retval;
}

template <typename T>
vector<vector<T>> BinarySearchTree<T>::print_possible_init_arrays_helper(BTNode<T>* n) const {
	
	vector<vector<T>> retval;
	if (n == nullptr) {
		retval.push_back(vector<T>());
		return retval;
	}

	vector<T> prefix;
	prefix.push_back(n->data);
	
	vector<vector<T>> left_all = print_possible_init_arrays_helper(n->left);
	vector<vector<T>> right_all = print_possible_init_arrays_helper(n->right);
	
	for (int i = 0; i < left_all.size(); i++) {
		for (int j = 0; j < right_all.size(); j++) {
			vector<vector<T>> temp;
			temp = generate_possibles(left_all.at(i), right_all.at(j), prefix);
			retval.insert(retval.end(), temp.begin(), temp.end());
		}
	}
	
	return retval;
}

//CTCI 4.9
template <typename T>
void BinarySearchTree<T>::print_possible_init_arrays() const {
	if (root == nullptr) {
		cout << "Binary Search Tree is empty" << endl;
		return;
	}
	
	vector<vector<T>> ret = print_possible_init_arrays_helper(root);
	// print them here
	for (int i = 0; i < ret.size(); i++) {
		vector<T> temp = ret.at(i);
		for (int j = 0; j < temp.size(); j++) {
			cout << temp.at(j) << " " ;
		}
		cout << endl;
	}
}

#endif