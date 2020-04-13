package project_euler;

import java.math.BigInteger;
import java.util.HashMap; 
public class LongestCollatzSeq {

	final static BigInteger bigIntThree = new BigInteger("3");
	static BigInteger bigIntCap = new BigInteger(Integer.toString(Integer.MAX_VALUE));
	
	static HashMap<Integer, Integer> memo = new HashMap<Integer, Integer>();
	
	
	static BigInteger nextVal(BigInteger n) {
		
		if (BigInteger.ZERO.compareTo(n.mod(BigInteger.TWO)) == 0) {
			
			return n.shiftRight(1);
			
		} else {
			
			return (n.multiply(bigIntThree)).add(BigInteger.ONE);
		}
	}
	
	static int lengthSequence2(int n) {
		
		int count = 0;
		BigInteger next = new BigInteger(Integer.toString(n));
		
		while (next.compareTo(BigInteger.ONE) == 1) {
			
			if (next.compareTo(bigIntCap) == -1) {
				if (memo.containsKey(next.intValue())) {
					return count + memo.get(next.intValue());
				} 
			}
			count++;
			next = nextVal(next);
		}
		return count;
	}
	
	static int findLongestSeqStartingNumUnder2(int cap) {
		
		int maxLength = 1;
		int startNum = cap-1;
		
		for (int i = cap/2 ; i < cap; i++) {
			int length = lengthSequence2(i);
			memo.put(i, length);
			if (length > maxLength) {
				maxLength = length;
				startNum = i;
			}
		}
		return startNum;
	}
	
	static int lengthSequence(int n) {
		int count = 0;
		
		BigInteger next = new BigInteger(Integer.toString(n));
		for (; next.compareTo(BigInteger.ONE) == 1; next = nextVal(next)) {
			count++;
		}
		return count;
	}
	
	static int findLongestSeqStartingNumUnder(int cap) {
		int maxLength = 1;
		int startNum = cap-1;
		for (int i = cap-1; i > 1; i--) {
			
			int length = lengthSequence(i);
			
			if (length > maxLength) {
				maxLength = length;
				startNum = i;
			}
		}
		return startNum;
	}
	
	public static void main(String[] args) {
		
		System.out.println(findLongestSeqStartingNumUnder2(1000000));
	}

}
