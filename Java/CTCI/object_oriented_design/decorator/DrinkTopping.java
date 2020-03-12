package decorator;

public abstract class DrinkTopping implements BubbleTea {
	
	protected BubbleTea bbt;
	
	public DrinkTopping(BubbleTea bbt) {
		this.bbt = bbt;
	}
	
	@Override
	public String getDescription() {
		return bbt.getDescription();
	}
	
	@Override
	public double getPrice() {
		return bbt.getPrice();
	}
}
