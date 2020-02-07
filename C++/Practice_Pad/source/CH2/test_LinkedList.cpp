#include "pch.h"
#include "LinkedList.h"

TEST(LinkedListTests, Init) {
	LinkedList ll = LinkedList();
	EXPECT_EQ(ll.getLength(), 0);
}

TEST(LinkedListTests, AddElements) {
	LinkedList ll = LinkedList();
	for (int i = 0; i < 10; i++) {
		ll.prepend(i);
		EXPECT_EQ(ll.getLength(), i+1);
	}
	EXPECT_EQ(ll.getLength(), 10);
}

TEST(LinkedListTests, RemoveElements) {
	LinkedList ll = LinkedList();
	for (int i = 0; i < 10; i++) {
		ll.prepend(i);
		EXPECT_TRUE(ll.contains(i));
		EXPECT_EQ(ll.getLength(), i + 1);
	}
	for (int i = 0; i < 10; i++) {
		ll.remove(i);
		EXPECT_FALSE(ll.contains(i));
		EXPECT_EQ(ll.getLength(), 10-i-1);
	}
	EXPECT_EQ(ll.getLength(), 0);
}

TEST(LinkedListTests, RemoveDups) {
	LinkedList ll = LinkedList();
	LinkedList soln = LinkedList();
	for (int i = 0; i < 10; i++) {
		ll.prepend(i);
		ll.prepend(i);
		soln.prepend(i);
	}
	ll.remove_duplicates();
	EXPECT_TRUE(ll.compare(soln));
}

TEST(LinkedListTests, RemoveDups2) {
	LinkedList ll = LinkedList();
	LinkedList soln = LinkedList();
	for (int i = 0; i < 10; i++) {
		ll.prepend(i);
		ll.prepend(i);
		soln.prepend(i);
	}
	ll.remove_duplicates2();
	EXPECT_TRUE(ll.compare(soln));
}

TEST(LinkedListTests, Palindrome) {
	LinkedList ll_t = LinkedList();
	LinkedList ll_f = LinkedList();
	for (int i = 0; i < 5; i++) {
		ll_t.prepend(i);
		ll_f.prepend(i);
	}
	for (int i = 4; i >=0; i--) {
		ll_t.prepend(i);
	}
	EXPECT_TRUE(ll_t.is_palindrome());
	EXPECT_FALSE(ll_f.is_palindrome());
}

TEST(LinkedListTests, PalindromeOddLength) {
	LinkedList ll_t = LinkedList();
	LinkedList ll_f = LinkedList();
	for (int i = 0; i < 5; i++) {
		ll_t.prepend(i);
		ll_f.prepend(i);
	}
	for (int i = 3; i >= 0; i--) {
		ll_t.prepend(i);
		ll_f.prepend(i);
	}
	ll_f.prepend(0);
	EXPECT_TRUE(ll_t.is_palindrome());
	EXPECT_FALSE(ll_f.is_palindrome());
}

TEST(LinkedListTests, PalindromeEdgeCases) {
	LinkedList ll_t = LinkedList();
	LinkedList ll_f = LinkedList();
	
	ll_t.prepend(1);

	ll_f.prepend(1);
	ll_f.prepend(2);
	
	EXPECT_TRUE(ll_t.is_palindrome());
	EXPECT_FALSE(ll_f.is_palindrome());
}