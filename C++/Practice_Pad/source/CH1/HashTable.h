#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "LinkedListString.h"

using namespace std;

class HashTable {

private:
    int size = 0;
    int capacity = 16;
    LinkedListS * arraylist;
    void copy(const HashTable& other);
    int hash(string s) const;

public:
    HashTable();
    HashTable(const HashTable& other);
    HashTable& operator=(const HashTable& other);
    ~HashTable();
    void insert(string s);
    bool contains(string s) const;
    void remove(string s);
    void print() const;
};

#endif