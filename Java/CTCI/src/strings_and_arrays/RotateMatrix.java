package strings_and_arrays;


public class RotateMatrix {
	
	public static void rotate_cw_90(int[][] mat, int N) {
	    
	    for (int li = 0; li < N / 2; li++) { //li is layer index
	        int start = li;
	        int end = N - li - 1;
	        for (int i = 0; i < end-li; i++) { // i will be offset
	            int temp = mat[start+i][end];

	            mat[start+i][end] = mat[start][start+i];
	            mat[start][start+i] = mat[end-i][start];
	            mat[end-i][start] = mat[end][end-i];
	            mat[end][end-i] = temp;
	        }
	    }
	}
	
	public static void rotate_ccw_90(int[][] mat, int N) {
	    
	    for (int li = 0; li < N / 2; li++) { //li is layer index
	        int start = li;
	        int end = N - li - 1;
	        for (int i = 0; i < end-li; i++) { // i will be offset
	        	
	            int temp = mat[start+i][end];
	            mat[start+i][end] = mat[end][end-i];
	            mat[end][end-i] = mat[end-i][start];
	            mat[end-i][start] = mat[start][start+i];
	            mat[start][start+i] = temp;
	        }
	    }
	}
	
	public static void rotate_ccw_90(int[][] mat, int N, int M) {
	    
	    for (int li = 0; li < N / 2; li++) { //li is layer index
	        int start = li;
	        int end = N - li - 1;
	        for (int i = 0; i < end-li; i++) { // i will be offset
	        	
	            int temp = mat[start+i][end];
	            mat[start+i][end] = mat[end][end-i];
	            mat[end][end-i] = mat[end-i][start];
	            mat[end-i][start] = mat[start][start+i];
	            mat[start][start+i] = temp;
	        }
	    }
	}
	
	
	public static void flip_180(int[][] mat, int N, int M) {
	    for (int i=0 ; i< N/2; i++) {
	        for (int j=0; j < M; j++) {
	            MatrixUtils.swap(mat, i, j, N-i-1, j);
	        }
	    }
	}
	public static void rotate_180( int[][] mat, int N, int M) {
		for (int i= 0; i < N/2; i++) {
			for (int j = 0;j < M; j++) {
				MatrixUtils.swap(mat, i, j, N-i-1, M-j-1);
			}
		}
		if ((N % 2) == 1) {
			int row = N/2;
			for (int j = 0; j < M/2; j++) {
				MatrixUtils.swap(mat, row, j, row, M-j-1);
			}
		}
	}
}
