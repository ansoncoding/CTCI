#include "pch.h"
#include "BinarySearchTree.h"
#include "BinaryTree.h"
#include <iostream>

#if 0
int main() {
	cout << "hello" << endl;
	BinarySearchTree<int> bt = BinarySearchTree<int>();
	//BinaryTree<int> bt = BinaryTree<int>();
	
	int N = 15;
	
	int d[] = { 8, 12, 3, 7, 2 , 10, 6, 77, 1, 5, 4, 19, 14, 0, 49 };
	//int d[] = {  6, 3, 9, 4, 7, 8 , 10, 6, 77, 1, 5, 4, 19, 14, 0, 49 };
	for (int i = 0; i < N; i++) {
		bt.insert(d[i]);
	}
	cout << "==================================" << endl;
	bt.print();
	
	for (int i = 0; i < N; i++) {
		
		bt.remove(d[i]);
		//cout << "==============REMOVE " << d[i] << " ====================" << endl;
		//bt.print();
	}

	cout << "==================================" << endl;
	bt.print();
}
#endif