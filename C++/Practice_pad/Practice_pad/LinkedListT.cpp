#include "LinkedListT.h"

LinkedListT sum_lists(LinkedListT l1, LinkedListT l2) {
    LinkedListT retval = LinkedListT();
    Node * n1 = l1.getHead();
    Node * n2 = l2.getHead();

    int remainder = 0;
    int prev_quotient = 0;

    while ((n1 != NULL) || (n2 != NULL)) {
        int val1 = 0;
        int val2 = 0;
        if (n1 != NULL){
            val1 = n1->data;
        }
        if (n2 != NULL) {
            val2 = n2->data;
        }
        int sum = val1 + val2 + prev_quotient;
        remainder = sum % 10;
        
        retval.append(remainder);

        prev_quotient = sum / 10;
        if (n1 != NULL){
            n1 = l1.getNext(n1);
        }
        if (n2 != NULL) {
            n2 = l2.getNext(n2);
        }
    }
    if (prev_quotient > 0) {
        retval.append(prev_quotient);
    } 
    return retval;
}

