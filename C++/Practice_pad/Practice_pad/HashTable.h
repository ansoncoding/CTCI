#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "LinkedListString.h"
#include <iomanip>
#include <iostream>

using namespace std;

class HashTable {

private:
    int capacity = 16;
    LinkedListS * arraylist;
public:
    HashTable() {
        arraylist = new LinkedListS[capacity]; 
    }

    int hash(string s) {
        int hash_val = 0;
        for (int i = 0; i < s.length(); i++) {
            hash_val += s.at(i);
        }
        return hash_val;
    }
    void insert(string s) {
        int index = hash(s) % capacity;
        arraylist[index].prepend(s);
    }

    bool contains(string s) {
        int index = hash(s) % capacity;
        return arraylist[index].contains(s);
    }

    void remove(string s) {
        int index = hash(s) % capacity;
        if (arraylist[index].contains(s)) {
            arraylist[index].remove(s);
        }
    }

    void print() {
        for (int i = 0; i < capacity; i++) {
            
            if (!arraylist[i].isEmpty()) {
                cout << setw(3) << i << " " ; // max 128 3 digit
                arraylist[i].print();
            }
        }
        cout << endl;
    }
}

#endif