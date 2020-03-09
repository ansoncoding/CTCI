package interface_implementation;

public class ScrewDriverFlathead implements ScrewDriverInterface {
	public void turnClockwise() {
		System.out.println("Flat head turns clockwise");
	}
	
	public void turnCounterclockwise() {
		System.out.println("Flat head turns counter clockwise");
	}
}
