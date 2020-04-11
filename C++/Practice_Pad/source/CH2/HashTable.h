#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <vector>

using namespace std;

class HashTable {

private:    
    const int capacity = 16;
    vector<vector<pair<string, string>>> arraylist;
    void copy(const HashTable& other);
    void cleanup();
    int hash(const string s) const;
    
public:
    HashTable();
    HashTable(const HashTable& other);
    HashTable& operator=(const HashTable& other);
    ~HashTable();
    string get(string key) const;
    void put(string key, string val);
    void remove(string key);
    bool containsKey(string key) const;
    bool containsVal(string val) const;
    int size() const;
    void print() const;
};

#endif