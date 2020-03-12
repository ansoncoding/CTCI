package composite;

import java.util.ArrayList;

public class CompositePerson extends CompositeTreeMember {
	
	public CompositePerson(String name) {
		members = new ArrayList<CompositeTreeMember>();
		this.name = name;
		this.depth = 0;
	}
	
	@Override
	public void print() {
		for (int i = 0; i < this.depth; i++) {
			System.out.print(" ");
		}
		System.out.println(name);
	}
}
