#include "is_one_edit.h"

bool is_one_edit(string s1, string s2) {
    int len1 = s1.length();
    int len2 = s2.length();
    int abs_len_diff = abs(len1 - len2);

    cout << s1 << " " << s2 ;

    if (abs_len_diff > 1) {
        cout << " False" << endl;
        return false;
    }

    if (abs_len_diff == 0) {
        bool diffFound = false;
        for (int i = 0; i < len1; i++) {
            if (s1.at(i) != s2.at(i)) {
                if (diffFound) {
                    cout << " False" << endl;
                    return false;
                }
                diffFound = true;
            }
        }
        cout << " True" << endl;
        return true;
    }
    else {
        bool skipped = false;
        int j = 0;
        int shorter_len = (len1 > len2) ? len2 : len1;
        for (int i = 0; i < shorter_len; i) {
            //cout << endl << i << " " << j << endl;
            if (s1.at(i) != s2.at(j)) {
                if (skipped) {
                    cout << " False" << endl;
                    return false;
                }
                //cout << "\nskipped\n";
                skipped = true;
                if (len1 > len2) {
                    
                    i++;
                    //cout << endl << i << endl;
                }
                else {
                    j++;
                    //cout << endl << j << endl;
                }
            }
            else {
                i++;
                j++;
            }
        }
        cout << " True" << endl;
        return true;
    }
}