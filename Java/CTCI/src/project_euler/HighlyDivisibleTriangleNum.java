package project_euler;

import java.util.ArrayList;

public class HighlyDivisibleTriangleNum {

	// positive number only
	public static int numDivisors(int n) {
		if (n == 1) {
			return 1;
		}
		ArrayList<Integer> factors = new ArrayList<Integer>();
		ArrayList<Integer> exponents = new ArrayList<Integer>();
		
		if (n % 2 == 0) {
			int count = 0;
			factors.add(2);
			do {
				n /= 2;
				count++;
			}
			while ( n % 2 == 0);
			exponents.add(count);
		}
		
		// the number is odd now
		int n_prev = n;
		for (int try_factor = 3; n > 1; try_factor+=2) {
			
			if (n % try_factor == 0) {
				
				int count = 0;
				factors.add(try_factor);
				do {
					n_prev = n;
					n /= try_factor;
					
					count++;
				}
				while ( n % try_factor == 0 && n > 1);
				exponents.add(count);
			}
		}
		
		int numDivisors = 1;
		for (Integer e: exponents) {
			numDivisors *= (e + 1);
		}
		return numDivisors;
	}
	
	public static int triangleNumWithNSide(int n) {
		return (n * (n+1)/2);
	}
	
	public static int triangleNumWithDivisorsGT(int numDivisors) {
		int triangleNum;
		int sideLen = 1;
		int numFactors = 0;
		do {
			triangleNum = triangleNumWithNSide(sideLen);
			numFactors = numDivisors(triangleNum);
			sideLen++;
			
		} while (numFactors <= numDivisors);
		return triangleNum;
	}
	
	public static void main(String[] args) {
		System.out.println(triangleNumWithDivisorsGT(500));

	}

}
