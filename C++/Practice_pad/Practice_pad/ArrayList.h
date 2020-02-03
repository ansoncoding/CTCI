#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

class ArrayList {

private:
    const int initial_capacity = 8;
    const int resizing_factor = 2;
    int current_capacity = 8;
    int size = 0;
    int * arraylist;
    
public:
    ArrayList() {
        arraylist = new int[initial_capacity];
        memset(arraylist, 0, initial_capacity*sizeof(int));
    }
    
    void add(int data) {
        if (size == current_capacity) {
            int * newarraylist = new int[current_capacity * resizing_factor];
            current_capacity *= resizing_factor;
            memset(newarraylist, 0, current_capacity * sizeof(int));

            for (int i = 0; i < size; i++){
                newarraylist[i] = arraylist[i];
            }
            
            delete[] arraylist;
            arraylist = newarraylist;
            arraylist[size] = data;
            size++;
        }
        else {
            arraylist[size] = data;
            size++;
        }
    }

    int getSize(){
        return size;
    }
    int getCapacity() {
        return current_capacity;
    }
    int get(int index) {
        if (index < current_capacity)
            return arraylist[index];
        else {
            cerr << "Index is out of bounds for ArrayList" << endl;
            return -1;
        }
    }
    bool set(int index, int data) {
        if (index < 0 || index >= size) {
            cerr << "Index out of bounds" << endl;
            return false;
        }
        else {
            arraylist[index] = data;
            return true;
        }
    }
    void print(){
        for (int i = 0; i < size; i++){
            cout << arraylist[i] << " ";
        }
        cout << endl;
    }
    bool isEmpty(){
        return (size == 0);
    }

    bool remove(int index) {
        if (index < 0 || index >= size) {
            cerr << "Index out of bounds" << endl;
            return false;
        } else {
            for (int i = index; i < size-1; i++){
                arraylist[i] = arraylist[i + 1];
            }
            size--;
            return true;
        }
    }
};

#endif
