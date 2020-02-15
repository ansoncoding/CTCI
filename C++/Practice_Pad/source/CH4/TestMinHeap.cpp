#include "pch.h"
#include "Heap.h"
#include <iostream>

int d3[] = { 8, 12, 3, 7, 2 , 10, 6, 77, 1, 5, 4, 19, 14, 0, 49 };
int N3 = 15;

TEST(TestMinHeap, InsertFindRemove) {
	MinHeap<int> mh = MinHeap<int>();
	EXPECT_TRUE(mh.isNull());
	
	for (int i = 0; i < N3; i++) {
		mh.insert(d3[i]);
	}
	EXPECT_EQ(mh.getMin(), 0);
}
//
//TEST(TestMinHeap, CopyConstructor) {
//	MinHeap<int> mh = MinHeap<int>();
//	for (int i = 0; i < N; i++) {
//		mh.insert(d[i]);
//	}
//	MinHeap<int> copy(mh);
//
//
//	EXPECT_TRUE(mh.isNull());
//	EXPECT_TRUE(copy.isNull());
//}
//
//TEST(TestMinHeap, AssignmentOperator) {
//	MinHeap<int> mh = MinHeap<int>();
//	for (int i = 0; i < N; i++) {
//		mh.insert(d[i]);
//	}
//	MinHeap<int> copy = mh;
//
//	for (int i = 0; i < N; i++) {
//		EXPECT_TRUE(copy.find(d[i]));
//	}
//
//	for (int i = 0; i < N; i++) {
//		EXPECT_TRUE(mh.remove(d[i]));
//		EXPECT_TRUE(copy.remove(d[i]));
//
//		EXPECT_FALSE(mh.find(d[i]));
//		EXPECT_FALSE(copy.find(d[i]));
//	}
//	EXPECT_TRUE(mh.isNull());
//	EXPECT_TRUE(copy.isNull());
//}
