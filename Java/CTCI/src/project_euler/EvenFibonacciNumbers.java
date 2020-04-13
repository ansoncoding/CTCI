package project_euler;

import java.util.*;

public class EvenFibonacciNumbers {
	
	ArrayList<Integer> fib = new ArrayList<Integer>();
	
	int getFib(int ind) {
		if (ind == 0) {
			fib.add(ind, 1);
			return 1;
			
		} else if (ind == 1) {
			fib.add(ind, 1);
			return 1;
			
		} else {
		
			int retval = fib.get(ind-2) + fib.get(ind-1);
			fib.add(ind, retval);
			return retval;
		}
	}
	
	public int SumEvenFibNum(int cap) {
		int sum = 0;
		int count = 0;
		int fib;
		while (true) {
			
			fib = getFib(count); 
			if (fib < cap) {
				count++;
				if (fib % 2 == 0) {
					sum += fib;
				}
			} else {
				break;
			}
		}
		
		return sum;
	}
	
	public static void main(String[] args) {
		EvenFibonacciNumbers e = new EvenFibonacciNumbers();
		System.out.println(e.SumEvenFibNum(4000000));

	}

}
