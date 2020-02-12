package linked_list;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertNotNull;
import static org.junit.Assert.assertTrue;

import org.junit.Test;

public class TestLinkedListT {
	
	@Test
	public void testLinkedListTInit() {
		LinkedListT ll = new LinkedListT();
		assertEquals(ll.getLength(), 0);
		assertFalse(ll.contains(5));
	}
	
	@Test 
	public void testLinkedListTInsert() {
		LinkedListT ll = new LinkedListT();
		for (int i = 0; i < 20; i++) {
			ll.prepend(i);
			assertEquals(ll.getLength(), i+1);
		}
		for (int i = 0; i < 20; i++) {
			assertTrue(ll.contains(i));
		}
		assertFalse(ll.contains(20));
		assertFalse(ll.contains(21));
		assertFalse(ll.contains(-1));
	}
	
	@Test
	public void testLinkedListTIsPalindromeEven() {
		LinkedListT ll = new LinkedListT();
		for (int i = 0; i < 3; i++) {
			ll.prepend(i);
		}
		for (int i = 2; i >= 0; i--) {
			ll.prepend(i);
		}
		assertTrue(ll.isPalindrome());
	}
	
	@Test
	public void testLinkedListTIsPalindromeOdd() {
		LinkedListT ll = new LinkedListT();
		for (int i = 0; i < 3; i++) {
			ll.prepend(i);
		}
		for (int i = 3; i >= 0; i--) {
			ll.prepend(i);
		}
		assertTrue(ll.isPalindrome());
	}
	
	@Test
	public void testLinkedListTKthLastNode() {
		LinkedListT ll = new LinkedListT(10);

		for (int i = 1; i<= 10; i++) {
			Node retval = ll.kth_last_node(i);
			assertNotNull(retval);
			assertEquals(retval.data, 10 - i);
		}
	}
	
	@Test(expected = IllegalArgumentException.class)
	public void testLinkedListTKthLastNodeIllegalArg() throws IllegalArgumentException {
		LinkedListT ll = new LinkedListT(10);
		Node retval = ll.kth_last_node(0);
	}
	
	@Test(expected = IllegalArgumentException.class)
	public void testLinkedListTKthLastNodeIllegalArg2() throws IllegalArgumentException {
		LinkedListT ll = new LinkedListT(10);
		Node retval = ll.kth_last_node(-1);
	}
	
	@Test(expected = IndexOutOfBoundsException.class)
	public void testLinkedListTKthIndexOutOfBounds() throws IndexOutOfBoundsException {
		LinkedListT ll = new LinkedListT(10);
		Node retval = ll.kth_last_node(11);	
	}
	
	@Test(expected = IndexOutOfBoundsException.class)
	public void testLinkedListTKthIndexOutOfBounds2() throws IndexOutOfBoundsException {
		LinkedListT ll = new LinkedListT(10);
		Node retval = ll.kth_last_node(12);
	}	
	
	@Test
	public void testLinkedListTRemoveDup() {
		LinkedListT ll = new LinkedListT(10, true);
		ll.remove_dups();
		assertFalse(ll.containsDuplicate());
	}
	
	@Test
	public void testLinkedListTRemoveDupNoChange() {
		LinkedListT ll = new LinkedListT(5);
		LinkedListT soln = new LinkedListT(5);
		ll.remove_dups();
		assertTrue(ll.compare(soln));
	}
	
	@Test
	public void testLinkedListTRemoveDup2() {
		LinkedListT ll = new LinkedListT(10, true);
		assertEquals(ll.getLength(), 20);
		ll.remove_dups2();
		assertEquals(ll.getLength(), 10);
		assertFalse(ll.containsDuplicate());

	}
	
	@Test
	public void testLinkedListTRemoveDup2NoChange() {
		LinkedListT ll = new LinkedListT(5);
		LinkedListT soln = new LinkedListT(5);
		ll.remove_dups2();
		assertTrue(ll.compare(soln));
	}
	
