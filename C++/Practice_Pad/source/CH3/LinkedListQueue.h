#ifndef LINKED_LIST_GENERIC_H
#define LINKED_LIST_GENERIC_H

#include "practice_exceptions.h"

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
	bool contains(T data) const;
	T peek() const;
	void print(bool endline=true) const;


	// Forward declaration must be done in the same access scope 
	class Iterator;

	// Root of LinkedList wrapped in Iterator type 
	Iterator begin() {
		return Iterator(head);
	}

	// End of LinkedList wrapped in Iterator type 
	Iterator end() {
		return Iterator(nullptr);
	}

	class Iterator {
	public:
		Iterator() noexcept :
			current(head) { }

		Iterator(const NodeG<T>* pNode) noexcept :
			current(pNode) { }

		Iterator& operator=(NodeG<T>* pNode) {
			this->current = pNode;
			return *this;
		}

		// Prefix ++ overload 
		Iterator& operator++() {
			if (current)
				current = current->next;
			return *this;
		}

		// Postfix ++ overload 
		Iterator operator++(int) {
			Iterator iterator = *this;
			++* this;
			return iterator;
		}

		bool operator!=(const Iterator& iterator) {
			return current != iterator.current;
		}

		T operator*() {
			return current->data;
		}

	private:
		const NodeG<T>* current;
	};
};

template<typename T>
bool LinkedListQ<T>::contains(T data) const {
	NodeG<T>* temp = head;
	while (temp != nullptr) {
		if (temp->data == data) {
			return true;
		}
		temp = temp->next;
	}
	return false;
}

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

template<typename T>
void LinkedListQ<T>::print(bool endline) const {
	if (head == nullptr) {
		cout << "List is empty" << endl;
	}
	else {
		NodeG<T>* temp = head;
		while (temp != nullptr) {
			
			cout << temp->data << " ";
			temp = temp->next;
		}
		if (endline) {
			cout << endl;
		}
	}
}
#endif
