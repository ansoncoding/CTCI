#include "LinkedList.h"

int main() {

    //LinkedList LL1 = LinkedList(10);
    //LL1.print();
    //LL1.remove_duplicates2();
    //LL1.print();
    //
    //int ret;
    //bool is_answer = LL1.kth_last_element2(4, ret);
    //if (is_answer) {
    //    cout << ret << endl;
    //}
    //Node * retval;
    //is_answer = LL1.kth_last_node(3, &retval);
    //if (is_answer) {
    //    cout << retval->data << endl;
    //    delete_middle_node(retval);
    //    LL1.print();
    //    LL1.partition(5);
    //    LL1.print();
    //}

    LinkedListT LLT = LinkedListT(1);
    LinkedListT LLT2 = LinkedListT(7);
    LLT.print();
    LLT2.print();
    LinkedListT LLT_sum = sum_lists(LLT, LLT2);
    LLT_sum.print();

    system("pause");
}