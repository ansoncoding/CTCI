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
	unordered_map<int, GNode<T>*> nodes; // ID mapped to GNode
	void cleanup();
	void copy(const GraphAL& other);
	void clearVisitedFlags();
	bool isConnectedHelperBFS(int find_ID, LinkedListQ<int>& q, vector<int> & path) const;
	bool isConnectedHelperDFS(int find_ID, vector<int>& stack, vector<int> & path) const;
public:
	GraphAL<T>(const GraphAL & other);
	GraphAL<T>& operator=(const GraphAL& other);
	~GraphAL<T>();
	GraphAL<T>();
	GraphAL<T>(T * data, int length);
	bool find(T data, int & retID) const;
	void insert(GNode<T> new_Node);
	void remove(T data);
	bool isConnected(T data1, T data2, vector<int>& path, bool BFS=true);
	void print() const;
	void printPath(vector<int>& path) const;
	bool addEdge(T data1, T data2);
	bool removeEdge(T data1, T data2);
};

template <typename T>
void GraphAL<T>::cleanup() {
	for (auto it = nodes.begin(); it != nodes.end(); ++it) {

		delete it->second;
		it->second = nullptr;
	}
}

template <typename T>
void GraphAL<T>::copy(const GraphAL& other) {
	for (auto it = other.nodes.begin(); it != other.nodes.end(); ++it) {
		this->nodes.insert(pair<int, GNode<T>*>(it->first, it->second));
	}
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
GraphAL<T>::GraphAL(T* vals, int length) {

	nodes = unordered_map<int, GNode<T>*>();

	for (int i = 0; i < length; i++) {
		GNode<T>* n = new GNode<T>(i, vals[i]);
		nodes.insert(pair<int, GNode<T>*>(i, n));
	}
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

template <typename T>
bool GraphAL<T>::removeEdge(T data1, T data2) {
	int ID_d1 = -1;
	int ID_d2 = -1;

	//ensure the nodes are in the graph first
	if (find(data1, ID_d1) && find(data2, ID_d2)) {
		nodes.at(ID_d1)->links.erase(ID_d2);
		nodes.at(ID_d2)->links.erase(ID_d1);
		return true;
	}
	return false;
}

template <typename T>
bool GraphAL<T>::addEdge(T data1, T data2) {
	
	int ID_d1 = -1;
	int ID_d2 = -1;

	//ensure the nodes are in the graph first
	if (find(data1, ID_d1) && find(data2, ID_d2)) {
		nodes.at(ID_d1)->links.insert(ID_d2);
		nodes.at(ID_d2)->links.insert(ID_d1);
		return true;
	}
	return false;
}

//DFS
template <typename T>
bool GraphAL<T>::isConnectedHelperDFS(int find_ID, vector<int> & stack, vector<int> & path) const {

	if (stack.empty()) {
		throw invalid_argument("Queue is empty");
	}

	while (!stack.empty()) {

		int seek_ID = stack.back();
		stack.pop_back();
		

		GNode<T>* n = nodes.at(seek_ID);

		if (!n->visited) {

			
			path.push_back(seek_ID);

			n->visited = true;
			if (seek_ID == find_ID) {

				//path.push_back(seek_ID);
				return true;
			}

			if (!n->links.empty()) {		

				for (auto it = n->links.begin(); it != n->links.end(); ++it) {

					stack.push_back(*it);
				}
			}
		}
		else {
			path.pop_back();
		}

	}
	return false;
}

//BFS
template <typename T>
bool GraphAL<T>::isConnectedHelperBFS(int find_ID, LinkedListQ<int>& q, vector<int>& path) const {

	if (q.isEmpty()) {
		throw invalid_argument("Queue is empty");
	}

	LinkedListQ<int> newq = LinkedListQ<int>();
	

	while (!q.isEmpty()) {

		int seek_ID = q.peek();

		GNode<T>* n = nodes.at(seek_ID); // get the node from the hashmap with the ID
		
		if (!n->visited) {

			n->visited = true;

			if (seek_ID == find_ID) { // if the node's ID matches the ID we're trying to find, return true
				
				path.push_back(seek_ID);

				return true;
			}

			if (!n->links.empty()) { // the node is not the one we're trying to find. insert the nodes in a new list

				path.push_back(seek_ID);

				for (auto it = n->links.begin(); it != n->links.end(); ++it) {

					if (*it == find_ID) {

						path.push_back(find_ID);
						return true;
					}
					newq.append(*it);
				}
			}
		}
		q.remove();
	}

	// if we reach here means the q is empty, none of the nodes in the queue were the node we're looking for.
	// we have to look further (next layer) out in BFS
	if (!newq.isEmpty()) {
		if (isConnectedHelperBFS(find_ID, newq, path)) {
			return true;
		}
	}
	return false;
}


template <typename T>
bool GraphAL<T>::isConnected(T data1, T data2, vector<int>& path, bool BFS) {
	bool retval = false;
	int ID_d1 = -1;
	int ID_d2 = -1;

	//ensure the nodes are in the graph first
	if (find(data1, ID_d1) && find(data2, ID_d2)) {
		
		path.push_back(ID_d1);
		
		// the node knows about itself
		if (ID_d1 == ID_d2) {
			return true;
		}

		// use the IDs to see if the nodes know each other
		GNode<T>* node = nodes.at(ID_d1);
		node->visited = true;

		if (!node->links.empty()) { // the links being empty means the node is disconnected from rest of the nodes

			if (BFS) {
				LinkedListQ<int> q = LinkedListQ<int>();
				for (auto it = node->links.begin(); it != node->links.end(); it++) {
					q.append(*it);
				}
				retval = isConnectedHelperBFS(ID_d2, q, path);
			}
			else {
				vector<int> stack = vector<int>();
				for (auto it = node->links.begin(); it != node->links.end(); it++) {
					stack.push_back(*it);
				}
				retval = isConnectedHelperDFS(ID_d2, stack, path);
			}

			clearVisitedFlags();
		}
	}
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
void GraphAL<T>::printPath(vector<int> & path) const {

	for (int i = 0; i < path.size(); i++) {

		GNode<T>* n = nodes.at(path.at(i));

		cout << n->data;

		if (i < (path.size() - 1)) {
			cout << " -> ";
		}
	}
	cout << " (Path length: " << path.size() - 1 << ")" << endl;
}

template <typename T>
void GraphAL<T>::clearVisitedFlags() {
	for (auto it = nodes.begin(); it != nodes.end(); ++it) {
		GNode<T>* temp = it->second;
		temp->visited = false;
	}
}
#endif
