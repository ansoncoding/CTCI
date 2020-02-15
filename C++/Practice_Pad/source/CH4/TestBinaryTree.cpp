#include "pch.h"
#include "BinaryTree.h"
#include <iostream>

int d[] = { 8, 12, 3, 7, 2 , 10, 6, 77, 1, 5, 4, 19, 14, 0, 49 };
int N = 15;

TEST(TestBinaryTree, InsertFindRemove) {
	BinaryTree<int> bt = BinaryTree<int>();
	EXPECT_TRUE(bt.isNull());
	
	for (int i = 0; i < N; i++) {
		bt.insert(d[i]);
	}
	for (int i = 0; i < N; i++) {
		EXPECT_TRUE(bt.find(d[i]));
	}

	for (int i = 0; i < N; i++) {
		EXPECT_TRUE(bt.remove(d[i]));
		EXPECT_FALSE(bt.find(d[i]));
	}
	EXPECT_TRUE(bt.isNull());
}

TEST(TestBinaryTree, CopyConstructor) {
	BinaryTree<int> bt = BinaryTree<int>();
	for (int i = 0; i < N; i++) {
		bt.insert(d[i]);
	}
	BinaryTree<int> copy(bt);

	for (int i = 0; i < N; i++) {
		EXPECT_TRUE(copy.find(d[i]));
	}

	for (int i = 0; i < N; i++) {
		EXPECT_TRUE(bt.remove(d[i]));
		EXPECT_TRUE(copy.remove(d[i]));
		
		EXPECT_FALSE(bt.find(d[i]));
		EXPECT_FALSE(copy.find(d[i]));
	}
	EXPECT_TRUE(bt.isNull());
	EXPECT_TRUE(copy.isNull());
}

TEST(TestBinaryTree, AssignmentOperator) {
	BinaryTree<int> bt = BinaryTree<int>();
	for (int i = 0; i < N; i++) {
		bt.insert(d[i]);
	}
	BinaryTree<int> copy = bt;

	for (int i = 0; i < N; i++) {
		EXPECT_TRUE(copy.find(d[i]));
	}

	for (int i = 0; i < N; i++) {
		EXPECT_TRUE(bt.remove(d[i]));
		EXPECT_TRUE(copy.remove(d[i]));

		EXPECT_FALSE(bt.find(d[i]));
		EXPECT_FALSE(copy.find(d[i]));
	}
	EXPECT_TRUE(bt.isNull());
	EXPECT_TRUE(copy.isNull());
}
