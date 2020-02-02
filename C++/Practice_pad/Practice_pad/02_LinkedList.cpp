#include "LinkedList.h"
#include "LinkedListT.h"

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

    //LinkedListT LLT = LinkedListT(3);
    //LinkedListT LLT2 = LinkedListT(7);
    //LLT.print();
    //LLT2.print();
    //LinkedListT LLT_sum = sum_lists(LLT, LLT2);
    //LLT_sum.print();
    //LLT_sum.prepend(18);
    //LLT_sum.print();
    //
    //LinkedList LLr = LLT_sum.reverse();
    //LLr.print();

    //LinkedListT LLT_sum_r =  LLT_sum.reverse();
    //LLT_sum_r.print();

    /*LinkedListT ll = LinkedListT();
    for (int i = 0; i < 4; i++){
        ll.prepend(i);
        ll.append(i);
    }
    ll.print();
    cout << ll.is_palindrome() << endl;

    LinkedList ll1 = LinkedList();
    for (int i = 0; i < 4; i++){
        ll1.prepend(i);
    }
    for (int i = 1; i >= 0; i--) {
        ll1.prepend(i);
    }
    
    ll1.print();
    cout << ll1.is_palindrome() << endl;*/


    Node * retval;

    LinkedListT cir = LinkedListT(10, true);
    cir.print(20);
    bool isloop = loop_detection(cir, &retval);
    cout << "is loop? " << isloop << endl;
    if (isloop)
        cout << retval->data << endl;

    LinkedList ll = LinkedList(10);
    ll.print();
    isloop = loop_detection(ll, &retval);
    cout << "is loop? " << isloop << endl;
    if (isloop)
        cout << retval->data << endl;
    system("pause");
}