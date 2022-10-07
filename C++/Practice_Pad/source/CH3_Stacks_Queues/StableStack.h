#ifndef STABLE_STACK_H
#define STABLE_STACK_H

#include "SimpleStack.h"

class StableStack {
private:
	unsigned int current_stack = 0;
	SimpleStack** stacks = nullptr;
	void copy(const StableStack& other);
	void cleanup();
	void start_new_stack();
public:
	StableStack();
	~StableStack();
	StableStack(const StableStack& other);
	StableStack& operator=(const StableStack& other);
	void push(int data);
	void pop();
	int peek() const;
	bool isEmpty() const;
};

#endif