#include "LinkedList.h"

int main() {

    LinkedList LL1 = LinkedList(10);
    LL1.print();
    cout << LL1.getLength() << endl;
    LL1.remove_duplicates2();
    LL1.print();
    cout << LL1.getLength() << endl;
    
    system("pause");
}