#include "pch.h"

#include "is_unique.h"

#include <iostream>

//#1.1 is string made of unique characters?
bool is_unique(string s) {
    for (unsigned int i = 0; i < s.length(); i++){
        for (unsigned int j = i + 1; j < s.length(); j++) {
            if (s.at(i) == s.at(j)) {
                return false;
            }
        }
    }
    return true;
}

bool is_unique_2(string s) {
    char count[26] = { 0 };
    for (unsigned int i = 0; i < s.length(); i++){
        unsigned int index = tolower(s.at(i)) - 'a';

        if (index >= 26) {
            cerr << "Error: Character not in range." << endl;
            return false;
        }
        if (count[index] >= 1) {

            return false;
        }
        count[index]++;
    }

    return true;
}

// Bitwise implementation to save space.
// This is pretty much O(1) space depending on the charset 
// it could be anywhere from 128 to more if we're going beyond ascii but still O(1)
bool is_unique_3(string s) {
    int counts = 0;
    for (unsigned int i = 0; i < s.length(); i++) {
        unsigned int index = tolower(s.at(i)) - 'a';
        if (index >= 26) {
            cerr << "Error: Character not in range." << endl;
            return false;
        }
        if (counts & (1 << index)) {

            return false;
        }
        counts |= (1 << index);
    }

    return true;
}