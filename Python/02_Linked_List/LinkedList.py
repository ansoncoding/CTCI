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
        self.print()


LinkedList(10)