#include "pch.h"
#include "DualStackQueue.h"
#include "practice_exceptions.h"

TEST(DualStackQueueTests, AddAndPeek) {
	DSQueue sm = DSQueue();
	EXPECT_TRUE(sm.isEmpty());

	for (int i = 0; i < 8; i++) {
		sm.add(i);
		EXPECT_EQ(sm.peek(), 0);
	}
}

TEST(DualStackQueueTests, MoreAddAndPeek) {
	DSQueue sm = DSQueue();
	for (int i = 0; i < 100; i++) {
		sm.add(i);
		EXPECT_EQ(sm.peek(), 0);
	}
}

TEST(DualStackQueueTests, PeekOutOfBounds) {
	DSQueue sm = DSQueue();
	EXPECT_THROW(sm.peek(), OutofBoundsException);

	for (int i = 0; i < 5; i++) {
		sm.add(i);
	}
	for (int i = 0; i < 5; i++) {
		sm.remove();
	}
	EXPECT_THROW(sm.peek(), OutofBoundsException);
}

TEST(DualStackQueueTests, AddAndRemove) {
	DSQueue sm = DSQueue();

	for (int i = 0; i < 8; i++) { // 0, 10, 20 ... 70
		sm.add(i * 10);
	}

	for (int i = 0; i < 8; i++) {
		EXPECT_EQ(sm.peek(), i * 10);
		sm.remove();
	}
	EXPECT_TRUE(sm.isEmpty());
}

TEST(DualStackQueueTests, ResizeManyTimes) {
	DSQueue sm = DSQueue();

	for (int i = 0; i < 256; i++) {
		sm.add(i * 10);
		EXPECT_EQ(sm.peek(), 0);
	}
}

TEST(DualStackQueueTests, CopyConstructor) {
	DSQueue sm = DSQueue();
	for (int i = 0; i < 8; i++) {
		sm.add(i * 10);
	}

	DSQueue copy(sm);

	for (int i = 0; i < 8; i++) {
		EXPECT_EQ(copy.peek(), i * 10);
		copy.remove();
	}
}

TEST(DualStackQueueTests, AssignmentOperator) {
	DSQueue sm = DSQueue();
	for (int i = 0; i < 8; i++) {
		sm.add(i * 10);
	}

	DSQueue copy = sm;
	for (int i = 0; i < 8; i++) {
		EXPECT_EQ(copy.peek(), i * 10);
		copy.remove();
	}
}
