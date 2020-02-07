#ifndef TRI_STACK_H
#define TRI_STACK_H


enum Stack{
    one, two, three
};

class TriStack {

private:
    const int initial_capacity = 8; // per stack
    const int resizing_factor = 2;
    int current_capacity = 8; // per stack
    int size[3] = {0};
    int* onearray = nullptr;
private:
    void cleanup();
    void copy(const TriStack& other);
    int getStackPushIndex(Stack stack) const;
    int getStackTopIndex(Stack stack) const;
public:
    TriStack();
    ~TriStack();
    TriStack(const TriStack& other);
    TriStack& operator=(const TriStack& other);
    void push(Stack stack, int data);
    int peek(Stack stack) const;
    void pop(Stack stack);
    bool isEmpty(Stack stack) const;

};
#endif