package object_oriented_design;

public class ScrewDriverFlathead implements ScrewDriverInterface {
	public void turnClockwise() {
		System.out.println("Flat head turns clockwise");
	}
	
	public void turnCounterclockwise() {
		System.out.println("Flat head turns counter clockwise");
	}
}
