import unittest
from LinkedListT import LinkedListT, sum_lists
from LinkedListModule import is_intersecting

class TestLinkedListTModule(unittest.TestCase):

    def test_LinkedListT_init(self):
        ll = LinkedListT()
        self.assertEqual(ll.length, 0)

    def test_LinkedListT_prepend(self):
        ll = LinkedListT()
        ll.prepend(5)
        self.assertEqual(ll.length, 1)
        self.assertTrue(ll.contains(5))
        ll.prepend(1)
        ll.prepend(2)
        self.assertEqual(ll.length, 3)
        self.assertTrue(ll.contains(1))
        self.assertTrue(ll.contains(2))
        self.assertFalse(ll.contains(0))

    def test_LinkedListT_append(self):
        ll = LinkedListT()
        ll.append(5)
        self.assertEqual(ll.length, 1)
        self.assertTrue(ll.contains(5))
        ll.append(1)
        ll.append(2)
        self.assertEqual(ll.length, 3)
        self.assertTrue(ll.contains(1))
        self.assertTrue(ll.contains(2))
        self.assertFalse(ll.contains(0))


    def test_LinkedListT_remove(self):
        ll = LinkedListT()
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

    def test_LinkedListT_compare(self):
        l1 = LinkedListT(list_length=10)
        l2 = LinkedListT(list_length=10)
        self.assertTrue(l1.compare(l2))

    def test_LinkedListT_remove_dup(self):
        l1 = LinkedListT(list_length=10)
        for i in range(0, 5):
            l1.append(i)
        soln = LinkedListT(list_length=10)
        l1.remove_duplicates()
        self.assertTrue(l1.compare(soln))
        self.assertTrue(l1.length, 10)

    def test_LinkedListT_remove_dup2(self):
        l1 = LinkedListT(list_length=10)
        for i in range(0, 5):
            l1.append(i)
        soln = LinkedListT(list_length=10)
        l1.remove_duplicates2()
        self.assertTrue(l1.compare(soln))
        self.assertTrue(l1.length, 10)

    def test_LinkedListT_kth_last_node(self):
        ll = LinkedListT(list_length=10)
        for i in range(1, 10):
            success, node = ll.kth_last_node(i)
            self.assertTrue(success)
            self.assertEqual(node.data, 10-i)

    def test_LinkedListT_partition(self):
        ll = LinkedListT(list_length=10)
        for i in range(1, 9):
            ll.partition(i)
            self.assertTrue(ll.test_partition(i))

    def test_LinkedListT_is_palindrome(self):
        ll = LinkedListT(2)
        self.assertFalse(ll.isPalindrome())

        ll = LinkedListT()
        for i in range(0,3):
            ll.prepend(i)
        for i in range(2, -1, -1):
            ll.prepend(i)
        self.assertTrue(ll.isPalindrome())

        lt = LinkedListT()
        for i in range(0,3):
            lt.prepend(i)
            lt.append(i)
        self.assertTrue(lt.isPalindrome())

    def test_sum_lists(self):
        LLT1 = LinkedListT(3) # 0 1 2
        LLT2 = LinkedListT(4) # 0 1 2 3
        soln = LinkedListT()  # 0 2 4 3
        soln.append(0)
        soln.append(2)
        soln.append(4)
        soln.append(3)
        lt_sum = sum_lists(LLT1, LLT2)
        self.assertTrue(lt_sum.compare(soln))

    def test_sum_lists2(self):
        LLT1 = LinkedListT(list_length=3, init_vals=[6, 6, 6]) #
        LLT2 = LinkedListT(list_length=3, init_vals=[3, 5, 7]) # 
        soln = LinkedListT(list_length=4, init_vals=[9, 1, 4, 1])  # 0 2 4 3
        lt_sum = sum_lists(LLT1, LLT2)
        self.assertTrue(lt_sum.compare(soln))

    def test_sum_lists_carry(self):
        LLT1 = LinkedListT(8) 
        rev = LLT1.reverse()  # 7 6 5 4 3 2 1 0
        LLT2 = LinkedListT(6) 
        LLT2.remove(0)
        LLT2.remove(1)
        LLT2.remove(2)        # 3 4 5
        soln = LinkedListT()  # 0 1 1 5 3 2 1 0
        soln.append(0)
        soln.append(1)
        soln.append(1)
        soln.append(5)
        soln.append(3)
        soln.append(2)
        soln.append(1)
        soln.append(0)
        lt_sum = sum_lists(rev, LLT2)
        self.assertTrue(lt_sum.compare(soln))

    def test_is_circular(self):
        LT = LinkedListT(10, circular=True)
        isloop, node = LT.loop_detection()
        self.assertTrue(isloop)
        self.assertEqual(node.data, 0)

        LT2 = LinkedListT(10, circular=False)
        isloop, node = LT2.loop_detection()
        self.assertFalse(isloop)

        LT3 = LinkedListT(10, circular=True, k=3)
        
        isloop, node = LT3.loop_detection()
        self.assertTrue(isloop)
        self.assertEqual(node.data, 3)

    def test_is_intersecting_false(self):
        ll1 = LinkedListT(10)
        ll2 = LinkedListT(4)
        ret, node = is_intersecting(ll1, ll2) 
        self.assertFalse(ret)
        ret, node = is_intersecting(ll2, ll1) # communitative
        self.assertFalse(ret)

    def test_is_intersecting_beg(self):
        ll1 = LinkedListT(10)
        ll2 = LinkedListT(4)
        ll2.append(50)
        ret, node = ll1.kth_last_node(10)
        self.assertTrue(ret)
        ll2.setTail(node)
        ret, node = is_intersecting(ll1, ll2)
        self.assertTrue(ret)
        self.assertEqual(node.data, 0)
        ret, node = is_intersecting(ll2, ll1) # commutative
        self.assertTrue(ret)
        self.assertEqual(node.data, 0)

    def test_is_intersecting_mid(self):
        ll1 = LinkedListT(10)
        ll2 = LinkedListT(4)
        ret, node = ll1.kth_last_node(3)
        self.assertTrue(ret)
        ll2.setTail(node)
        ret, node = is_intersecting(ll1, ll2)
        self.assertTrue(ret)
        self.assertEqual(node.data, 7)
        ret, node = is_intersecting(ll2, ll1) # commutative
        self.assertTrue(ret)
        self.assertEqual(node.data, 7)

    def test_is_intersecting_end(self):
        ll1 = LinkedListT(10)
        ll2 = LinkedListT(4)
        ret, node = ll1.kth_last_node(1)
        self.assertTrue(ret)
        ll2.setTail(node)
        ret, node = is_intersecting(ll1, ll2)
        self.assertTrue(ret)
        self.assertEqual(node.data, 9)
        ret, node = is_intersecting(ll2, ll1) # commutative
        self.assertTrue(ret)
        self.assertEqual(node.data, 9)

if __name__ == '__main__':
    unittest.main()
