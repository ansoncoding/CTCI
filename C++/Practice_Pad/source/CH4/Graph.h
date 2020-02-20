#ifndef GRAPH_ADJACENCY_LIST_H
#define GRAPH_ADJACENCY_LIST_H
#include "LinkedListQueue.h"

#include <unordered_map> 
#include <set>
#include <vector>

template <typename T>
struct GNode {
	set<int> links;
	T data;
	bool visited = false;
	int ID; // the ID and also index in the list
	void copy(const GNode& other) {
		this->ID = other.ID;
		this->data = other.data;
		links = other.links;
	}
	GNode(int ID, T data, const set<int> & l) {
		this->data = data;
		this->links = l;
		this->ID = ID;
	}
	GNode(int ID, T data) {
		this->data = data;
		this->ID = ID;
		this->links = set<int>();
		this->links.insert(ID);
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
	
	void clearVisitedFlags();
	bool isConnectedHelper(int find_ID, LinkedListQ<int>& q, vector<int>& path) const;
public:
	bool find(T data, int & retID) const;
	void insert(GNode<T> new_Node);
	void remove(T data);
	bool isConnected(T data1, T data2, vector<int>& path);
	void print() const;
};

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
void GraphAL<T>::remove(T data) {
	
	int remove_ID;
	if (find(data, remove_ID)) {
		for (auto it = nodes.begin(); it != nodes.end(); ++it) {
			GNode<T>* temp = it->second;
			temp->links.erase(remove_ID);
		}
		nodes.erase(remove_ID);
	}
}

//BFS
template <typename T>
bool GraphAL<T>::isConnectedHelper(int find_ID, LinkedListQ<int> & q, vector<int>& path) const {

	if (q.isEmpty()) {
		throw invalid_argument("Queue is empty");
	}
	int index = q.peek();
	GNode<T>* n = nodes.at(index);

	if (!n->visited) {

		path.push_back(index);

		n->visited = true;

		if (!n->links.empty()) {

			for (auto it = n->links.begin(); it != n->links.end(); ++it) {

				if (*it == find_ID) {
					path.push_back(*it);
					return true;
				}
				q.append(*it);
			}
		}
	}
	q.remove();

	if (!q.isEmpty()) {
		if (isConnectedHelper(find_ID, q, path)) {
			return true;
		}
	}
	return false;
}

template <typename T>
bool GraphAL<T>::isConnected(T data1, T data2, vector<int> &path) {
	bool retval = false;
	int ID_d1 = -1;
	int ID_d2 = -1;
	if (find(data1, ID_d1) && find(data2, ID_d2)) {
		
		path.push_back(ID_d1);
		
		GNode<T>* node = nodes.at(ID_d1);
		if (!node->links.empty()) {
			LinkedListQ<int> q = LinkedListQ<int>();
			for (auto it = node->links.begin(); it != node->links.end(); it++) {
				q.append(*it);
			}
			retval = isConnectedHelper(ID_d2, q, path);
		}
	}
	clearVisitedFlags();

	return retval;
}

template <typename T>
void GraphAL<T>::print() const {
	
	for (auto it = nodes.begin(); it != nodes.end(); ++it) {
		GNode<T> * temp = it->second;
		cout << temp->data << " ";
		for (auto it = temp->links.begin(); it != temp->links.end(); it++) {
			cout << *it << " ";
		}
		cout << endl;
	}
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
