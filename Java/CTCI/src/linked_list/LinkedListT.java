package linked_list;

public class LinkedListT extends LinkedList {
	
	protected Node tail = null;
	
	public LinkedListT() {
		super();
	}
	public LinkedListT(int len) {
		for (int i= 0 ; i < len ; i++) {
			append(i);
		}
	}
	public void append(int data) {
		if (head == null) {
			head = new Node(data);
			head.next = tail;
			length++;
			return;
		}
		if (tail == null) {
			tail = new Node(data);
			head.next = tail;
			length++;
			return;
		}
		Node temp = new Node(data);
		tail.next = temp;
		tail = temp;
		length++;
	}
	public static LinkedListT sumLists(LinkedListT l1, LinkedListT l2) {
		Node n1 = l1.head;
		Node n2 = l2.head;
		LinkedListT retval = new LinkedListT();
		
		int sum = 0;
		int prev_quotient = 0;
		while (n1 != null || n2 != null) {
			
			int val1 = 0;
			int val2 = 0;	
			if (n1 != null) {
				val1 = n1.data;
			}
			if (n2 != null) {
				val2 = n2.data;
			}
			sum = val1 + val2 + prev_quotient;
			int remainder = sum %10;
			retval.append(remainder);
			prev_quotient = sum / 10;
			
			if (n1 != null) {
				n1 = n1.next;
			}
			if (n2 != null) {
				n2 = n2.next;
			}
		}
		return retval;
	}
	
	public static void main(String[] args) {
		LinkedListT LLT1 = new LinkedListT(10);
		LinkedListT LLT2 = new LinkedListT(7);
		LLT1.print();
		LLT2.print();
		LinkedListT LLT_sum = sumLists(LLT1, LLT2);
		LLT_sum.print();
	}

}
