#include "LinkedList.h"

int main() {

    LinkedList LL1 = LinkedList(10);
    LL1.print();
    LL1.remove_duplicates2();
    LL1.print();
    
    int ret;
    bool is_answer = LL1.kth_last_element2(4, ret);
    if (is_answer) {
        cout << ret << endl;
    }
    Node * retval;
    is_answer = LL1.kth_last_node(3, &retval);
    if (is_answer) {
        cout << retval->data << endl;
        delete_middle_node(retval);
        LL1.print();
        LL1.partition(5);
        LL1.print();
    }

    
    system("pause");
}