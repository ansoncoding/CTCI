#ifndef LINKED_LIST_T_H
#define LINKED_LIST_T_H

#include "LinkedList.h"

class LinkedListT : public LinkedList
{
private:
    Node * tail = NULL;
    void copy(const LinkedListT& other);
public:
    LinkedListT();
    ~LinkedListT();
    LinkedListT(const LinkedListT& other);
    LinkedListT(int len, bool circular = false);
    void prepend(int data);
    void append(int data);
    void setTailNext(Node* node);
    LinkedListT LinkedListT::reverse();
    LinkedListT sum_lists(LinkedListT l1) const;
};

#endif