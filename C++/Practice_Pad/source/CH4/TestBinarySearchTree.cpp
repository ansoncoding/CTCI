#include "pch.h"
#include "BinarySearchTree.h"
#include <iostream>

#if 1
int d2[] = { 8, 12, 3, 7, 2 , 10, 6, 77, 1, 5, 4, 19, 14, 0, 49 };
int N2 = 15;

TEST(TestBinarySearchTree, InsertFindRemove) {
	BinarySearchTree<int> bt = BinarySearchTree<int>();
	EXPECT_TRUE(bt.isNull());
	
	for (int i = 0; i < N2; i++) {
		bt.insert(d2[i]);
	}
	for (int i = 0; i < N2; i++) {
		EXPECT_TRUE(bt.find(d2[i]));
	}

	for (int i = 0; i < N2; i++) {
		bt.remove(d2[i]);
		EXPECT_FALSE(bt.find(d2[i]));
	}
	EXPECT_TRUE(bt.isNull());
}

TEST(TestBinarySearchTree, CopyConstructor) {
	BinarySearchTree<int> bt = BinarySearchTree<int>();
	for (int i = 0; i < N2; i++) {
		bt.insert(d2[i]);
	}
	BinarySearchTree<int> copy(bt);

	for (int i = 0; i < N2; i++) {
		EXPECT_TRUE(copy.find(d2[i]));
	}

	for (int i = 0; i < N2; i++) {
		bt.remove(d2[i]);
		copy.remove(d2[i]);
		
		EXPECT_FALSE(bt.find(d2[i]));
		EXPECT_FALSE(copy.find(d2[i]));
	}
	EXPECT_TRUE(bt.isNull());
	EXPECT_TRUE(copy.isNull());
}

TEST(TestBinarySearchTree, AssignmentOperator) {
	BinarySearchTree<int> bt = BinarySearchTree<int>();
	for (int i = 0; i < N2; i++) {
		bt.insert(d2[i]);
	}
	BinarySearchTree<int> copy = bt;

	for (int i = 0; i < N2; i++) {
		EXPECT_TRUE(copy.find(d2[i]));
	}

	for (int i = 0; i < N2; i++) {
		bt.remove(d2[i]);
		copy.remove(d2[i]);

		EXPECT_FALSE(bt.find(d2[i]));
		EXPECT_FALSE(copy.find(d2[i]));
	}
	EXPECT_TRUE(bt.isNull());
	EXPECT_TRUE(copy.isNull());
}
#endif