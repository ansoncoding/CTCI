package composite2;


public class Composite2FamilyTree extends Composite2Person {
	
	public Composite2FamilyTree(String name) {
		super(name);
	}
	
	public void addMember(Composite2Person m) {
		
		if (members.contains(m)) {
			return;
		}
		int new_depth = this.depth +1;
		m.setDepth(new_depth);
		members.add(m);
	}

	@Override
	public void print() {
		for (int i = 0; i < depth; i++) {
			System.out.print(" ");
		}
		System.out.println(name);
		for (Composite2Person p : members) {
			p.print();
		}
	}

}
