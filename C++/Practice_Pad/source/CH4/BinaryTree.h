#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream>
#include <iomanip>
#include <random>
#include <stack>
#include <unordered_map>

using namespace std;

template <typename T>
struct BTNode {
	BTNode* left = nullptr;
	BTNode* right = nullptr;
	T data;
	int size;
	bool visited = false;
	BTNode(T data) {
		this->data = data;
		this->size = 1;
	}
};

template <typename T>
class BinaryTree {
protected:
	void cleanup();
	BTNode<T>* copy_helper(const BTNode<T>* other);
	virtual bool find_helper(T data, const BTNode<T>* n) const;
	virtual bool find_node_helper(T data, BTNode<T>* n, BTNode<T>*& ret);
	bool remove_helper(T data, BTNode<T>*& n);
	virtual void insert_helper(T data, BTNode<T>* n);
	T find_leaf_remove(BTNode<T>*& n);
	int getHeight_helper(BTNode<T>* n) const;
	void copy(const BinaryTree& other);
	void deleteNode(BTNode<T>*& n);
	void print_helper(int space, const BTNode<T>* n) const;
	void inorder_helper(const BTNode<T>* n) const;
	void inorder_helper(const BTNode<T>* n, T* output, int& index) const; //for testing purposes only
	void preorder_helper(const BTNode<T>* n) const;
	void postorder_helper(const BTNode<T>* n) const;
	bool isBalanced_helper(const BTNode<T>* n) const;
	bool isBST_helper(const BTNode<T>* n) const;
	BTNode<T>* first_common_ancestor_helper(T data1, T data2, BTNode<T>* n) const;
	BTNode<T>* first_common_ancestor_helper_v2(BTNode<T>* cur, BTNode<T>* n1, BTNode<T>* n2) const;
	bool compare_subtree_helper(BTNode<T>* equal_val, BTNode<T>* compare_root) const;
	BTNode<T>* getRandomNode_helper(BTNode<T>* n, int randInt);
	void num_paths_with_sum_helper(int sum, int & current_sum, int & current_path_len, int & num_paths, vector<BTNode<T>*> & v) ;
	void num_paths_with_sum_helper2(int sum, int current_sum, int& num_paths, BTNode<T>* n, unordered_map<int, int>& m) const;
	void decrease_count(unordered_map<int, int>& m, int item) const;
	void increase_count(unordered_map<int, int>& m, int item) const;
	void clearVisitedFlagsHelper(BTNode<T>* n);

	const int COUNT = 10;
	BTNode<T>* root;

public:

	BinaryTree<T>();
	BinaryTree<T>(T* data, int size);
	BinaryTree<T>(const BinaryTree& other);
	BinaryTree<T>& operator=(const BinaryTree& other);

	bool isLeaf(const BTNode<T>* n) const;
	bool isNull() const;
	bool remove(T data);
	void insert(T data);
	bool find(T data) const;
	bool find_node(T data, BTNode<T>*& ret);
	int getHeight() const;
	void print() const;
	void inorder() const;
	void preorder() const;
	void postorder() const;
	void inorder(T* output) const;
	bool isBalanced() const;
	bool isBST() const;
	BTNode<T>* first_common_ancestor(T data1, T data2) const;
	BTNode<T>* first_common_ancestor_v2(T data1, T data2);
	bool compare_subtree(BTNode<T>* subtree_root);
	bool compare_subtree(const BinaryTree<T>& other);
	BTNode<T>* getRandomNode();
	int size() const;
	int num_paths_with_sum(int sum);
	int num_paths_with_sum2(int sum) const;
	void clearVisitedFlags();
};


template <typename T>
BTNode<T>* BinaryTree<T>::copy_helper(const BTNode<T>* other) {

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
	return*this;
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
			n->size--;
			return retval;
		}
	}
	if (n->right != nullptr) {
		if (isLeaf(n->right)) {
			T retval = T(n->right->data);
			delete n->right;
			n->right = nullptr;
			n->size--;
			return retval;
		}
	}
	int randint = rand();
	if (randint % 2) {
		if (n->left != nullptr) {
			n->size--;
			return find_leaf_remove(n->left);
		}
		else {
			n->size--;
			return find_leaf_remove(n->right);
		}
	}
	else {
		if (n->right != nullptr) {
			n->size--;
			return find_leaf_remove(n->right);
		}
		else {
			n->size--;
			return find_leaf_remove(n->left);
		}
	}
}

