package project_euler;

public class CircularPrimes {
	public static boolean isPrime(int number) { 
		if (number == 2 || number == 3) { 
			return true; 
		} 
		
		if (number % 2 == 0) {
			return false; 
		} 
		
		if (number % 3 == 0) {
			return false; 
		} 
		
		if (number < 9) {
			return true;
		}
		
		int sqrt = (int) Math.sqrt(number) + 1; 
		
		for (int i = 5; i < sqrt; i++) {
			
			if (number % i == 0) { 
				return false; 
			} 
		} 
		return true; 
	}
	
	static int circularPrimesUnderN(int n) {
		if (n <= 2) {
			return 0;
		}
		if (n == 3) {
			return 1;
		}
		
		int count = 2;
		int start = 3;
		int retval = start;
		for (int i = start;  count < n; i+=2) {
			if (isPrime(i)) {
				count++;
				if (count == n) {
					retval = i;
					break;
				}
			}
		}
		return retval;
	}
	
	public static void main(String[] args) {
		System.out.println(circularPrimesUnderN(1000));
	}

}
