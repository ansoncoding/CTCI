#include "pch.h"
#include "urlfy.h"

#define SPACE "%20"

void urlfy(string & s, int length){

    int num_space = 0;
    for (int i = 0; i < length; i++) {
        if (s.at(i) == ' ') {
            num_space++;
        }
    }
    int end = length + (num_space << 1);
    end--;
    for (int i = length - 1; i >= 0; i--) {
        if (s.at(i) == ' ') {
            s.replace(end - 2, 3, SPACE);
            end -= 3;
        } else {
            s[end] = s[i];
            end--;
        }
    }
}