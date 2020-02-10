import unittest
from LinkedListModule import LinkedList, remove_middle_node, is_intersecting

class TestLinkedListModule(unittest.TestCase):

    def test_LinkedList_init(self):
        ll = LinkedList()
        self.assertEqual(ll.length, 0)

    def test_LinkedList_prepend(self):
        ll = LinkedList()
        ll.prepend(5)
        self.assertEqual(ll.length, 1)
        self.assertTrue(ll.contains(5))
        ll.prepend(1)
        ll.prepend(2)
        self.assertEqual(ll.length, 3)
        self.assertTrue(ll.contains(1))
        self.assertTrue(ll.contains(2))
        self.assertFalse(ll.contains(0))

    def test_LinkedList_remove(self):
        ll = LinkedList()
        ll.prepend(5)
        self.assertEqual(ll.length, 1)
        self.assertTrue(ll.contains(5))
        ll.remove(5)
        self.assertEqual(ll.length, 0)
        self.assertFalse(ll.contains(5))
        ll.prepend(1)
        ll.prepend(2)
        self.assertEqual(ll.length, 2)
        self.assertFalse(ll.contains(5))
        self.assertTrue(ll.contains(1))
        self.assertTrue(ll.contains(2))
        ll.remove(1)
        ll.remove(2)
        self.assertEqual(ll.length, 0)
        self.assertFalse(ll.contains(1))
        self.assertFalse(ll.contains(2))

    def test_LinkedList_compare(self):
        l1 = LinkedList(list_length=10)
        l2 = LinkedList(list_length=10)
        self.assertTrue(l1.compare(l2))

    def test_LinkedList_remove_dup(self):
        l1 = LinkedList(list_length=10, duplicate=True)
        soln = LinkedList(list_length=10)
        l1.remove_duplicates()
        self.assertTrue(l1.compare(soln))
        self.assertTrue(l1.length, 10)

    def test_LinkedList_remove_dup2(self):
        l1 = LinkedList(list_length=10, duplicate=True)
        soln = LinkedList(list_length=10)
        l1.remove_duplicates2()
        self.assertTrue(l1.compare(soln))
        self.assertTrue(l1.length, 10)

    def test_LinkedList_kth_last_node(self):
        ll = LinkedList(list_length=10)
        for i in range(1, 10):
            success, node = ll.kth_last_node(i)
            self.assertTrue(success)
            self.assertEqual(node.data, i-1)

    def test_LinkedList_partition(self):
        ll = LinkedList(list_length=10)
        for i in range(1, 9):
            ll.partition(i)
            self.assertTrue(ll.test_partition(i))

    def test_LinkedList_is_palindrome(self):
        ll = LinkedList(2)
        self.assertFalse(ll.isPalindrome())

        ll = LinkedList()
        for i in range(0,3):
            ll.prepend(i)
        for i in range(2, -1, -1):
            ll.prepend(i)
        self.assertTrue(ll.isPalindrome())

    def test_remove_middle_node(self):

        ll = LinkedList(3)
        ret, node = ll.kth_last_node(2)
        self.assertTrue(ret)
        self.assertEqual(node.data, 1)
        remove_middle_node(node)
        self.assertFalse(ll.contains(1))

if __name__ == '__main__':
    unittest.main()
