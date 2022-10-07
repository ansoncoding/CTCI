#include "pch.h"
#include "LinkedListT.h"
#include <iostream>

LinkedListT::LinkedListT() {
    LinkedList();
}

LinkedListT::LinkedListT(int* init_vals, int len) {

    Node* temp = head;
    for (int i = 0; i < len; i++) {
        append(init_vals[i]);
    }
}

void LinkedListT::copy(const LinkedListT& other) {
    
    Node* temp = other.head;
    while (temp != NULL) {
        append(temp->data);
        temp = temp->next;
    }
}

LinkedListT::LinkedListT(const LinkedListT& other) {
    copy(other);
}

LinkedListT& LinkedListT::operator=(const LinkedListT& other) {

    if (&other != this) {
        cleanup();
        copy(other);
    }
    return *this;
}

LinkedListT::LinkedListT(int len, bool circular) {

    for (int i = 0; i < len; i++) {
        append(i);
    }
    if (circular) { //for testing loop function only
        tail->next = head;
        bad_list = true;
    }
}

// only used to create intersecting LL
void LinkedListT::setTailNext(Node* node) {
    tail->next = node;
    tail = tail->next;
    bad_list = true;
}

void LinkedListT::append(int data) {

    if (head == NULL) {
        head = new Node(data);
        tail = head;
        length++;
        return;
    }
    Node* temp = new Node(data);
    tail->next = temp;
    tail = temp;
    length++;
    return;
}

void LinkedListT::prepend(int data) {
    if (head == NULL) {
        head = new Node(data);
        tail = head;
    } else {
        Node* temp = new Node(data);
        temp->next = head;
        head = temp;
    }
    length++;
}

LinkedListT LinkedListT::reverse() {
    Node* temp = head;
    LinkedListT retval = LinkedListT();
    while (temp != NULL) {
        retval.prepend(temp->data);
        temp = temp->next;
    }
    return retval;
}

void LinkedListT::cleanup() {
    if (head == nullptr) {
        return;
    }
    if (bad_list) {

        Node* current = head;
        Node* next;
        for (int i = 0; i < length; i++) {

            if (current != NULL) {
                next = current->next;
                delete current;
                current = next;
            }
            else {
                break;
            }
        }
        tail = NULL;
        head = NULL;
        length = 0;
        return;
    }

    Node* current = head;
    Node* next;
    while (current != NULL) {
        next = current->next;
        delete current;
        current = next;
    }
    length = 0;
    head = NULL;
    tail = NULL;
}

LinkedListT::~LinkedListT() {
    cleanup();
}
LinkedListT LinkedListT::sum_lists(const LinkedListT& ll) const {

    LinkedListT retval = LinkedListT();
    Node * n1 = head;
    Node * n2 = ll.head;

    int remainder = 0;
    int prev_quotient = 0;

    while ((n1 != NULL) || (n2 != NULL)) {
        int val1 = 0;
        int val2 = 0;
        if (n1 != NULL){
            val1 = n1->data;
        }
        if (n2 != NULL) {
            val2 = n2->data;
        }
        int sum = val1 + val2 + prev_quotient;
        remainder = sum % 10;
        
        retval.append(remainder);

        prev_quotient = sum / 10;
        if (n1 != NULL){
            n1 = n1->next;
        }
        if (n2 != NULL) {
            n2 = n2->next;
        }
    }
    if (prev_quotient > 0) {
        retval.append(prev_quotient);
    } 
    return retval;
}

