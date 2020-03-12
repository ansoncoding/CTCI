package composite;

import java.util.ArrayList;

public abstract class CompositeTreeMember {
	
	protected ArrayList<CompositeTreeMember> members;
	protected String name;
	protected int depth;
	public abstract void print();
	
	public void setDepth(int d) {
		this.depth = d;
		for (CompositeTreeMember m : members) {
			int old_depth = m.getDepth();
			m.setDepth(d + old_depth);
		}
	}
	
	public int getDepth() {
		return depth;
	}
	
	public boolean hasChild(CompositeTreeMember m) {
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
		if (!(o instanceof CompositeTreeMember)) {
			
			return false;
		}		 
		
		CompositeTreeMember m = (CompositeTreeMember)o; 
		
		if (!this.name.equals(m.getName())) {
			return false;
		}
		if (this.depth != m.getDepth()) {
			return false;
		}
		for (CompositeTreeMember c : members) {
			if (!m.members.contains(c)) {
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
		for (CompositeTreeMember m : members) {
			hc += m.hashCode();
		}
		return hc;
	}
	
	public String getName() {
		return name;
	}
	
	public void addMember(String name) {}
	
	public void removeMember(String name) {}
}
