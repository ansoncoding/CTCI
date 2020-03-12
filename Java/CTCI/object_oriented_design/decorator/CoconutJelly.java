package decorator;

public class CoconutJelly extends DrinkTopping {

	public CoconutJelly(BubbleTea bbt) {
		super(bbt);
	}

	@Override
	public String getDescription() {
		return bbt.getDescription() + " with Coconut Jelly";
	}

	@Override
	public double getPrice() {
		return bbt.getPrice() + 0.75;
	}

}
