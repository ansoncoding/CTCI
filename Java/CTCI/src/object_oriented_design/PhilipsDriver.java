package object_oriented_design;

public class PhilipsDriver implements ScrewDriver {

	public void turnClockwise() {
		System.out.println("Philips turn clockwise");
	}
	public void turnCounterclockwise() {
		System.out.println("Philips turn counter clockwise");
	}
	public static void main(String[] args) {
		PhilipsDriver pd = new PhilipsDriver();
		pd.turnClockwise();
		pd.turnCounterclockwise();
		
		FlatheadDriver fd = new FlatheadDriver();
		fd.turnClockwise();
		fd.turnCounterclockwise();
	}

}
