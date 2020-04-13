package project_euler;

import java.math.BigInteger;

public class PrimeSummation {
	
	public static boolean isPrime(int number) { 
		if (number <= 1) {
			return false;
		}
		
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
	
	
	// Optimized Sieve of Eratothenes method where since we're crossing off 1/2 the numbers anyway, might as well
	// save on memory and only allocate cap/2 booleans for the sieve
	public static BigInteger sumPrimesUnder3(int cap) {
		if (cap <= 1) {
			return new BigInteger("0");
		}
		if (cap <= 3) {
			return new BigInteger("2");
		}
		
		// sieve contains values [3][5][7][9][11][13][15] so index 0 = 3; 1 = 5, 2 = 7; 3 = 9; 
		// we can use (index + 1) * 2 + 1 to get the value - E.g. (0+1) * 2 + 1 = 3; (1+1) *2 + 1 = 5; (2+1) * 2 + 1 = 7
		// the reverse is (num - 1) / 2 - 1 to get the index of the sieve
		// E.g. we want to mark 15 as true, (15 - 1)/2 - 1= 6, index 6 is 15; which we know is true
		boolean[] sieve = new boolean[cap/2];
		int limit = (int)Math.sqrt(cap);
		
		// starting at 3, we only need to look at odd numbers since even numbers above 2 are marked already
		// hence the i += 2
		for (int i = 3; i < limit; i +=2) {
			int sieve_ind = (i - 1)/2 - 1;
			// the sieve is not marked - it's a prime number
			if (!sieve[sieve_ind]) {
				// we start at 3^2 because 4, 6, 8 have already been marked by the even numbers loop above
				// similarly with 3, we mark 9, 15, 21 etc.
				// we don't need to mark off 12, 18, etc because they have already been marked by the even # loop
				// so we can increment by 2*i
				for (int j = i * i; j < cap; j += 2*i) {
					int index = (j - 1) /2 - 1;
					sieve[index] = true;
				}
			}
		}
		
		// because we started at 3 our sieve is actually 1 size too large, we need to subtract 1 at the end of the for loop
		BigInteger sum = new BigInteger("2");
		for (int i = 0; i < cap/2-1; i++) {
			if (!sieve[i]) {
				int val = (i + 1) * 2 + 1;
				sum = sum.add(new BigInteger(Integer.toString(val)));
			}
		}
		return sum;
	}
	
	// Use the Sieve of Eratothenes for a faster algorithm, but use more memory as trade-off
	public static BigInteger sumPrimesUnder2(int cap) {
		
		if (cap <= 3) {
			return new BigInteger("0");
		}
		
		boolean[] sieve = new boolean[cap];
		int limit = (int)Math.sqrt(cap);
		

		// even numbers are not prime
		for (int i = 4; i < cap; i += 2) {
			sieve[i] = true;
		}
		
		// starting at 3, we only need to look at odd numbers since even numbers above 2 are marked already
		// hence the i += 2
		for (int i = 3; i < limit; i +=2) {
			
			// the sieve is not marked - it's a prime number
			if (!sieve[i]) {
				// we start at 3^2 because 4, 6, 8 have already been marked by the even numbers loop above
				// similarly with 3, we mark 9, 15, 21 etc.
				// we don't need to mark off 12, 18, etc because they have already been marked by the even # loop
				// so we can increment by 2*i
				for (int j = i * i; j < cap; j += 2*i) {
					sieve[j] = true;
				}
			}
		}
		
		BigInteger sum = new BigInteger("0");
		for (int i = 2; i < cap; i++) {
			if (!sieve[i]) {
				sum = sum.add(new BigInteger(Integer.toString(i)));
			}
		}
		return sum;
	}
	
	public static BigInteger sumPrimesUnder(int cap) {
		
		// Get past these edge cases so we can skip the even numbers in the main loop
		if (cap <= 1) {
			return new BigInteger("0");
		}
		if (cap <= 3) {
			return new BigInteger("2");
		}
		if (cap <= 5) {
			return new BigInteger("5");
		}
		
		BigInteger sum = new BigInteger("5"); 
			
		int i = 5; 
		while (i < cap) {
			if(isPrime(i)) {
				sum = sum.add(new BigInteger(Integer.toString(i)));
			}
			i+=2;
			if (i < cap) {
				if (isPrime(i)) {
					sum = sum.add(new BigInteger(Integer.toString(i)));
				}
			}
			i += 4;
		}
		return sum;
	}
	
	
	public static void main(String[] args) {
		System.out.println(sumPrimesUnder3(2000000));
	}
}
