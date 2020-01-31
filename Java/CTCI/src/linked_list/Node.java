package linked_list;

public class Node {
	int data;
	Node next = null;
	Node() {
	
	}
	Node(int data) {
		this.data = data;
	}
	public void copy(Node n) {
		n.data = data;
		n.next = next;
	}
}
