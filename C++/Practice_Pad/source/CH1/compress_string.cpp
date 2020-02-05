#include "pch.h"
#include "compress_string.h"

string compress(string s) {
    cout << s;
    int len = s.length();
    if (len <= 2) {
        cout << " return " << s << endl;
        return s;
    }

    int count = 0;
    int i = 0;
    string result;
    do {
        result += s.at(i);
        char current = s.at(i);
        while ((i < len) && (current == s.at(i))) {
            i++;
            count++;
        }
        result += to_string(count);
        count = 0;

    } while (i < len);

    if (result.length() > len) {
        cout << " return " << s << endl;
        return s;
    }
    cout << " return " << result << endl;
    return result;
}