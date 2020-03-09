package abstract_class_extension;

public class BasicStaff extends BasicPerson {
	int pay;
	int starting_year;
	public BasicStaff(String name, int age, int pay, int starting_year) {
		super(name, age);
		this.pay = pay;
		this.starting_year = starting_year;
	}
	public void print_info() {
		System.out.println(name + " " + age + " years old, works here for " + pay + " per hour starting in " + starting_year );
	}	
	
	public static void main(String[] args) {
		BasicStaff s = new BasicStaff("John", 19, 14, 1999);
		s.print_info();
	}
}

