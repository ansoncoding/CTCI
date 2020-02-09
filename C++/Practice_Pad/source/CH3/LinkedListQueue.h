#ifndef LINKED_LIST_GENERIC_H
#define LINKED_LIST_GENERIC_H

template <typename T>

class NodeG {
public:
	T data;
	NodeG<T>* next = nullptr;
	NodeG<T>* tail = nullptr;

	NodeG<T>(T data) {
		this->data = data;
		next = nullptr;
	}
};

template <typename T>
class LinkedListQ {
private:
	NodeG<T>* head = nullptr;
	NodeG<T>* tail = nullptr;
	unsigned int size = 0;
	void copy(const LinkedListQ& other);
	void cleanup();
public:
	LinkedListQ();
	~LinkedListQ();
	LinkedListQ<T> & operator=(const LinkedListQ& other);
	LinkedListQ(const LinkedListQ & other);
	void append(T data);
	unsigned int getSize() const;
	void remove();
	bool isEmpty() const;
	T peek() const;
};

//#include "pch.h"
//#include "practice_exceptions.h"
//#include "LinkedListQueue.h"
//Node<T>* temp = new Node<T>;

template<typename T>
LinkedListQ<T>::LinkedListQ() {

}

template<typename T>
LinkedListQ<T>::~LinkedListQ() {
	cleanup();
}

template<typename T>
void LinkedListQ<T>::copy(const LinkedListQ& other) {
	if (other.head == nullptr) {
		return;
	}
	head = new NodeG<T>(other.head->data);
	tail = head;
	NodeG<T>* iter = other.head->next;
	while (iter != nullptr) {
		tail->next = new NodeG<T>(iter->data);
		tail = tail->next;
		iter = iter->next;
	}
	size = other.size;
}

template<typename T>
void LinkedListQ<T>::cleanup() {
	if (head == nullptr) {
		return;
	}
	NodeG<T>* temp;
	while (head != nullptr) {
		temp = head->next;
		delete head;
		head = temp;
		size--;
	}
}

template<typename T>
LinkedListQ<T>::LinkedListQ(const LinkedListQ& other) {
	copy(other);
}

template<typename T>
LinkedListQ<T>& LinkedListQ<T>::operator=(const LinkedListQ& other) {
	if (&other != this) {
		cleanup();
		copy(other);
	}
	return *this;
}

template<typename T>
void LinkedListQ<T>::append(T data) {
	if (head == nullptr) {
		head = new NodeG<T>(data);
		tail = head;
	}
	else {
		tail->next = new NodeG<T>(data);
		tail = tail->next;
	}
	size++;
}

template<typename T>
unsigned int LinkedListQ<T>::getSize() const {
	return size;
}

template<typename T>
T LinkedListQ<T>::peek() const {
	if (head == nullptr) {
		throw OutofBoundsException();
	}
	return head->data;
}

template<typename T>
void LinkedListQ<T>::remove() {
	if (head == nullptr)
		throw OutofBoundsException();
	else {
		NodeG<T>* temp = head->next;
		delete head;
		head = temp;
		size--;
	}
}

template<typename T>
bool LinkedListQ<T>::isEmpty() const {
	return size == 0;
}

#endif
