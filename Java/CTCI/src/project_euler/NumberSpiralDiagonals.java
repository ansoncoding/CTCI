package project_euler;

public class NumberSpiralDiagonals {
	
	// ODD ONLY
	static int sumSpiralDiagonalsOfNxN(int n) {
		
		int sum = 1;
		for (int i = 3; i <= n ; i+=2) {
			int sqr = i * i;
			sum += sqr;
			int sideDiff = (i-1);
			for (int j = 0; j < 3; j++) {
				sqr -= sideDiff;
				sum += sqr;
			}
		}
		return sum;
	}
	
	public static void main(String[] args) {
		// ONLY WORKS FOR ODD VALUES, HAVE NOT TESTED ON EVEN VALUES 
		System.out.println(sumSpiralDiagonalsOfNxN(1001));

	}

}
