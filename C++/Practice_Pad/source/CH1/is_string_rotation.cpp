#include "pch.h"
#include "is_string_rotation.h"

// find out if
bool is_substring(string src, string substr) {
    int len_src = src.length();
    int len_substr = substr.length();
    if (len_substr > len_src) {
        return false;
    }
    int len_diff = len_src - len_substr;
    
    for (int i = 0; i < len_diff+1; i++) {
        string test = src.substr(i, len_substr);

        if (test.compare(substr) == 0)
            return true;
    }
    return false;
}

bool is_string_rotation(string s1, string s2) {
    int len_s1 = s1.length();
    int len_s2 = s2.length();
    if (len_s1 != len_s2){
        return false;
    }
    string r = s1 + s1;

    return (is_substring(r, s2));
}