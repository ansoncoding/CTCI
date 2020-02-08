#include "pch.h"
#include "StableStack.h"
#include "practice_exceptions.h"

TEST(StableStackTests, PushAndPeek) {
	StableStack ss = StableStack();
	EXPECT_TRUE(ss.isEmpty());

	for (int i = 0; i < 8; i++) {
		ss.push(i);
		EXPECT_EQ(ss.peek(), i);
	}
}

TEST(StableStackTests, Pop) {
	StableStack ss = StableStack();

	for (int i = 0; i < 8; i++) { // 0, 10, 20 ... 70
		ss.push(i * 10);
	}

	for (int i = 7; i >= 0; i--) {
		EXPECT_EQ(ss.peek(), i * 10);
		ss.pop();
	}
	EXPECT_TRUE(ss.isEmpty());
}


TEST(StableStackTests, CreateNewStack) {
	StableStack ss = StableStack();
	for (int i = 0; i < 65; i++) {
		ss.push(i);
		EXPECT_EQ(ss.peek(), i);
	}
}

TEST(StableStackTests, ResizeManyTimes) {
	StableStack ss = StableStack();

	for (int i = 0; i < 256; i++) {
		ss.push(i * 10);
		EXPECT_EQ(ss.peek(), i * 10);
	}
}

TEST(StableStackTests, PeekOutOfBounds) {
	StableStack ss = StableStack();
	EXPECT_THROW(ss.peek(), OutofBoundsException);

	for (int i = 0; i < 5; i++) {
		ss.push(i);
	}
	for (int i = 0; i < 5; i++) {
		ss.pop();
	}
	EXPECT_THROW(ss.peek(), OutofBoundsException);
}

TEST(StableStackTests, CopyConstructor) {
	StableStack ss = StableStack();
	for (int i = 0; i < 8; i++) {
		ss.push(i * 10);
	}

	StableStack copy(ss);

	for (int i = 7; i >= 0; i--) {
		EXPECT_EQ(copy.peek(), i * 10);
		copy.pop();
	}
}

TEST(StableStackTests, AssignmentOperator) {
	StableStack ss = StableStack();
	for (int i = 0; i < 8; i++) {
		ss.push(i * 10);
	}

	StableStack copy = ss;
	for (int i = 7; i >= 0; i--) {
		EXPECT_EQ(copy.peek(), i * 10);
		copy.pop();
	}
}
