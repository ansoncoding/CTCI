package interface_implementation;

public class ScrewDriverPhilips implements ScrewDriverInterface {

	public void turnClockwise() {
		System.out.println("Philips turn clockwise");
	}
	public void turnCounterclockwise() {
		System.out.println("Philips turn counter clockwise");
	}
	public static void main(String[] args) {
		ScrewDriverPhilips pd = new ScrewDriverPhilips();
		pd.turnClockwise();
		pd.turnCounterclockwise();
		
		ScrewDriverFlathead fd = new ScrewDriverFlathead();
		fd.turnClockwise();
		fd.turnCounterclockwise();
	}

}
