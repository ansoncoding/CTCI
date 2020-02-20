#ifndef GRAPH_ADJACENCY_LIST_H
#define GRAPH_ADJACENCY_LIST_H
#include "LinkedListQueue.h"
//#include "ArrayList.h"
#include <unordered_map> 

template <typename T>
struct GNode {
	LinkedListQ<int> links;
	T data;
	bool visited = false;
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
	GNode(int ID, T data) {
		this->data = data;
		this->ID = ID;
		this->links = LinkedListQ<int>();
		this->links.append(ID);
	}
	GNode(const GNode& other) {
		copy(other);
	}
	void print() const {
		cout << "Data: " << data << " connections: ";
		links.print();
	}
	GNode<T>& operator=(const GNode& other) {
		if (&other != this) {
			cleanup();
			copy();
		}
	}
	bool operator==(const GNode& other) {
		return other.ID == this->ID;
	}
};

template <typename T>
class GraphAL {

private:
	unordered_map<int, GNode<T>*> nodes;
	//ArrayList<GNode<T>*> * nodes = nullptr;
	void copy(const GraphAL& other);
	void cleanup();
	void clearVisitedFlags();
	bool isConnectedHelper(int find_ID, LinkedListQ<int>& q) const;
public:
	GraphAL<T>();
	~GraphAL<T>();
	GraphAL<T>(const GraphAL& other);
	GraphAL<T> & operator=(const GraphAL& other);
	bool find(T data, int & retID) const;
	void insert(GNode<T> new_Node);
	void remove(GNode<T> n);
	bool isConnected(T data1, T data2);
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
	nodes = unordered_map<int, GNode<T>*>();
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
	for (auto it = nodes.begin(); it != nodes.end(); ++it) {
		GNode<T>* temp = it->second;
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
	nodes.insert(pair<int, GNode<T>*>(new_Node.ID, n));
}

template <typename T>
void GraphAL<T>::remove(GNode<T> n) {
	
	int remove_ID = n->ID;
	for (auto it = nodes.begin(); it != nodes.end(); ++it) {
		nodes.get(i)->links.removeByVal(remove_ID);
	}

	for (auto it = nodes.begin(); it != nodes.end(); ++it) {
		GNode<T>* temp = it->second;
		if (temp->ID == remove_ID) {

			nodes.erase(it);

		}
	}
}

//BFS
template <typename T>
bool GraphAL<T>::isConnectedHelper(int find_ID, LinkedListQ<int> & q) const {

	if (q.isEmpty()) {
		throw invalid_argument("Queue is empty");
	}
	GNode<T>* n = nodes.at(q.peek());

	if (!n->visited) {

		n->visited = true;

		if (!n->links.isEmpty()) {

			for (auto it = n->links.begin(); it != n->links.end(); ++it) {

				if (*it == find_ID) {
					return true;
				}
				q.append(*it);
			}
		}
	}
	q.remove();

	if (!q.isEmpty()) {
		if (isConnectedHelper(find_ID, q)) {
			return true;
		}
	}
	return false;
}

template <typename T>
bool GraphAL<T>::isConnected(T data1, T data2) {
	bool retval = false;
	int ID_d1 = -1;
	int ID_d2 = -1;
	if (find(data1, ID_d1) && find(data2, ID_d2)) {
		GNode<T>* node = nodes.at(ID_d1);
		if (!node->links.isEmpty()) {
			LinkedListQ<int> q = LinkedListQ<int>(node->links);
			retval = isConnectedHelper(ID_d2, q);
		}
	}
	clearVisitedFlags();

	return retval;
}

template <typename T>
void GraphAL<T>::print() const {
	/*for (int i = 0; i < nodes->getSize(); i++) {
		nodes->get(i)->print();
	}*/
	
	for (auto it = nodes.begin(); it != nodes.end(); ++it)
		it->second->print();
	cout << endl;
}

template <typename T>
void GraphAL<T>::clearVisitedFlags() {
	for (auto it = nodes.begin(); it != nodes.end(); ++it) {
		GNode<T>* temp = it->second;
		temp->visited = false;
	}
}
#endif