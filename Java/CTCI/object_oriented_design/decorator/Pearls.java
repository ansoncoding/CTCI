package decorator;

public class Pearls extends DrinkTopping {

	public Pearls(BubbleTea bbt) {
		super(bbt);
	}

	@Override
	public String getDescription() {
		return bbt.getDescription() + " with Pearls";
	}

	@Override
	public double getPrice() {
		return bbt.getPrice() + 0.50;
	}
	
}
