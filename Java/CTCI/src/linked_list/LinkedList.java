package linked_list;
import java.util.*;
 

public class LinkedList {

	private Node head = null;
	
	private int length = 0;
	
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
	
	public boolean kth_last_node(int k, Node retval) {
		if (k == 0) {
			System.out.println("K cannot be 0");
			return false;
		}
		
		if (head == null) {
			System.out.println("List is empty, cannot return " + k + "th element");
			return false;
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
			return false;
		}
		
		while (to_end != null) {
			to_end = to_end.next;
			kth_last = kth_last.next;		
		}
		kth_last.copy(retval);
		return true;
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
	// node cannot be head or last element
	public static void remove_middle_node(Node n) {
		Node temp = n.next;
		n.data = temp.data;
		n.next = temp.next;
	}
	
	public static void main(String[] args) {

		LinkedList ll = new LinkedList(10);
		ll.print();
		ll.remove_dups2();
		ll.print();
		
		Node ret = new Node();
		boolean answer = ll.kth_last_node(5, ret);
		if (answer) {
			System.out.println(ret.data);
			remove_middle_node(ret);
			ll.print();
			ll.partition(4);
			ll.print();
		}
	}

}
