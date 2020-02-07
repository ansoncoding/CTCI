#include "pch.h"
#include "LinkedListT.h"
#include "practice_exceptions.h"

TEST(LinkedListTTests, Init) {
	//Empty
	LinkedListT llt = LinkedListT();
	EXPECT_EQ(llt.getLength(), 0);

	//values 0 - 10
	llt = LinkedListT(10);
	EXPECT_EQ(llt.getLength(), 10);
	
	Node* retval;
	for (int i = 0; i < 10; i++) {
		EXPECT_TRUE(llt.contains(i));
		retval = llt.get(i);
		ASSERT_NE(retval, nullptr);
		EXPECT_EQ(retval->data, i);
	}

	// custom vals
	int d[] = { 1,3,6,9,88 };
	llt = LinkedListT(d, 5);
	EXPECT_TRUE(llt.getLength(), 5);
	for (int i = 0; i < 5; i++) {
		EXPECT_TRUE(llt.contains(d[i]));
		retval = llt.get(i);
		ASSERT_NE(retval, nullptr);
		EXPECT_EQ(retval->data, d[i]);
	}
}
#if 1
TEST(LinkedListTTests, PrependElements) {
	LinkedListT llt = LinkedListT();
	Node* retval;
	for (int i = 0; i < 10; i++) {
		llt.prepend(i);
		EXPECT_EQ(llt.getLength(), i + 1);
		retval = llt.get(0); //front of list should always be the value just appended.
		ASSERT_NE(retval, nullptr);
		ASSERT_EQ(retval->data, i);
	}
	EXPECT_EQ(llt.getLength(), 10);
}

TEST(LinkedListTTests, AppendElements) {
	LinkedListT llt = LinkedListT();
	Node* retval;
	for (int i = 0; i < 10; i++) {
		llt.append(i);
		EXPECT_EQ(llt.getLength(), i + 1);
		retval = llt.get(i); //the current index of list should be the value just appended
		ASSERT_NE(retval, nullptr);
		ASSERT_EQ(retval->data, i);
	}
	EXPECT_EQ(llt.getLength(), 10);
}

TEST(LinkedListTTests, RemoveElements) {
	LinkedListT llt = LinkedListT();
	for (int i = 0; i < 10; i++) {
		llt.prepend(i);
		EXPECT_TRUE(llt.contains(i));
		EXPECT_EQ(llt.getLength(), i + 1);
	}
	for (int i = 0; i < 10; i++) {
		llt.remove(i);
		EXPECT_FALSE(llt.contains(i));
		EXPECT_EQ(llt.getLength(), 10 - i - 1);
	}
	EXPECT_EQ(llt.getLength(), 0);
}

TEST(LinkedListTTests, RemoveDups) {
	LinkedListT llt = LinkedListT();
	LinkedListT soln = LinkedListT();
	for (int i = 0; i < 10; i++) {
		llt.prepend(i);
		llt.prepend(i);
		soln.prepend(i);
	}
	llt.remove_duplicates();
	EXPECT_TRUE(llt.compare(soln));
}

TEST(LinkedListTTests, RemoveDups2) {
	LinkedListT llt = LinkedListT();
	LinkedListT soln = LinkedListT();
	for (int i = 0; i < 10; i++) {
		llt.prepend(i);
		llt.prepend(i);
		soln.prepend(i);
	}
	llt.remove_duplicates2();
	EXPECT_TRUE(llt.compare(soln));
}

TEST(LinkedListTTests, Palindrome) {
	LinkedListT llt_t = LinkedListT();
	LinkedListT llt_f = LinkedListT();
	for (int i = 0; i < 5; i++) {
		llt_t.prepend(i);
		llt_t.append(i);
		llt_f.prepend(i);
	}
	
	EXPECT_TRUE(llt_t.is_palindrome());
	EXPECT_FALSE(llt_f.is_palindrome());
}

TEST(LinkedListTTests, PalindromeOddLength) {
	LinkedListT llt_t = LinkedListT();
	LinkedListT llt_f = LinkedListT();
	for (int i = 0; i < 5; i++) {
		llt_t.prepend(i);
		llt_f.prepend(i);
	}
	for (int i = 3; i >= 0; i--) {
		llt_t.prepend(i);
		llt_f.prepend(i);
	}
	llt_f.prepend(0);
	EXPECT_TRUE(llt_t.is_palindrome());
	EXPECT_FALSE(llt_f.is_palindrome());
}

TEST(LinkedListTTests, PalindromeEdgeCases) {
	LinkedListT llt_t = LinkedListT();
	LinkedListT llt_f = LinkedListT();
	LinkedListT llt_e = LinkedListT();

	llt_t.prepend(1);

	llt_f.prepend(1);
	llt_f.prepend(2);

	EXPECT_TRUE(llt_t.is_palindrome());
	EXPECT_FALSE(llt_f.is_palindrome());
	EXPECT_FALSE(llt_e.is_palindrome());
}

TEST(LinkedListTTests, KthLastElement) {
	LinkedListT llt = LinkedListT(10);
	for (int i = 1; i <= 10; i++) {
		Node* ret = llt.kth_last_node(i);
		ASSERT_NE(ret, nullptr);
		EXPECT_EQ(ret->data, 10-i);
	}
}

TEST(LinkedListTTests, KthLastElementException) {
	LinkedListT llt = LinkedListT(10);
	EXPECT_THROW(llt.kth_last_node(11), OutofBoundsException);
	EXPECT_THROW(llt.kth_last_node(0), invalid_argument);
	EXPECT_THROW(llt.kth_last_node(-1), invalid_argument);
	EXPECT_THROW(llt.kth_last_node(12), OutofBoundsException);
}

TEST(LinkedListTTests, TestPartition) {
	LinkedListT llt = LinkedListT(10);
	int k = 5;
	llt.partition(k);
	EXPECT_TRUE(llt.test_partition(k));

	k = 6;
	llt.partition(k);
	EXPECT_TRUE(llt.test_partition(k));
}

TEST(LinkedListTTests, DeleteMiddleNode) {
	LinkedListT llt = LinkedListT(10); // list contains vals 0 - 9
	Node* retval = llt.kth_last_node(9); // value is 1
	ASSERT_NE(retval, nullptr);

	llt.delete_middle_node(retval);  // list contains vals 0, 2 - 9

	EXPECT_EQ(llt.getLength(), 9);
	EXPECT_FALSE(llt.contains(1));
	EXPECT_TRUE(llt.contains(0));
	for (int i = 2; i < 10; i++) {
		EXPECT_TRUE(llt.contains(i));
	}
}

TEST(LinkedListTTests, CircularLL) {
	LinkedListT llt = LinkedListT(10, true);
	Node* retval = nullptr;
	EXPECT_TRUE(llt.contains_loop(retval));
	ASSERT_NE(retval, nullptr);
	EXPECT_EQ(retval->data, 0);
}

TEST(LinkedListTTests, SumLists) {
	int d1[] = { 1,2 };
	int d2[] = { 2,3 };
	int s[] = { 3, 5 };
	LinkedListT l1 = LinkedListT(d1, 2);
	LinkedListT l2 = LinkedListT(d2, 2);
	LinkedListT soln = LinkedListT(s, 2);
	LinkedListT * sum = l1.sum_lists(l2);
	EXPECT_TRUE(sum->compare(soln));
}
#endif