#include "pch.h"
#include "SimpleStack.h"
#include "practice_exceptions.h"

SimpleStack::SimpleStack() {
	stack = new int[capacity];
}

SimpleStack::~SimpleStack() {
	cleanup();
}

SimpleStack::SimpleStack(const SimpleStack& other) {
	copy(other);
}

SimpleStack& SimpleStack::operator=(const SimpleStack& other) {
	if (&other != this) {
		cleanup();
		copy(other);
	}
	return *this;
}

void SimpleStack::copy(const SimpleStack& other) {
	
	stack = new int[capacity];
	
	for (unsigned int i = 0; i < other.size; i++) {
		stack[i] = other.stack[i];
	}
	size = other.size;
}

void SimpleStack::cleanup() {
	if (stack != NULL) {
		delete[] stack;
		stack = nullptr;
	}
	size = 0;
}

void SimpleStack::push(int data) {
	if (size == capacity) {
		cerr << "reached capacity" << endl;
		return;
	}
	stack[size] = data;
	size++;
}

unsigned int SimpleStack::getCapacity() const {
	return capacity;
}

unsigned int SimpleStack::getSize() const {
	return size;
}

void SimpleStack::pop() {
	size--;
}

int SimpleStack::peek() const {
	if (size == 0)
		throw OutofBoundsException();
	else
		return stack[size - 1];
}

bool SimpleStack::isEmpty() const {
	return size == 0;
}
