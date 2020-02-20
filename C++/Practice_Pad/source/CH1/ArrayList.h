#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include "practice_exceptions.h"
using namespace std;

template <typename T>
class ArrayList {

protected:
    const int initial_capacity = 8;
    const int resizing_factor = 2;
    int current_capacity = 8;
    int count = 0;
    T * arraylist;
    void copy(const ArrayList& other);
    void cleanup();
    void grow();
public:
    ArrayList();
    ArrayList(const ArrayList& other);
    ArrayList& operator=(const ArrayList& other);
    ~ArrayList();
    void add(T data);
    int getSize() const ;
    int getCapacity() const;
    T get(int index) const;
    bool contains(T value, int& retval_ind);
    void set(int index, T data);
    void print() const;
    virtual bool isEmpty() const;
    void remove(int index);
    void removeByVal(T data);
};




template <typename T>
ArrayList<T>::ArrayList() {
    arraylist = new T[initial_capacity];
    memset(arraylist, 0, initial_capacity * sizeof(int));
}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList& other) {
    copy(other);
}

template <typename T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList& other) {
    if (&other != this) {
        cleanup();
        copy(other);
    }
    return *this;
}

template <typename T>
void ArrayList<T>::cleanup() {
    delete[] arraylist;
    arraylist = nullptr;
}

template <typename T>
ArrayList<T>::~ArrayList() {
    cleanup();
}

template <typename T>
void ArrayList<T>::copy(const ArrayList& other) {
    current_capacity = other.current_capacity;
    arraylist = new int[current_capacity];
    memset(arraylist, 0, current_capacity * sizeof(int));

    for (int i = 0; i < other.count; i++) {
        this->arraylist[i] = other.arraylist[i];
    }
    count = other.count;
}

template <typename T>
void ArrayList<T>::grow() {
    T* newarraylist = new T[current_capacity * resizing_factor];
    current_capacity *= resizing_factor;
    memset(newarraylist, 0, current_capacity * sizeof(int));

    for (int i = 0; i < count; i++) {
        newarraylist[i] = arraylist[i];
    }

    delete[] arraylist;
    arraylist = newarraylist;
}

template <typename T>
void ArrayList<T>::add(T data) {
    if (count == current_capacity) {
        grow();
        arraylist[count] = data;
        count++;
    }
    else {
        arraylist[count] = data;
        count++;
    }
}

template <typename T>
int ArrayList<T>::getSize() const {
    return count;
}

template <typename T>
int ArrayList<T>::getCapacity() const {
    return current_capacity;
}

template <typename T>
T ArrayList<T>::get(int index) const {
    if (index < count && index >= 0)
        return arraylist[index];
    else {
        throw OutofBoundsException();
    }
}

template <typename T>
bool ArrayList<T>::contains(T value, int& retval_ind) {
    for (int i = 0; i < count; i++) {
        if (arraylist[i] == value) {
            retval_ind = i;
            return true;
        }
    }
    return false;
}

template <typename T>
void ArrayList<T>::set(int index, T data) {
    if (index < 0 || index >= count) {
        throw OutofBoundsException();
    }
    else {
        arraylist[index] = data;
    }
}

template <typename T>
void ArrayList<T>::print() const {
    for (int i = 0; i < count; i++) {
        cout << arraylist[i] << " ";
    }
    cout << endl;
}

template <typename T>
bool ArrayList<T>::isEmpty() const {
    return (count == 0);
}

template <typename T>
void ArrayList<T>::remove(int index) {
    if (index < 0 || index >= count) {
        throw OutofBoundsException();
    }
    else {
        for (int i = index; i < count - 1; i++) {
            arraylist[i] = arraylist[i + 1];
        }
        count--;
    }
}

template <typename T>
void ArrayList<T>::removeByVal(T data) {
    
    for (int i = 0; i < count; i++) {
        if (arraylist[i] == data) {
            remove(i);
        }
    }    
}

#endif