template <typename T>
bool BinaryTree<T>::remove_helper(T data, BTNode<T>*& n) {
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
	if (retval) {
		return retval;
	}
	if (n != nullptr && n->left != nullptr) {
		retval |= remove_helper(data, n->left);
		if (retval) {
			n->size--;
		}
	}
	if (retval) {
		return retval;
	}
	if (n != nullptr && n->right != nullptr) {
		retval |= remove_helper(data, n->right);
		if (retval) {
			n->size--;
		}
	}
	return retval;
}

template <typename T>
bool BinaryTree<T>::remove(T data) {
	if (root == nullptr) {
		return false;
	}
	bool retval = remove_helper(data, root);

	return retval;
}

template <typename T>
bool BinaryTree<T>::isLeaf(const BTNode<T>* n) const {
	return (n->right == nullptr) && (n->left == nullptr);
}

template <typename T>
bool BinaryTree<T>::isNull() const {
	return (root == nullptr);
}

template <typename T>
void BinaryTree<T>::insert_helper(T data, BTNode<T>* n) {
	int randint = rand();
	if (randint % 2) {
		if (n->left == nullptr) {
			n->left = new BTNode<T>(data);
			n->size++;
		}
		else if (n->right == nullptr) {
			n->right = new BTNode<T>(data);
			n->size++;
		}
		else {
			insert_helper(data, n->left);
			n->size++;
		}
	}
	else {
		if (n->right == nullptr) {
			n->right = new BTNode<T>(data);
			n->size++;
		}
		else if (n->left == nullptr) {
			n->left = new BTNode<T>(data);
			n->size++;
		}
		else {
			insert_helper(data, n->right);
			n->size++;
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
bool BinaryTree<T>::find_node_helper(T data, BTNode<T>* n, BTNode<T>*& ret) {
	bool retval = false;
	if (n->data == data) {
		ret = n;
		return true;
	}
	else {
		if (n->left != nullptr) {
			retval = find_node_helper(data, n->left, ret);
		}
		if (!retval && (n->right != nullptr)) {
			retval = find_node_helper(data, n->right, ret);
		}
		return retval;
	}
}

template <typename T>
bool BinaryTree<T>::find_node(T data, BTNode<T>*& ret) {
	if (root == nullptr) {
		return false;
	}
	return find_node_helper(data, root, ret);
}

template <typename T>
void BinaryTree<T>::print_helper(int space, const BTNode<T>* n) const {
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
bool BinaryTree<T>::isBST_helper(const BTNode<T>* n) const {


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

template <typename T>
BTNode<T>* BinaryTree<T>::first_common_ancestor_helper(T data1, T data2, BTNode<T>* n) const {

	if (isLeaf(n)) { // should throw exception but in general if we reach here something is wrong
		throw invalid_argument("Node is leaf, something is wrong");
	}

	if (n->data == data1 || n->data == data2) {
		return n;
	}

	// has both left and right
	bool data1_in_left = false;
	bool data1_in_right = false;
	bool data2_in_left = false;
	bool data2_in_right = false;

	if (n->right != nullptr && n->left != nullptr) {

		data1_in_left = find_helper(data1, n->left);
		data1_in_right = find_helper(data1, n->right);
		data2_in_left = find_helper(data2, n->left);
		data2_in_right = find_helper(data2, n->right);

		// two pieces of data in different left and right subtrees, return current node.
		if ((data1_in_left && data2_in_right) || (data2_in_left && data1_in_right)) {
			return n;
		}
		if (data1_in_left && data2_in_left) {
			return first_common_ancestor_helper(data1, data2, n->left);
		}
		if (data1_in_right && data2_in_right) {
			return first_common_ancestor_helper(data1, data2, n->right);
		}
	}
	else if (n->left != nullptr) {
		return first_common_ancestor_helper(data1, data2, n->left);
	}
	else if (n->right != nullptr) {
		return first_common_ancestor_helper(data1, data2, n->right);
	}
	return nullptr;
}

template <typename T>
BTNode<T>* BinaryTree<T>::first_common_ancestor(T data1, T data2) const {
	if (data1 == data2) {
		throw invalid_argument("tree doesn't contain duplicates");
	}

	if (root == nullptr) {
		return nullptr;
	}

	if (!find(data1) || !find(data2)) {
		return nullptr;
	}

	return first_common_ancestor_helper(data1, data2, root);
}

// we already know the data required is in the tree and n1 and n2 are valid nodes that exist in the tree.
template <typename T>
BTNode<T>* BinaryTree<T>::first_common_ancestor_helper_v2(BTNode<T>* cur, BTNode<T>* n1, BTNode<T>* n2) const {
	if (cur == nullptr) { // not found
		return nullptr;
	}
	if (cur == n1 || cur == n2) { // one of the nodes is the current node, the current node is the ancestor
		return cur;
	}

	BTNode<T>* found_in_left = first_common_ancestor_helper_v2(cur->left, n1, n2); // try finding the ancestor in left tree. 
	if (found_in_left != nullptr && found_in_left != n1 && found_in_left != n2) {
		return found_in_left;
	}
	BTNode<T>* found_in_right = first_common_ancestor_helper_v2(cur->right, n1, n2); // try finding the ancestor in right tree.

	if (found_in_right != nullptr && found_in_left == nullptr) {//both elements are in one subtree, return the left or right subtree
		return found_in_right;
	}
	if (found_in_left != nullptr && found_in_right == nullptr) { //both elements are in one subtree, return the left or right subtree
		return found_in_left;
	}
	if (found_in_left != nullptr && found_in_right != nullptr) { // elements are in different subtrees, return root (or A.K.A cur)
		return cur;
	}
	// elements not found in this subtree, return nullptr
	return nullptr;
}

template <typename T>
BTNode<T>* BinaryTree<T>::first_common_ancestor_v2(T data1, T data2) {

	if (data1 == data2) {
		throw invalid_argument("tree doesn't contain duplicates");
	}
	BTNode<T>* n1 = nullptr;
	BTNode<T>* n2 = nullptr;
	if (find_node(data1, n1) && find_node(data2, n2)) {
		return first_common_ancestor_helper_v2(root, n1, n2);
	}
	return nullptr;
}

// CTCI 4.10
template <typename T>
bool BinaryTree<T>::compare_subtree(const BinaryTree<T>& other) {
	return compare_subtree(other.root);
}

template <typename T>
bool BinaryTree<T>::compare_subtree_helper(BTNode<T>* equal_val, BTNode<T>* subtree_root) const {
	if ((equal_val == nullptr && subtree_root != nullptr) || (subtree_root == nullptr && equal_val != nullptr)) {
		return false;
	}

	if (subtree_root == nullptr && equal_val == nullptr) {
		return true;
	}

	if (equal_val->data != subtree_root->data) {
		return false;
	}
	return compare_subtree_helper(equal_val->left, subtree_root->left) && compare_subtree_helper(equal_val->right, subtree_root->right);
}

template <typename T>
bool BinaryTree<T>::compare_subtree(BTNode<T>* subtree_root) {
	if (subtree_root == nullptr) {
		return true;// empty tree always a subtree.
	}
	BTNode<T>* root_equal = nullptr;
	if (find_node(subtree_root->data, root_equal)) {
		return compare_subtree_helper(subtree_root, root_equal);
	}
	return false;
}

// CTCI 4.11
template <typename T>
int BinaryTree<T>::size() const {
	if (root == nullptr) {
		return 0;
	}
	return root->size;
}

template <typename T>
BTNode<T>* BinaryTree<T>::getRandomNode_helper(BTNode<T>* n, int randInt) {
	int leftSize = 0;
	if (n->left != nullptr) {
		leftSize = n->left->size;
	}
	if (leftSize == randInt) {
		return n;
	}
	else if (randInt > leftSize) {
		return getRandomNode_helper(n->right, randInt-leftSize-1);
	}
	else {
		return getRandomNode_helper(n->left, randInt);
	}
	return nullptr;
}

template <typename T>
BTNode<T>* BinaryTree<T>::getRandomNode() {
	if (root == nullptr) {
		return nullptr;
	}
	int randI = rand() % root->size;
	return getRandomNode_helper(root, randI);
}

template <typename T>
void BinaryTree<T>::num_paths_with_sum_helper(const int sum, int & current_sum, int& current_path_len, int & num_paths, vector<BTNode<T>*> & v)  {
	if (v.empty()) {
		return;
	}
	BTNode<T>* n = v.back();
	
	if (n->left != nullptr) {
		int current_sum_copy = current_sum + n->left->data;
		int current_path_len_copy = current_path_len + 1;
		vector<BTNode<T>*> v_copy = v;
		v_copy.push_back(n->left);
		n->visited = true;
		
		if (current_sum_copy > sum) {
			
			while (!v.empty() && (current_sum_copy > sum)) {
				BTNode<T>* begin = v_copy.front();
				current_sum_copy -= begin->data;
				current_path_len_copy--;
				v_copy.erase(v_copy.begin());
			}
		}
		if ((current_sum_copy == sum) && (current_path_len_copy >= 1)) {
			num_paths++;
		}
		
		num_paths_with_sum_helper(sum, current_sum_copy, current_path_len_copy, num_paths, v_copy);
	}

	if (n->right != nullptr) {
		vector<BTNode<T>*> v_copy = v;
		v_copy.push_back(n->right);
		int current_sum_copy = current_sum + n->right->data;
		int current_path_len_copy = current_path_len + 1;
		
		if (current_sum_copy > sum) {

			while (!v_copy.empty() && (current_sum_copy > sum)) {
				BTNode<T>* begin = v_copy.front();
				current_sum_copy -= begin->data;
				current_path_len_copy--;
				v_copy.erase(v_copy.begin());
			}
		}
		if ((current_sum_copy == sum) && (current_path_len_copy >= 1)) {
			num_paths++;
		}
		
		num_paths_with_sum_helper(sum, current_sum_copy, current_path_len_copy, num_paths, v_copy);
	}
	n->visited = true;
	if (isLeaf(n)) {
		v.pop_back();
	}
	else if (n->visited) {
		v.pop_back();
	}
}

template <typename T>
int BinaryTree<T>::num_paths_with_sum(int sum) {
	if (root == nullptr) {
		return 0;
	}
	vector<BTNode<T>* > v;
	v.push_back(root);
	int num_paths = 0;
	int current_sum = root->data;
	int current_path_len = 0;
	num_paths_with_sum_helper(sum, current_sum, current_path_len,  num_paths, v);
	clearVisitedFlags();
	return num_paths;
}

template <typename T>
void BinaryTree<T>::decrease_count(unordered_map<int, int>& m, int item) const {
	unordered_map<int, int>::const_iterator found = m.find(item);
	if (found != m.end()) {
		m.at(item)--;
		if (m.at(item) == 0) {
			m.erase(item);
		}
	}
}

template <typename T>
void BinaryTree<T>::increase_count(unordered_map<int, int>& m, int item) const {
	unordered_map<int, int>::const_iterator found = m.find(item);
	if (found != m.end()) {
		m.at(item)++;
	}
	else {
		m.insert(pair<int, int>(item, 1));
	}
}

template <typename T>
void BinaryTree<T>::num_paths_with_sum_helper2(const int sum, int current_sum, int& num_paths, BTNode<T> * n, unordered_map<int, int> & m) const {
	current_sum += n->data;
	if (current_sum == sum) {
		num_paths++;
	}
	increase_count(m, current_sum);
	int complement = sum - current_sum;
	
	unordered_map<int, int>::const_iterator found = m.find(complement);
	if (found != m.end()) {
		num_paths += found->second;
	}
	if (n->left != nullptr) {
		num_paths_with_sum_helper2(sum, current_sum, num_paths, n->left, m);
	}
	if (n->right != nullptr) {
		num_paths_with_sum_helper2(sum, current_sum, num_paths, n->right, m);
	}
	decrease_count(m, current_sum);
}

template <typename T>
int BinaryTree<T>::num_paths_with_sum2(int sum) const {
	if (root == nullptr) {
		return 0;
	}
	unordered_map<int, int> m;
	int current_sum = 0;
	int num_paths = 0;
	num_paths_with_sum_helper2(sum, current_sum, num_paths, root, m);

	return num_paths;
}

template <typename T>
void BinaryTree<T>::clearVisitedFlagsHelper(BTNode<T> * n) {
	if (n != nullptr) {
		n->visited = false;
		clearVisitedFlagsHelper(n->left);
		clearVisitedFlagsHelper(n->right);
	}
}

template <typename T>
void BinaryTree<T>::clearVisitedFlags() {
	clearVisitedFlagsHelper(root);
}

#endif
