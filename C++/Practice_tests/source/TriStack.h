#ifndef TRI_STACK_H
#define TRI_STACK_H
#include <iostream>
using namespace std;
enum Stack{
    one, two, three
};

class TriStack {

private:
    const int initial_capacity = 8; // per stack
    const int resizing_factor = 2;
    int current_capacity = 8; // per stack
    int size[3] = {0};
    int* onearray;
private:
    int getStackPushIndex(Stack stack) const {
        return size[stack] * 3 + stack;
    }

    int getStackTopIndex(Stack stack) const {
        if (size[stack] == 0) {
            cerr << "Stack is empty" << endl;
            return -1;
        }
        return (size[stack] - 1) * 3 + stack;
    }
public:

    TriStack(){
        onearray = new int[initial_capacity * 3];
    }

    TriStack(const TriStack & other) {
        copy(other);
    }

    void copy(const TriStack & other) {
        current_capacity = other.current_capacity;
        int max_size = 0;
        for (int i = 0; i < 3; i++) {
            size[i] = other.size[i];
            if (size[i] > max_size)
                max_size = size[i];
        }
        onearray = new int[current_capacity*3];

        for (int i = 0; i < max_size * 3 + 3; i++) {
            onearray[i] = other.onearray[i];
        }
    }



    bool pop(Stack stack) {
        if (size[stack] == 0) {
            cerr << "Stack is empty, cannot pop" << endl;
            return false;
        }
        size[stack]--;   
        return true;
    }

    int peek(Stack stack) const {
        if (size[stack] == 0) {
            cerr << "Stack is empty, cannot peek" << endl;
            return -1;
        }
        int index = getStackTopIndex(stack);
        return onearray[index];
    }

    bool push(Stack stack, int data) {
        
        if (size[stack] == current_capacity) {
            int * newonearray;

            try {
                newonearray = new int[current_capacity*resizing_factor*3];
            } catch (bad_alloc& ba) {
                std::cerr << "bad_alloc caught: " << ba.what() << '\n';
                return false;
            }
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
        return true;
    }

    bool isEmpty(Stack stack) const {
        return size[stack] == 0;
    }

    ~TriStack(){
        delete[] onearray;
        onearray = NULL;
    }

};
#endif