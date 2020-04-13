package project_euler;

import java.math.BigInteger;

public class PowerDigitSum {

	
	static int powerDigitSum(int power) {
		BigInteger bigIntTwo = BigInteger.TWO;
		BigInteger val = bigIntTwo.pow(power);
		int sum = 0;
		String digits = val.toString();
		for (int i = 0; i < digits.length(); i++) {
			sum += Character.getNumericValue(digits.charAt(i));
		}
		return sum;
	}
	
	public static void main(String[] args) {
		System.out.println(powerDigitSum(1000));
	}
}
