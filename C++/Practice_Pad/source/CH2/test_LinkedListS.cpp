#include "pch.h"
#include "LinkedListString.h"

TEST(LinkedListStringTests, Init) {
	LinkedListS lls = LinkedListS();
	EXPECT_TRUE(lls.isEmpty());
}

TEST(LinkedListStringTests, PrependElements) {
	LinkedListS lls = LinkedListS();
	string s[] = { "!", "day", "beautiful", "a", "it's", "Hello"};
	for (unsigned int i = 0; i < 6; i++) {
		lls.prepend(s[i]);
		EXPECT_TRUE(lls.contains(s[i]));
		EXPECT_EQ(lls.getLength(), i + 1);
		EXPECT_FALSE(lls.isEmpty());
	}
}

TEST(LinkedListStringTests, RemoveElements) {
	LinkedListS lls = LinkedListS();
	string s[] = { "!", "day", "beautiful", "a", "it's", "Hello" };
	for (unsigned int i = 0; i < 6; i++) {
		lls.prepend(s[i]);
	}
	for (unsigned int i = 0; i < 6; i++) {
		lls.remove(s[i]);
		EXPECT_FALSE(lls.contains(s[i]));
		EXPECT_EQ(lls.getLength(), 6 - i - 1);
	}
	EXPECT_TRUE(lls.isEmpty());
}

TEST(LinkedListStringTests, CopyConstructor) {
	
	LinkedListS lls = LinkedListS();
	string s[] = { "!", "day", "beautiful", "a", "it's", "Hello" };
	for (unsigned int i = 0; i < 6; i++) {
		lls.prepend(s[i]);
	}

	LinkedListS copy(lls);
	EXPECT_EQ(copy.getLength(), 6);
	EXPECT_FALSE(copy.isEmpty());
	for (unsigned int i = 0; i < 6; i++) {
		EXPECT_TRUE(copy.contains(s[i]));	
	}
}

TEST(LinkedListStringTests, AssignmentOperator) {

	LinkedListS lls = LinkedListS();
	string s[] = { "!", "day", "beautiful", "a", "it's", "Hello" };
	for (unsigned int i = 0; i < 6; i++) {
		lls.prepend(s[i]);
	}

	LinkedListS copy = lls;
	EXPECT_EQ(copy.getLength(), 6);
	EXPECT_FALSE(copy.isEmpty());
	for (unsigned int i = 0; i < 6; i++) {
		EXPECT_TRUE(copy.contains(s[i]));
	}
}