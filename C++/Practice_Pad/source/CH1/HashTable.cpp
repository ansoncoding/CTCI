#include "pch.h"
#include "HashTable.h"
#include <iomanip>
#include <iostream>
int HashTable::hash(string s) const {
    int hash_val = 0;
    for (int i = 0; i < s.length(); i++) {
        hash_val += s.at(i);
    }
    return hash_val;
}

HashTable::HashTable() {
        arraylist = new LinkedListS[capacity]; 
}

HashTable& HashTable::operator=(const HashTable& other) {
    return HashTable(other);
}

HashTable::HashTable(const HashTable & other){
    copy(other);
}

void HashTable::copy(const HashTable & other) {
    capacity = other.capacity;
    arraylist = new LinkedListS[capacity];
    for (int i = 0; i < capacity; i++) {
        arraylist[i] = LinkedListS(other.arraylist[i]);
    }
}

void HashTable::insert(string s) {
    int index = hash(s) % capacity;
    arraylist[index].prepend(s);
}

bool HashTable::contains(string s) const {
    int index = hash(s) % capacity;
    return arraylist[index].contains(s);
}

void HashTable::remove(string s) {
    int index = hash(s) % capacity;
    if (arraylist[index].contains(s)) {
        arraylist[index].remove(s);
    }
}

void HashTable::print() const {
    for (int i = 0; i < capacity; i++) {
            
        if (!arraylist[i].isEmpty()) {
            cout << setw(3) << i << " " ; // max 128 3 digit
            arraylist[i].print();
        }
    }
    cout << endl;
}

HashTable::~HashTable() {
    for (int i = 0; i < capacity; i++) {
        if (!arraylist[i].isEmpty()) {
            arraylist[i].~LinkedListS();
        }
    }
    delete[] arraylist;
    arraylist = NULL;
}