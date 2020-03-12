package decorator;

public class Mango extends DrinkTopping {

	public Mango(BubbleTea bbt) {
		super(bbt);
	}
	@Override
	public String getDescription() {
		return bbt.getDescription() + " with Mango";
	}

	@Override
	public double getPrice() {
		return bbt.getPrice() + 1.50;
	}
}
