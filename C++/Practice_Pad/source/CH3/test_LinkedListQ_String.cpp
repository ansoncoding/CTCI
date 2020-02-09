#include "pch.h"
#include "LinkedListQueue.h"
#include "practice_exceptions.h"
#include <string>

using namespace std;

const string d12[] = { "These", "are", "the", "strings", "I", "want", "to", "insert", "into", "the", "list", "." };
const string d33[] = {
		"These", "are", "the", "strings", "I", "want", "to", "insert", "into", "the", "linkedlist", ".",
		"Here", "are", "some", "more", "to", "test", "the", "linked", "list", "mechanism", "!",
		"1", "2", "some", "numbers", "provide", "more", "data", "variety", "3", "4" };

TEST(LinkedListQ_StringTests, Init) {
	//Empty
	LinkedListQ<string> llt = LinkedListQ<string>();
	EXPECT_EQ(llt.getSize(), 0);
}

TEST(LinkedListQ_StringTests, CopyConstructor) {

	LinkedListQ<string> ll = LinkedListQ<string>();
	for (int i = 0; i < 12; i++) {
		ll.append(d12[i]);
		EXPECT_STREQ(ll.peek().c_str(), d12[0].c_str());
	}
	
	LinkedListQ<string> copy(ll);
		
	EXPECT_EQ(copy.getSize(), 12);
	for (int i = 0; i < 12; i++) {
		EXPECT_STREQ(ll.peek().c_str(), d12[i].c_str());
		ll.remove();
	}
}

TEST(LinkedListQ_StringTests, AssignmentOperator) {
	LinkedListQ<string> ll = LinkedListQ<string>();
	for (int i = 0; i < 12; i++) {
		ll.append(d12[i]);
		EXPECT_STREQ(ll.peek().c_str(), d12[0].c_str());
	}

	LinkedListQ<string> copy = ll;

	EXPECT_EQ(copy.getSize(), 12);
	for (int i = 0; i < 12; i++) {
		EXPECT_STREQ(ll.peek().c_str(), d12[i].c_str());
		ll.remove();
	}
}

TEST(LinkedListQ_StringTests, AddRemoveElements) {
	LinkedListQ<string> ll = LinkedListQ<string>();

	for (int i = 0; i < 12; i++) {
		ll.append(d12[i]);
		EXPECT_EQ(ll.getSize(), i + 1);
	}

	EXPECT_EQ(ll.getSize(), 12);
	for (int i = 0; i < 12; i++) {
		EXPECT_STREQ(ll.peek().c_str(), d12[i].c_str());
		ll.remove();
	}
}

TEST(LinkedListQ_StringTests, AddRemoveMoreElements) {
	LinkedListQ<string> ll = LinkedListQ<string>();

	for (int i = 0; i < 33; i++) {
		ll.append(d33[i]);
		EXPECT_EQ(ll.getSize(), i + 1);
		EXPECT_STREQ(ll.peek().c_str(), d33[0].c_str());
	}

	EXPECT_EQ(ll.getSize(), 33);
	for (int i = 0; i < 33; i++) {
		EXPECT_STREQ(ll.peek().c_str(), d33[i].c_str());
		ll.remove();
	}
}

TEST(LinkedListQ_StringTests, RemoveElementsEmpty) {
	LinkedListQ<string> l = LinkedListQ<string>();
	EXPECT_EQ(l.getSize(), 0);
	EXPECT_THROW(l.remove(), OutofBoundsException);

	for (int i = 0; i < 12; i++) {
		l.append(d12[i]);
	}
	for (int i = 0; i < 12; i++) {
		l.remove();
	}
	EXPECT_THROW(l.remove(), OutofBoundsException);
}
