#include "pch.h"
#include "urlfy.h"

TEST(URLify, EdgeCases) {
    
    string e = "";
    urlfy(e, 0);
    EXPECT_STREQ(e.c_str(), "");
    
    string a = "a";
    urlfy(a, 1);
    EXPECT_STREQ(a.c_str(), "a");

    string aa = "aa";
    urlfy(aa, 2);
    EXPECT_STREQ(aa.c_str(), "aa");

    string space_a = " a  ";
    urlfy(space_a, 2);
    EXPECT_STREQ(space_a.c_str(), "%20a");
}

TEST(URLify, RegularCases) {

    string john = "john is awesome    ";
    urlfy(john, 15);
    EXPECT_STREQ(john.c_str(), "john%20is%20awesome");

    string oh = "oh look!  ";
    urlfy(oh, 8);
    EXPECT_STREQ(oh.c_str(), "oh%20look!");

    string complex = " oh my darling it's a beautiful day isn't it                  ";
    urlfy(complex, 44);
    EXPECT_STREQ(complex.c_str(), "%20oh%20my%20darling%20it's%20a%20beautiful%20day%20isn't%20it");
}