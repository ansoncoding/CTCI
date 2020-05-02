package codility;

import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class CoverBuildings {
    
	// Given an array of buildings of various heights (widths are all equal to 1)
	// there are 2 rectangular covers which can be used to cover the buildings.
	// Find the minimum area required to cover all of the buildings using 2 covers 
	
	// Analysis: The problem is complex because there are many possibilities
	// For an array of length N there are N-1 places where the 2 covers could meet
	// The total area is the max height of the 1st partition * width of 1st partition + max height of 2nd partition * its width
	// Using one pass we can find the max height "so far" and store them in an array, however how to find the max height starting at 
	// index i?
	// Using a 2D matrix we can store the max heights of the arrays starting at index i however this would require O(n^2) time 
	// and O(n^2) space, not ideal.
	
	// The insight is there are only two covers, so in the case that the max heights occur on two opposing sides of the 
	// array the minimum area is max height * N, no matter how many lower buildings are in between them.
	
	// So the insight is we can store the max height "so far" in another array but starting from the right hand side, and 
	// find the minimum areas start from each side
	
	// Getting max height is O(n) and we know the max area is max height * N (N is the total number of buildings)
	// We can go from the left side and subtract the first building from the max area, and add its height instead 
	// So we can use O(n) to find the minimum of these :
	// maxArea - 1 * maxHeight + 1 * H[0]
	// maxArea - 2 * maxHeight + 2 * max(H[1], H[0])
	// maxArea - 3 * maxHeight + 3 * max(H[2], H[1], H[0])
	// ...
	// maxArea - (N-1) * maxHeight + (N-1) * max(H[N-1], .... H[0])
	
	// Then we do it again from the right hand side - think about flipping the buildings around the y-axis without changing their order
	// it still works.
	// This will take O(n) again. 
	// And we take the minimum area of the min areas found starting from left, and starting from right and return that. 
	// Total space is O(n), total time O(n)
	
    static int solution(int[] H) {
    	
        int N = H.length;
        
        // Trivial cases, simply return the appropriate values
        if (N == 1) {
            return H[0];
        }
        if (N == 2) {
            return H[0] + H[1];
        }
        
        // Initialize the max height arrays, memo is from left side, rev_memo from right hand side. They store the max height seen
        // so far. E.g H = [5, 2, 3, 4] memo will be [5, 5, 5, 5], rev_memo will be [4, 4, 4, 5]
        int[] memo = new int[N];
        int[] rev_memo = new int[N];
        int global_max = H[0];
        memo[0] = H[0];
        rev_memo[0] = H[N-1];
        
        for (int i = 1; i < N; i++) {
        	memo[i] = Math.max(memo[i-1], H[i]);
        	rev_memo[i] = Math.max(rev_memo[i-1], H[N-i-1]);
        	if (H[i] > global_max) {
        		global_max = H[i];
        	}
        }       

        int maxArea = global_max * N;
        
        // Left hand side
        int minArea1 = maxArea;
        for (int i = 0; i < N-1; i++) {
        	int area = maxArea - (global_max * (i + 1)) + (memo[i] * (i + 1)); 
        	if (area < minArea1) {
        		minArea1 = area;
        	}
        }
        
        // Right hand side
        int minArea2 = maxArea;
        for (int i = 0; i < N-1; i++) {
        	int area = maxArea - (global_max * (i + 1)) + (rev_memo[i] * (i + 1)); 
        	if (area < minArea2) {
        		minArea2 = area;
        	}
        }
        return Math.min(minArea1, minArea2);
    }
    
    @Test
	public void testCoverBuildings() {
    	int input[] = {5, 3, 2, 4};
    	int input2[] = {1, 1, 7, 6, 6, 6};
    	int input3[] = {7, 7, 3, 7, 7};
    	int input4[] = {5, 3, 5, 2, 1};
    	int input5[] = {3, 1, 4};
    	int input6[] = {1, 2, 3, 4, 5, 6};
    	int input7[] = {6, 5, 4, 3, 2, 1};
		assertEquals(17, solution(input));
		assertEquals(30, solution(input2));
		assertEquals(35, solution(input3));
		assertEquals(19, solution(input4));
		assertEquals(10, solution(input5));
		assertEquals(27, solution(input6));
		assertEquals(27, solution(input7));
		
		int input8[] = new int[100];
		for (int i = 1; i <= 100 ; i++) {
			input8[i-1] = i;
		}
		assertEquals(7500, solution(input8));
	}
    
}
