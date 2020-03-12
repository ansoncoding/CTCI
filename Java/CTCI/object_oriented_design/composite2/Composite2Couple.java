package composite2;

import composite.CompositeTreeMember;

public class Composite2Couple extends Composite2Person {

	String name2;
	public Composite2Couple(String name1, String name2) {
		super(name1);
		this.name2 = name2;
	}
	
	public void addMember(Composite2Person m) {
		
		if (members.contains(m)) {
			return;
		}
		int new_depth = this.depth +1;
		m.setDepth(new_depth);
		members.add(m);
	}
	
	public void print() {
		for (int i = 0; i < depth; i++) {
			System.out.print(" ");	
		}
		System.out.println(name + " " + name2);
		for (Composite2Person p : members) {
			p.print();
		}
	}
	
}
