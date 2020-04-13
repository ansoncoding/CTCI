package project_euler;


import java.math.BigInteger;
public class FactorialDigitSum {

	static int factorialDigitSum(int n) {
		
		BigInteger factorial = new BigInteger("1");
		for (int i = n ; i > 1; i--) {
			factorial = factorial.multiply(new BigInteger(Integer.toString(i)));
		}
		String f = factorial.toString();
		
		int sum = 0;
		for (int i = 0; i < f.length(); i++) {
			sum += Character.getNumericValue(f.charAt(i));
		}
		return sum;
	}
	
	public static void main(String[] args) {
		
		System.out.println(factorialDigitSum(100));
	}
}
