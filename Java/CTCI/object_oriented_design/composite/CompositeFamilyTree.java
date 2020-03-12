package composite;

import java.util.ArrayList;

public class CompositeFamilyTree extends CompositeTreeMember {
	
	public CompositeFamilyTree(CompositeTreeMember m) {
		this.name = "Family Tree";
		members = new ArrayList<CompositeTreeMember>();
		this.depth = 0;
		addMember(m);
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
		for (int i = 0; i < this.depth; i++) {
			System.out.print(" ");
		}
		System.out.println(name);
		for (CompositeTreeMember m: members) {
			m.print();
		}
	}
}
