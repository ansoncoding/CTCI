#ifndef GRAPH_ADJACENCY_LIST_H
#define GRAPH_ADJACENCY_LIST_H
#include "LinkedListQueue.h"
#include "ArrayList.h"

template <typename T>
struct GNode {
	LinkedListQ<int> links;
	T data;
	int ID; // the ID and also index in the list
	void copy(const GNode& other) {
		this->ID = other.ID;
		this->data = other.data;
		links = other.links;
	}
	GNode(int ID, T data, const LinkedListQ<int> & l) {
		this->data = data;
		this->links = l;
		this->ID = ID;
	}
	GNode(const GNode& other) {
		copy(other);
	}
	void print() const {
		cout << "Data: " << data << " ";
		links.print();
	}
	GNode<T>& operator=(const GNode& other) {
		if (&other != this) {
			cleanup();
			copy();
		}
	}
};

template <typename T>
class GraphAL {

private:
	ArrayList<GNode<T>*> * nodes = nullptr;
	void copy(const GraphAL& other);
	void cleanup();
	bool isConnectedHelper(int ID1, int ID2) const;
public:
	GraphAL<T>();
	~GraphAL<T>();
	GraphAL<T>(const GraphAL& other);
	GraphAL<T> & operator=(const GraphAL& other);
	bool find(T data, int & retID) const;
	void insert(GNode<T> new_Node);
	void remove(GNode<T> n);
	bool isConnected(T data1, T data2) const;
	void print() const;
};

template <typename T>
void GraphAL<T>::copy(const GraphAL& other) {

}

template <typename T>
void GraphAL<T>::cleanup() {

}

template <typename T>
GraphAL<T>::GraphAL() {
	nodes = new ArrayList<GNode<T>*>();
}

template <typename T>
GraphAL<T>::~GraphAL() {
	cleanup();
}

template <typename T>
GraphAL<T>::GraphAL(const GraphAL& other) {
	copy(other);
}

template <typename T>
GraphAL<T>& GraphAL<T>::operator=(const GraphAL& other) {
	if (&other != this) {
		cleanup();
		copy(other);
	}
	return *this;
}

template <typename T>
bool GraphAL<T>::find(T data, int & retID) const {
	for (int i = 0; i < nodes->getSize(); i++) {
		GNode<T>* temp = nodes->get(i);
		if (data == temp->data) {
			retID = temp->ID;
			return true;
		}
	}
	return false;
}

template <typename T>
void GraphAL<T>::insert(GNode<T> new_Node) {
	GNode<T> * n = new GNode<T>(new_Node);
	nodes->add(n);
}

template <typename T>
void GraphAL<T>::remove(GNode<T> n) {
	nodes->remove(n);
}

template <typename T>
bool GraphAL<T>::isConnectedHelper(int ID1, int ID2) const {

	for (int i = 0; i < nodes->getSize(); i++) { 
		
		GNode<T>* temp = nodes->get(i);
		if (temp->ID == ID1) { // find the first ID GNode<T>

			for (LinkedListQ<int>::Iterator iter = temp->links.begin(); iter != temp->links.end(); iter++) {
				
				// if its links include ID2, they are connected.
				if (*iter == ID2) {
					return true;
				}
			}
		}
	}
	return false;
}

template <typename T>
bool GraphAL<T>::isConnected(T data1, T data2) const {
	
	int ID_d1 = -1;
	int ID_d2 = -1;
	if (find(data1, ID_d1) && find(data2, ID_d2)) {
		return isConnectedHelper(ID_d1, ID_d2);
	}
	return false;
}

template <typename T>
void GraphAL<T>::print() const {
	for (int i = 0; i < nodes->getSize(); i++) {
		nodes->get(i)->print();
	}
}

#endif