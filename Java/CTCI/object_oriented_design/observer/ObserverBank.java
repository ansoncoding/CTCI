package observer;

public class ObserverBank implements ObserverInterface {
	
	public void update(String news) {
		System.out.println("Bank has received news that " + news);
	}
}
