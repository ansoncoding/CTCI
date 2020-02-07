#ifndef LINKED_LIST_T_H
#define LINKED_LIST_T_H

#include "LinkedList.h"

class LinkedListT : public LinkedList
{
private:
    Node * tail = NULL;
    void copy(const LinkedListT& other);
    void cleanup();
public:
    LinkedListT();
    ~LinkedListT();
    LinkedListT(int* init_vals, int len);
    LinkedListT& operator=(const LinkedListT& other);
    LinkedListT(const LinkedListT& other);
    LinkedListT(int len, bool circular = false);
    void prepend(int data);
    void append(int data);
    void setTailNext(Node* node); // only used to create intersecting LL
    LinkedListT* LinkedListT::reverse();
    LinkedListT* sum_lists(const LinkedListT & l1) const;
};

#endif
