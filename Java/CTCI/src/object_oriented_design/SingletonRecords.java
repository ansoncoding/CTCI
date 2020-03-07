package object_oriented_design;

public class SingletonRecords {

	private static SingletonRecords record;
	private StringBuilder log;
	private SingletonRecords() {
		log = new StringBuilder();
	}
	
	public static SingletonRecords getInstance() {
		if (record == null) {
			record = new SingletonRecords();
			System.out.println("Record is created");
		}
		return record;
	}
	
	public void write(String msg) {
	
		log.append(msg);
		System.out.println("Record is updated");
	}
	
	public String getLog() {
		return log.toString();
	}
	
	public static void main(String[] args) {
		
		SingletonRecords.getInstance().write("First log");
		String l = SingletonRecords.getInstance().getLog();
		System.out.println(l);
	}

}
