#include "pch.h"
#include "BinaryTree.h"
#include <iostream>


int main() {
	cout << "hello" << endl;
	BinaryTree<int> bt = BinaryTree<int>();
	for (int i = 0; i < 6; i++) {
		bt.insert(i);
	}
	for (int i = 0; i < 6; i++) {
		cout << bt.find(i) << endl;
	}
	bt.print();
	cout << "==================================" << endl;

	for (int i = 0; i < 6; i++) {
		bt.remove(i);
	}
	
	bt.print();
}