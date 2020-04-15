package project_euler;

public class CoinSum {

	final static int[] coins = {0, 1, 2, 5, 10, 20, 50, 100, 200};
	
	static int[][] memo;
	
	
	static int numCoinSum(int sum, int denominationIndex) {
		
		// sum is 0, only one way 
		if (sum == 0) {
			return 1;
		}
		
		int currentCoin = coins[denominationIndex]; 

		// if we get here, it means sum is not zero yet we're only considering coin value $0 which means we cannot 
		// make that sum, return 0
		if (currentCoin == 0) {
			return 0;
		}
		
		// if sum is smaller than current sum, we can't really take advantage of the current coin/bill,
		//return the value from the row before with a smaller denomination
		if (sum < currentCoin) {
			return memo[(denominationIndex-1)%2][sum];
		}
		
		// If we CAN use the current denomination, we subtract the current denomination value from the sum, 
		// then go to the previously calculated leftover value's cell and see how many ways it can be made, 
		// add that with the option where if we didn't use the denomination 
		int leftoverSum = sum - currentCoin;
		
		return memo[denominationIndex%2][leftoverSum] + memo[(denominationIndex-1)%2][sum];
		
	}
	
	static int numCoinSum(int sum) {
		// save memory by using 2xsum array elements instead of (num coins * sum) elements since we only  need to know
		// previous row and current row, use modulus operation to alternate and write over existing data we don't need. 
		memo = new int[2][sum+1];
		
		for (int i = 0; i < coins.length; i++) {
			for (int j = 0; j <= sum; j++) {
				memo[i%2][j] = numCoinSum(j, i);
			}
		}
		
		return memo[(coins.length-1)%2][sum];
	}
	
	public static void main(String[] args) {
		System.out.println(numCoinSum(200));
	}
}
