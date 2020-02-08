#include "pch.h"
#include "SimpleStack.h"
#include "practice_exceptions.h"

TEST(SimpleStackTests, PushAndPeek) {
	SimpleStack ss = SimpleStack();
	EXPECT_TRUE(ss.isEmpty());

	for (int i = 0; i < 8; i++) {
		ss.push(i);
		EXPECT_EQ(ss.peek(), i);
	}
}

TEST(SimpleStackTests, PeekOutOfBounds) {
	SimpleStack ss = SimpleStack();
	EXPECT_THROW(ss.peek(), OutofBoundsException);

	for (int i = 0; i < 5; i++) {
		ss.push(i);
	}
	for (int i = 0; i < 5; i++) {
		ss.pop();
	}
	EXPECT_THROW(ss.peek(), OutofBoundsException);
}

TEST(SimpleStackTests, Pop) {
	SimpleStack ss = SimpleStack();

	for (int i = 0; i < 8; i++) { // 0, 10, 20 ... 70
		ss.push(i * 10);
	}

	for (int i = 7; i >= 0; i--) {
		EXPECT_EQ(ss.peek(), i * 10);
		ss.pop();
	}
	EXPECT_TRUE(ss.isEmpty());
}


TEST(SimpleStackTests, CopyConstructor) {
	SimpleStack ss = SimpleStack();
	for (int i = 0; i < 8; i++) {
		ss.push(i * 10);
	}

	SimpleStack copy(ss);

	for (int i = 7; i >= 0; i--) {
		EXPECT_EQ(copy.peek(), i * 10);
		copy.pop();
	}
}

TEST(SimpleStackTests, AssignmentOperator) {
	SimpleStack ss = SimpleStack();
	for (int i = 0; i < 8; i++) {
		ss.push(i * 10);
	}

	SimpleStack copy = ss;
	for (int i = 7; i >= 0; i--) {
		EXPECT_EQ(copy.peek(), i * 10);
		copy.pop();
	}
}
