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

    int hash(string s) const {
        int hash_val = 0;
        for (int i = 0; i < s.length(); i++) {
            hash_val += s.at(i);
        }
        return hash_val;
    }

public:
    HashTable() {
        arraylist = new LinkedListS[capacity]; 
    }

    HashTable(const HashTable & other){
        copy(other);
    }

    void copy(const HashTable & other) {
        capacity = other.capacity;
        arraylist = new LinkedListS[capacity];
        for (int i = 0; i < capacity; i++) {
            arraylist[i].copy(other.arraylist[i]);
        }
    }

    void insert(string s) {
        int index = hash(s) % capacity;
        arraylist[index].prepend(s);
    }

    bool contains(string s) const {
        int index = hash(s) % capacity;
        return arraylist[index].contains(s);
    }

    void remove(string s) {
        int index = hash(s) % capacity;
        if (arraylist[index].contains(s)) {
            arraylist[index].remove(s);
        }
    }

    void print() const {
        for (int i = 0; i < capacity; i++) {
            
            if (!arraylist[i].isEmpty()) {
                cout << setw(3) << i << " " ; // max 128 3 digit
                arraylist[i].print();
            }
        }
        cout << endl;
    }
    ~HashTable() {
        for (int i = 0; i < capacity; i++) {
            if (!arraylist[i].isEmpty()) {
                arraylist[i].~LinkedListS();
            }
        }
        delete[] arraylist;
        arraylist = NULL;
    }
};

#endif