#include "pch.h"
#include "TriStack.h"
#include "practice_exceptions.h"

TEST(TriStackTests, PushAndPeek) {
	TriStack stacks = TriStack();
	EXPECT_TRUE(stacks.isEmpty(one));
	EXPECT_TRUE(stacks.isEmpty(two));
	EXPECT_TRUE(stacks.isEmpty(three));

	stacks.push(one, 100);
	stacks.push(two, 100);
	stacks.push(three, 100);

	EXPECT_FALSE(stacks.isEmpty(one));
	EXPECT_FALSE(stacks.isEmpty(two));
	EXPECT_FALSE(stacks.isEmpty(three));

	EXPECT_EQ(stacks.peek(one), 100);
	EXPECT_EQ(stacks.peek(two), 100);
	EXPECT_EQ(stacks.peek(three), 100);
}

TEST(TriStackTests, MorePushAndPeek) {
	TriStack stacks = TriStack();

	for (unsigned int i = 0; i < 20; i++) {
		stacks.push(one, i * 10);
		EXPECT_EQ(stacks.peek(one), i * 10);
	}

	for (unsigned int i = 0; i < 20; i++) {
		stacks.push(two, i * 2);
		EXPECT_EQ(stacks.peek(two), i * 2);
	}

	for (unsigned int i = 0; i < 20; i++) {
		stacks.push(three, i * 5);
		EXPECT_EQ(stacks.peek(three), i * 5);
	}
}

TEST(TriStackTests, PeekOutOfBounds) {
	TriStack stacks = TriStack();
	EXPECT_THROW(stacks.peek(one), OutofBoundsException);
	EXPECT_THROW(stacks.peek(two), OutofBoundsException);
	EXPECT_THROW(stacks.peek(three), OutofBoundsException);
}

TEST(TriStackTests, Pop) {
	TriStack stacks = TriStack();

	for (int i = 0; i < 8; i++) {
		stacks.push(one, i * 10);
	}

	for (int i = 7; i >= 0; i--) {
		EXPECT_EQ(stacks.peek(one), i*10);
		stacks.pop(one);
	}

	for (int i = 0; i < 8; i++) {
		stacks.push(two, i * 2);
	}
	for (int i = 7; i >= 0; i--) {
		EXPECT_EQ(stacks.peek(two), i * 2);
		stacks.pop(two);
	}

	for (int i = 0; i < 8; i++) {
		stacks.push(three, i * 5);
	}
	for (int i = 7; i >= 0; i--) {
		EXPECT_EQ(stacks.peek(three), i * 5);
		stacks.pop(three);
	}
}

TEST(TriStackTests, ResizeManyTimes) {
	TriStack stacks = TriStack();

	for (int i = 0; i < 20; i++) {
		stacks.push(one, i * 10);
		EXPECT_EQ(stacks.peek(one), i * 10);
	}

	for (int i = 0; i < 50; i++) {
		stacks.push(two, i * 2);
		EXPECT_EQ(stacks.peek(two), i * 2);
	}

	for (int i = 0; i < 100; i++) {
		stacks.push(three, i * 5);
		EXPECT_EQ(stacks.peek(three), i * 5);
	}
}

TEST(TriStackTests, CopyConstructor) {
	TriStack stacks = TriStack();
	for (int i = 0; i < 8; i++) {
		stacks.push(one, i * 10);
	}
	for (int i = 0; i < 8; i++) {
		stacks.push(two, i * 2);
	}
	for (int i = 0; i < 8; i++) {
		stacks.push(three, i * 5);
	}

	TriStack copy(stacks);

	for (int i = 7; i >= 0; i--) {
		EXPECT_EQ(copy.peek(one), i * 10);
		copy.pop(one);
	}	
	for (int i = 7; i >= 0; i--) {
		EXPECT_EQ(copy.peek(two), i * 2);
		copy.pop(two);
	}
	for (int i = 7; i >= 0; i--) {
		EXPECT_EQ(copy.peek(three), i * 5);
		copy.pop(three);
	}
}

TEST(TriStackTests, AssignmentOperator) {
	TriStack copy;
	{
		TriStack stacks = TriStack();
		for (int i = 0; i < 8; i++) {
			stacks.push(one, i * 10);
		}
		for (int i = 0; i < 8; i++) {
			stacks.push(two, i * 2);
		}
		for (int i = 0; i < 8; i++) {
			stacks.push(three, i * 5);
		}

		copy = stacks;
	}

	for (int i = 7; i >= 0; i--) {
		EXPECT_EQ(copy.peek(one), i * 10);
		copy.pop(one);
	}
	for (int i = 7; i >= 0; i--) {
		EXPECT_EQ(copy.peek(two), i * 2);
		copy.pop(two);
	}
	for (int i = 7; i >= 0; i--) {
		EXPECT_EQ(copy.peek(three), i * 5);
		copy.pop(three);
	}
}