#include "pch.h"
#include "compress_string.h"

TEST(CompressString, EdgeCases) {
    EXPECT_STREQ(compress_string("").c_str(), "");
    EXPECT_STREQ(compress_string("a").c_str(), "a");
    EXPECT_STREQ(compress_string("ab").c_str(), "ab");
    EXPECT_STREQ(compress_string("abc").c_str(), "abc");
    EXPECT_STREQ(compress_string("Aabbccc").c_str(), "Aabbccc");
}

TEST(CompressString, RegularCases) {
    EXPECT_STREQ(compress_string("aaabb").c_str(), "a3b2");
    EXPECT_STREQ(compress_string("aaaabbbbccc").c_str(), "a4b4c3");
    EXPECT_STREQ(compress_string("AAAaabbbbccc").c_str(), "A3a2b4c3");
}