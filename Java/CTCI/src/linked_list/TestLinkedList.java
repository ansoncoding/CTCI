package linked_list;
import org.junit.Test; 
import static org.junit.Assert.*;

public class TestLinkedList {
	@Test
	public void testLinkedListInit() {
		LinkedList ll = new LinkedList();
		assertEquals(ll.getLength(), 0);
		assertFalse(ll.contains(5));
	}
	
	@Test 
	public void testLinkedListInsert() {
		LinkedList ll = new LinkedList();
		for (int i = 0; i < 20; i++) {
			ll.prepend(i);
		}
		for (int i = 0; i < 20; i++) {
			assertTrue(ll.contains(i));
		}
		assertFalse(ll.contains(20));
		assertFalse(ll.contains(21));
		assertFalse(ll.contains(-1));
	}
	
	@Test
	public void testLinkedListIsPalindromeEven() {
		LinkedList ll = new LinkedList();
		for (int i = 0; i < 3; i++) {
			ll.prepend(i);
		}
		for (int i = 2; i >= 0; i--) {
			ll.prepend(i);
		}
		assertTrue(ll.isPalindrome());
	}
	
	@Test
	public void testLinkedListIsPalindromeOdd() {
		LinkedList ll = new LinkedList();
		for (int i = 0; i < 3; i++) {
			ll.prepend(i);
		}
		for (int i = 3; i >= 0; i--) {
			ll.prepend(i);
		}
		assertTrue(ll.isPalindrome());
	}
	
	@Test
	public void testLinkedListKthLastNode() {
		LinkedList ll = new LinkedList(10);

		for (int i = 1; i<= 10; i++) {
			Node retval = ll.kth_last_node(i);
			assertNotNull(retval);
			assertEquals(retval.data, i-1);
		}
	}
	
	@Test(expected = IllegalArgumentException.class)
	public void testLinkedListKthLastNodeIllegalArg() throws IllegalArgumentException {
		LinkedList ll = new LinkedList(10);
		Node retval = ll.kth_last_node(0);
	}
	
	@Test(expected = IllegalArgumentException.class)
	public void testLinkedListKthLastNodeIllegalArg2() throws IllegalArgumentException {
		LinkedList ll = new LinkedList(10);
		Node retval = ll.kth_last_node(-1);
	}
	
	@Test(expected = IndexOutOfBoundsException.class)
	public void testLinkedListKthIndexOutOfBounds() throws IndexOutOfBoundsException {
		LinkedList ll = new LinkedList(10);
		Node retval = ll.kth_last_node(11);	
	}
	
	@Test(expected = IndexOutOfBoundsException.class)
	public void testLinkedListKthIndexOutOfBounds2() throws IndexOutOfBoundsException {
		LinkedList ll = new LinkedList(10);
		Node retval = ll.kth_last_node(12);
	}	
	
	@Test
	public void testLinkedListRemoveDup() {
		LinkedList ll = new LinkedList(10, true);
		LinkedList soln = new LinkedList(10);
		ll.remove_dups();
		assertTrue(ll.compare(soln));
	}
	
	@Test
	public void testLinkedListRemoveDupNoChange() {
		LinkedList ll = new LinkedList(5);
		LinkedList soln = new LinkedList(5);
		ll.remove_dups();
		assertTrue(ll.compare(soln));
	}
	
	@Test
	public void testLinkedListRemoveDup2() {
		LinkedList ll = new LinkedList(10, true);
		LinkedList soln = new LinkedList(10);
		ll.remove_dups2();
		assertTrue(ll.compare(soln));
	}
	
	@Test
	public void testLinkedListRemoveDup2NoChange() {
		LinkedList ll = new LinkedList(5);
		LinkedList soln = new LinkedList(5);
		ll.remove_dups2();
		assertTrue(ll.compare(soln));
	}
	
	@Test
	public void testLinkedListPartitionNoChange() {
		LinkedList ll = new LinkedList(10);
		LinkedList soln = ll;
		ll.partition(20);
		assertTrue(ll.compare(soln));
	}
	
	@Test
	public void testLinkedListPartition() {
		LinkedList ll = new LinkedList(10);
		int k = 5;
		ll.partition(5);
		
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
	public void testLinkedListGetIllegalArg() throws IllegalArgumentException {
		LinkedList ll = new LinkedList(10);
		int retval = ll.get(-2);
	}
	
	@Test(expected = IllegalArgumentException.class)
	public void testLinkedListGetIllegalArg2() throws IllegalArgumentException {
		LinkedList ll = new LinkedList(10);
		int retval = ll.get(-1);
	}
	
	@Test(expected = IndexOutOfBoundsException.class)
	public void testLinkedListGetOutofBounds() throws IndexOutOfBoundsException {
		LinkedList ll = new LinkedList(10);
		int retval = ll.get(11);	
	}
}
