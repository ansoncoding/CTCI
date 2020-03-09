package observer;

public class ObserverFinancialAdvisor implements ObserverInterface {
	public void update(String news) {
		System.out.println("Financial adviser has received news that " + news);
	}
}
