package project_euler;

import java.math.BigInteger;
import java.util.*;

public class ReciprocalCycles {
	
	
	static int inverseDecimalRepeatLen(int n) {
		
		HashMap<Integer, Integer> store = new HashMap<Integer, Integer>();
		ArrayList<Integer> decimals = new ArrayList<Integer>();
		
		int quotient;
		int retval = 0;
		int remainder = -1 ;
		boolean repeat = false;
		int divisor = 10;
		
		while(!repeat && remainder != 0) {
			
			quotient = divisor / n;
			decimals.add(quotient);
			
			remainder = divisor % n;
			
			if (store.containsKey(divisor)) {
				repeat = true;
				break;
			}
			store.put(divisor, 0);
			
			divisor = remainder;
			divisor *= 10;
		}
		
		if (repeat) {
			System.out.print(n + " : ");
			for (int i = 0; i < decimals.size(); i++) {
				System.out.print(decimals.get(i) + " ");
			}
			System.out.println();
			
			int len = decimals.size();
			int repeatingLast = decimals.get(len-1);
			for (int i = 0; i < decimals.size(); i++) {
				if (decimals.get(i) == repeatingLast) {
					
					retval =len - i -1;
					System.out.println("length : " + retval);
					return retval; 
				}
			}
		}
		return 0;
	}
	
	
	static int longestRepeatingDecimalSequenceInv(int invCap) {
		
		int longestRepeat = 0;
		int longestVal = 0;
		int length;
		for (int i = invCap ; i > 2; i--) {
			
			length = inverseDecimalRepeatLen(i);
			if (length > longestRepeat) {
				longestRepeat = length;
				longestVal = i;
			}
		}
		return longestVal;
	}
	
	public static void main(String[] args) {
		System.out.println(longestRepeatingDecimalSequenceInv(1000));
	}
}
