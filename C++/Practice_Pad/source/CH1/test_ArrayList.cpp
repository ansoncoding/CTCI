#include "pch.h"
#include "ArrayList.h"

TEST(TestCaseName, TestName) {
    ArrayList al = ArrayList();
    EXPECT_EQ(al.getSize(), 0);
}