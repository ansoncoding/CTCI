#include "LinkedList.h"

int main() {

    LinkedList LL1 = LinkedList(10);
    LL1.print();
    LL1.remove_duplicates2();
    LL1.print();
    
    int ret;
    int is_answer = LL1.kth_last_element2(4, ret);
    if (is_answer) {
        cout << ret << endl;
    } 
    
    system("pause");
}