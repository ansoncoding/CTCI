#ifndef DUAL_STACK_QUEUE_H
#define DUAL_STACK_QUEUE_H

#include "StackMin.h"

class DSQueue {

private:
	unsigned int size = 0;
	StackMin stacks[2];
	void copy(const DSQueue& other);
	void turn_over_stack();
	bool stack_ind = 0;

public:
	DSQueue();
	~DSQueue();
	DSQueue& operator=(const DSQueue& other);
	DSQueue(const DSQueue & other);
	int peek(bool pop_after = false); //since we're doing dual stack queue, we can given the option to save some moves
	void add(int data);
	void remove(int count=1);
	bool isEmpty() const;
};

#endif
