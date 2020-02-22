#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream>
#include <iomanip>
#include <random>

using namespace std;

template <typename T>
struct BTNode {
	BTNode* left = nullptr; 
	BTNode* right = nullptr;
	T data;
	BTNode(T data) {
		this->data = data;
	}
};

template <typename T>
class BinaryTree {
protected:
	void cleanup();
	BTNode<T> * copy_helper(const BTNode<T>*other);
	virtual bool find_helper(T data, const BTNode<T>* n) const;
	bool remove_helper(T data, BTNode<T>*& n);
	virtual void insert_helper(T data, BTNode<T>* n);
	T find_leaf_remove(BTNode<T> *& n);
	int getHeight_helper(BTNode<T>* n) const;
	void copy(const BinaryTree& other);
	void deleteNode(BTNode<T>*& n);
	void print_helper(int space, const BTNode<T>* n) const;
	void inorder_helper(const BTNode<T>* n) const;
	void inorder_helper(const BTNode<T>* n, T* output, int &index) const; //for testing purposes only
	void preorder_helper(const BTNode<T>* n) const;
	void postorder_helper(const BTNode<T>* n) const;
	bool isBalanced_helper(const BTNode<T>* n) const;
	bool isBST_helper(const BTNode<T>* n) const;

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
	int getHeight() const;
	void print() const;
	void inorder() const;
	void preorder() const;
	void postorder() const; 
	void inorder(T* output) const;
	bool isBalanced() const;
	bool isBST() const;
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
	if (root != nullptr)
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
	if (root == nullptr) {
		cout << "Tree is empty" << endl;
		return;
	}
	print_helper(0, root);
}

template <typename T>
void BinaryTree<T>::inorder_helper(const BTNode<T>* n) const {
	if (n->left != nullptr) {
		inorder_helper(n->left);
	}
	cout << n->data << " ";
	if (n->right != nullptr) {
		inorder_helper(n->right);
	}
}

template <typename T>
void BinaryTree<T>::inorder() const {
	if (root == nullptr) {
		cout << "Tree is empty" << endl;
		return;
	}
	inorder_helper(root);
	cout << endl;
}

template <typename T>
void BinaryTree<T>::preorder_helper(const BTNode<T>* n) const {
	
	cout << n->data << " ";

	if (n->left != nullptr) {
		preorder_helper(n->left);
	}

	if (n->right != nullptr) {
		preorder_helper(n->right);
	}
}

template <typename T>
void BinaryTree<T>::preorder() const {
	if (root == nullptr) {
		cout << "Tree is empty" << endl;
		return;
	}
	preorder_helper(root);
	cout << endl;
}

template <typename T>
void BinaryTree<T>::postorder_helper(const BTNode<T>* n) const {

	if (n->left != nullptr) {
		postorder_helper(n->left);
	}

	if (n->right != nullptr) {
		postorder_helper(n->right);
	}
	cout << n->data << " ";
}

template <typename T>
void BinaryTree<T>::postorder() const {
	if (root == nullptr) {
		cout << "Tree is empty" << endl;
		return;
	}
	postorder_helper(root);
	cout << endl;
}

//for testing purposes only
template <typename T>
void BinaryTree<T>::inorder_helper(const BTNode<T>* n, T* output, int& index) const {
	if (n->left != nullptr) {
		inorder_helper(n->left, output, index);
	}

	output[index] = n->data;
	index++;

	if (n->right != nullptr) {
		inorder_helper(n->right, output, index);
	}
}

//for testing purposes only
template <typename T>
void BinaryTree<T>::inorder(T* output) const {
	if (root == nullptr) {
		cout << "Tree is empty" << endl;
		return;
	}
	int index = 0;
	inorder_helper(root, output, index);
	cout << endl;
}

template <typename T>
int BinaryTree<T>::getHeight_helper(BTNode<T>* n) const {
	if (isLeaf(n)) {
		return 0;
	}
	else {
		int height_left = 0;
		int height_right = 0;
		if (n->left != nullptr) {
			height_left = getHeight_helper(n->left);
		}
		if (n->right != nullptr) {
			height_right = getHeight_helper(n->right);
		}
		int height_children = max(height_left, height_right);
		return height_children + 1;
	}
}

template <typename T>
int BinaryTree<T>::getHeight() const {
	if (root == nullptr) {
		return 0;
	}
	
	return getHeight_helper(root);
}

template <typename T>
bool BinaryTree<T>::isBalanced() const {
	if (root == nullptr) {
		return true;
	}
	return isBalanced_helper(root);
}

template <typename T>
bool BinaryTree<T>::isBalanced_helper(const BTNode<T>* n) const {
	if (isLeaf(n)) {
		return true;
	}
	
	int height_left = 0;
	int height_right = 0;
	if (n->left != nullptr && n->right != nullptr) {
		return isBalanced_helper(n->left) && isBalanced_helper(n->right);
	}
	if (n->right != nullptr) {
		height_right = getHeight_helper(n->right) + 1;
	} 
	else if (n->left != nullptr) {
		height_left = getHeight_helper(n->left) + 1;
	}
	unsigned int abs_diff = abs(height_left - height_right);
	return (abs_diff <= 1);
}

template <typename T>
bool BinaryTree<T>::isBST_helper(const BTNode<T> * n) const {
	
	
	if (isLeaf(n)) {
		return true;
	}

	bool retval = false;
	if (n->left != nullptr && n->right != nullptr) {
		retval = (n->data > n->left->data) && (n->data < n->right->data) && isBST_helper(n->left) && isBST_helper(n->right);
	}
	else if (n->left != nullptr) {
		retval = (n->data > n->left->data) && isBST_helper(n->left);
	}
	else if (n->right != nullptr) {
		retval = (n->data < n->right->data) && isBST_helper(n->right);
	}
	return retval;
}

template <typename T>
bool BinaryTree<T>::isBST() const {
	if (root == nullptr) {
		throw invalid_argument("Tree is empty, cannot determine if tree BST");
		// could also return true, depending on definition.
	}
	return isBST_helper(root);
}

#endif
