
public class RotateMatrix {

	
	public static void print_matrix(int[][] mat, int N, int M) {
		for (int i= 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				System.out.format("%2d ", mat[i][j]);
			}
			System.out.println();
		}
		System.out.println();
	}
	
	public static void print_matrix(int[][] mat, int N) {
		print_matrix(mat, N, N);
	}
	
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
	
	public static int[][] init_matrix(int N, int M) {
		int[][] mat = new int[N][M];
		int count = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				mat[i][j] = count++;
			}
		}
		return mat;
	}
	
	public static int[][] init_matrix(int N) {
		return init_matrix(N, N);
	}
	
	public static void swap(int[][] mat, int i1, int j1, int i2, int j2) {
		int temp = mat[i1][j1];
		mat[i1][j1] = mat[i2][j2];
		mat[i2][j2] = temp;
	}
	
	public static void flip_180(int[][] mat, int N, int M) {
	    for (int i=0 ; i< N/2; i++) {
	        for (int j=0; j < M; j++) {
	            swap(mat, i, j, N-i-1, j);
	        }
	    }
	}
	public static void rotate_180( int[][] mat, int N, int M) {
		for (int i= 0; i < N/2; i++) {
			for (int j = 0;j < M; j++) {
				swap(mat, i, j, N-i-1, M-j-1);
			}
		}
		if ((N % 2) == 1) {
			int row = N/2;
			for (int j = 0; j < M/2; j++) {
				swap(mat, row, j, row, M-j-1);
			}
		}
	}
	
	public static void main(String[] args) {
		
//		int[][] mat;
//		int N = 8;
//		mat = init_matrix(N);
//		print_matrix(mat, N);
//		rotate_ccw_90(mat, N);
//		print_matrix(mat, N);
		
//		int [][] mat;
//		int N = 4; 
//		int M = 5;
//		mat = init_matrix(N, M);
//		print_matrix(mat, N, M);
//		flip_180(mat, N, M);
//		print_matrix(mat, N, M);
		
		int[][] mat;
		int N = 5;
		int M = 3;
		mat = init_matrix(N, M);
		print_matrix(mat, N, M);
		rotate_180(mat, N, M);
		print_matrix(mat, N, M);
		
	}

}
