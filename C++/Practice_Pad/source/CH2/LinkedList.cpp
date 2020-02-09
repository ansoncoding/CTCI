#include "pch.h"
#include "LinkedList.h"
#include "practice_exceptions.h"

#include <cstdlib>
#include <iostream>
#include <set>

using namespace std;

LinkedList::LinkedList() {
    head = NULL;
    length = 0;
}

LinkedList::LinkedList(int len) {
    this->length = 0;
    head = NULL;
    int count = 0;
    for (int i = 0; i < len; i++) {
        int val = count;
        count++;
        prepend(val);
    }
}

bool LinkedList::test_partition(int k) const {
    
    Node* temp = head;
    bool greater_or_equal_found = false;

    while (temp != NULL) {
        if (greater_or_equal_found) {
            if (temp->data < k) {
                return false;
            }
        } else if (temp->data >= k) {
            greater_or_equal_found = true;
        }
        temp = temp->next;
    }
    return true;
}
void LinkedList::copy(const LinkedList& other) {
    if (other.head == NULL)
        return;

    this->length = other.length;
    head = new Node(other.head->data);

    Node* from = other.head->next;
    Node* prev = head;

    while (from != NULL) {

        Node* temp = new Node(from->data);
        prev->next = temp;
        
        prev = prev->next;
        from = from->next;
    }   
}

LinkedList::LinkedList(const LinkedList& other) {
    copy(other);
}

void LinkedList::cleanup() {
    if (head == NULL) {
        return;
    }
    // will get stuck in infinite loop if try to free circular LL
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
    head = NULL;
    length = 0;
}

LinkedList::~LinkedList() {
    cleanup();
}

LinkedList& LinkedList::operator=(const LinkedList& other) {

    if (&other != this) {
        cleanup();
        copy(other);
    }
    return *this;
}

LinkedList LinkedList::reverse() const {
    Node* temp = this->head;
    LinkedList retval = LinkedList();
    while (temp != NULL) {
        retval.prepend(temp->data);
        temp = temp->next;
    }
    return retval;
}

bool LinkedList::contains(int val) const {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == val) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int LinkedList::getLength() const {
    return length;
}

void LinkedList::prepend(int data) {

    if (head == NULL) {
        head = new Node(data);
    }
    else {
        Node* temp = new Node(data);
        temp->next = head;
        head = temp;
    }
    length++;
    //print();
}

