#include "is_unique.h"

//#1.1 is string made of unique characters?
bool is_unique(string s) {
    for (int i = 0; i < s.length(); i++){
        for (int j = i + 1; j < s.length(); j++) {
            if (s.at(i) == s.at(j)) {
                printf("string %s: False\n", s.c_str());
                return false;
            }
        }
    }
    printf("string %s: True\n", s.c_str());
    return true;
}

bool is_unique_2(string s) {
    char count[26] = { 0 };
    for (int i = 0; i < s.length(); i++){
        int index = tolower(s.at(i)) - 'a';
        // printf("index %d\n", index);
        if (index >= 26) {
            printf("Error: Character not in range.\n");
            return false;
        }
        if (count[index] >= 1) {
            printf("string %s: False\n", s.c_str());
            return false;
        }
        count[index]++;
    }
    printf("string %s: True\n", s.c_str());
    return true;
}

// Bitwise implementation to save space.
// This is pretty much O(1) space depending on the charset 
// it could be anywhere from 128 to more if we're going beyond ascii but still O(1)
bool is_unique_3(string s) {
    int counts = 0;
    for (int i = 0; i < s.length(); i++) {
        int index = tolower(s.at(i)) - 'a';
        if (index >= 26) {
            printf("Error: Character not in range.\n");
            return false;
        }
        if (counts & (1 << index)) {
            printf("string %s: False\n", s.c_str());
            return false;
        }
        counts |= (1 << index);
    }
    printf("string %s: True\n", s.c_str());
    return true;
}