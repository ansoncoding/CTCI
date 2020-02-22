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
	BinaryTree<int> copy;
	{
		BinaryTree<int> bt = BinaryTree<int>();
		for (int i = 0; i < N; i++) {
			bt.insert(d[i]);
		}
		copy = bt;
	}

	for (int i = 0; i < N; i++) {
		EXPECT_TRUE(copy.find(d[i]));
	}

	for (int i = 0; i < N; i++) {
		EXPECT_TRUE(copy.remove(d[i]));


		EXPECT_FALSE(copy.find(d[i]));
	}

	EXPECT_TRUE(copy.isNull());
}

TEST(TestBinaryTree, Height0) {

	BinaryTree<int> bt = BinaryTree<int>();
	EXPECT_EQ(bt.getHeight(), 0);

	bt.insert(1);
	EXPECT_EQ(bt.getHeight(), 0);
	
}

TEST(TestBinaryTree, HeightOther) {
	BinaryTree<int> bt = BinaryTree<int>();
	for (int i = 0; i < N; i++) {
		bt.insert(d[i]);
	}
	EXPECT_EQ(bt.getHeight(), 4);


	BinaryTree<int> bt2 = BinaryTree<int>();
	for (int i = 0; i < 3; i++) {
		bt2.insert(d[i]);
	}
	EXPECT_EQ(bt2.getHeight(), 1);
}

TEST(TestBinaryTree, IsBalancedEdgeCases) {
	BinaryTree<int> bt = BinaryTree<int>();
	EXPECT_TRUE(bt.isBalanced());
	bt.insert(1);
	EXPECT_TRUE(bt.isBalanced());
}

TEST(TestBinaryTree, IsBalancedTrue) {
	// for False cases please see Binary Search Tree tests
	BinaryTree<int> bt = BinaryTree<int>();
	EXPECT_TRUE(bt.isBalanced());
	bt.insert(1);
	bt.insert(2);
	bt.insert(0);
	EXPECT_TRUE(bt.isBalanced());

	BinaryTree<int> bt2 = BinaryTree<int>();
	for (int i = 0; i < N; i++) {
		bt2.insert(d[i]);
	}
	EXPECT_TRUE(bt2.isBalanced());
}

TEST(TestBinaryTree, IsBST_Edge) {
	BinaryTree<int> bt = BinaryTree<int>();
	EXPECT_THROW(bt.isBST(), invalid_argument);

	bt.insert(1);
	EXPECT_TRUE(bt.isBST());
}

TEST(TestBinaryTree, IsBST_False) {
	// for True cases please see Binary Search Tree tests
	BinaryTree<int> bt = BinaryTree<int>();
	for (int i = 0; i < N; i++) {
		bt.insert(d[i]);
	}
	EXPECT_FALSE(bt.isBST());


	BinaryTree<int> bt2 = BinaryTree<int>();
	for (int i = 0; i < 6; i++) {
		bt2.insert(d[i]);
	}
	EXPECT_FALSE(bt2.isBST());
}
