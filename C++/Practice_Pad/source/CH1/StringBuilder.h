#ifndef STRING_BUILDER_H
#define STRING_BUILDER_h

#include <string>

using namespace std;

// Just an exercise, do not use in real programming 
class StringBuilder {
private:
    const int initital_capacity = 16;
    const int resizing_factor = 2;
    int current_capacity = 16;
    int size = 0;
    char * arraylist;
public:
    StringBuilder(){
        arraylist = new char[initital_capacity];
        memset(arraylist, 0, initital_capacity);
    }
    void append(string s) {
        if (size + s.length() > current_capacity) {
            char * newarraylist = new char[initital_capacity* resizing_factor];
            
            current_capacity *= resizing_factor;
            memset(newarraylist, 0, current_capacity);

            for (int i = 0; i < size; i++) {
                newarraylist[i] = arraylist[i];
            }
            
            delete[] arraylist;
            arraylist = newarraylist;
            for (int i = 0; i < s.length(); i++) {
                arraylist[size + i] = s.at(i);
            }
            size += s.length();
        }
        else {
            for (int i = 0; i < s.length(); i++) {
                arraylist[size + i] = s.at(i);
            }
            size += s.length();
        }
    }
    string toString() const {
        return string(arraylist);
    }

    ~StringBuilder() {
        delete[] arraylist;
        arraylist = NULL;
    }
};


#endif