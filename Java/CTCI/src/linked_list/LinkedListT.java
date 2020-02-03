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
	// creates circular list with k nodes in the beginning
	public LinkedListT(int len, int circular_k) {
		for (int i= 0 ; i < len ; i++) {
			append(i);
		}
		
		int k = circular_k % len; // in case user passes k greater than len
		int count = 0;
		Node temp = head;
		
		while(temp != null && count < k) {
			temp = temp.next;
			count++;
		}
		tail.next = temp;
	}
	
	public void setTail(Node n) {
		tail.next = n;
	}
	
	public void append(int data) {
		if (head == null) {
			head = new Node(data);
			tail = head;
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
//		LinkedListT LLT1 = new LinkedListT(10, 11);
//		LLT1.print(20);
//		
//		Node retval = LLT1.loop_detection();
//		if (retval == null) {
//			System.out.println("No loop found");
//		} else {
//			System.out.println("Loop found, node val is " + retval.data);
//		}
//		
//		LinkedList LL = new LinkedList(10);
//		LL.print();
//		retval = LL.loop_detection();
//		if (retval == null) {
//			System.out.println("No loop found");
//		} else {
//			System.out.println("Loop found, node val is " + retval.data);
//		}
		LinkedListT ll1 = new LinkedListT(10);
		LinkedListT ll2 = new LinkedListT(1);
		LinkedListT ll3 = new LinkedListT(3);
		Node n = ll1.kth_last_node(10);
		if (n != null) {
			ll2.setTail(n);
			ll2.print();
		}
		Node ret = isIntersecting(ll1, ll2);
		if (ret != null ) {
			System.out.println("Is intersecting, intersecting node val is " + n.data);
		} else {
			System.out.println("Is not interesecting");
		}
		
		ret = isIntersecting(ll3, ll2);
		if (ret != null ) {
			System.out.println("Is intersecting, intersecting node val is " + n.data);
		} else {
			System.out.println("Is not interesecting");
		}
		
	}

}
