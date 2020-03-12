package composite;

public class CompositeMainDriver {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		CompositeCouple cc = new CompositeCouple("James", "Lily");
		
		CompositePerson p = new CompositePerson("Harry");
		cc.addMember(p);
		CompositeFamilyTree ft = new CompositeFamilyTree(cc);
		ft.print();
	}

}
