#include "pch.h"
#include "BinarySearchTree.h"
#include "BinaryTree.h"
#include "Heap.h"
#include <iostream>

#if 0
int main() {
	MinHeap<int> mh = MinHeap<int>();
	int N = 15;
	int io[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 10, 12, 14, 19, 49, 77 };
	int d[] = { 8, 12, 3, 7, 2 , 10, 6, 77, 1, 5, 4, 19, 14, 0, 49 };
	//int d[] = {  6, 3, 9, 4, 7, 8 , 10, 6, 77, 1, 5, 4, 19, 14, 0, 49 };
	for (int i = 0; i < N; i++) {
		mh.insert(d[i]);
	}
	cout << "==================================" << endl;
	mh.print();
	
	cout << "==================================" << endl;
	for (int i = 0; i < N; i++) {
		mh.removeMin();
		mh.print();
	}
}
#endif