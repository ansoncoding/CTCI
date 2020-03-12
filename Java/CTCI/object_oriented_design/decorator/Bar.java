package decorator;

public class Bar {

	public static void main(String[] args) {
		DrinkTopping drink = new CoconutJelly(new BubbleTeaBasic());
		System.out.println(drink.getDescription());
		System.out.println(drink.getPrice());
		
		DrinkTopping drink2 = new CoconutJelly(new Pearls(new Mango(new BubbleTeaBasic())));
		System.out.println(drink2.getDescription());
		System.out.println(drink2.getPrice());
	}

}
