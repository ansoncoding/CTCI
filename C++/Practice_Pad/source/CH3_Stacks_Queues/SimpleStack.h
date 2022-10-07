#ifndef SIMPLE_STACK_H
#define SIMPLE_STACK_H

class SimpleStack {
private:
	unsigned int size = 0;
	int* stack = nullptr;
	const unsigned int capacity = 64;
	void copy(const SimpleStack& other);
	void cleanup();
	
public:
	SimpleStack();
	~SimpleStack();
	SimpleStack(const SimpleStack& other);
	SimpleStack& operator=(const SimpleStack& other);
	void push(int data);
	void pop();
	int peek() const;
	bool isEmpty() const;
	unsigned int getCapacity() const;
	unsigned int getSize() const;
};

#endif