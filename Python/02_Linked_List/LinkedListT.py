import LinkedListModule

class LinkedListT(LinkedListModule.LinkedList):

    def append(self, data):
        if self.head is None:
            self.head = LinkedListModule.Node(data)
            self.head = self.tail
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
        self.print()

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

    return retval

# LLT1 = LinkedListT(7)
# LLT1.print()
# LLT2 = LinkedListT(4)
# LLT2.print()
# LLT2.prepend(8)
# LLT2.print()
# LLT3 = LLT2.reverse()
# LLT3.print()
# LLT3.prepend(2)
# LLT3.print()
#soln = sum_lists(LLT1, LLT2)
#soln.print()

LT1 = LinkedListT()

for i in range(0,3):
    LT1.prepend(i)
    LT1.append(i)

LT1.print()
LT2 = LT1.reverse()
LT2.print()
print(LT1.isPalindrome())