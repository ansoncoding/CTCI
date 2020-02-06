#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

class ArrayList {

private:
    const int initial_capacity = 8;
    const int resizing_factor = 2;
    int current_capacity = 8;
    int size = 0;
    int * arraylist;
    void copy(const ArrayList& other);
    void cleanup();
public:
    ArrayList();
    ArrayList(const ArrayList& other);
    ArrayList& operator=(const ArrayList& other);
    ~ArrayList();
    void add(int data);
    int getSize() const ;
    int getCapacity() const;
    int get(int index) const;
    bool contains(int value, int& retval_ind);
    void set(int index, int data);
    void print() const;
    bool isEmpty() const;
    void remove(int index);
};

#endif
