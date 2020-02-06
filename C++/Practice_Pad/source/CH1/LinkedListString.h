#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

class Node {

public:
    Node(string data) {
        this->data = data;
    }
    string data;
    Node * next = NULL;
};


class LinkedListS {
    
protected:
        Node * head;

        int length; 
public:
        LinkedListS() {
            head = NULL;
            length = 0;
        }
        
        LinkedListS(const LinkedListS & other){
            copy(other);
        }

        void copy(const LinkedListS & other){
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
        
        int getLength() const {
            return length;
        }

        void prepend(string data){
            
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

        void print() const {  
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
        void print(int len) const {  
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

        bool contains(string s) const {
            Node * temp = head;
            while (temp != NULL){
                if (temp->data.compare(s) == 0) {
                    return true;
                }
                temp = temp->next;
            }
            return false;
        }

        void remove(string s) {
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
        bool isEmpty() const {
            return (head == NULL);
        }

        ~LinkedListS() {
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
};

#endif
