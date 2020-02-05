#include "pch.h"
#include "is_string_rotation.h"

TEST(Substring, TrueCases) {
    EXPECT_TRUE(is_substring("a", "a"));
    EXPECT_TRUE(is_substring("ab", "a"));
    EXPECT_TRUE(is_substring("ab", "b"));
    EXPECT_TRUE(is_substring("abc", "bc"));
    EXPECT_TRUE(is_substring("abc", "ab"));
    EXPECT_TRUE(is_substring("the ", " "));
    EXPECT_TRUE(is_substring("the ", "e "));
}

TEST(Substring, FalseCases) {
    EXPECT_FALSE(is_substring("", "a"));
    EXPECT_FALSE(is_substring("a", "ab"));
    EXPECT_FALSE(is_substring("amanda", "dad"));
    EXPECT_FALSE(is_substring("ashley", "ushley"));
    EXPECT_FALSE(is_substring("annie", "annen"));
    EXPECT_FALSE(is_substring("the ", " e"));
}

TEST(StringRotation, TrueCases) {
    EXPECT_TRUE(is_string_rotation("a", "a"));
    EXPECT_TRUE(is_string_rotation("ab", "ba"));
    EXPECT_TRUE(is_string_rotation("abc", "bca"));
    EXPECT_TRUE(is_string_rotation("abc", "cab"));
    EXPECT_TRUE(is_string_rotation("waterbottle", "terbottlewa"));
}

TEST(StringRotation, FalseCases) {
    EXPECT_FALSE(is_string_rotation("", "a"));
    EXPECT_FALSE(is_string_rotation("ab", "bac"));
    EXPECT_FALSE(is_string_rotation("abcaaa", "abcaaA"));
    EXPECT_FALSE(is_string_rotation("abc", "acb"));
    EXPECT_FALSE(is_string_rotation("waterbottle", "aterbottlewa"));
}
