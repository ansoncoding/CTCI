#include "pch.h"
#include "LinkedListT.h"

LinkedListT::LinkedListT() {
    LinkedList();
}

void LinkedListT::copy(const LinkedListT& other) {

    length = other.length;
    Node* temp = other.head;
    while (temp != NULL) {
        append(temp->data);
        temp = temp->next;
    }
}

LinkedListT::LinkedListT(const LinkedListT& other) {
    copy(other);
}

LinkedListT::LinkedListT(int len, bool circular) {
    for (int i = 0; i < len; i++) {
        append(i);
        //print();
    }
    if (circular) {
        tail->next = head;
    }
}

void LinkedListT::setTailNext(Node* node) {
    tail->next = node;
    tail = tail->next;
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

LinkedListT::~LinkedListT() {
    Node* current = head;
    Node* next;
    while (current != NULL) {
        next = current->next;
        delete current;
        current = next;
    }
    head = NULL;
    tail = NULL;
}

LinkedListT LinkedListT::sum_lists(LinkedListT ll) const {
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

