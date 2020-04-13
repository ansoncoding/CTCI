package project_euler;

public class AmicableSum {

	
	static int[] memo;
	
	static int sumDivisorsOfN(int n) {
		if (n == 1) {
			return 1;
		}
		if (memo[n] != 0) {
			return memo[n];
		}
		int sqrt = (int)Math.sqrt(n);
		int sum = 1; // all numbers are divisible by 1
		for (int i = 2; i < sqrt ; i++) {
			if (n % i == 0) {
				sum +=i;
				int quotient = n / i; 
				if (quotient != i) { // don't add perfect squares twice
					sum += quotient;
				}
			}
		}
		
		memo[n] = sum;
		return sum;
	}
	
	static boolean isAmicablePair(int a, int b) {
		return (a != b && sumDivisorsOfN(a) == b && sumDivisorsOfN(b) == a);
	}
	
	static int sumAmicableNumUnder(int cap) {
		memo = new int[cap];
				
		int sum = 0;
		
		for (int a = 1; a < cap; a++) {
			for (int b = a+1; b < cap ; b++) {
				if (a == b) {
					continue;
				}
				if (isAmicablePair(a, b)) {
					sum += (a + b);
				}
			}
		}
		return sum;
	}
	
	public static void main(String[] args) {
		System.out.println(sumAmicableNumUnder(10000));

	}

}
