#include "pch.h"
#include "is_permutation.h"

TEST(IsPermutation, TrueCases) {
    EXPECT_TRUE(is_permutation("", ""));
    EXPECT_TRUE(is_permutation("a", "a"));
    EXPECT_TRUE(is_permutation("ba", "ab"));
    EXPECT_TRUE(is_permutation("cba", "abc"));
    EXPECT_TRUE(is_permutation("cbac", "cabc"));
    EXPECT_TRUE(is_permutation("cbac", "ccab"));
}

TEST(IsPermutation, DiffLengths) {
    EXPECT_FALSE(is_permutation("a", ""));
    EXPECT_FALSE(is_permutation("ba", "abb"));
    EXPECT_FALSE(is_permutation("cba", "ab"));
    EXPECT_FALSE(is_permutation("cbac", "cabca"));
}

TEST(IsPermutation, NotPermutation) {
    EXPECT_FALSE(is_permutation("a", "b"));
    EXPECT_FALSE(is_permutation("ba", "ac"));
    EXPECT_FALSE(is_permutation("cba", "abb"));
    EXPECT_FALSE(is_permutation("cbac", "cbcc"));
}

TEST(IsPermutation, InvalidInput) {
    EXPECT_FALSE(is_permutation("A", "b"));
    EXPECT_FALSE(is_permutation(".", "c"));
    EXPECT_FALSE(is_permutation("#", "2"));
    EXPECT_FALSE(is_permutation("_c", "c/"));
}
// ===================== Version 2 ======================

TEST(IsPermutation2, TrueCases) {
    EXPECT_TRUE(is_permutation_2("", ""));
    EXPECT_TRUE(is_permutation_2("a", "a"));
    EXPECT_TRUE(is_permutation_2("ba", "ab"));
    EXPECT_TRUE(is_permutation_2("cba", "abc"));
    EXPECT_TRUE(is_permutation_2("cbac", "cabc"));
    EXPECT_TRUE(is_permutation_2("cbac", "ccab"));
}

TEST(IsPermutation2, DiffLengths) {
    EXPECT_FALSE(is_permutation_2("a", ""));
    EXPECT_FALSE(is_permutation_2("ba", "abb"));
    EXPECT_FALSE(is_permutation_2("cba", "ab"));
    EXPECT_FALSE(is_permutation_2("cbac", "cabca"));
}

TEST(IsPermutation2, NotPermutation) {
    EXPECT_FALSE(is_permutation_2("a", "b"));
    EXPECT_FALSE(is_permutation_2("ba", "ac"));
    EXPECT_FALSE(is_permutation_2("cba", "abb"));
    EXPECT_FALSE(is_permutation_2("cbac", "cbcc"));
}


