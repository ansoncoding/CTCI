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


l1 = LinkedList(10)
l1.print()
l1.remove_duplicates2()
l1.print()