package project_euler;

public class PythagoreanTriplet {

	public static int GCD(int a, int b) {

		if (a == 0) {
			return b;
		}
		if (b == 0) {
			return a;
		}

		int x = a;
		int y = b;

		while (y != 0) {
			int temp = y;
			y = x % y;
			x = temp;
		}
		return x;
	}

	public static boolean isCoprime(int a, int b) {
		if (a % 2 == 0 && b % 2 == 0) {
			return false;
		}
		return (GCD(a, b) == 1);
	}

	public static int productTripletWithSum(int sum) {
		for (int i = 1; i < sum / 2; i++) {
			for (int j = i + 1; j < sum / 2; j++) {
				if (j % 2 == 1 && i % 2 == 1) {
					continue;
				}
				if (isCoprime(i, j)) {
					int j_sqr = j * j;
					int i_sqr = i * i;
					int a = j_sqr - i_sqr;
					int b = 2 * j * i;
					int c = j_sqr + i_sqr;
					int triplet_sum = (a + b + c);
					if (triplet_sum == sum) {
						System.out.println("Triplet: " + a + " " + b + " " + c);
						return a * b * c;
					}
					if ((sum % triplet_sum) == 0) {
						int k = sum / triplet_sum;
						System.out.println("Triplet: " + k * a + " " + k * b + " " + k * c);
						return (k * a * k * b * k * c);
					}
				}
			}
		}
		return -1;
	}

	public static void main(String[] args) {
		System.out.println(productTripletWithSum(1000));
	}
}
