#include "pch.h"
#include "is_palindrome_perm.h"

bool is_palindrome_perm(string s) {

    bool counts[128] = { false };
    for (unsigned int i = 0; i < s.length(); i++) {
        int index = s.at(i);
        counts[index] = !counts[index];
    }
    bool oddFound = false;
    for (int i = 0; i < 128; i++) {
        if (counts[i] && oddFound) {
            return false;
        }
        if (counts[i]) {
            oddFound = true;
        }
    }
    return true;
}