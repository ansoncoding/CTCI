#ifndef LINKED_LIST_GENERIC_H
#define LINKED_LIST_GENERIC_H

template <typename T>

class NodeG {
private:
	T data;
	NodeG * next;
public:
	NodeG(T data) {
		this->data = data;
		next = nullptr;
	}
};

template <typename T>
class LinkedListG {
private:
	NodeG* head = nullptr;
	NodeG* tail = nullptr;
	unsigned int size = 0;
	void copy(const LinkedListG& other);
	void cleanup();
public:
	LinkedListG();
	~LinkedListG();
	LinkedListG(const LinkedListG & other);
	void append(T data);
	unsigned int getSize() const;
	void remove_head();
	bool isEmpty() const;
};

#endif