void LinkedList::print() const {
    if (head == NULL) {
        cout << "Linked list is empty" << endl;
    }
    else {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

void LinkedList::print(int len) const {
    if (head == NULL) {
        cout << "Linked list is empty" << endl;
    }
    else {
        Node* temp = head;
        int count = 0;
        while (temp != NULL && count < len) {
            cout << temp->data << " ";
            temp = temp->next;
            count++;
        }
        cout << endl;
    }
}

void LinkedList::remove_duplicates() {
    set<int> vals;
    if (head == NULL) {
        return;
    }
    Node* prev = head;
    Node* temp = head->next;
    vals.insert(head->data);
    while (temp != NULL) {
        set<int> ::iterator it = vals.find(temp->data);
        if (it != vals.end()) {
            prev->next = temp->next;
            delete temp;
            length--;
            temp = prev->next;
        }
        else {
            vals.insert(temp->data);
            prev = temp;
            temp = temp->next;
        }
    }
}

// no temp buffer
void LinkedList::remove_duplicates2() {
    if (head == NULL) {
        return;
    }

    Node* val_node = head;

    while (val_node != NULL) {

        int val = val_node->data;

        Node* prev = val_node;
        Node* temp = val_node->next;

        while (temp != NULL) {
            if (temp->data == val) {
                prev->next = temp->next;
                delete temp;
                length--;
                temp = prev->next;
            }
            else {
                prev = temp;
                temp = temp->next;
            }
        }
        val_node = val_node->next;
    }
}
Node* LinkedList::get(int k) {
    if (k < 0) {
        throw invalid_argument("K cannot be less than 0");
        return nullptr;
    }
    if (k >= length || head == NULL) {
        cerr << "Cannot get " << k << "th last element. List is too small" << endl;
        throw OutofBoundsException();
        return nullptr;
    }

    int count = 0;
    Node* temp = head;
    while (temp != nullptr && count < k) {
        count++;
        temp = temp->next;
    }
    return temp;
        
}

Node * LinkedList::kth_last_node(int k) {
    if (k <= 0) {
        throw invalid_argument("K cannot be 0 or less than 0");
        return nullptr;
    }
    if (head == NULL) {
        cerr << "Cannot get " << k << "th last element. List is empty" << endl;
        throw OutofBoundsException();
        return nullptr;
    }
    Node* to_end = head;
    Node* k_th_last = head;
    int count = 0;
    while ((to_end != NULL) && (count < k)) {
        to_end = to_end->next;
        count++;
    }
    if (count < k) {
        cerr << "Cannot get " << k << "th last element. List has " << count << " nodes" << endl;
        throw OutofBoundsException();
        return nullptr;
    }
    while (to_end != NULL) {
        to_end = to_end->next;
        k_th_last = k_th_last->next;
    }
    return k_th_last;
}

void LinkedList::partition(int k) {
    LinkedList other = LinkedList();
    if (head == NULL) {
        cerr << "List is empty" << endl;
        return;
    }
    Node* temp = head;
    Node* prev = head;
    bool passed = false;

    while (temp != NULL) {
        if (temp->data < k) {

            if (!passed) {
                prev = temp;
                temp = temp->next;
            }
            else {
                prev->next = temp->next;
                temp->next = head;
                head = temp;
                temp = prev->next;
            }
        }
        else {
            passed = true;
            prev = temp;
            temp = temp->next;
        }
    }
}
bool LinkedList::is_palindrome() const {
    if (head == NULL)
        return false;

    LinkedList rev = reverse();

    Node* n1 = head;
    Node* n2 = rev.head;
    while (n1 != NULL) {
        if (n1->data != n2->data) {
            return false;
        }
        n1 = n1->next;
        n2 = n2->next;
    }
    return true;
}

void LinkedList::delete_middle_node(Node * n){
    // copy node information from next node over then delete the next node;
    Node * temp = n->next;
    n->data = temp->data;
    n->next = temp->next;
    delete temp;
    length--;
    return;
}

void LinkedList::remove(int val, bool remove_first_find) {
    if (head == NULL) {
        return;
    }

    if (head->data == val) {
        head = head->next;
        length--;
        delete head;
    }
    else {

        Node* prev = head;
        Node* temp = head->next;

        while (temp != NULL) {
            if (temp->data == val) {

                prev->next = temp->next;
                delete temp;
                length--;
                if (remove_first_find) {
                    return;
                }
                temp = prev->next;
            }
            else {
                prev = temp;
                temp = temp->next;
            }
        }
    }
}

bool LinkedList::contains_loop(Node *& retval) const {
    
    Node * p1 = head;
    Node * p2 = head;
    bool firstpass = false;

    while (p1 != NULL && p2 != NULL) {
        
        if (p2 == p1) { 
            
            if (!firstpass) { // because both pointers are starting at head, they gonna collide at the beginning
                firstpass = true;
            } else {
                // there is a loop 
                p1 = head;

                int count = 0;
                while (p1 != p2) {
                    p1 = p1->next; // keep going, if they collide again it's gonna be the node that's the start of the loop
                    p2 = p2->next;
                }
                retval = p1;
                return true;
            }
        }
        p1 = p1->next; // increment p1 by 1
        p2 = p2->next; // increment p2 by 2

        if (p2 != NULL) { // remember to check that p2 is not null! since we're increment by 2 at once
            p2 = p2->next;
        }
        else {
            return false; // if a pointer gets to tail means there's no loop
        }
    }
    return false; // if a pointer gets to tail means there's no loop
}

bool LinkedList::is_intersecting(const LinkedList & ll, Node *& retval) const {

    Node* t1 = head;
    Node * t1_prev = NULL;
    Node * t2 = ll.head;
    Node * t2_prev = NULL;
    int len1 = 0;
    int len2 = 0;

    while (t1 != NULL) {
        t1_prev = t1;
        t1 = t1->next;
        len1++;
    }
    while (t2 != NULL) {
        t2_prev = t2;
        t2 = t2->next;;
        len2++;
    }
    if (t1_prev != t2_prev) { // tails are not equivalent
        return false;
    }
    
    int len_diff = abs(len2 - len1);

    Node * n1 = NULL;
    Node * n2 = NULL;

    if (len_diff != 0) {
        Node * temp = NULL;
        temp = (len1 > len2) ? head : ll.head;

        for (int i = 0; i < len_diff; i++) {
            temp = temp->next;
        }
        if (len1 > len2) {
            n1 = temp;
            n2 = ll.head;
        } else {
            n1 = head;
            n2 = temp;
        }
    } else { // lists are same length
        n1 = head;
        n2 = ll.head;
    }
    while (n1 != NULL && n2 != NULL) {
        if (n2 == n1) {
            retval = n1;
            return true;
        }
        n1 = n1->next;
        n2 = n2->next;
    }
    return false;
}

bool LinkedList::compare(LinkedList l) const {
    if (this->length != l.length) {
        return false;
    }
    Node* n1 = this->head;
    Node* n2 = l.head;
    while (n1 != NULL && n2 != NULL) {
        if (n1->data != n2->data) {
            return false;
        }
        n1 = n1->next;
        n2 = n2->next;
    }
    return true;
}