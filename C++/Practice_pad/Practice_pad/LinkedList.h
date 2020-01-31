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
        // O(n) time, O(k) space
        bool kth_last_element(int k, int & ret) {
            if (k == 0) {
                cerr << "K cannot be 0" << endl;
                return false;
            }
            if (head == NULL) {
                return false;
            }
            int * vals = new int[k];
            int count = 0;
            Node * temp = head;
            while (temp != NULL) {
                vals[count%k] = temp->data;
                
                temp = temp->next;
                //cout << count%k << " " << vals[count%k] << endl;
                count++;
            }
            if (count < k) {
                cout << "No Kth last element, array is too small" << endl;
                return false;
            }
            //cout << "Count " << count << endl;
            ret = vals[count%k];
            return true;
        }

        // O(n) time O(1) space, use two pointers k nodes apart
        bool kth_last_element2(int k, int & ret) {
            if (k == 0) {
                cerr << "K cannot be 0" << endl;
                return false;
            }
            if (head == NULL) {
                cerr << "Cannot get "<< k << "th last element. List is empty" << endl;
                return false;
            }
            Node * to_end = head;
            Node * k_th_last = head;
            int count = 0;
            while ((to_end != NULL) && (count < k)) {
                to_end = to_end->next;
                count++;
            }
            if (count < k) {
                cerr << "Cannot get " << k << "th last element. List has " << count << " nodes" << endl;
                return false;
            }
            while (to_end != NULL) {
                to_end = to_end->next;
                k_th_last = k_th_last->next;
            }
            ret = k_th_last->data;
            return true;
        }
};

#endif
