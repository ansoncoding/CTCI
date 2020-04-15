package project_euler;


public class DigitFifthPowers {
	
	// The idea behind this question is not necessarily "which 5 digit number is also its digits each to the power of 5
	// summed together? It's saying, what number is each of its digits each to the power of 5 summed together? 
	// There was no rule anywhere saying it had to be a 5 digit number.
	
	// We have to find the cap ourselves.
	// The sum of the digits' fifth powers is maximized when each digit is 9:<br />
    // 1 digit: 1 x 9^5 = 59049
    // 2 digits: 2 * 9^5 = 118098
    // 3 digits: 3 * 9^5 = 177147
    // 4 digits: 4 * 9^5 = 236196
    // 5 digits: 5 * 9^5 = 295245
    // 6 digits: 6 * 9^5 = 354294
    // 7 digits: 7 * 9^5 = 413343
	
	// We can see that we can stop at 6 digits because at 7 digits the max of the 5th powers (even if they were all 9's)
	// only add up to 6 digit numbers.
	static int sumFifthPowerDigits() {
		
		int retsum = 0;
		int cap = (int)Math.pow(9, 5) * 6;
		
		for (int i = 2; i < cap; i++) {
			int[] digits = new int[6];
			int val = i;
			int index = 0;
			
			// use modulus to find each individual digit
			// index will keep track of how many digits the number is
			// we're storing it in an array index 0 being the ones, index 1 being tens etc..
			// but the order doesn't matter for the purposes of this question since we're summing up the
			// 5th power of each and order doesn't matter.
			while (val > 0) {
				digits[index] = val % 10;
				val /= 10;
				index++;
			}
			int sum = 0;
			for (int j = 0; j < index; j++) {
				sum += (int)Math.pow(digits[j], 5);
			}
			if (sum == i) {
				retsum += sum;
			}
		}
		return retsum;
	}
	
	public static void main(String[] args) {
		System.out.println(sumFifthPowerDigits());

	}
}
