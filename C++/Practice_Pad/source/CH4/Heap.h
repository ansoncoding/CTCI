#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <iomanip>
#include <random>
#include "practice_exceptions.h"
#include "LinkedListQueue.h"

using namespace std;

template <typename T>
struct HNode {
	HNode<T>* left = nullptr;
	HNode<T>* right = nullptr;
	HNode<T>* parent = nullptr;
	T data = 0;
	HNode(T data) {
		this->data = data;
	}
};

template <typename T>
class MinHeap {
protected:
	void cleanup();
	HNode<T>* copy_helper(const HNode<T>* other);
	bool remove_helper(LinkedListQ<HNode<T>*> &q);
	void insert_helper(T data, LinkedListQ<HNode<T>*> &q);

	void copy(const MinHeap& other);
	void deleteNode(HNode<T>*& n);
	void print_helper(int space, const HNode<T>* n) const;

	const int COUNT = 10;
	HNode<T>* root;
	HNode<T>* parent_of_next_insert = nullptr;
	HNode<T>* parent_of_last = nullptr;

public:

	MinHeap<T>();
	MinHeap<T>(T* data, int size);
	MinHeap<T>(const MinHeap& other);
	MinHeap<T>& operator=(const MinHeap& other);

	bool isLeaf(const HNode<T>* n) const;
	bool isNull() const;
	bool removeMin();
	void insert(T data);
	T getMin() const;
	void print() const;
};


template <typename T>
HNode<T>* MinHeap<T>::copy_helper(const HNode<T>* other) {

	HNode<T>* retval = nullptr;

	if (other != nullptr) {
		retval = new HNode<T>(other->data);
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
void MinHeap<T>::copy(const MinHeap<T>& other) {
	root = copy_helper(other.root);
}

template <typename T>
void MinHeap<T>::deleteNode(HNode<T>*& n) {
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
void MinHeap<T>::cleanup() {
	deleteNode(root);
}

template <typename T>
MinHeap<T>::MinHeap() {
	root = nullptr;
}

template <typename T>
MinHeap<T>& MinHeap<T>::operator=(const MinHeap<T>& other) {
	if (&other != this) {
		cleanup();
		copy(other);
	}
	return*this;
}

template <typename T>
MinHeap<T>::MinHeap(const MinHeap<T>& other) {
	copy(other);
}

template <typename T>
MinHeap<T>::MinHeap(T* vals, int size) {
	for (int i = 0; i < size; i++) {
		insert(vals[i]);
	}
}

template <typename T>
bool MinHeap<T>::remove_helper(LinkedListQ<HNode<T>*> &q) {
	if (q.isEmpty())
		throw new std::invalid_argument("queue is empty");

	HNode<T>* temp;
	bool removed = false;
	while (!q.isEmpty() && !removed) {
		temp = q.peek();
		if (isLeaf(temp))
			throw new std::invalid_argument("nodes in queue cannot be leaves");

		
		if (temp->right == nullptr && temp->left != nullptr) {
			n->data = temp->left->data;
			delete temp->left;
			temp->left = nullptr
		} else 
		if (temp->left == nullptr) {
			temp->left = new HNode<T>(data);
			temp->left->parent = temp;
			inserted = true;
			if (data < temp->data) {
				swap_parent(temp->left);
			}
		}
		if (temp->right != nullptr) {
			q.append(temp->right);
		}
		if (temp->left != nullptr) {
			q.append(temp->left);
		}
		
		q.remove();
	}
}

template <typename T>
bool MinHeap<T>::removeMin() {
	if (root == nullptr) {
		return false;
	}
	
	if (isLeaf(root)) {
		delete root;
		root = nullptr;
		return true;
	}
	else {
		LinkedListQ<HNode<T>*> q = LinkedListQ<HNode<T>*>();
		q.append(root);
		remove_helper(q);
		return true;
	}
}

template <typename T>
bool MinHeap<T>::isLeaf(const HNode<T>* n) const {
	return (n->right == nullptr) && (n->left == nullptr);
}

template <typename T>
bool MinHeap<T>::isNull() const {
	return (root == nullptr);
}

template <typename T>
T MinHeap<T>::getMin() const {
	if (root != nullptr)
		return root->data;
	throw new OutofBoundsException();
}
template <typename T>

void swap_parent(HNode<T> * n) {
	HNode<T>* current = n;
	while (current->parent != nullptr) {
		if (current->data < current->parent->data) {
			T temp = current->parent->data;
			current->parent->data = current->data;
			current->data = temp;
		}
		current = current->parent;
	}
}
template <typename T>
void MinHeap<T>::insert_helper(T data, LinkedListQ<HNode<T>*>& q) {
	if (q.isEmpty())
		throw new std::invalid_argument("queue is empty");

	HNode<T>* temp;
	bool inserted = false;
	while (!q.isEmpty() && !inserted) {
		temp = q.peek();
		if (temp->left != nullptr) {
			q.append(temp->left);
		}
		if (temp->right != nullptr) {
			q.append(temp->right);
		}

		if (temp->left == nullptr) {
			temp->left = new HNode<T>(data);
			temp->left->parent = temp;
			inserted = true;
			if (data < temp->data) {
				swap_parent(temp->left);
			}
		}
		else if (temp->right == nullptr) {
			temp->right = new HNode<T>(data);
			temp->right->parent = temp;
			inserted = true;
			if (data < temp->data) {
				swap_parent(temp->right);
			}
		}
		q.remove();
	}
}

template <typename T>
void MinHeap<T>::insert(T data) {
	if (root == nullptr) {
		root = new HNode<T>(data);
		root->parent = nullptr;
	}
	else {
		LinkedListQ<HNode<T>*> q = LinkedListQ<HNode<T>*>();
		q.append(root);
		insert_helper(data, q);
	}
}

template <typename T>
void MinHeap<T>::print_helper(int space, const HNode<T>* n) const {
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
void MinHeap<T>::print() const {
	if (root == nullptr) {
		cout << "Heap is empty" << endl;
		return;
	}
	print_helper(0, root);
}


#endif
