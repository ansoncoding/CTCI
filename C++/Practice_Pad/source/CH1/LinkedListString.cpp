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
    return LinkedListS(other);
}

void LinkedListS::copy(const LinkedListS & other){
    length = other.length;
    Node * from = other.head;
    Node * to = head;
    while (from != NULL) {
        to = new Node(from->data);
        to->next = from->next;
        from = from->next;
        to = to->next;
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

LinkedListS::~LinkedListS() {
    if (head == NULL)
        return;

    Node * current = head;
    Node * next;
    while (current != NULL)  
    {  
        next = current->next;  
        delete current;
        current = next;  
    }  
    head = NULL;
}