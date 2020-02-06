#include "pch.h"
#include "LinkedList.h"

TEST(LinkedListTests, Init) {
	LinkedList ll = LinkedList();
	EXPECT_EQ(ll.getLength(), 0);

}