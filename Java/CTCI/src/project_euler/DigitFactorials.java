package project_euler;

public class DigitFactorials {
	
	// The way to calculate the cap is - say there's a D digit number, it must fall between 10^D and 10^(D+1)
	// E.g. a 4 digit number falls between 1000 and 10000 (excluding 10000)
	// The D digit number's factorial sum must fall between 1 and D*9!  (the range of a 4 digit number 1000 (sum is 1)
	// and 9999 (sum is 4*9!)
	// We can do some simple calculations to see when this stops making sense
	
	// 1! = 1
	// 2! = 2
	// 3! = 6
	// 4! = 24
	// 5! = 120
	// 6! = 720
	// 7! = 5040
	// 8! = 40320
	// 9! = 362880
	
	// For a single digit number, we're asking what number is equal to its factorial? Answer is none
	// For 2 digit numbers we only need to consider digits 1 - 4 since having a 5 already exceeds the 99 cap
	// For 3 digit numbers we only need to consider digits 1 - 6 since having 7! already exceeds the 999 cap
	// For 4 digit numbers we only need to consider digits 1 - 7 since having 8! already exceeds the 9999 cap
	// For 5 digit numbers we only need to consider digits 1 - 8 since having 9! already exceeds the 99999 cap
	// For 6 digit numbers we consider all numbers and the max factorial sum will be 1 - 6 * 9! which is 2,177,280 (7 digits OK)
	// For 7 digit numbers we consider all numbers and the max factorial sum will be 1 - 7 * 9! which is 2,540,160 (7 digits OK) 
	// For 8 digit numbers we consider all numbers and the max factorial sum will be 1 - 8 * 9! which is 2,903,040 (7 digits NOT OK)
	
	// Why is 8 digit NOT OKAY? Imagine we have an 8 digit number between 10,000,000 and 99,999,999 the minimum factorial sum is 1,
	// The maximum factorial sum is 8* 9! = 2,903,040, both the minimum factorial sum and maximum factorial sum are under 10,000,000
	// So there is 0 chance that the factorial sum can be the number itself
	// I.E. There's no overlap in the range of the number 10,000,000 -- 99,999,999 and the range of the factorial sum 1 -- 2,903,040
	// So they can never be the same number
	
	// Let's recap this one more time and explain why 7 digits is OK
	// Imagine we have a 7 digit # between 1,000,000 and 9,999,999 the min factorial sum is 1, max factorial sum is 7 * 9! = 2,540,160
	// In this case there IS overlap between range of the number: 1,000,000 -- 9,999,999 and range of the factorial sum: 1 -- 2,540,160 
	// The overlapping region is 1,000,000 -- 2,540,160
	
	// And that's why the cap is 2,540,160 without any further analysis
	// To optimize further we can also see that having at most 2! + 4! + 5*9! as the factorial sum (1,814,426) from the cap we computed
	// We can set the cap to be further down
	
	// Can we do better?
	
	// So now we see that actually the first digit is 1 not 2
	
	// We notice that 5! and over the factorial all end with 0 since they all have 2 and 5 as factors
	// Using this clue we know that out of the possible values 1 - 1,999,999, the ones that start with 1 and has all digits >= 5 after it
	// will have a factorial sum ending in 1, not possible. So from this we can eliminate 1,555,555 - 1,999,999
	
	// So we can probably go further but for the purposes of this question, we can stop here. Know that we can keep going but
	// the law of diminishing returns kind of says it's probably ok to stop here.
	
	final static int cap = 2540160;
	final static int[] factorials = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
	
	static int digitFactorialSum(int n) {
		int sum = 0;
		while (n != 0) {
			sum += factorials[n % 10];
			n /= 10;
		}
		return sum;
	}
	
	static int digitFactorialAll() {
		int sum = 0;
		for (int i = 10; i < cap; i++) {
			if (i == digitFactorialSum(i)) {
				sum += i;
			}
		}
		return sum;
	}
	
	public static void main(String[] args) {
		System.out.println(digitFactorialAll());
	}

}
