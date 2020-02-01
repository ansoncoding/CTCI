#include "LinkedList.h"

void delete_middle_node(Node * n){
    // copy node information from next node over then delete the next node;
    Node * temp = n->next;
    n->data = temp->data;
    n->next = temp->next;
    delete temp;
    return;
}