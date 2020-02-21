#include "pch.h"
#include "BinarySearchTree.h"

int bst_data[] = { 0, 1, 2, 3, 4, 5, 6 };

template <typename T>
void insert_array_min_height_bst(T* data, int length, BinarySearchTree<T> & bst) {

	int mid = (length-1) / 2; //index 2 is mid
	
	bst.insert(data[mid]); // insert index 2 into bst
	
	
	int size = length - 1;
	int size1 = size / 2 ; // size1 = 2
	int size2 = size - size1; // size2 = 3
	if (size1 > 0) {
		T* first_half = new T[size1];
		for (int i = 0; i < size1; i++) {
			first_half[i] = data[i];
		}
		insert_array_min_height_bst(first_half, size1, bst);
	}
	if (size2 > 0) {
		T* second_half = new T[size2];
	
		for (int i = mid + 1; i < size + 1; i++) {
			second_half[i - mid - 1] = data[i];
		}
		insert_array_min_height_bst(second_half, size2, bst);
	}
}

#if 1
int main() {
	BinarySearchTree<int> tree = BinarySearchTree<int>();
	insert_array_min_height_bst(bst_data, 3, tree);
	tree.print();
}
#endif