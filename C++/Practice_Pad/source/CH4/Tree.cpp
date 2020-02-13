#include "pch.h"
#include "Tree.h"
#include <iostream>


int main() {
	cout << "hello" << endl;
	BinaryTree<int> bt = BinaryTree<int>();
	for (int i = 0; i < 20; i ++) {
		bt.insert(i);
	}
	for (int i = 0; i < 20; i++) {
		cout << bt.find(i) << endl;
	}
	bt.print();
}