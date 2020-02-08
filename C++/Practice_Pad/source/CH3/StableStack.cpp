#include "pch.h"
#include "StableStack.h"
#include "practice_exceptions.h"

StableStack::StableStack() {
	stacks = new SimpleStack * [1];
	stacks[0] = new SimpleStack();
}

StableStack::~StableStack() {
	cleanup();
}

StableStack::StableStack(const StableStack& other) {
	copy(other);
}

StableStack& StableStack::operator=(const StableStack& other) {
	if (&other != this) {
		cleanup();
		copy(other);
	}
	return *this;
}

void StableStack::copy(const StableStack& other) {
	current_stack = other.current_stack;
	int curr_num_stacks = current_stack + 1;
	stacks = new SimpleStack * [curr_num_stacks];
	for (int i = 0; i < curr_num_stacks; i++) {
		stacks[i] = new SimpleStack(*other.stacks[i]);
	}
}

void StableStack::cleanup() {
	if (stacks != NULL) {
		for (int i = 0; i < current_stack+1; i++) {
			stacks[i] -> ~SimpleStack();
		}
		delete[] stacks;
		stacks = NULL;
	}
	current_stack = 0;
}

void StableStack::start_new_stack() {
	int curr_num_stacks = current_stack + 1;
	
	SimpleStack** new_stacks = new SimpleStack * [curr_num_stacks+1];
	for (int i = 0; i < curr_num_stacks; i++) {
		new_stacks[i] = stacks[i];
	}
	new_stacks[current_stack + 1] = new SimpleStack();
	//???
	delete stacks;
	stacks = new_stacks;
	current_stack++;
}

void StableStack::push(int data) {
	if (stacks[current_stack]->getSize() == stacks[current_stack]->getCapacity()) {
		start_new_stack();
	}
	stacks[current_stack]->push(data);
}

void StableStack::pop() {
	stacks[current_stack]->pop();
	if (stacks[current_stack]->isEmpty() && (current_stack != 0)) { // we have emptied a stack
		//delete the stack if it's not the first stack (basic stack)
		stacks[current_stack]->~SimpleStack();
		current_stack--;
	}
}

int StableStack::peek() const {
	return stacks[current_stack]->peek();
}

bool StableStack::isEmpty() const {
	return current_stack == 0 && stacks[current_stack]->isEmpty();
}
