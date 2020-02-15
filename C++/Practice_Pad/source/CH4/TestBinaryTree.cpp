#include "pch.h"
#include "BinaryTree.h"
#include <iostream>

TEST(TestBinaryTree, InsertFindRemove) {
	BinaryTree<int> bt = BinaryTree<int>();
	EXPECT_TRUE(bt.isNull());

	for (int i = 0; i < 20; i++) {
		bt.insert(i);
	}
	for (int i = 0; i < 20; i++) {
		EXPECT_TRUE(bt.find(i));
	}

	for (int i = 0; i < 20; i++) {
		EXPECT_TRUE(bt.remove(i));
		EXPECT_FALSE(bt.find(i));
	}
	EXPECT_TRUE(bt.isNull());
}

//TEST(TestBinaryTree, CopyConstructor) {
//	BinaryTree<int> bt = BinaryTree<int>();
//	for (int i = 0; i < 20; i++) {
//		bt.insert(i);
//	}
//	BinaryTree<int> copy(bt);
//
//	for (int i = 0; i < 20; i++) {
//		EXPECT_TRUE(copy.find(i));
//	}
//
//	for (int i = 0; i < 20; i++) {
//		EXPECT_TRUE(bt.remove(i));
//		EXPECT_TRUE(copy.remove(i));
//		
//		EXPECT_FALSE(bt.find(i));
//		EXPECT_FALSE(copy.find(i));
//	}
//	EXPECT_TRUE(bt.isNull());
//	EXPECT_TRUE(copy.isNull());
//}
//
//TEST(TestBinaryTree, AssignmentOperator) {
//	BinaryTree<int> bt = BinaryTree<int>();
//	for (int i = 0; i < 20; i++) {
//		bt.insert(i);
//	}
//	BinaryTree<int> copy = bt;
//
//	for (int i = 0; i < 20; i++) {
//		EXPECT_TRUE(copy.find(i));
//	}
//
//	for (int i = 0; i < 20; i++) {
//		EXPECT_TRUE(bt.remove(i));
//		EXPECT_TRUE(copy.remove(i));
//
//		EXPECT_FALSE(bt.find(i));
//		EXPECT_FALSE(copy.find(i));
//	}
//	EXPECT_TRUE(bt.isNull());
//	EXPECT_TRUE(copy.isNull());
//}
