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
	EXPECT_EQ(llt.getLength(), 5);
	for (int i = 0; i < 5; i++) {
		EXPECT_TRUE(llt.contains(d[i]));
		retval = llt.get(i);
		ASSERT_NE(retval, nullptr);
		EXPECT_EQ(retval->data, d[i]);
	}
}

TEST(LinkedListTTests, CopyConstructor) {
	LinkedListT ll = LinkedListT(10);
	LinkedListT copy(ll);

	Node* retval;
	EXPECT_EQ(copy.getLength(), 10);
	for (int i = 0; i < 10; i++) {
		EXPECT_TRUE(copy.contains(i));
		retval = copy.get(i);
		ASSERT_NE(retval, nullptr);
		EXPECT_EQ(retval->data, i);
	}
}

TEST(LinkedListTTests, AssignmentOperator) {
	LinkedListT ll = LinkedListT(10);
	LinkedListT copy = ll;

	Node* retval;
	EXPECT_EQ(copy.getLength(), 10);
	for (int i = 0; i < 10; i++) {
		EXPECT_TRUE(copy.contains(i));
		retval = copy.get(i);
		ASSERT_NE(retval, nullptr);
		EXPECT_EQ(retval->data, i);
	}
}

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

TEST(LinkedListTTests, RemoveElementsEmpty) {
	LinkedListT l = LinkedListT();
	EXPECT_EQ(l.getLength(), 0);
	l.remove(1);
	EXPECT_EQ(l.getLength(), 0);
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

TEST(LinkedListTTests, RemoveDupsEmpty) {
	LinkedListT l = LinkedListT();
	EXPECT_EQ(l.getLength(), 0);
	l.remove_duplicates();
	EXPECT_EQ(l.getLength(), 0);
	l.remove_duplicates2();
	EXPECT_EQ(l.getLength(), 0);
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

TEST(LinkedListTTests, CircularLLTrue) {
	LinkedListT llt = LinkedListT(10, true);
	Node* retval = nullptr;
	EXPECT_TRUE(llt.contains_loop(retval));
	ASSERT_NE(retval, nullptr);
	EXPECT_EQ(retval->data, 0);
}

TEST(LinkedListTTests, CircularLLFalse) {
	LinkedListT llt = LinkedListT();
	LinkedListT llt2 = LinkedListT(10);
	LinkedListT llt3 = LinkedListT();
	llt3.append(5);

	Node* retval,  *retval2, *retval3;
	
	EXPECT_FALSE(llt.contains_loop(retval));
	EXPECT_FALSE(llt2.contains_loop(retval2));
	EXPECT_FALSE(llt3.contains_loop(retval3));

}

TEST(LinkedListTTests, SumListsEmpty) {
	LinkedListT llt = LinkedListT();
	LinkedListT llt2 = LinkedListT();
	LinkedListT sum = llt.sum_lists(llt2);
	EXPECT_EQ(sum.getLength(), 0);
}

TEST(LinkedListTTests, SumLists) {
	//2 digits
	int a1[] = { 1, 2 };
	int b1[] = { 2, 3 };
	int s1[] = { 3, 5 };
	LinkedListT l1 = LinkedListT(a1, 2);
	LinkedListT l2 = LinkedListT(b1, 2);
	LinkedListT soln = LinkedListT(s1, 2);
	LinkedListT sum = l1.sum_lists(l2);
	EXPECT_TRUE(sum.compare(soln));


	// 3 digits
	int a2[] = { 1, 2, 4 };
	int b2[] = { 2, 3, 1 };
	int s2[] = { 3, 5, 5 };

	l1 = LinkedListT(a2, 3);
	l2 = LinkedListT(b2, 3);
	soln = LinkedListT(s2, 3);
	sum = l1.sum_lists(l2);
	EXPECT_TRUE(sum.compare(soln));

	// with carry
	int a3[] = { 9, 2, 4 };
	int b3[] = { 2, 3, 7 };
	int s3[] = { 1, 6, 1, 1 };

	l1 = LinkedListT(a3, 3);
	l2 = LinkedListT(b3, 3);
	soln = LinkedListT(s3, 4);
	sum = l1.sum_lists(l2);
	EXPECT_TRUE(sum.compare(soln));

	//addends are not the same lengths
	int a4[] = { 9, 2, 4, 2, 5, 7 };
	int b4[] = { 5, 3, 7 };
	int s4[] = { 4, 6, 1, 3, 5, 7 };

	l1 = LinkedListT(a4, 6);
	l2 = LinkedListT(b4, 3);
	soln = LinkedListT(s4, 6);
	sum = l1.sum_lists(l2);
	EXPECT_TRUE(sum.compare(soln));

	//addends are not the same lengths swapped 
	int a5[] = { 9, 2, 4, 2 };
	int b5[] = { 5, 9, 7, 8, 0, 1 };
	int s5[] = { 4, 2, 2, 1, 1, 1 };

	l1 = LinkedListT(a5, 4);
	l2 = LinkedListT(b5, 6);
	soln = LinkedListT(s5, 6);
	sum = l1.sum_lists(l2);
	EXPECT_TRUE(sum.compare(soln));

	//zeros
	int a6[] = { 0, 0, 0 };
	int b6[] = { 0, 0, 0, 0, 0 };

	l1 = LinkedListT(a6, 3);
	l2 = LinkedListT(b6, 5);
	soln = LinkedListT(b6, 5);
	sum = l1.sum_lists(l2);
	EXPECT_TRUE(sum.compare(soln));
}

TEST(LinkedListTTests, IsIntersectingEmpty) {
	LinkedListT l1 = LinkedListT();
	LinkedListT l2 = LinkedListT();
	Node* retval;
	EXPECT_FALSE(l1.is_intersecting(l2, retval));
	EXPECT_FALSE(l2.is_intersecting(l1, retval));
}

TEST(LinkedListTTests, IsIntersectingFalse) {
	LinkedListT l1 = LinkedListT(20);
	LinkedListT l2 = LinkedListT(11);
	Node* retval;
	EXPECT_FALSE(l1.is_intersecting(l2, retval));
	EXPECT_FALSE(l2.is_intersecting(l1, retval));
}

TEST(LinkedListTTests, IsIntersectingMid) {
	LinkedListT l1 = LinkedListT(5);
	LinkedListT l2 = LinkedListT(10);
	
	Node* middle = l2.get(5);
	Node* retval;

	ASSERT_NE(middle, nullptr);
	l1.setTailNext(middle);
	EXPECT_TRUE(l1.is_intersecting(l2, retval));
	ASSERT_NE(retval, nullptr);
	EXPECT_EQ(retval->data, 5);

	//test associativity
	Node* retval2;
	EXPECT_TRUE(l2.is_intersecting(l1, retval2));
	ASSERT_NE(retval2, nullptr);
	EXPECT_EQ(retval2->data, 5);
}

TEST(LinkedListTTests, IsIntersectingBeg) {
	LinkedListT l1 = LinkedListT(5);
	LinkedListT l2 = LinkedListT(10);

	Node* begin= l2.get(0);
	Node* retval;

	ASSERT_NE(begin, nullptr);
	l1.setTailNext(begin);
	EXPECT_TRUE(l1.is_intersecting(l2, retval));
	ASSERT_NE(retval, nullptr);
	EXPECT_EQ(retval->data, 0);

	//test associativity
	Node* retval2;
	EXPECT_TRUE(l2.is_intersecting(l1, retval2));
	ASSERT_NE(retval2, nullptr);
	EXPECT_EQ(retval2->data, 0);
}

TEST(LinkedListTTests, IsIntersectingTail) {
	LinkedListT l1 = LinkedListT(5);
	LinkedListT l2 = LinkedListT(10);

	Node* tail = l2.get(9);
	Node* retval;

	ASSERT_NE(tail, nullptr);
	l1.setTailNext(tail);
	EXPECT_TRUE(l1.is_intersecting(l2, retval));
	ASSERT_NE(retval, nullptr);
	EXPECT_EQ(retval->data, 9);

	//test associativity
	Node* retval2;
	EXPECT_TRUE(l2.is_intersecting(l1, retval2));
	ASSERT_NE(retval2, nullptr);
	EXPECT_EQ(retval2->data, 9);
}

