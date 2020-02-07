#ifndef LINKED_LIST_H
#define LINKED_LIST_H

class Node {

public:
    Node(int data) {
        this->data = data;
    }
    int data;
    Node * next = NULL;
};


class LinkedList {
    
protected:
    Node * head = NULL;
    int length = 0; 
    void copy(const LinkedList& other);
    void cleanup();
public:
    LinkedList();
    LinkedList(int len);
    LinkedList(const LinkedList & other);
    LinkedList& operator=(const LinkedList& other);
    ~LinkedList();
    void remove(int data, bool remove_first_find = true);
    void prepend(int data);
    int getLength() const;
    bool contains(int val) const;
    bool compare(LinkedList l) const;
    void print() const;
    void print(int len) const;
    void remove_duplicates();
    void remove_duplicates2();
    Node * kth_last_node(int k);
    void partition(int k);
    bool test_partition(int k) const;
    bool is_palindrome() const;
    LinkedList * reverse() const;
    bool is_intersecting(LinkedList ll, Node*& retval) const;
    bool contains_loop(Node*& retval) const;
    void delete_middle_node(Node* n);
};

#endif
