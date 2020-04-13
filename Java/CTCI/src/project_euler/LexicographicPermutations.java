package project_euler;

import java.util.*;

public class LexicographicPermutations {
	
	static boolean[] values = new boolean[10]; 
	
	static int factorial(int n) {
		int retval = 1;
		for (int i = 1; i <= n; i++ ) {
			retval *= i;
		}
		return retval;
	}
	
	static int getValue(int index) {
		
		int count = index;
		
		for (int i = 0; i < 10; i++) {
			if (!values[i]) {
				
				if (count == 0) { 
			
					return i;
				} else {
					count--;
				}
			}
		}
		System.out.println("Unexpected behaviour");
		return -1;
	}
	
	static String findNthPermutation(int n) {
		// Usually people want to find things like the "millionth permutation" they mean start counting from 1
		n-= 1;
		
		int totalPermutations = factorial(10);
		StringBuilder retval = new StringBuilder();
		
		if (n > totalPermutations) {
			System.out.println("Index exceeds total number of permutations: " + totalPermutations);
			return "";
		}
		
		// Since the permutations are lexically sorted we know the first 1/10 of the permutations start with 0
		// the 2nd 1/10 of the sorted permutations start with 1 and 3rd 1/10 of the permutations start with 2 etc.
		// We get the first index by doing nth / 9! because there are 10! in total, by dividing by 9! we know which tenth
		// the first digit is in. 
		
		// After we know the first digit, we repeat using 8! to find the first 1/9, the second 1/9 and the third 1/9.
		// E.g. first digit was 3 - the values left are 0, 1, 2, 4, 5, 6, 7, 8, 9 (9 values leftover) we divide the 
		// leftover permutations by 9, the first 1/9 of the permutations will have 0 has its second digit, the 2nd 1/9 
		// of the permutations will have 1 as its second digit, the 3rd 1/9 of the permutations will have 4 as its second
		// digit and so on.
		
		// We need to mark off the digit found from the prev round as there are no duplicates in a permutation.
		// So the values array will be "true" after the number has been used. We simply find the next smallest (also 
		// lexically smallest) to fill the spot. This is done in getValue()
		
		for (int i = 9; i >= 0; i--) {
			int countPrefix = factorial(i);
			int index = n / countPrefix;
			int val = getValue(index);
			values[val] = true;
			retval.append(Integer.toString(val));

			// we need to subtract the accounted for permutations so we can start next round 
			n -= (index * countPrefix); 
		}
	
		return retval.toString();
	}

	public static void main(String[] args) {
		System.out.println(findNthPermutation(1000000));

	}

}
