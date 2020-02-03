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
        
        int getLength() {
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

        void print() {  
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
        void print(int len) {  
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

        bool contains(string s) {
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
        bool isEmpty() {
            return (head == NULL);
        }

};

#endif
