package project_euler;

public class MaxPathSum {
	
	final static String input = 
			"75 " + 
			"95 64 " + 
			"17 47 82 " + 
			"18 35 87 10 " + 
			"20 04 82 47 65 " + 
			"19 01 23 75 03 34 " + 
			"88 02 77 73 07 63 67 " + 
			"99 65 04 28 06 16 70 92 " + 
			"41 41 26 56 83 40 80 70 33 " + 
			"41 48 72 33 47 32 37 16 94 29 " + 
			"53 71 44 65 25 43 91 52 97 51 14 " + 
			"70 11 33 28 77 73 17 78 39 68 17 57 " + 
			"91 71 52 38 17 14 91 43 58 50 27 29 48 " + 
			"63 66 04 68 89 53 67 30 73 16 69 87 40 31 " + 
			"04 62 98 27 23 09 70 98 73 93 38 53 60 04 23";
	
	static int[][] input_num = new int[15][15];

//	static boolean isEdge(int currentRow, int row, int col) {
//		return (col == 0 || col == (currentRow +1));
//	}
	static int leftChild(int row, int col) {
		if (row >= 14) {
			System.out.println("Row is out of bounds");
			return -1;
		}
		return input_num[row+1][col];
	}
	
	static int rightChild(int row, int col) {
		if (row >= 14) {
			System.out.println("Row is out of bounds");
			return -1;
		}
		return input_num[row+1][col+1];
	}
	
	static void parseInput() {
		String[] splitInput = input.split(" ");
		int count = 0;
				
		for (int i = 0; i < 15; i++) {
			for (int j = 0; j < i+1; j++ ) {
				input_num[i][j] = Integer.parseInt(splitInput[count]);
				count++;
			}
		}
		
//		for (int i = 0; i < 15; i++) {
//			for (int j = 0; j < i+1; j++ ) {
//				System.out.printf("%02d ", input_num[i][j]); 
//			}
//			System.out.println();
//		}
	}

	
	static int maxPathSum(int row, int col) {
		if (row == 14) {
			return input_num[row][col];
		} else {
			int leftPathSum = input_num[row][col] + maxPathSum(row+1, col);
			int rightPathSum = input_num[row][col] + maxPathSum(row+1, col+1);
			return Math.max(leftPathSum, rightPathSum);
		}
	}
	
	public static void main(String[] args) {
		parseInput();
		System.out.println(maxPathSum(0,0));

	}

}
