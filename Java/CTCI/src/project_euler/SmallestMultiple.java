package project_euler;

public class SmallestMultiple {

	// for 20 we don't need to test all 20 factors, we need to test the constraining ones
	public static boolean isMultiple(int n) {
		// 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 13,    
		// test 20, 19, 18, 17, 16, 15, 14, 13, 11
		int[] factors = {20, 19, 18, 17, 16, 15, 14, 13, 11};
		for (int i = 0; i < factors.length; i++) {
			if (n % factors[i] != 0) {
				return false;
			}
		}
		return true;
	}
	
	public static int SmallestAllMultiples() {
		int retval = 1;
		
		// for Smallest all multiples 1 - 20 the one answer we know for sure is by multiplying together the factors of 
		// numbers 1 - 20, but 20! is a large number we can simplify by multiplying together the factors
		// E.g. by multiplying together 2 and 5 we already know the number will be divisible by 10 as well
		// So we don't need to multiply by 10, however the prime numbers we can't simplify
		int factors[] = {2, 19, 9, 17, 4, 3, 5, 7, 13, 11};

		for (int i = 0; i < factors.length; i++) {
			retval *= factors[i];
		}
		System.out.println(retval);
		
		// After we found one return value for sure, we want to see if there's any that are smaller
		// we don't need to check every value below the return value, 
		// we can skip some values that are not divisible by 20 and 19
		
		for (int i = retval - (20*19) ; i > 1 ; i-=(20*19)) {
			if (isMultiple(i)) {
				return i;
			}
		}
		return retval;
	}
	
	public static void main(String[] args) {
		System.out.println(SmallestMultiple.SmallestAllMultiples());

	}

}
