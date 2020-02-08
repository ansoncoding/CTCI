#ifndef DUAL_STACK_QUEUE_H
#define DUAL_STACK_QUEUE_H

#include "StackMin.h"

class DSQueue {

private:
	const int newest = 0;
	const int oldest = 1;
	StackMin stacks[2];
	void copy(const DSQueue& other);
	void update_oldest_stack();

public:
	DSQueue();
	~DSQueue();
	DSQueue& operator=(const DSQueue& other);
	DSQueue(const DSQueue & other);
	int peek(); //since we're doing dual stack queue, we can given the option to save some moves
	void add(int data);
	void remove();
	bool isEmpty() const;
};

#endif
