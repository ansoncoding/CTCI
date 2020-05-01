package project_euler;

public class DoubleBasePalindromes {

	static boolean isPalindrome(String s) {
		int len = s.length();
		for (int i = 0; i < s.length()/2; i++) {
			if (s.charAt(i) != s.charAt(len-1-i)) {
				return false;
			}
		}
		return true;
	}
	
	static int countDoubleBasePalindromes(int cap) {
		int sum = 0;
		for (int i = 0; i < cap; i++) {
			if (isPalindrome(Integer.toBinaryString(i)) && isPalindrome(Integer.toString(i))) {
				sum += i;
			}
		}
		return sum;
	}
	
	static int generatePalindrome(int i, boolean odd) {
		int retval = i;
		if (odd) {
			i /= 10;
		}
		while(i != 0) {
			retval *= 10;
			retval += i % 10;
			i /= 10;
		}
		//System.out.print(retval + " ");
		return retval;
	}
	
	// Use optimization of 
	// 1) Even numbers (aside from 0 ) cannot be binary palindromes since leading zeros are not allowed
	// 2) For every palindrome abcba or abccba we know the first 3 numbers we already know the whole number
	// We can generate palindromes this way and not have to test every value up to cap
	
	static int countDoubleBasePalindromes2(int cap) {
		int sum = 0;
		
		// abc -> abcba
		int i = 1;
		int p = generatePalindrome(i, true);
		while (p < cap) {
			if (p % 2 == 1 && isPalindrome(Integer.toBinaryString(p))) {
				sum += p;
			}
			i+=1;
			p = generatePalindrome(i, true);
		}
		
		// abc -> abccba
		i = 1;
		p = generatePalindrome(i, false);
		while (p < cap) {
			if (p % 2 == 1 && isPalindrome(Integer.toBinaryString(p))) {
				sum += p;
			}
			i+=1;
			p = generatePalindrome(i, false);
		}
	
		return sum;
	}
	
	public static void main(String[] args) {
		System.out.println(countDoubleBasePalindromes(1000000));

	}

}
