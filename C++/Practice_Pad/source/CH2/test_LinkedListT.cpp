#include "pch.h"
#include "LinkedListT.h"

TEST(LinkedListTTests, CircularLL) {
	LinkedListT llt = LinkedListT(10, true);
	Node* retval = nullptr;
	EXPECT_TRUE(llt.contains_loop(retval));
	//ASSERT_NE(retval, nullptr);
	//EXPECT_EQ(retval->data, 10);
}