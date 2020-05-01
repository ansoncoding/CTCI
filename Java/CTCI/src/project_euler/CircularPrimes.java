package project_euler;

public class CircularPrimes {
	
	static boolean isPrime(int number) { 
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
	
	static boolean isCircularPrime(String num) {
		for (int i = 0; i < num.length(); i++) {
			int temp = Integer.parseInt(num);
			if (!isPrime(temp)) {
				return false;
			}
			num = num.substring(1).concat(num.substring(0,1));
			//System.out.println(num);
		}
		return true;
	}
	
	static boolean noEvenDigits(String num) {
		for (int i = 0; i < num.length(); i++) {
			int val = Character.getNumericValue(num.charAt(i));
			
			if (val %2 == 0) {
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
		int start = 5;
		
		for (int i = start;  i < n; i+=2) {
			
			String temp = Integer.toString(i);
			
			// Since we're looking for circular primes we cannot allow any even digits in the number
			// since the rotation will be an even number
			if (noEvenDigits(temp)) {
			
				if (isCircularPrime(temp)) {
					count++;
				}
			}
		}
		return count;
	}
	
	public static void main(String[] args) {
		System.out.println(circularPrimesUnderN(1000000));
	}

}
