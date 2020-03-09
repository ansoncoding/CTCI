package observer;

public class ObserverStockPlayer implements ObserverInterface {
	public void update(String news) {
		System.out.println("Stock market player has received news that " + news);
	}
}
