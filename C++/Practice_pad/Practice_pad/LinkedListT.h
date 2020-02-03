#ifndef LINKED_LIST_T_H
#define LINKED_LIST_T_H

#include "LinkedList.h"

class LinkedListT : public LinkedList
{
private:
    Node * tail = NULL;
public:
    LinkedListT(){
        LinkedList();
    }
    LinkedListT(int len, bool circular=false){
        for (int i = 0; i < len; i++) {
            append(i);
            //print();
        }
        if (circular) {
            tail->next = head;
        }
    }
    
    Node * getHead() {
        return head;
    }
    
    Node * getNext(Node * current) {
        return current->next;
    }
    void setTailNext(Node * node) {
        tail->next = node;
        tail = tail->next;
    }

    void append(int data) {
        
        if (head == NULL) {
            head = new Node(data);
            tail = head;
            length++;
            return;
        }
        Node * temp = new Node(data);
        tail->next = temp;
        tail = temp;
        length++;
        return;
    }
    void prepend(int data) {
        if (head== NULL) {
            head = new Node(data);
            tail = head;

        } else {
            Node * temp =  new Node(data); 
            temp->next = head;
            head = temp;
        }
        length++;
    }
    LinkedListT reverse() {
        Node * temp = head;
        LinkedListT retval = LinkedListT();
        while (temp != NULL) {
            retval.prepend(temp->data);
            temp = temp->next;
        }
        return retval;
    }
};

LinkedListT sum_lists(LinkedListT l1, LinkedListT l2);

#endif