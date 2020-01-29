#include "urlfy.h"

#define SPACE "%20"

void urlfy(string & s, int length) {

    cout << "Begin " << s << endl;
    for (int i = 0; i < length; i++) {
        if (s.at(i) == ' ') {
            string rest = s.substr(i + 1);
            s.replace(i + 3, length - i-1, rest);
            //cout << s << endl;
            s.replace(i, 3, SPACE);
            //cout << s << endl;
            length += 2;
        }
    }
    cout << "End " << s << endl;
}

void urlfy_2(string & s, int length){
    cout << "Begin " << s << endl;
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
    cout << "End " << s << endl;
}