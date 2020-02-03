package linked_list;
import java.util.*;
 

public class LinkedList {

	protected Node head = null;
	
	protected int length = 0;
	
	public LinkedList() {
		length = 0;
		head = null;
	}
	public LinkedList(int len) {
		for (int i= 0; i < len ;i++) {
			this.prepend(i);
			this.prepend(i);
		}
	}

	public void prepend(int data) {
		Node n = new Node(data);
		if (head == null) {
			head = n;
		} else {
			n.next = head;
			this.head = n;
		}
		length++;
	}
	
	public int getLength() {
		return length;
	}
	
	public void print() {
		Node temp = head;
		while(temp != null) {
			System.out.print(temp.data + " ");
			temp = temp.next;
		}
		System.out.println();
	}
	
	// to print circular lists, give option to print first <len> nodes
	public void print(int len) {
		Node temp = head;
		int count = 0;
		while(temp != null && count < len) {
			System.out.print(temp.data + " ");
			temp = temp.next;
			count++;
		}
		System.out.println();
	}
	
	public void remove_dups() {
		if (head == null) {
			return;
		}
		HashSet<Integer> vals = new HashSet<Integer>();	
		Node prev = head;
		Node temp = head.next;
		vals.add(head.data);
		while(temp!= null) {
			if (vals.contains(temp.data)) {
				prev.next = temp.next;
				length--;
			} else {
				prev = temp;
				vals.add(temp.data);
			}
			temp = temp.next;
		}
	}
	public void remove_dups2() {
		if (head == null) {
			return;
		}
		
		Node valnode = head;
		while (valnode != null) {
			Node prev = valnode;
			Node temp = valnode.next;
			int val = valnode.data;
			while(temp!= null) {
				if (val == temp.data) {
					prev.next = temp.next;
					length--;
				} else {
					prev = temp;
				}
				temp = temp.next;
			}
			valnode = valnode.next;
		}
	}
	
	public Node kth_last_node(int k) {
		if (k == 0) {
			System.out.println("K cannot be 0");
			return null;
		}
		
		if (head == null) {
			System.out.println("List is empty, cannot return " + k + "th element");
			return null;
		}
		
		Node to_end = head;
		Node kth_last = head;
		int count = 0;
		
		while((to_end != null) && (count < k)) {
			to_end = to_end.next;
			count++;
		}
		
		if (count < k) {
			System.out.println("List is " + count + " elements long, cannot return " + k + "th element");
			return null;
		}
		
		while (to_end != null) {
			to_end = to_end.next;
			kth_last = kth_last.next;		
		}
		return kth_last;
	}
	
	public void partition(int k) {
		boolean passed = false;
		Node temp = head;
		Node prev = head;
		while(temp != null) {
			if (temp.data < k) {
				
				if (passed) {
					prev.next = temp.next;
					temp.next = head;
					head = temp;
					temp = prev.next;
				} else {
					prev = temp;
					temp = temp.next;
				}
			} else {
				passed = true;
				prev = temp;
				temp = temp.next;
			}
		}
	}
	public Node loop_detection() {
		Node n1 = head;
		Node n2 = head;
		boolean passed = false;
		while(n1 != null && n2 != null) {
			if (n1 == n2) {
				if (!passed) { // we're starting at head so they're going to collide at least once
					passed = true;
				} else {
					// loop detected
					n1 = head;
					while(n1 != n2) {
						n1 = n1.next;
						n2 = n2.next;
					}
					return n1;
				}
			}
			n1 = n1.next; // n1 increment by 1
			n2 = n2.next; // n2 increment by 2 
			if (n2 != null) { // watch out for loop ending here, unchecked by "while"
				n2 = n2.next; 
			} else {
				return null; // tail reached, no loop exists
			}
		}
		return null; // tail reached, no loop exists
	}
	
	// node cannot be head or last element
	public static void remove_middle_node(Node n) {
		Node temp = n.next;
		n.data = temp.data;
		n.next = temp.next;
	}
	public void reverse_in_place() {
		if (head == null)
			return;
		int[] stack = new int[length];
		Node temp = head;
		int count = 0;
		while(temp!= null) {
			stack[count++] = temp.data;
			temp = temp.next;
		}
		temp = head;
		count--;
		while(count >= 0) {
			temp.data = stack[count--];
			temp = temp.next;
		}
	}
	public static Node isIntersecting(LinkedList l1, LinkedList l2) {
		Node t1 = l1.head;
		Node t2 = l2.head;
		Node t1_prev = null;
		Node t2_prev = null;
		int len1 = 0;
		int len2 = 0;
		while (t1 != null) {
			t1_prev = t1;
			t1 = t1.next;
			len1++;
		}
			
		while(t2 != null) {
			t2_prev = t2;
			t2 = t2.next;
			len2++;
		}
		if (t1_prev != t2_prev ) {
			return null;
		}
		int len_diff = Math.abs(len1 - len2);
		Node n1;
		Node n2;
		if (len_diff != 0) {
			LinkedList longer = len1 > len2 ? l1 : l2;
			LinkedList shorter = len1 > len2? l2 : l1;
			int k = (len1 > len2 ? len1 : len2) - len_diff;
			n1 = longer.kth_last_node(k);
			if (n1 == null) {
				System.out.println("kth_last_node failed");
				return null;
			} else {
				n2 = shorter.head;
			}
		} else {
			n1 = l1.head;
			n2 = l2.head;
		}
		while(n1 != null && n2 != null) {
			if (n1 == n2) {
				return n1;
			}
			n1 = n1.next;
			n2 = n2.next;
		}
		return null;
	}
	public boolean isPalindrome() {
		if (head == null) {
			System.out.println("The list is empty");
			return false;
		}
		int[] stack = new int[length];
		Node temp = head;
		int count = 0;
		while (temp != null) {
			stack[count++] = temp.data;
			temp = temp.next;
		}
		temp = head;
		count--;
		while (count >= 0) { 
			if (temp.data != stack[count--]) {
				return false;
			}
			temp= temp.next;
		}
		return true;
	}
	
	public static void main(String[] args) {

		LinkedList ll = new LinkedList();
		for (int i = 0; i < 3; i++) {
			ll.prepend(i);
		}
		for (int i = 2; i >= 0; i--) {
			ll.prepend(i);
		}
		ll.print();
		System.out.println(ll.isPalindrome());
		Node retval = ll.kth_last_node(5);
		if (retval == null) {
			System.out.println("Could not find node");
		} else {
			System.out.println(retval.data);
		}
	}
}
