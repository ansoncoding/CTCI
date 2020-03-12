package composite2;

import java.util.ArrayList;

public class Composite2Person {
	
	protected ArrayList<Composite2Person> members;
	
	protected String name;
	protected int depth;
	
	public Composite2Person(String name) {
		members = new ArrayList<Composite2Person>();
		this.name = name;
		this.depth = 0;
	}
	
	public void setDepth(int d) {
		this.depth = d;
		for (Composite2Person m : members) {
			int old_depth = m.getDepth();
			m.setDepth(d + old_depth);
		}
	}
	
	public int getDepth() {
		return depth;
	}
	
	public boolean hasChild(Composite2Person m) {
		return members.contains(m);
	}
	
	@Override
	public boolean equals(Object o) {
		// null check
		if (o == null) {
			return false;
		}
 
		// this instance check
		if (this == o) {
			return true;
		}
		// instanceof Check and actual value check
		if (!(o instanceof Composite2Person)) {
			
			return false;
		}		 
		
		Composite2Person m = (Composite2Person)o; 
		
		if (!this.name.equals(m.getName())) {
			return false;
		}
		if (this.depth != m.getDepth()) {
			return false;
		}
		for (Composite2Person c : members) {
			if (!m.hasChild(c)) {
				return false;
			}
		}
		return true;
	}
	
	@Override
	public int hashCode() {
		int hc = 0;
		for (int i = 0; i < name.length(); i++) {
			hc += name.charAt(i);
		}
		hc += depth;
		for (Composite2Person m : members) {
			hc += m.hashCode();
		}
		return hc;
	}
	
	public String getName() {
		return name;
	}
	
	public void addMember(String name) {}
	
	public void removeMember(String name) {}
	
	public void print() {
		for (int i = 0; i < this.depth; i++) {
			System.out.print(" ");
		}
		System.out.println(name);
	}
}
