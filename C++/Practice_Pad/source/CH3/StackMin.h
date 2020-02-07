#ifndef STACK_MIN_H
#define STACK_MIN_H


class StackMin {
private:
	unsigned int size = 0;
	int* min_stack = nullptr;
	int* stack = nullptr;
	const int initial_capacity = 8;
	const int resizing_factor = 2;
	int current_capacity = 8;
	void copy(const StackMin& other);
	void cleanup();
	void grow();
public:
	StackMin();
	~StackMin();
	StackMin(const StackMin & other);
	StackMin & operator=(const StackMin& other);
	void push(int data);
	void pop();
	int peek() const;
	bool isEmpty() const;
	int getMin() const;
};

#endif