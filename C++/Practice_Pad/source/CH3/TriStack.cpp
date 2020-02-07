#include "pch.h"
#include "TriStack.h"
#include "practice_exceptions.h"

#include <iostream>

using namespace std;

TriStack::TriStack(){
    onearray = new int[initial_capacity * 3];
}

TriStack::TriStack(const TriStack & other) {
    copy(other);
}

TriStack& TriStack::operator=(const TriStack& other) {
    if (&other != this) {
        cleanup();
        copy(other);
    }
    return *this;
}

int TriStack::getStackPushIndex(Stack stack) const {
    return size[stack] * 3 + stack;
}

int TriStack::getStackTopIndex(Stack stack) const {
    if (size[stack] == 0) {
        throw OutofBoundsException();
        return -1;
    }
    return (size[stack] - 1) * 3 + stack;
}

void TriStack::copy(const TriStack & other) {
    current_capacity = other.current_capacity;
    int max_size = 0;
    for (int i = 0; i < 3; i++) {
        size[i] = other.size[i];
        if (size[i] > max_size)
            max_size = size[i];
    }
    onearray = new int[current_capacity*3];

    for (int i = 0; i < max_size * 3 ; i++) {
        onearray[i] = other.onearray[i];
    }
}

void TriStack::pop(Stack stack) {
    if (size[stack] == 0) {
        throw OutofBoundsException();
        return;
    }
    size[stack]--;   
}

int TriStack::peek(Stack stack) const {
    if (size[stack] == 0) {
        throw OutofBoundsException();
        return -1;
    }
    int index = getStackTopIndex(stack);
    if (index == -1)
        throw OutofBoundsException();

    return onearray[index];
}

void TriStack::push(Stack stack, int data) {
        
    if (size[stack] == current_capacity) {
        int * newonearray;
        newonearray = new int[current_capacity*resizing_factor*3];

        current_capacity *= resizing_factor;
        delete[] onearray;
        onearray = newonearray;
        int index = getStackPushIndex(stack);
        onearray[index] = data;
        size[stack]++;
    }
    else {
        int index = getStackPushIndex(stack);
        onearray[index] = data;
        size[stack]++;
    }
}

bool TriStack::isEmpty(Stack stack) const {
    return size[stack] == 0;
}

void TriStack::cleanup() {
    if (onearray != NULL) {
        delete[] onearray;
        onearray = NULL;
    }
}
TriStack::~TriStack(){
    cleanup();
}