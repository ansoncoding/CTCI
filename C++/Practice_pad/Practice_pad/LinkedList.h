#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <cstdlib>
#include <iostream>
#include <set>
using namespace std;

class Node {

public:
    Node(int data) {
        this->data = data;
    }
    int data;
    Node * next = NULL;
};


class LinkedList {
    
public:
        Node * head;
private:
        int length; 
public:
        LinkedList() {
            head = NULL;
            length = 0;
        }
        LinkedList(int length) {
            cout << length << endl;
            head = NULL;
            int count = 0;
            for (int i = 0; i < length; i++){
                int val = count % 4;
                count++;
                prepend(val);
                
            }
        }

        int getLength() {
            return length;
        }

        void prepend(int data){
            
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

        void remove_duplicates() {
            set<int> vals;
            if (head == NULL) {
                return;
            }
            Node * prev = head;
            Node * temp = head->next;
            vals.insert(head->data);
            while (temp != NULL)  {
                set<int> ::iterator it = vals.find(temp->data);
                if (it != vals.end()) {
                    prev->next = temp->next;
                    length--;
                } else {
                    vals.insert(temp->data);
                    prev = temp;
                }
                
                temp = temp->next;
            }
        }
        // no temp buffer
        void remove_duplicates2() {
            if (head == NULL) {
                return;
            }
            
            Node * val_node = head;
            
            while (val_node != NULL) {

                int val = val_node->data;

                Node * prev = val_node;
                Node * temp = val_node->next;
                
                while (temp != NULL) {
                    if (temp->data == val) {
                        prev->next = temp->next;
                        length--;
                    } else {
                        prev = temp;
                    }
                    temp = temp->next;
                }
                val_node = val_node->next;
            }
        }


};

#endif
