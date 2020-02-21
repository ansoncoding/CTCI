#include "pch.h"
#include "BinarySearchTree.h"

int d2[] = { 8, 12, 3, 7, 2, 10, 6, 77, 1, 5, 4, 19, 14, 0, 49 };
int io[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 10, 12, 14, 19, 49, 77 };
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

TEST(TestBinarySearchTree, Order) {
	BinarySearchTree<int> bt = BinarySearchTree<int>();
	for (int i = 0; i < N2; i++) {
		bt.insert(d2[i]);
	}
	int* output = new int[N2];
	bt.inorder(output);
	for (int i = 0; i < N2; i++) {
		EXPECT_EQ(output[i], io[i]);
	}
}


TEST(TestBinarySearchTree, Height0) {

	BinarySearchTree<int> bst = BinarySearchTree<int>();
	EXPECT_EQ(bst.getHeight(), 0);

	bst.insert(1);
	EXPECT_EQ(bst.getHeight(), 0);
}

TEST(TestBinarySearchTree, HeightOther) {
	BinarySearchTree<int> bst = BinarySearchTree<int>();
	for (int i = 0; i < N2; i++) {
		bst.insert(d2[i]);
	}
	EXPECT_EQ(bst.getHeight(), 5);


	BinarySearchTree<int> bst2 = BinarySearchTree<int>();
	for (int i = 0; i < 3; i++) {
		bst2.insert(d2[i]);
	}
	EXPECT_EQ(bst2.getHeight(), 1);
}
