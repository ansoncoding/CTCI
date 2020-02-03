class Node:

    def __init__(self, data):
        self.data = data;
        self.next = None
        return


class LinkedList:

    def print(self, length=None):
        temp = self.head
        if length is not None:
            count = 0
            while(temp is not None and count < length):
                print(str(temp.data) + " ", end='')
                temp = temp.next
                count += 1
            print("\n")
        else:
            while(temp is not None):
                print(str(temp.data) + " ", end='')
                temp = temp.next
            print("\n")
        return


    def prepend(self, data):
        if self.head == None:
            self.head = Node(data)
            self.length += 1
        else:
            temp = Node(data)
            temp.next = self.head
            self.head = temp
            self.length += 1
        return


    def __init__(self, list_length=None):
        if list_length is not None:
            self.head = None
            self.length = 0
            for i in range(0, list_length):
                self.prepend(i)
                self.prepend(i)
        else:
            self.head = None
            self.length = 0
        return


    def remove_duplicates(self):
        if self.head is None:
            return

        vals = set()
        vals.add(self.head.data)
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
        return


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
        return


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
        return


    def reverse(self):
        retval = LinkedList()
        temp = self.head;
        while (temp is not None):
            retval.prepend(temp.data)
            temp = temp.next
        return retval


    def isPalindrome(self):
        if(self.head is None):
            print("List is empty")
            return False
        rev = self.reverse()
        rev.print()
        n1 = self.head
        n2 = rev.head
        while(n1 is not None):
            if (n1.data != n2.data):
                #print("n1 : " + str(n1.data) + " n2 : " + str(n2.data))
                return False
            n1 = n1.next
            n2 = n2.next
        return True

    def loop_detection(self):
        if self.head is None:
            print("List is empty")
            return False, None
        n1 = self.head
        n2 = self.head
        passed = False

        while (n1 is not None and n2 is not None):
            if n1 == n2:
                if not passed:
                    passed = True
                else: # loop detected
                    n1 = self.head
                    while(n1 != n2):
                        n1 = n1.next
                        n2 = n2.next
                    return True, n1
            n1 = n1.next
            n2 = n2.next
            if (n2 is not None):
                n2 = n2.next
            else:
                return False, None # tail reached, no loop
        return False, None # tail reached, no loop



# the node given is not the first nor last node of the list
def remove_middle_node(n):
    temp = n.next
    n.data = temp.data
    n.next = temp.next
    return


def is_intersecting(l1, l2):
    t1 = l1.head
    t1_prev = None
    t2 = l2.head
    t2_prev = None
    len1 = 0
    len2 = 0
    while t1 is not None:
        t1_prev = t1
        t1 = t1.next
        len1+= 1
        
    while t2 is not None:
        t2_prev = t2
        t2 = t2.next
        len2 += 1

    if (t1_prev != t2_prev): # compare tails
        return False

    if (len1 != len2):
        len_diff = abs(len2 - len1)
        longer = l1 if len1 > len2 else l2
        shorter = l2 if len1 > len2 else l1
        k = (len1 if len1 > len2 else len2) - len_diff
        ret, node = longer.kth_last_node(k)
        if ret:
            n1 = node
            n2 = shorter.head
            while n1 != n2:
                n1 = n1.next
                n2 = n2.next
            return True, n1
        else:
            print("kth_last_node failed")
            return False
    else: #lengths are the same
        n1 = l1.head
        n2 = l2.head
        while n1!= n2:
            n1 = n1.next
            n2 = n2.next
        return True, n1

#================================================================================

# l1 = LinkedList(10)
# l1.print()
# l1.remove_duplicates2()
# l1.print()
# is_answer, node = l1.kth_last_node(5)
# if is_answer:
#     print("answer is " + str(node.data))
#     remove_middle_node(node)
#     l1.print()
#     l1.partition(4)
#     l1.print()

# l1 = LinkedList(10)
# l1.print()
# l2 = l1.reverse()
# l2 = l2.print()

# l1 = LinkedList()
# for i in range(0,3):
#     l1.prepend(i)
# for i in range(2, 0, -1):
#     l1.prepend(i)
# l1.print()
# print(l1.isPalindrome())


