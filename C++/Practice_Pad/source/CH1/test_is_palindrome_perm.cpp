#include "pch.h"
#include "is_palindrome_perm.h"

TEST(IsPalindromePerm, TruePalindromeOdd) {
    
    EXPECT_TRUE(is_palindrome_perm("a"));
    EXPECT_TRUE(is_palindrome_perm("aba"));
    EXPECT_TRUE(is_palindrome_perm("abcba"));
    EXPECT_TRUE(is_palindrome_perm("AabcbaA"));
}

TEST(IsPalindromePerm, TruePalindromeEven) {

    EXPECT_TRUE(is_palindrome_perm("aa"));
    EXPECT_TRUE(is_palindrome_perm("abba"));
    EXPECT_TRUE(is_palindrome_perm("abccba"));
    EXPECT_TRUE(is_palindrome_perm("AabccbaA"));
}

TEST(IsPalindromePerm, TruePalindromeOddPerm) {

    EXPECT_TRUE(is_palindrome_perm("aab"));
    EXPECT_TRUE(is_palindrome_perm("abbac"));
    EXPECT_TRUE(is_palindrome_perm("AaAbcba"));
}

TEST(IsPalindromePerm, TruePalindromeEvenPerm) {

    EXPECT_TRUE(is_palindrome_perm("abab"));
    EXPECT_TRUE(is_palindrome_perm("abcabc"));
    EXPECT_TRUE(is_palindrome_perm("AacbaAbc"));
}

TEST(IsPalindromePerm, FalseCases) {
    EXPECT_FALSE(is_palindrome_perm("ab"));
    EXPECT_FALSE(is_palindrome_perm("abc"));
    EXPECT_FALSE(is_palindrome_perm("abcd"));
    EXPECT_FALSE(is_palindrome_perm("cherry"));
    EXPECT_FALSE(is_palindrome_perm("cherrypie"));
}