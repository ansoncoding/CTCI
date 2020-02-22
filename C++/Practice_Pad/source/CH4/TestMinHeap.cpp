#include "pch.h"
#include "Heap.h"
#include <iostream>

int d3[] = { 8, 12, 3, 7, 2 ,10, 6, 77, 1, 5, 4, 19, 14, 0, 49 };
int mins[] = { 8, 8, 3, 3, 2 ,2,  2,  2, 1, 1, 1, 1,  1, 0, 0 };	
int dio[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 10, 12, 14, 19, 49, 77 };
int N3 = 15;

TEST(TestMinHeap, Insert) {
	MinHeap<int> mh = MinHeap<int>();
	EXPECT_TRUE(mh.isEmpty());
	
	for (int i = 0; i < N3; i++) {
		mh.insert(d3[i]);
		EXPECT_EQ(mh.getMin(), mins[i]);
	}
}

TEST(TestMinHeap, RemoveMin) {
	MinHeap<int> mh = MinHeap<int>();
	EXPECT_TRUE(mh.isEmpty());

	for (int i = 0; i < N3; i++) {
		mh.insert(d3[i]);
	}
	for (int i = 0; i < N3; i++) {
		EXPECT_EQ(mh.getMin(), dio[i]);
		mh.removeMin();
	}
}


TEST(TestMinHeap, CopyConstructor) {
	MinHeap<int> mh = MinHeap<int>();
	for (int i = 0; i < N3; i++) {
		mh.insert(d3[i]);
	}

	MinHeap<int> copy(mh);
	for (int i = 0; i < N3; i++) {
		EXPECT_EQ(copy.getMin(), dio[i]);
		copy.removeMin();
	}
}

TEST(TestMinHeap, AssignmentOperator) {
	MinHeap<int> copy;
	{
		MinHeap<int> mh = MinHeap<int>();
		for (int i = 0; i < N3; i++) {
			mh.insert(d3[i]);
		}
		copy = mh;
	}

	for (int i = 0; i < N3; i++) {
		EXPECT_EQ(copy.getMin(), dio[i]);
		copy.removeMin();
	}
}
