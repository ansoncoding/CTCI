#include "pch.h"
#include "LinkedList.h"

void delete_middle_node(Node * n){
    // copy node information from next node over then delete the next node;
    Node * temp = n->next;
    n->data = temp->data;
    n->next = temp->next;
    delete temp;
    return;
}

bool loop_detection(LinkedList l, Node ** retval) {
    
    Node * p1 = l.getHead();
    Node * p2 = l.getHead();
    bool firstpass = false;

    while (p1 != NULL && p2 != NULL) {
        
        if (p2 == p1) { 
            
            if (!firstpass) { // because both pointers are starting at head, they gonna collide at the beginning
                firstpass = true;
            } else {
                // there is a loop 
                p1 = l.getHead();

                int count = 0;
                while (p1 != p2) {
                    p1 = l.getNext(p1); // keep going, if they collide again it's gonna be the node that's the start of the loop
                    p2 = l.getNext(p2);
                }
                *retval = p1;
                return true;
            }
        }
        p1 = l.getNext(p1); // increment p1 by 1
        p2 = l.getNext(p2); // increment p2 by 2

        if (p2 != NULL) { // remember to check that p2 is not null! since we're increment by 2 at once
            p2 = l.getNext(p2);
        }
        else {
            return false; // if a pointer gets to tail means there's no loop
        }
    }
    return false; // if a pointer gets to tail means there's no loop
}

bool is_intersecting(LinkedList l1, LinkedList l2, Node ** retval) {

    Node * t1 = l1.getHead();
    Node * t1_prev = NULL;
    Node * t2 = l2.getHead();
    Node * t2_prev = NULL;
    int len1 = 0;
    int len2 = 0;

    while (t1 != NULL) {
        t1_prev = t1;
        t1 = l1.getNext(t1);
        len1++;
    }
    while (t2 != NULL) {
        t2_prev = t2;
        t2 = l2.getNext(t2);
        len2++;
    }
    if (t1_prev != t2_prev) { // tails are not equivalent
        return false;
    }
    
    int len_diff = abs(len2 - len1);

    Node * n1 = NULL;
    Node * n2 = NULL;

    if (len_diff != 0) {
        Node * temp = NULL;
        temp = (len1 > len2 ? l1.getHead() : l2.getHead());
        LinkedList  longer = (len1 > len2 ? l1 : l2);
        for (int i = 0; i < len_diff; i++) {
            temp = longer.getNext(temp);
        }
        if (len1 > len2) {
            n1 = temp;
            n2 = l2.getHead();
        } else {
            n1 = l1.getHead();
            n2 = temp;
        }
    } else { // lists are same length
        n1 = l1.getHead();
        n2 = l2.getHead();
    }
    while (n1 != NULL && n2 != NULL) {
        if (n2 == n1) {
            *retval = n1;
            return true;
        }
        n1 = l1.getNext(n1);
        n2 = l2.getNext(n2);
    }
    return false;
}

