#include "LinkedList.h"

void delete_middle_node(Node * n){
    // copy node information from next node over then delete the next node;
    Node * temp = n->next;
    n->data = temp->data;
    n->next = temp->next;
    delete temp;
    return;
}

bool is_intersecting(LinkedList l1, LinkedList l2) {
    Node * n1 = l1.getHead();
    Node * n2 = l2.getHead();
    for (n1; n1 != NULL; n1 = l1.getNext(n1)) {
        for (n2; n2 != NULL; n2 = l2.getNext(n2)) {
            if (n1 == n2) {
                return true;
            }
        }
    }
    return false;
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