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
    Node * head = nullptr;
    int length = 0; 
    void copy(const LinkedList& other);
    void cleanup();
public:
    LinkedList();
    LinkedList(int len);
    LinkedList(const LinkedList & other);
    ~LinkedList();
    void prepend(int data);
    int getLength() const;
    void print() const;
    void print(int len) const;
    void remove_duplicates();
    void remove_duplicates2();
    Node * kth_last_node(int k);
    void partition(int k);
    bool is_palindrome() const;
    LinkedList LinkedList::reverse() const;
    bool is_intersecting(LinkedList ll, Node** retval);
    bool contains_loop(Node** retval);
    void delete_middle_node(Node* n);
};

#endif
