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

TEST(TestBinarySearchTree, MinHeightBST_Edge) {
	int data[128];
	for (int i = 0; i < 128; i++) {
		data[i] = i;
	}
	BinarySearchTree<int> bst0 = BinarySearchTree<int>();
	insert_array_min_height_bst(data, 1, bst0);
	EXPECT_EQ(bst0.getHeight(), 0);

	BinarySearchTree<int> bst1 = BinarySearchTree<int>();
	insert_array_min_height_bst(data, 2, bst1);
	EXPECT_EQ(bst1.getHeight(), 1);

	BinarySearchTree<int> bst2 = BinarySearchTree<int>();
	insert_array_min_height_bst(data, 3, bst2);
	EXPECT_EQ(bst2.getHeight(), 1);

	BinarySearchTree<int> bst3 = BinarySearchTree<int>();
	insert_array_min_height_bst(data, 4, bst3);
	EXPECT_EQ(bst3.getHeight(), 2);

	BinarySearchTree<int> bst4 = BinarySearchTree<int>();
	insert_array_min_height_bst(data, 15, bst4);
	EXPECT_EQ(bst4.getHeight(), 3);

	BinarySearchTree<int> bst5 = BinarySearchTree<int>();
	insert_array_min_height_bst(data, 16, bst5);
	EXPECT_EQ(bst5.getHeight(), 4);

	BinarySearchTree<int> bst6 = BinarySearchTree<int>();
	insert_array_min_height_bst(data, 128, bst6);
	EXPECT_EQ(bst6.getHeight(), 7);
}

TEST(TestBinarySearchTree, MinHeightBST_Other) {
	int data[128];
	for (int i = 0; i < 128; i++) {
		data[i] = i;
	}

	BinarySearchTree<int> bst = BinarySearchTree<int>();
	insert_array_min_height_bst(data, 5, bst);
	EXPECT_EQ(bst.getHeight(), 2);

	BinarySearchTree<int> bst1 = BinarySearchTree<int>();
	insert_array_min_height_bst(data, 22, bst1);
	EXPECT_EQ(bst1.getHeight(), 4);

	BinarySearchTree<int> bst2 = BinarySearchTree<int>();
	insert_array_min_height_bst(data, 56, bst2);
	EXPECT_EQ(bst2.getHeight(), 5);
}

TEST(TestBinarySearchTree, IsBalancedFalse) {
	BinarySearchTree<int> bst = BinarySearchTree<int>();
	
	bst.insert(0);
	bst.insert(1);
	bst.insert(2);
	EXPECT_FALSE(bst.isBalanced());
}

TEST(TestBinarySearchTree, IsBalancedTrue) {
	BinarySearchTree<int> bst = BinarySearchTree<int>();
	int data[128];
	for (int i = 0; i < 128; i++) {
		data[i] = i;
	}
	
	insert_array_min_height_bst(data, 5, bst);
	EXPECT_TRUE(bst.isBalanced());

	BinarySearchTree<int> bst1 = BinarySearchTree<int>();
	insert_array_min_height_bst(data, 22, bst1);
	EXPECT_TRUE(bst1.isBalanced());

	BinarySearchTree<int> bst2 = BinarySearchTree<int>();
	insert_array_min_height_bst(data, 56, bst2);
	EXPECT_TRUE(bst2.isBalanced());
}