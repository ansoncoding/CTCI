#include "pch.h"
#include "LinkedList.h"
#include "practice_exceptions.h"

TEST(LinkedListTests, Init) {
	LinkedList ll = LinkedList();
	EXPECT_EQ(ll.getLength(), 0);

	ll = LinkedList(10);

	Node* retval;
	EXPECT_EQ(ll.getLength(), 10);
	for (int i = 0; i < 10; i++) {
		EXPECT_TRUE(ll.contains(i));
		retval = ll.get(i);
		ASSERT_NE(retval, nullptr);
		EXPECT_EQ(retval->data, 10 - i - 1);
	}
}

TEST(LinkedListTests, CopyConstructor) {
	LinkedList ll = LinkedList(10);
	LinkedList copy(ll);

	Node* retval;
	EXPECT_EQ(copy.getLength(), 10);
	for (int i = 0; i < 10; i++) {
		EXPECT_TRUE(copy.contains(i));
		retval = copy.get(i);
		ASSERT_NE(retval, nullptr);
		EXPECT_EQ(retval->data, 10 - i - 1);
	}
}

TEST(LinkedListTests, AssignmentOperator) {
	
	LinkedList copy;
	{
		LinkedList ll = LinkedList(10);
		copy = ll;
	}

	Node* retval;
	EXPECT_EQ(copy.getLength(), 10);
	for (int i = 0; i < 10; i++) {
		EXPECT_TRUE(copy.contains(i));
		retval = copy.get(i);
		ASSERT_NE(retval, nullptr);
		EXPECT_EQ(retval->data, 10 - i - 1);
	}
}

TEST(LinkedListTests, AddElements) {
	LinkedList ll = LinkedList();
	Node* retval;
	for (int i = 0; i < 10; i++) {
		ll.prepend(i);
		retval = ll.get(0); //front of list is always the most recently prepended val
		EXPECT_EQ(ll.getLength(), i + 1);
		ASSERT_NE(retval, nullptr);
		ASSERT_EQ(retval->data, i);
	}
	EXPECT_EQ(ll.getLength(), 10);
}

TEST(LinkedListTests, RemoveElementsEmpty) {
	LinkedList ll = LinkedList();
	EXPECT_EQ(ll.getLength(), 0);
	ll.remove(1);
	EXPECT_EQ(ll.getLength(), 0);
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

TEST(LinkedListTests, RemoveDupsEmpty) {
	LinkedList ll = LinkedList();
	EXPECT_EQ(ll.getLength(), 0);
	ll.remove_duplicates();
	EXPECT_EQ(ll.getLength(), 0);
	ll.remove_duplicates2();
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
	LinkedList ll_e = LinkedList();

	ll_t.prepend(1);

	ll_f.prepend(1);
	ll_f.prepend(2);
	
	EXPECT_TRUE(ll_t.is_palindrome());
	EXPECT_FALSE(ll_f.is_palindrome());
	EXPECT_FALSE(ll_e.is_palindrome());
}

TEST(LinkedListTests, KthLastElement) {
	LinkedList ll = LinkedList(10);
	for (int i = 1; i <= 10; i++) {
		Node* ret = ll.kth_last_node(i);
		ASSERT_NE(ret, nullptr);
		EXPECT_EQ(ret->data, i-1);
	}
}

TEST(LinkedListTests, KthLastElementException) {
	LinkedList ll = LinkedList(10);
	EXPECT_THROW(ll.kth_last_node(11), OutofBoundsException);
	EXPECT_THROW(ll.kth_last_node(0), invalid_argument);
	EXPECT_THROW(ll.kth_last_node(-1), invalid_argument);
	EXPECT_THROW(ll.kth_last_node(12), OutofBoundsException);
}

TEST(LinkedListTests, TestPartition) {
	LinkedList ll = LinkedList(10);
	int k = 5;
	ll.partition(k);
	EXPECT_TRUE(ll.test_partition(k));

	k = 6;
	ll.partition(k);
	EXPECT_TRUE(ll.test_partition(k));
}

TEST(LinkedListTests, DeleteMiddleNode) {
	LinkedList ll = LinkedList(10);
	Node * retval = ll.kth_last_node(9);
	ASSERT_NE(retval, nullptr);
	ll.delete_middle_node(retval);
	EXPECT_EQ(ll.getLength(), 9);
	EXPECT_FALSE(ll.contains(8));
	EXPECT_TRUE(ll.contains(9));
	for (int i = 0; i < 8; i++) {
		EXPECT_TRUE(ll.contains(i));
	}
}