#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <iomanip>
#include <random>
#include "practice_exceptions.h"
#include "ArrayList.h"

using namespace std;

template <typename T>

class MinHeap : public ArrayList<T> {
private:
	void swap(int ind1, int ind2);
	void swapParent();
	void swapChildren(int currentInd);
	bool hasLeftChild(int k) const;
	bool hasRightChild(int k) const;
	unsigned int getLeftArrayIndex(unsigned int k) const;
	unsigned int getRightArrayIndex(unsigned int k) const;
	unsigned int getParentArrayIndex(unsigned int k) const;
public:
	MinHeap();
	void removeMin();
	void insert(T data);
	T getMin() const;
	void print() const;
	bool isEmpty() const;
};

template <typename T>
MinHeap<T>::MinHeap() {
	arraylist = new T[initial_capacity];
	memset(arraylist, 0, initial_capacity * sizeof(int));
	count = 1; //start at index 1
}

template <typename T>
unsigned int MinHeap<T>::getLeftArrayIndex(unsigned int k) const {
	return 2 * k;
}

template <typename T>
unsigned int MinHeap<T>::getRightArrayIndex(unsigned int k) const {
	return 2 * k + 1;
}

template <typename T>
unsigned int MinHeap<T>::getParentArrayIndex(unsigned int k) const {
	return k / 2;
}

template <typename T>
void MinHeap<T>::swap(int ind1, int ind2) {
	T temp = arraylist[ind1];
	arraylist[ind1] = arraylist[ind2];
	arraylist[ind2] = temp;
}

template <typename T>
void MinHeap<T>::swapParent() {
	int currentInd = count;
	int k = count;
	int parentInd = getParentArrayIndex(k);
	
	T parentVal = arraylist[parentInd];
	T currentVal = arraylist[currentInd];


	while (parentInd != 0 && parentVal > currentVal) {
		
		arraylist[currentInd] = parentVal;
		arraylist[parentInd] = currentVal;

		currentInd = parentInd;
		parentInd = getParentArrayIndex(parentInd);
		if (parentInd == 0) {
			break;
		}
		parentVal = arraylist[parentInd];
		currentVal = arraylist[currentInd];
	}
}

template <typename T>
bool MinHeap<T>::hasLeftChild(int k) const {
	return getLeftArrayIndex(k) < count;
}

template <typename T>
bool MinHeap<T>::hasRightChild(int k) const {
	return getRightArrayIndex(k) < count;
}

template <typename T>
void MinHeap<T>::swapChildren(int k) {
	
	int currentInd = k;
	T currentVal = arraylist[currentInd];
	int leftInd = getLeftArrayIndex(currentInd);
	int rightInd = getRightArrayIndex(currentInd);

	// has both children
	if (hasRightChild(currentInd) && hasLeftChild(currentInd)) {
		T leftVal = arraylist[leftInd];
		T rightVal = arraylist[rightInd];

		//both children are smaller than parent, swap with smaller child
		if (leftVal < currentVal && rightVal < currentVal) {

			if (leftVal < rightVal) {
				//swap parent with left val
				swap(leftInd, currentInd);
				currentInd = leftInd;
			}
			else {
				//swap parent with right val
				swap(rightInd, currentInd);
				currentInd = rightInd;
			}
		}
		else if (leftVal < currentVal) {
			//swap parent with left val
			swap(leftInd, currentInd);
			currentInd = leftInd;
		}
		else if (rightVal < currentVal) {
			//swap parent with right val
			swap(rightInd, currentInd);
			currentInd = rightInd;
		}
		else {
			return; // both children are greater than the parent, we're done
		}
	}
	else if (hasLeftChild(currentInd)) {
		T leftVal = arraylist[leftInd]; 
		if (leftVal < currentVal) {
			//swap parent with left val
			swap(leftInd, currentInd);
			currentInd = leftInd;
		}
		else {
			return; // we're done, the only child it has is greater
		}
	}
	else if (hasRightChild(currentInd)){
		T rightVal = arraylist[rightInd];
		if (rightVal < currentVal) {
			//swap parent with right val
			swap(rightInd, currentInd);
			currentInd = rightInd;
		}
		else {
			return; // we're done, the only child it has is greater
		}
	}
	else {
		return; // we're done, node has no children 
	}
	swapChildren(currentInd);
}

template <typename T>
void MinHeap<T>::removeMin() {
	if (count <= 1) {
		throw OutofBoundsException();
	}
	if (count == 2) {
		count--;
		return;
	}
	T temp = arraylist[count-1]; //this is the last element in the heap
	arraylist[1] = temp;
	swapChildren(1);
	count--;
}

template <typename T>
void MinHeap<T>::insert(T data) {

	if (count == current_capacity) {
		grow();
	}
	arraylist[count] = data;
	swapParent();	
	count++;
}


template <typename T>
bool MinHeap<T>::isEmpty() const {
	return (count == 1);
}


template <typename T>
T MinHeap<T>::getMin() const {
	if (count <= 1) {
		throw OutofBoundsException();
	}
	return arraylist[1];
}

template <typename T>
void MinHeap<T>::print() const {
	if (count <= 1) {
		cout << "The heap is empty" << endl;
		return;
	}
	for (int i = 1; i < count; i++) {
		cout << arraylist[i] << " ";
	}
	cout << endl;
}

#endif
