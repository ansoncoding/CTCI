import LinkedListModule

class LinkedListT(LinkedListModule.LinkedList):

    def append(self, data):
        if self.head is None:
            self.head = LinkedListModule.Node(data)
            self.tail = self.head
            self.length += 1
            return
        temp = LinkedListModule.Node(data)
        self.tail.next = temp
        self.tail = self.tail.next
        self.length+=1
        return


    def setTail(self, node):
        self.tail.next = node
        self.tail = self.tail.next

    def __init__(self, list_length=None, circular=False, k=None, init_vals=None):
        if list_length is not None:
            self.head = None
            self.length = 0
            self.tail = None
            if init_vals is not None:
                for i in range(0, list_length):
                    self.append(init_vals[i])
            else:
                for i in range(0, list_length):
                    self.append(i)
                if circular:
                    if k is None:
                        self.tail.next = self.head
                    if k is not None:
                        k = k % list_length # in case the user enters k = 20 on a list that's 10 long
                        n = self.head
                        count = 0
                        while(n != None and k > count):
                            n = n.next
                            count += 1
                        self.tail.next = n
        else:
            LinkedListModule.LinkedList.__init__(self)
            self.tail = None
            self.length = 0
        return


    def prepend(self, data):
        if self.head == None:
            self.head = LinkedListModule.Node(data)
            self.tail = self.head
            self.length += 1
        else:
            temp = LinkedListModule.Node(data)
            temp.next = self.head
            self.head = temp
            self.length += 1
        return


    def reverse(self):
        retval = LinkedListT()
        temp = self.head;
        while (temp is not None):
            retval.prepend(temp.data)
            temp = temp.next
        return retval



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

    if previous_quotient > 0:
        retval.append(previous_quotient)

    return retval
