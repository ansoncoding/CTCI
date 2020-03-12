package composite;

import java.util.ArrayList;


public class CompositeCouple extends CompositeTreeMember {
	
	String name2;
	
	public CompositeCouple(String person1, String person2) {
		members = new ArrayList<CompositeTreeMember>();
		this.depth = 0;
		this.name = person1;
		this.name2 = person2;
	}
	
	public void addMember(CompositeTreeMember m) {
		if (members.contains(m)) {
			return;
		}
		int new_depth = this.depth +1;
		m.setDepth(new_depth);
		members.add(m);
	}
	
	@Override
	public void print() {
		for (int i = 0; i < depth; i++ ) {
			System.out.print(" ");
		}
		System.out.println(name + " " + name2);
		for (CompositeTreeMember m : members){
			m.print();
		}
	}
}