	@Test
	public void testLinkedListTPartitionNoChange() {
		LinkedListT ll = new LinkedListT(10);
		assertEquals(ll.getLength(), 10);
		LinkedListT soln = ll;
		ll.partition(20);
		assertEquals(ll.getLength(), 10);
		assertTrue(ll.compare(soln));
	}
	
	@Test
	public void testLinkedListTPartition() {
		LinkedListT ll = new LinkedListT(10);
		assertEquals(ll.getLength(), 10);
		int k = 5;
		ll.partition(5);
		assertEquals(ll.getLength(), 10);
		
		boolean partition_found = false;
		int val;
		for (int i = 0; i < ll.getLength(); i++) {
			
			val = ll.get(i);
			
			if (val >= k)
				partition_found = true;
			
			if (!partition_found) {
				assertTrue(val < k);
			} else {
				assertTrue(val >= k);
			}
		}
	}
	
	@Test(expected = IllegalArgumentException.class)
	public void testLinkedListTGetIllegalArg() throws IllegalArgumentException {
		LinkedListT ll = new LinkedListT(10);
		int retval = ll.get(-2);
	}
	
	@Test(expected = IllegalArgumentException.class)
	public void testLinkedListTGetIllegalArg2() throws IllegalArgumentException {
		LinkedListT ll = new LinkedListT(10);
		int retval = ll.get(-1);
	}
	
	@Test(expected = IndexOutOfBoundsException.class)
	public void testLinkedListTGetOutofBounds() throws IndexOutOfBoundsException {
		LinkedListT ll = new LinkedListT(10);
		int retval = ll.get(11);	
	}
	
	@Test 
	public void testLinkedListLoopDetection() {
		LinkedListT LLT1 = new LinkedListT(10, 11);	
		Node retval = LLT1.loop_detection();
		assertNotNull(retval);
	}
	
	@Test
	public void testLinkedListLoopDetectionNoLoop() {
		LinkedListT LLT1 = new LinkedListT(10);
		Node retval = LLT1.loop_detection();
		assertTrue(retval == null);
	}
	
	@Test
	public void testIsIntersecting() {

		LinkedListT ll1 = new LinkedListT(10);
		LinkedListT ll2 = new LinkedListT(1);
		LinkedListT ll3 = new LinkedListT(3);
		Node n = ll1.kth_last_node(5);
		assertNotNull(n);
		ll2.setTail(n);
		
		Node ret = LinkedList.isIntersecting(ll1, ll2);
		assertNotNull(ret);
		assertEquals(ret.data, 5);
		
		ret = LinkedList.isIntersecting(ll3, ll2);
		assertTrue(ret == null);
	}
	
	@Test
	public void testLinkedListTRemoveMiddleNode() {
		LinkedListT ll1 = new LinkedListT(10);
		Node n = ll1.kth_last_node(5);
		assertEquals(ll1.getLength(), 10);
		assertNotNull(n);
		ll1.remove_middle_node(n);
		assertEquals(ll1.getLength(), 9);
		assertFalse(ll1.contains(5));
		for (int i = 0; i < 10; i++) {
			if (i == 5)
				continue;
			assertTrue(ll1.contains(i));
		}
	}
	
	@Test
	public void testLinkedListTSumLists() {
		LinkedListT l1 = new LinkedListT(3);
		LinkedListT l2 = new LinkedListT(4);
		LinkedListT soln = new LinkedListT();
		soln.append(0);
		soln.append(2);
		soln.append(4);
		soln.append(3);
		LinkedListT sum = LinkedListT.sumLists(l1, l2);
		assertTrue(soln.compare(sum));
	}
	
	@Test
	public void testLinkedListTSumListsCarry() {
		int[] val1 = {3, 5, 7};
		int[] val2 = {6, 6, 6};
		int[] val_s = {9, 1, 4, 1};
		LinkedListT l1 = new LinkedListT(3, val1);
		LinkedListT l2 = new LinkedListT(3, val2);
		LinkedListT soln = new LinkedListT(4, val_s);
		
		LinkedListT sum = LinkedListT.sumLists(l1, l2);
		assertTrue(soln.compare(sum));
	}
}
