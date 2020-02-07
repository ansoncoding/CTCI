#include "pch.h"
#include "LinkedListString.h"

#include <iostream>

LinkedListS::LinkedListS() {
    head = NULL;
    length = 0;
}

LinkedListS::LinkedListS(const LinkedListS & other){
    copy(other);
}

LinkedListS& LinkedListS::operator=(const LinkedListS& other) {
    if (&other != this) {
        cleanup();
        copy(other);
    }
    return *this;
}

void LinkedListS::copy(const LinkedListS & other){
    if (other.head == NULL)
        return;

    length = other.length;
    head = new Node(other.head->data);

    Node * iter = other.head->next;
    Node * prev = head;

    while (iter != NULL) {
        prev->next = new Node(iter->data);
        
        prev = prev->next;
        iter = iter->next;
    }
}

int LinkedListS::getLength() const {
    return length;
}

void LinkedListS::prepend(string data){
    
    if (head== NULL) {
           head = new Node(data);
    } else {
        Node * temp =  new Node(data); 
        temp->next = head;
        head = temp;
    }
    length++;
    //print();
}

void LinkedListS::print() const {
    if (head == NULL) {
        cout << "Linked list is empty" << endl;
    } else {
        Node * temp = head;
        while (temp != NULL)  {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}
void LinkedListS::print(int len) const {
    if (head == NULL) {
        cout << "Linked list is empty" << endl;
    } else {
        Node * temp = head;
        int count = 0;
        while (temp != NULL && count < len)  {
            cout << temp->data << " ";
            temp = temp->next;
            count++;
        }
        cout << endl;
    }
}

bool LinkedListS::contains(string s) const {
    Node * temp = head;
    while (temp != NULL){
        if (temp->data.compare(s) == 0) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void LinkedListS::remove(string s) {
    Node * temp = head;
    Node * prev = head;
    while (temp != NULL){
        
        if (temp->data.compare(s) == 0) {
            if (temp == head) {
                delete temp;
                head = NULL;
            } else {
                prev->next = temp->next;
                delete temp;
            }
            length--;
            return;
        } else {
            prev = temp;
            temp = temp->next;
        }
    }
}
bool LinkedListS::isEmpty() const {
    return (head == NULL);
}

void LinkedListS::cleanup() {
    if (head == NULL)
        return;

    Node* current = head;
    Node* next;
    while (current != NULL)
    {
        next = current->next;
        delete current;
        current = next;
    }
    head = NULL;
    length = 0;
}

LinkedListS::~LinkedListS() {
    cleanup();
}