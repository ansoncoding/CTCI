package project_euler;

import java.math.BigInteger;

public class LargestPrimeFactor {

	public static boolean isPrime(int number) { 
		if (number == 2 || number == 3) { 
			return true; 
		} 
		
		if (number % 2 == 0) {
			return false; 
		} 
		
		int sqrt = (int) Math.sqrt(number) + 1; 
		
		for (int i = 3; i < sqrt; i += 2) {
			
			if (number % i == 0) { 
				return false; 
			} 
		} 
		return true; 
	}

	
	public static int LargestPrimeFac(BigInteger n) {
		BigInteger sqr = n.sqrt();
		BigInteger max = new BigInteger(Integer.toString(Integer.MAX_VALUE));
		
		if (-1 == sqr.compareTo(max)) {
			int sqr_int = sqr.intValue();
			
			for (int i = sqr_int; i > 1; i--) {
				
				if ( BigInteger.ZERO == n.mod(new BigInteger(Integer.toString(i)))) {
					if (isPrime(i)) {
						return i;
					}
				}
			}
		}
		return 0;
	}
	
	public static void main(String[] args) {
		
		BigInteger  n = new BigInteger ("600851475143");
		System.out.println(LargestPrimeFac(n));
	}
}
