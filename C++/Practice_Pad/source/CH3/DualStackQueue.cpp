#include "pch.h"
#include "DualStackQueue.h"
#include "practice_exceptions.h"

void DSQueue::copy(const DSQueue& other) {
	size = other.size;
	stacks[0] = other.stacks[0];
	stacks[1] = other.stacks[1];
	stack_ind = other.stack_ind;
}

void DSQueue::turn_over_stack() {
	for (int i = 0; i < size; i++) {
		stacks[!stack_ind].push(stacks[stack_ind].peek());
		stacks[stack_ind].pop();
	}
	stack_ind = !stack_ind;
}

DSQueue::DSQueue() {
	size = 0;
	stack_ind = 0;
}

DSQueue::~DSQueue() {

}

DSQueue::DSQueue(const DSQueue& other) {
	copy(other);
}

DSQueue& DSQueue::operator=(const DSQueue& other) {
	if (&other != this) {
		copy(other);
	}
	return *this;
}

int DSQueue::peek(bool pop_after) {
	if (size == 0) {
		throw OutofBoundsException();
	}
	turn_over_stack();

	int retval = stacks[stack_ind].peek();
	if (pop_after) {
		stacks[stack_ind].pop();
		size--;
	}
	turn_over_stack();
	return retval;
}

void DSQueue::add(int data) {
	stacks[stack_ind].push(data);
	size++;
}

void DSQueue::remove(int count) {
	turn_over_stack();
	for (int i = 0; i < count; i++) {
		stacks[stack_ind].pop();
		size--;
	}
	turn_over_stack();
}

bool DSQueue::isEmpty() const {
	return size == 0;
}
