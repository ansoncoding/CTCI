package observer;

import java.util.ArrayList;

// One can also choose to decouple the observable functionality (add observer/notifyObservers/init array) 
// from the class itself by inheriting from an abstract class

public class ObservableStocks {
	
	private ArrayList<ObserverInterface> observers;
	
	int stock;
	public ObservableStocks(int init) {
		this.stock = init;
		observers = new ArrayList<ObserverInterface>();
	}
	
	public void addObserver(ObserverInterface o) {
		observers.add(o);
	}
	
	public void updateStock(int new_stock) {
		notifyObservers(new_stock);
		stock = new_stock;
	}
	
	protected void notifyObservers(int new_stock) {
		
		String news = "";
		
		if (new_stock > stock) {
			news = "Stock has gone up";
		} else if (new_stock < stock) {
			news = "Stock has gone down";
		}
		
		if (new_stock != stock) {
			
			for (ObserverInterface o : observers) {
				o.update(news);
			}
		}
	}
	
	public static void main(String args[]) {
		ObservableStocks os = new ObservableStocks(10);
		ObserverBank ob = new ObserverBank();
		ObserverFinancialAdvisor of = new ObserverFinancialAdvisor();
		ObserverStockPlayer op = new ObserverStockPlayer();
		os.addObserver(ob);
		os.addObserver(of);
		os.addObserver(op);
		os.updateStock(20);
		os.updateStock(10);
	}
}
