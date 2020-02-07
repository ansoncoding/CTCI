#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <string>

using namespace std;

class Node {

public:
    Node(string data) {
        this->data = data;
    }
    string data;
    Node * next = NULL;
};


class LinkedListS {
    
protected:
    Node * head;
    int length; 
    void copy(const LinkedListS& other);
    void cleanup();
public:
    LinkedListS();
    ~LinkedListS();
    LinkedListS(const LinkedListS & other);
    LinkedListS& operator=(const LinkedListS& other);
    int getLength() const;
    void prepend(string data);
    void print() const;
    void print(int len) const;
    bool contains(string s) const;
    void remove(string s, bool remove_first_find=false);
    bool isEmpty() const;
};

#endif
