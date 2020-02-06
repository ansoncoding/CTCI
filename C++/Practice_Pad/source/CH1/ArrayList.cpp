#include "pch.h"
#include "ArrayList.h"
#include "practice_exceptions.h"

using namespace std;

ArrayList::ArrayList() {
    arraylist = new int[initial_capacity];
    memset(arraylist, 0, initial_capacity*sizeof(int));
}
    
ArrayList::ArrayList(const ArrayList& other) {
    copy(other);
}
    
ArrayList& ArrayList::operator=(const ArrayList& other) {
    return ArrayList(other);
}

ArrayList::~ArrayList() {
    delete[] arraylist;
    arraylist = nullptr;
}

void ArrayList::copy(const ArrayList& other) {
    current_capacity = other.current_capacity;
    arraylist = new int[current_capacity];
    memset(arraylist, 0, current_capacity * sizeof(int));

    for (int i = 0; i < other.size; i++) {
        arraylist[i] = other.arraylist[i];
    }
    size = other.size;
}
    
void ArrayList::add(int data) {
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

int ArrayList::getSize() const {
    return size;
}

int ArrayList::getCapacity() const {
    return current_capacity;
}

int ArrayList::get(int index) const {
    if (index < size && index >= 0)
        return arraylist[index];
    else {
        throw OutofBoundsException();
        return -1;
    }
}

bool ArrayList::contains(int value, int& retval_ind) {
    for (int i = 0; i < size; i++) {
        if (arraylist[i] == value) {
            retval_ind = i;
            return true;
        }
    }
    return false;
}

void ArrayList::set(int index, int data) {
    if (index < 0 || index >= size) {
        throw OutofBoundsException();
    }
    else {
        arraylist[index] = data;
    }
}

void ArrayList::print() const {
    for (int i = 0; i < size; i++){
        cout << arraylist[i] << " ";
    }
    cout << endl;
}

bool ArrayList::isEmpty() const {
    return (size == 0);
}

void ArrayList::remove(int index) {
    if (index < 0 || index >= size) {
        throw OutofBoundsException();
    } else {
        for (int i = index; i < size-1; i++){
            arraylist[i] = arraylist[i + 1];
        }
        size--;
    }
}
