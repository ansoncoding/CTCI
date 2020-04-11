#include "pch.h"
#include "HashTable.h"
#include <iomanip>
#include <iostream>

int HashTable::hash(const string key) const {
    int hash_val = 0;
    for (unsigned int i = 0; i < key.length(); i++) {
        hash_val += key.at(i) + (key.at(i) * i);
    }
    return hash_val;
}

HashTable::HashTable() {
    arraylist = vector<vector<pair<string, string>>>(capacity); 
}

HashTable& HashTable::operator=(const HashTable& other) {
    if (&other != this) {
        cleanup();
        copy(other);
    }
    return *this;
}

HashTable::HashTable(const HashTable & other){
    copy(other);
}

void HashTable::copy(const HashTable & other) {
    arraylist = vector<vector<pair<string, string>>>(capacity);
    for (int i = 0; i < capacity; i++) {
        arraylist[i] = other.arraylist[i]; 
    }
}

string HashTable::get(string key) const {
    int index = hash(key)%capacity;
    
    vector<pair<string, string>> list = arraylist.at(index);
    for (vector<pair<string, string>>::iterator it = list.begin(); it != list.end(); it++ ) {
        if (it->first == key) {
            return it->second;
        }
    }
}

void HashTable::put(string key, string val) {

    int index = hash(key) % capacity;
    bool found = false;    
    
    vector<pair<string, string>> list = arraylist[index];
    vector<pair<string, string>>::iterator it;
    for (it = list.begin(); it != list.end(); it++) {
        if (it->first == key) {
            found = true;
            break;
        }
    }
    if (found) {
        list.erase(it);
        list.insert(list.begin(), make_pair(key, val));
    }
    else {
        list.push_back(make_pair(key, val));
    }
    arraylist[index] = list;
}

void HashTable::remove(string key) {
    int index = hash(key) % capacity;
    
    vector<pair<string, string>> list = arraylist.at(index);
    vector<pair<string, string>>::iterator it;
    bool found = false;
    for (it = list.begin(); it != list.end(); it++) {
        if (it->first == key) {
            found = true;
            break;
        }
    }
    if (found) {
        list.erase(it);
        arraylist[index] = list;
    }
}

bool HashTable::containsKey(string key) const {
    int index = hash(key) % capacity;

    vector<pair<string, string>> list = arraylist.at(index);
    for (vector<pair<string, string>>::iterator it = list.begin(); it != list.end(); it++) {
        if (it->first == key) {
            return true;
        }
    }
    return false;
}

bool HashTable::containsVal(string val) const {
    
    for (int i = 0; i < arraylist.size(); i++) {
        vector<pair<string, string>> list = arraylist.at(i);
        for (vector<pair<string, string>>::iterator it = list.begin(); it != list.end(); it++) {
            if (it->second == val) {
                return true;
            }
        }
    }
    return false;
}

int HashTable::size() const {
    return arraylist.size();
}

void HashTable::cleanup() {

}

HashTable::~HashTable() {
    
}

void HashTable::print() const {
    for (int i = 0; i < arraylist.size(); i++) {
        vector<pair<string, string>> list = arraylist.at(i);
        for (vector<pair<string, string>>::iterator it = list.begin(); it != list.end(); it++) {
            cout << it->first << " : " << it->second << "  ";
        }
        cout << endl;
    }
    cout << endl;
}