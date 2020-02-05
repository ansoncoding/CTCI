#include "pch.h"
#include "is_one_edit.h"

TEST(IsOneEdit, TrueLenDiff) {
    
    EXPECT_TRUE(is_one_edit("a", ""));
    EXPECT_TRUE(is_one_edit("a", "ab"));
    EXPECT_TRUE(is_one_edit("ab", "abc"));
    EXPECT_TRUE(is_one_edit("ab", "cab"));
    EXPECT_TRUE(is_one_edit("abc", "bc"));
}

TEST(IsOneEdit, TrueCharDiff) {
    EXPECT_TRUE(is_one_edit("abc", "abd"));
    EXPECT_TRUE(is_one_edit("abc", "dbc"));
}

TEST(IsOneEdit, TrueNoDiff) {
    EXPECT_TRUE(is_one_edit("abc", "abc"));
    EXPECT_TRUE(is_one_edit("ttt", "ttt"));
}

TEST(IsOneEdit, FalseLenDiff) {
    EXPECT_FALSE(is_one_edit("ab", ""));
    EXPECT_FALSE(is_one_edit("a", "abb"));
    EXPECT_FALSE(is_one_edit("ab", "abcd"));
    EXPECT_FALSE(is_one_edit("aaab", "aa"));
}

TEST(IsOneEdit, FalseCharDiff) {
    EXPECT_FALSE(is_one_edit("ab", "ba"));
    EXPECT_FALSE(is_one_edit("abc", "acb"));
}
