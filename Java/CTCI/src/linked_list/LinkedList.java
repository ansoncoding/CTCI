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
		HashSet<Integer> vals = new HashSet();	
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
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		LinkedList ll = new LinkedList(10);
		ll.print();
		ll.remove_dups2();
		ll.print();
	}

}
