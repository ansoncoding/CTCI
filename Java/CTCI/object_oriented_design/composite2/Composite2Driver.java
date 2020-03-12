package composite2;

public class Composite2Driver {
	public static void main(String args[]) {
		Composite2Person p = new Composite2Person("Harry");
		Composite2Couple c = new Composite2Couple("Lily", "James");
		c.addMember(p);
		Composite2FamilyTree t = new Composite2FamilyTree("Potters");
		t.addMember(c);
		t.print();
	}
}
