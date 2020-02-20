#include "pch.h"
#include "BinarySearchTree.h"
#include "BinaryTree.h"
#include "Heap.h"
#include "Graph.h"
#include <iostream>
#include <string>

#if 0
int main() {

	/*unordered_map<int, string> ma = unordered_map<int, string>();
	
	ma.insert(pair<int, string>(1, "hi"));*/
	GraphAL<string> g = GraphAL<string>();
	string d[] = { "jane", "jack", "mike", "lisa", "lola", "lora", "anna", "lily" };
	string f[] = { "jay",  "jam",  "zak",  "rex",  "amy",  "jac",  "ida",  "eve" };
	int N = 3;
	int Length = 8;
	for (int i = 0; i < Length; i++) {
		LinkedListQ<int> ll = LinkedListQ<int>();
		ll.append(i%Length);
		ll.append((i+1)%Length);
		ll.append((i+2)%Length);
		GNode<string> gnode = GNode<string>(i, d[i], ll);
		g.insert(gnode);
	}
	for (int i = Length; i < Length+N; i++) {
		GNode<string> gnode = GNode<string>(i, f[i-Length]);
		g.insert(gnode);
	}
	cout << "==================================" << endl;
	g.print();
	cout << "==================================" << endl;
	cout << g.isConnected("jane", "jack") << endl;
	cout << g.isConnected("jane", "lily") << endl;
	cout << g.isConnected("jane", "jay") << endl;
	
	/*for (int i = 0; i < N; i++) {
		mh.removeMin();
		mh.print();
	}*/
}
#endif