package project_euler;

public class SumSquareDifference {

	static int squareOfSum(int n) {
		int retval;
		int sum = n* (n+1) / 2;
		retval = sum * sum;
		return retval;
	}
	
	static int sumOfSquare2(int n) {
		return (n * (2*n + 1) * (n + 1))/6;
	}
	
	static int sumOfSquare(int n) {
		int sum = 0;
		for (int i =1; i <= n; i++) {
			sum += (i*i);
		}
		return sum;
	}
	
	public static void main(String[] args) {
		
		System.out.println(squareOfSum(100) - sumOfSquare2(100));

	}

}
