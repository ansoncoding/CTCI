#include "pch.h"

#include "is_one_edit.h"

bool is_one_edit(string s1, string s2) {

    int len1 = s1.length();
    int len2 = s2.length();
    int abs_len_diff = abs(len1 - len2);

    if (abs_len_diff > 1) {
        
        return false;
    }

    if (abs_len_diff == 0) {
        bool diffFound = false;
        for (int i = 0; i < len1; i++) {
            if (s1.at(i) != s2.at(i)) {
                if (diffFound) {
                    
                    return false;
                }
                diffFound = true;
            }
        }
        
        return true;
    }
    else {
        bool skipped = false;
        int j = 0;
        int shorter_len = (len1 > len2) ? len2 : len1;
        for (int i = 0; i < shorter_len; i) {

            if (s1.at(i) != s2.at(j)) {
                if (skipped) {
                    
                    return false;
                }

                skipped = true;
                if (len1 > len2) {
                    i++;
                }
                else {
                    j++;
                }
            }
            else {
                i++;
                j++;
            }
        }
        
        return true;
    }
}