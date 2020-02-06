#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include "practice_exceptions.h"

using namespace std;

class ArrayList {

private:
    const int initial_capacity = 8;
    const int resizing_factor = 2;
    int current_capacity = 8;
    int size = 0;
    int * arraylist;
    
public:
    ArrayList() {
        arraylist = new int[initial_capacity];
        memset(arraylist, 0, initial_capacity*sizeof(int));
    }
    
    ArrayList(const ArrayList& other) {
        copy(other);
    }
    
    ArrayList& operator=(const ArrayList& other) {
        return ArrayList(other);
    }

    ~ArrayList() {
        delete[] arraylist;
        arraylist = nullptr;
    }

    void copy(const ArrayList& other) {
        current_capacity = other.current_capacity;
        arraylist = new int[current_capacity];
        memset(arraylist, 0, current_capacity * sizeof(int));

        for (int i = 0; i < other.size; i++) {
            arraylist[i] = other.arraylist[i];
        }
        size = other.size;
    }
    
    void add(int data) {
        if (size == current_capacity) {
            int * newarraylist = new int[current_capacity * resizing_factor];
            current_capacity *= resizing_factor;
            memset(newarraylist, 0, current_capacity * sizeof(int));

            for (int i = 0; i < size; i++){
                newarraylist[i] = arraylist[i];
            }
            
            delete[] arraylist;
            arraylist = newarraylist;
            arraylist[size] = data;
            size++;
        }
        else {
            arraylist[size] = data;
            size++;
        }
    }

    int getSize() const {
        return size;
    }

    int getCapacity() const {
        return current_capacity;
    }

    int get(int index) const {
        if (index < size && index >= 0)
            return arraylist[index];
        else {
            throw OutofBoundsException();
            return -1;
        }
    }

    bool contains(int value, int& retval_ind) {
        for (int i = 0; i < size; i++) {
            if (arraylist[i] == value) {
                retval_ind = i;
                return true;
            }
        }
        return false;
    }

    bool set(int index, int data) {
        if (index < 0 || index >= size) {
            throw OutofBoundsException();
            return false;
        }
        else {
            arraylist[index] = data;
            return true;
        }
    }

    void print() const {
        for (int i = 0; i < size; i++){
            cout << arraylist[i] << " ";
        }
        cout << endl;
    }

    bool isEmpty() const {
        return (size == 0);
    }

    void remove(int index) {
        if (index < 0 || index >= size) {
            throw OutofBoundsException();
        } else {
            for (int i = index; i < size-1; i++){
                arraylist[i] = arraylist[i + 1];
            }
            size--;
        }
    }
};

#endif
