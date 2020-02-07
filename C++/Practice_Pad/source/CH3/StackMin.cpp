#include "pch.h"
#include "StackMin.h"
#include "practice_exceptions.h"

StackMin::StackMin() {
	stack = new int[initial_capacity];
	min_stack = new int[initial_capacity];
}

StackMin::~StackMin() {
	cleanup();
}

StackMin::StackMin(const StackMin& other) {
	copy(other);
}

StackMin& StackMin::operator=(const StackMin& other) {
	if (&other != this) {
		cleanup();
		copy(other);
	}
	return *this;
}

void StackMin::copy(const StackMin& other) {
	current_capacity = other.current_capacity;
	stack = new int[current_capacity];
	min_stack = new int[current_capacity];
	for (unsigned int i = 0; i < other.size; i++) {
		stack[i] = other.stack[i];
		min_stack[i] = other.min_stack[i];
	}
	size = other.size;
}

void StackMin::cleanup() {
	if (stack != nullptr) {
		delete[] stack;
		stack = nullptr;
	}
	if (min_stack != nullptr) {
		delete[] min_stack;
		min_stack = nullptr;
	}
}

void StackMin::grow() {
	int* new_stack = new int[current_capacity * resizing_factor];
	int* new_min_stack = new int[current_capacity * resizing_factor];
	for (unsigned int i = 0; i < size; i++) {
		new_stack[i] = stack[i];
		new_min_stack[i] = min_stack[i];
	}
	delete[] stack;
	delete[] min_stack;
	stack = new_stack;
	min_stack = new_min_stack;
	current_capacity *= resizing_factor;
}

void StackMin::push(int data) {
	if (size == current_capacity) {
		grow();
	}
	stack[size] = data;
	if (size == 0) {
		min_stack[size] = data;
	}
	else {
		if (data < min_stack[size - 1]) {
			min_stack[size] = data;
		}
		else {
			min_stack[size] = min_stack[size - 1];
		}
	}
}

void StackMin::pop() {
	size--;
}

int StackMin::peek() const {
	if (size == 0)
		throw OutofBoundsException();
	else
		return stack[size - 1];
}

bool StackMin::isEmpty() const {
	return size == 0;
}

int StackMin::getMin() const {
	if (size == 0)
		throw OutofBoundsException();
	else
		return min_stack[size - 1];
}
