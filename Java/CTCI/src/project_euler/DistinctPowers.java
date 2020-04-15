package project_euler;

import java.math.BigInteger;
import java.util.HashSet;

public class DistinctPowers {

	static HashSet<BigInteger> distinctPowers = new HashSet<BigInteger>();
	
	static int numDistinctPowers() {
		for (int i = 2; i <= 100; i++ ) {
			for (int j = 2; j <= 100; j++) {
				distinctPowers.add((new BigInteger(Integer.toString(i)).pow(j)));
			}
		}
		return distinctPowers.size();
	}
	
	public static void main(String[] args) {
		System.out.println(numDistinctPowers());
	}
}
