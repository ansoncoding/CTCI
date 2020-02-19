#include "pch.h"
#include "BinarySearchTree.h"
#include "BinaryTree.h"
#include "Heap.h"
#include "Graph.h"
#include <iostream>
#include <string>

#if 0
int main() {

	LinkedListQ<int> ll = LinkedListQ<int>();
	for (int i = 0; i < 20; i++) {
		ll.append(i);
	}
	for (LinkedListQ<int>::Iterator iterator = ll.begin();
		iterator != ll.end(); iterator++)
	{
		cout << *iterator << " ";
	}

	//GraphAL<string> g = GraphAL<string>();
	//string d[] = { "jane", "jack", "mike", "lisa", "lola", "lora", "amy", "lily" };
	//int N = 5;

	//for (int i = 0; i < N; i++) {
	//	LinkedListQ<int> ll = LinkedListQ<int>();
	//	ll.append(i);
	//	ll.append(i+1);
	//	ll.append(i+2);
	//	GNode<string> gnode = GNode<string>(i, d[i], ll);
	//	g.insert(gnode);
	//}
	//cout << "==================================" << endl;
	//g.print();
	//cout << "==================================" << endl;
	//
	/*for (int i = 0; i < N; i++) {
		mh.removeMin();
		mh.print();
	}*/
}
#endif