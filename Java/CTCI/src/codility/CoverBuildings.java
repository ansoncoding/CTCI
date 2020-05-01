package codility;

import java.util.HashSet;
import java.util.Set;

public class CoverBuildings {
	
	// This algorithm uses O(n^2) but we can use it to check our answer
	static int cover2(int[] H) {
		
		int N = H.length;
		
		if (N == 1) {
            return H[0];
        }
        if (N == 2) {
            return H[0] + H[1];
        }
        int maxHeight = Math.max(H[0], H[1]);
        int[] memo = new int[N]; // memo stores the optimal area given 1 cloth at each height
        memo[0] = H[0] * 1;
        memo[1] = maxHeight * 2;
        int min= memo[1];
        for (int i = 2; i < N; i++) {
        	
        	// we can set the min to be the previous heights all under one cover and the new height under a new cover
        	min = memo[i-1] + H[i]; 
        	maxHeight = Math.max(maxHeight, H[i]);
        	for (int j = 0; j < i; j++) {
        		int area = memo[j] + maxHeight * (i-j);
        		//System.out.println("area " + area);
        		if (area < min) {
        			min = area;
        		}
        	}
        	memo[i] = maxHeight * (i+1);
        	//System.out.println("memo " + i + " " + memo[i]);
        }
        return min;
	}

    static int solution(int[] H) {
        
        int N = H.length;
        if (N == 1) {
            return H[0];
        }
        if (N == 2) {
            return H[0] + H[1];
        }
        
        int height1 = H[0];
        int height2 = H[1];
        int width1 = 1;
        int width2 = 1;
        int area = height1 * width1 + height2 * width2;
        
        for (int i = 2; i < N; i++) {
            
            int tempHeight1 = Math.max(height1, height2);
            int tempHeight2 = Math.max(height2, H[i]);
            
            int a1 = height1 * width1 + tempHeight2 * (width2 + 1);
            int a2 = tempHeight1 * (width1 + width2) + H[i];
            
            // option a1 is smaller, keep track of its widths and heights
            // width1 and height1 do not change
            if (a1 < a2) {
                height2 = tempHeight2;
                width2 += 1;
                area = a1;
            } else {
                //option a2 is smaller, keep track of width and heights
                height1 = tempHeight1;
                width1 += width2;
                height2 = H[i];
                width2 = 1;
                area = a2;
//            }
//            else {
//            	
//            }
            }
        }
        
        return area;
    }
    public static void main(String[] args) {
    	int N = 6;
    	int input[] = new int[N];
    	Set<Integer> in = new HashSet<Integer>(N);

    	for (int i = 1; i <= N; i++) {
    		in.add(i);
    	}
    	
    	int count = 0;
    	for (Integer i : in) {
    		input[count] = i;
    		count++;
    	}
    	System.out.println(in);
		System.out.println(solution(input));
		System.out.println(cover2(input));

	}
}
