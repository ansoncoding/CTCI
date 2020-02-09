#include "pch.h"
#include "LinkedListQueue.h"
#include "practice_exceptions.h"

TEST(LinkedListQ_IntegerTests, Init) {
	//Empty
	LinkedListQ<int> llt = LinkedListQ<int>();
	EXPECT_EQ(llt.getSize(), 0);
}

TEST(LinkedListQ_IntegerTests, CopyConstructor) {
	LinkedListQ<int> ll = LinkedListQ<int>();
	for (int i = 0; i < 10; i++) {
		ll.append(i);
		EXPECT_EQ(ll.peek(), 0);
	}
	
	LinkedListQ<int> copy(ll);
		
	EXPECT_EQ(copy.getSize(), 10);
	for (int i = 0; i < 10; i++) {
		EXPECT_EQ(ll.peek(), i);
		ll.remove();
	}
}

TEST(LinkedListQ_IntegerTests, AssignmentOperator) {
	LinkedListQ<int> ll = LinkedListQ<int>();
	for (int i = 0; i < 10; i++) {
		ll.append(i);
		EXPECT_EQ(ll.peek(), 0);
	}

	LinkedListQ<int> copy = ll;

	EXPECT_EQ(copy.getSize(), 10);
	for (int i = 0; i < 10; i++) {
		EXPECT_EQ(ll.peek(), i);
		ll.remove();
	}
}

TEST(LinkedListQ_IntegerTests, AddRemoveElements) {
	LinkedListQ<int> ll = LinkedListQ<int>();

	for (int i = 0; i < 10; i++) {
		ll.append(i);
		EXPECT_EQ(ll.getSize(), i + 1);
		EXPECT_EQ(ll.peek(), 0);		
	}

	EXPECT_EQ(ll.getSize(), 10);
	for (int i = 0; i < 10; i++) {
		EXPECT_EQ(ll.peek(), i);
		ll.remove();
	}
}

TEST(LinkedListQ_IntegerTests, AddRemoveMoreElements) {
	LinkedListQ<int> ll = LinkedListQ<int>();

	for (int i = 0; i < 100; i++) {
		ll.append(i);
		EXPECT_EQ(ll.getSize(), i + 1);
		EXPECT_EQ(ll.peek(), 0);
	}

	EXPECT_EQ(ll.getSize(), 100);
	for (int i = 0; i < 100; i++) {
		EXPECT_EQ(ll.peek(), i);
		ll.remove();
	}
}

TEST(LinkedListQ_IntegerTests, RemoveElementsEmpty) {
	LinkedListQ<int> l = LinkedListQ<int>();
	EXPECT_EQ(l.getSize(), 0);
	EXPECT_THROW(l.remove(), OutofBoundsException);

	for (int i = 0; i < 10; i++) {
		l.append(i);
	}
	for (int i = 0; i < 10; i++) {
		l.remove();
	}
	EXPECT_THROW(l.remove(), OutofBoundsException);
}
