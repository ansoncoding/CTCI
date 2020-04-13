package project_euler;

public class NthPrime {
	
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
	
	public static int nthPrime(int n) {
		
		if (n == 1) {
			return 2;
		}
		if (n == 2) {
			return 3;
		}
		
		int count = 2;
		int start = 3;
		int retval = start;
		for (int i = start;  count < n; i+=2) {
			if (isPrime(i)) {
				count++;
				if (count == n) {
					retval = i;
				}
			}
		}
		return retval;
	}
	
	public static void main(String[] args) {
		System.out.println(nthPrime(10001));

	}

}
