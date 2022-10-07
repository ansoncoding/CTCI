#include "pch.h"
#include "DualStackQueue.h"
#include "practice_exceptions.h"

void DSQueue::copy(const DSQueue& other) {
	stacks[0] = other.stacks[0];
	stacks[1] = other.stacks[1];
}

void DSQueue::update_oldest_stack() {
	if (stacks[oldest].isEmpty()) {
		while (!stacks[newest].isEmpty()) {
			stacks[oldest].push(stacks[newest].peek());
			stacks[newest].pop();
		}
	}
}

DSQueue::DSQueue() {

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

int DSQueue::peek() {
	if (stacks[newest].isEmpty() && stacks[oldest].isEmpty()) {
		throw OutofBoundsException();
	}
	update_oldest_stack();

	return stacks[oldest].peek();
}

void DSQueue::add(int data) {
	stacks[newest].push(data);
}

void DSQueue::remove() {
	if (stacks[newest].isEmpty() && stacks[oldest].isEmpty()) {
		throw OutofBoundsException();
	}
	update_oldest_stack();
	stacks[oldest].pop();
}

bool DSQueue::isEmpty() const {
	return stacks[newest].isEmpty() && stacks[oldest].isEmpty();
}

void DSQueue::EmptyQueueIntoString(std::string& ret) {
	
	for (int i = 0; isEmpty() != true; i++) {
		ret.append(std::to_string(peek()));
		remove();
	}
}