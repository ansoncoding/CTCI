#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <iomanip>
#include <random>
#include "practice_exceptions.h"
#include "ArrayList.h"

using namespace std;

template <typename T>

class MinHeap : public ArrayList {
private:
	void swap(int ind1, int ind2);
	void swapParent();
	void swapChildren();
	bool hasLeftChild(int k) const;
	bool hasRightChild(int k) const;
	unsigned int getLeftArrayIndex(unsigned int k) const;
	unsigned int getRightArrayIndex(unsigned int k) const;
	unsigned int getParentArrayIndex(unsigned int k) const;
public:
	
	void removeMin();
	void insert(T data);
	T getMin() const;
	void print() const;
};

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
	int currentInd = size;
	int k = size;
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
	return getLeftArrayIndex(k) <= size;
}

template <typename T>
bool MinHeap<T>::hasRightChild(int k) const {
	return getRightArrayIndex(k) <= size;
}

template <typename T>
void MinHeap<T>::swapChildren() {
	int currentInd = 1; //root
	
	
	while (currentInd < size) {
		
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
				break; // both children are greater than the parent, we're done
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
				break; // we're done, the only child it has is greater
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
				break; // we're done, the only child it has is greater
			}
		}
	}
}

template <typename T>
void MinHeap<T>::removeMin() {
	if (size == 0) {
		throw OutofBoundsException();
	}
	if (size == 1) {
		size--;
		return;
	}
	T temp = arraylist[size];
	arraylist[1] = temp;
	size--;
	swapChildren();
}

template <typename T>
void MinHeap<T>::insert(T data) {
	
	size++;
	arraylist[size] = data;
	swapParent();	
}

template <typename T>
T MinHeap<T>::getMin() const {
	if (size == 0) {
		throw OutofBoundsException();
	}
	return arraylist[1];
}

template <typename T>
void MinHeap<T>::print() const {
	if (size == 0) {
		cout << "The heap is empty" << endl;
		return;
	}
	for (int i = 1; i < size+1; i++) {
		cout << arraylist[i] << " ";
	}
	cout << endl;
}

#endif
