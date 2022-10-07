#include "pch.h"
#include "StackMin.h"
#include "practice_exceptions.h"

TEST(StackMinTests, PushAndPeek) {
	StackMin sm = StackMin();
	EXPECT_TRUE(sm.isEmpty());

	for (int i = 0; i < 8; i++) {
		sm.push(i);
		EXPECT_EQ(sm.peek(), i);
	}
}

TEST(StackMinTests, MorePushAndPeek) {
	StackMin sm = StackMin();
	for (int i = 0; i < 100; i++) {
		sm.push(i);
		EXPECT_EQ(sm.peek(), i);
	}
}

TEST(StackMinTests, PeekOutOfBounds) {
	StackMin sm = StackMin();
	EXPECT_THROW(sm.peek(), OutofBoundsException);
	EXPECT_THROW(sm.getMin(), OutofBoundsException);

	for (int i = 0; i < 5; i++) {
		sm.push(i);
	}
	for (int i = 0; i < 5; i++) {
		sm.pop();
	}
	EXPECT_THROW(sm.peek(), OutofBoundsException);
	EXPECT_THROW(sm.getMin(), OutofBoundsException);
}

TEST(StackMinTests, Pop) {
	StackMin sm = StackMin();

	for (int i = 0; i < 8; i++) { // 0, 10, 20 ... 70
		sm.push(i * 10);
	}

	for (int i = 7; i >= 0; i--) {
		EXPECT_EQ(sm.peek(), i * 10);
		sm.pop();
	}
	EXPECT_TRUE(sm.isEmpty());
}

TEST(StackMinTests, ResizeManyTimes) {
	StackMin sm = StackMin();

	for (int i = 0; i < 256; i++) {
		sm.push(i * 10);
		EXPECT_EQ(sm.peek(), i * 10);
		EXPECT_EQ(sm.getMin(), 0);
	}
}

TEST(StackMinTests, CopyConstructor) {
	StackMin sm = StackMin();
	for (int i = 0; i < 8; i++) {
		sm.push(i * 10);
	}

	StackMin copy(sm);

	for (int i = 7; i >= 0; i--) {
		EXPECT_EQ(copy.peek(), i * 10);
		copy.pop();
	}
}

TEST(StackMinTests, AssignmentOperator) {
	StackMin copy;
	{
		StackMin sm = StackMin();
		for (int i = 0; i < 8; i++) {
			sm.push(i * 10);
		}

		copy = sm;
	}
	for (int i = 7; i >= 0; i--) {
		EXPECT_EQ(copy.peek(), i * 10);
		copy.pop();
	}
}

TEST(StackMinTests, GetMinDecrease) {

	StackMin sm = StackMin();
	sm.push(100);
	EXPECT_EQ(sm.getMin(), 100);
	sm.push(50);
	EXPECT_EQ(sm.getMin(), 50);
	sm.push(25);
	EXPECT_EQ(sm.getMin(), 25);
}

TEST(StackMinTests, GetMinIncrease) {

	StackMin sm = StackMin();
	sm.push(40);
	EXPECT_EQ(sm.getMin(), 40);
	sm.push(60);
	EXPECT_EQ(sm.getMin(), 40);
	sm.push(55);
	EXPECT_EQ(sm.getMin(), 40);
}

TEST(StackMinTests, GetMinAfterPopInc) {

	StackMin sm = StackMin();
	sm.push(40);
	EXPECT_EQ(sm.getMin(), 40);
	sm.push(60);
	EXPECT_EQ(sm.getMin(), 40);
	sm.push(55);
	EXPECT_EQ(sm.getMin(), 40);
	sm.pop();
	EXPECT_EQ(sm.getMin(), 40);
	sm.pop();
	EXPECT_EQ(sm.getMin(), 40);
	sm.pop();
}


TEST(StackMinTests, GetMinAfterPopDec) {

	StackMin sm = StackMin();
	sm.push(100);
	EXPECT_EQ(sm.getMin(), 100);
	sm.push(50);
	EXPECT_EQ(sm.getMin(), 50);
	sm.push(25);
	EXPECT_EQ(sm.getMin(), 25);
	sm.pop();
	EXPECT_EQ(sm.getMin(), 50);
	sm.pop();
	EXPECT_EQ(sm.getMin(), 100);
	sm.pop();
}

TEST(StackMinTests, Sort) {
	StackMin sm = StackMin();
	StackMin soln = StackMin();
	for (int i = 0; i < 8; i++) {
		sm.push(i * 10);
		soln.push((8 - 1 - i) * 10);
	}
	sm.sort();
	EXPECT_TRUE(sm.compare(soln));
}