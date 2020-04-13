package project_euler;

public class LargestPalindromeProduct {

	static boolean isPalindrome(String s) {
		int len = s.length();
		//System.out.println(s);
		
		for (int i = 0; i < (len / 2); i++) {
			//System.out.println(Integer.toString(i)  + " " + Integer.toString(len-i));
			if (s.charAt(i) != s.charAt(len-i-1)) {
				return false;
			}
		}
		return true;
	}
	
	static int largestPalindromeProduct(int min, int max) {
		int largest = 0;
		for (int i = max; i >= min; i-- ) {
			for (int j = max; j >= i; j-- ) {
				int product = i * j;
				if (isPalindrome(Integer.toString(product))) {
					if (product > largest) {
						largest = product;
					}
				}
			}	
		}
		return largest;
	}
	
	public static void main(String[] args) {
		System.out.println(largestPalindromeProduct(100, 999));
	}
}
