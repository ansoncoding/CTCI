import LinkedListModule

class LinkedListT(LinkedListModule.LinkedList):

    def append(self, data):
        if self.head is None:
            self.head = LinkedListModule.Node(data)
            #self.tail = self.head
            self.head.next = self.tail
            self.length += 1
            return

        if self.tail is None:
            self.tail = LinkedListModule.Node(data)
            self.head.next = self.tail
            self.length += 1
            return
        
        temp = LinkedListModule.Node(data)
        self.tail.next = temp
        self.tail = self.tail.next
        self.length+=1
        return

    def __init__(self, list_length=None):
        if list_length is not None:
            self.head = None
            self.length = 0
            self.tail = None
            for i in range(0, list_length):
                self.append(i)
        else:
            LinkedListModule.LinkedList.__init__(self, list_length)
            self.tail = None
            self.length = 0
            

def sum_lists(LLT1, LLT2):
    n1 = LLT1.head
    n2 = LLT2.head
    previous_quotient = 0
    retval = LinkedListT()

    while (n1 is not None or n2 is not None):
        val1 = 0
        val2 = 0
        if n1 is not None:
            val1 = n1.data
        if n2 is not None:
            val2 = n2.data
        the_sum = val1 + val2 + previous_quotient
        remainder = the_sum % 10
        retval.append(remainder)
        previous_quotient = the_sum // 10
    
        if n1 is not None:
            n1 = n1.next
        if n2 is not None:
            n2 = n2.next
            
    return retval

LLT1 = LinkedListT(7)
LLT1.print()
LLT2 = LinkedListT(4)
LLT2.print()
soln = sum_lists(LLT1, LLT2)
soln.print()

