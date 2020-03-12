package decorator;

public class BubbleTeaBasic implements BubbleTea {
	
	
	@Override
	public String getDescription() {

		return "Bubble tea";
	}

	@Override
	public double getPrice() {

		return 3.00;
	}
	
}
