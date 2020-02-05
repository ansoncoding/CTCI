#include "pch.h"
#include "is_permutation.h"

#include <iostream>

//#1.2 are string 1 and string 2 permutations of each other?
bool is_permutation(string s1, string s2) {
    char count[26] = { 0 };
    if (s1.length() != s2.length()){
        //printf("string %s and %s: False\n", s1.c_str(), s2.c_str());
        return false;
    }
    for (int i = 0; i < s1.length(); i++){
        unsigned int index = tolower(s1.at(i)) - 'a';
        // printf("index %d\n", index);
        if (index >= 26) {
            cerr << "Error: Character not in range." << endl;
            return false;
        }
        count[index]++;
    }
    for (int i = 0; i < s2.length(); i++) {
        unsigned int index = tolower(s2.at(i)) - 'a';
        if (index >= 26) {
            cerr << "Error: Character not in range." << endl;
            return false;
        }
        count[index]--;
        if (count[index] < 0) {
            //printf("string %s and %s: False\n", s1.c_str(), s2.c_str());
            return false;
        }
    }
    //printf("string %s and %s: True\n", s1.c_str(), s2.c_str());
    return true;
}

// Use sorting to save space
bool is_permutation_2(string s1, string s2) {
    //printf("%s and %s ", s1.c_str(), s2.c_str());
    if (s1.length() != s2.length()) {
      //  printf("False\n");
        return false;
    }
    sortString(s1);
    sortString(s2);
    for (int i = 0; i < s1.length(); i++) {
        if (s1[i] != s2[i]) {
        //    printf("False\n");
            return false;
        }
    }
    //printf("True\n");
    return true;
}