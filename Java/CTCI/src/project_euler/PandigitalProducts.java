package project_euler;

import java.util.*;

public class PandigitalProducts {

	static HashSet<Integer> pandigitalProducts = new HashSet<Integer>();
	
	static boolean isOneThroughNine(int multiplicand, int multiplier, int product) {
		boolean[] temp = new boolean[10];
		int count =9;
		// Check for 0s! They cannot exist in any of the numbers
		// The method is to use an array to keep track of which digits are seen already
		// Since no duplicates allowed, as soon as the digit is seen again we return false
		// As soon as we see a zero digit return false
		// In the end we can loop through the array and see if any digits haven't been erased. 
		// Another more efficient way is to use a count down variable starting at 9 and count down each time 
		// we cross off a digit. If at the end we have reached zero we know we have seen all 9 digits
		while (multiplicand != 0) {
			int ind = multiplicand %10;
			if (ind == 0 || temp[ind]) {
				return false;
			}
			temp[ind] = true;
			count --;
			multiplicand /= 10;
		}
		
		while (multiplier != 0) {
			int ind = multiplier %10;
			if (ind == 0 || temp[ind]) {
				return false;
			}
			temp[ind] = true;
			count --;
			multiplier /= 10;
		}
		
		while (product != 0) {
			
			int ind = (int)(product %10);
			if (ind == 0 || temp[ind]) {
				return false;
			}
			temp[ind] = true;
			count --;
			product /= 10;
		}
		
		return count == 0;
	}
	
	// Use basic math we can start with 1 digit x N digit = (9 - N -1 ) digits and see what are possible values for N
	// Knowing that the first number is single digit, we have 8 digits left for multiplier and product, so 
	// 1 x 3 digit maybe? the product must be 9 - 1 - 3 = 5 digits (1 * 100 = 100, 9 * 999 = 8991 so we know even the
	// largest 1 x 3 digit product is 4 digit. So maybe 1 x 4 digits? (1 * 1000 = 1000, 9 * 9999 = 89991) Yes, 1x4 digits
	// definitely has possibility of giving us 4 digit products. How about 1 digit x 5 digit? (1 * 10000 = 10000) Not possible.
	
	// If we do this for all digits 1 - 9 we'll notice the possible combinations are:
	// 1) 1 digit  x 4 digits = 4 digits
	// 2) 2 digits x 3 digits = 4 digits
	// 3) 3 digits x 2 digits = 4 digits
	// 4) 4 digits x 1 digits = 4 digits
	
	// We can tell that 3) and 4) are duplicates of 1) and 2) so we only need to test the first and second combinations
	
	// Lastly since there might be some duplicate products which qualify, we use a set to store them and let the set
	// take care of the duplicates (which won't be added)
	static int pandigitalProductsSum() {
		// 1 digit x 4 digits
		for (int i = 1; i < 10; i++) {
			for (int j = 1000 ; j < 10000; j++) {
				int product = i * j;
				if (product < 10000) {
					if (isOneThroughNine(i, j, product)) {
						pandigitalProducts.add(product);
					}
				}
			}
		}
		
		// 2 digits x 3 digits
		for (int i = 10; i < 100; i++) {
			for (int j = 100; j < 1000; j++) {
				int product = i *j;
				if (product < 10000) {
					if (isOneThroughNine(i, j, product)) {
						pandigitalProducts.add(product);
					}
				}
			}
		}
		int sum = 0;
		for (int l : pandigitalProducts) {
			sum += l;
		}
		return sum;
	}
	
	public static void main(String[] args) {
		System.out.println(pandigitalProductsSum());
	}
}
