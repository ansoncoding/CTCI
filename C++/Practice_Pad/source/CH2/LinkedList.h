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
    
protected:
        Node * head;

        int length; 
public:
        LinkedList() {
            head = NULL;
            length = 0;
        }
        LinkedList(int length) {
            //cout << length << endl;
            head = NULL;
            int count = 0;
            for (int i = 0; i < length; i++){
                int val = count % length;
                count++;
                prepend(val);
                
            }
        }
        void copy(const LinkedList & other){
            length = other.length;
            Node * from = other.head;
            Node * to = head;
            while (from != NULL){
                to = new Node(from->data);
                to->next = from->next;
                from = from->next;
                to = to->next;
            }
        }

        LinkedList(const LinkedList& other){
            copy(other);
        }

        ~LinkedList() {
            Node * current = head;
            Node * next;
            while (current != NULL) {
                next = current->next;
                delete current;
                current = next;
            }
            head = NULL;
        }
        Node * getHead() const {
            return head;
        }
        Node * getNext(Node * current) const {
            return current->next;
        }
        LinkedList reverse() const {
            Node * temp = head;
            LinkedList retval = LinkedList();
            while (temp != NULL) {
                retval.prepend(temp->data);
                temp = temp->next;
            }
            return retval;
        }

        int getLength() const {
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
                    delete temp;
                    length--;
                    temp = prev->next;
                } else {
                    vals.insert(temp->data);
                    prev = temp;
                    temp = temp->next;
                }
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
                        delete temp;
                        length--;
                        temp = prev->next;
                    } else {
                        prev = temp;
                        temp = temp->next;
                    }
                }
                val_node = val_node->next;
            }
        }       

        // O(n) time O(1) space, use two pointers k nodes apart
        bool kth_last_element(int k, Node ** ret) {
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
            *ret = k_th_last;
            return true;
        }

        bool kth_last_node(int k, Node ** ret) {
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
            *ret = k_th_last;
            return true;
        }
        void partition(int k) {
            LinkedList other = LinkedList();
            if (head == NULL) {
                cerr << "List is empty" << endl;
                return;
            }
            Node * temp = head;
            Node * prev = head;
            bool passed = false;

            while (temp != NULL) {
                if (temp->data < k) {

                    if (!passed) {
                        prev = temp;
                        temp = temp->next;
                    } else {
                        prev->next = temp->next;
                        temp->next = head;
                        head = temp;
                        temp = prev->next;
                    }
                } else {
                    passed = true;
                    prev = temp;
                    temp = temp->next;
                }
            }
        }
        bool is_palindrome() const {
            LinkedList rev = reverse();
            Node * n1 = head;
            Node * n2 = rev.head;
            while (n1 != NULL) {
                if (n1->data != n2->data) {
                    return false;
                }
                n1 = n1->next;
                n2 = n2->next;
            }
            return true;
        }
};

bool is_intersecting(LinkedList l1, LinkedList l2, Node ** retval);
bool loop_detection(LinkedList l1, Node** retval);
void delete_middle_node(Node * n);

#endif