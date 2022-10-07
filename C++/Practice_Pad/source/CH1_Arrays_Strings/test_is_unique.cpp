#include "pch.h"

#include "is_unique.h"

TEST(IsUnique, TrueCases) {
    EXPECT_TRUE(is_unique("a"));
    EXPECT_TRUE(is_unique("ab"));
    EXPECT_TRUE(is_unique("abcdeg"));
}

TEST(IsUnique, FalseCases) {
    EXPECT_FALSE(is_unique("aa"));
    EXPECT_FALSE(is_unique("abb"));
    EXPECT_FALSE(is_unique("abcccccdeg"));
}

//================== Version 2 =====================

TEST(IsUnique2, TrueCases) {
    EXPECT_TRUE(is_unique_2("a"));
    EXPECT_TRUE(is_unique_2("ab"));
    EXPECT_TRUE(is_unique_2("abcdeg"));
}

TEST(IsUnique2, FalseCases) {
    EXPECT_FALSE(is_unique_2("aa"));
    EXPECT_FALSE(is_unique_2("abb"));
    EXPECT_FALSE(is_unique_2("abcccccdeg"));
}

//================== Version 3 =====================

TEST(IsUnique3, TrueCases) {
    EXPECT_TRUE(is_unique_3("a"));
    EXPECT_TRUE(is_unique_3("ab"));
    EXPECT_TRUE(is_unique_3("abcdeg"));
}

TEST(IsUnique3, FalseCases) {
    EXPECT_FALSE(is_unique_3("aa"));
    EXPECT_FALSE(is_unique_3("abb"));
    EXPECT_FALSE(is_unique_3("abcccccdeg"));
}
