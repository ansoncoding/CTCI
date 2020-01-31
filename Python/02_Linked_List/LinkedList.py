class Node:
    def __init__(self, data):
        self.data = data;
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None
        self.length = 0

    def print(self):
        temp = self.head
        while(temp is not None):
            print(str(temp.data) + " ", end='')
            temp = temp.next
        print("\n")

    def prepend(self, data):
        if self.head == None:
            self.head = Node(data)
            self.length += 1
        else:
            temp = Node(data)
            temp.next = self.head
            self.head = temp
            self.length += 1

    def __init__(self, list_length):
        self.head = None
        self.length = 0
        for i in range(0, list_length):
            self.prepend(i)
            self.prepend(i)
        

    def remove_duplicates(self):
        if self.head is None:
            return

        vals = set()
        vals.add(self.head.data)
        #print(vals)
        prev = self.head
        temp = self.head.next

        while(temp is not None):
            if temp.data in vals:
                prev.next = temp.next
                self.length-= 1
            else:
                vals.add(temp.data)
                prev = temp

            temp = temp.next
    
    def remove_duplicates2(self):
        if self.head is None:
            return

        
        valnode = self.head
        while(valnode is not None):
            prev = valnode
            val = valnode.data
            #print(str(val))
            temp = prev.next
            while(temp is not None):
                if temp.data == val:
                    prev.next = temp.next
                    self.length-=1
                else:
                    prev = temp
                temp = temp.next
            valnode = valnode.next

    def kth_last_node(self, k):
        if self.head is None:
            print("List is empty, cannot return " + str(k) + "th element")
            return False, 0

        if k == 0:
            print("K cannot be 0")
            return False, 0

        to_end = self.head
        k_last = self.head
        count = 0
        while(to_end is not None and count < k):
            to_end = to_end.next
            count += 1

        if count < k:
            print("List is " + str(count) + " elements long, cannot return " + str(k) + "th element")
            return False, 0

        while to_end is not None:
            to_end = to_end.next
            k_last = k_last.next

        return True, k_last

    def partition(self, k):
        passed = False
        temp = self.head
        prev = self.head
        while(temp is not None):
            if (temp.data < k):
                if not passed:
                    prev = temp
                    temp = temp.next
                    
                else:
                    prev.next = temp.next
                    temp.next = self.head
                    self.head = temp
                    temp = prev.next
            else:
                passed = True
                prev = temp
                temp = temp.next
                


# the node given is not the first nor last node of the list
def remove_middle_node(n):
    temp = n.next
    n.data = temp.data
    n.next = temp.next



l1 = LinkedList(10)
l1.print()
l1.remove_duplicates2()
l1.print()
is_answer, node = l1.kth_last_node(5)
if is_answer:
    print("answer is " + str(node.data))
    remove_middle_node(node)
    l1.print()
    l1.partition(4)
    l1.print()