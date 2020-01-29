
public class RotateMatrix {

	public static void print_matrix(int[][] mat, int N) {
		for (int i= 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				System.out.format("%2d ", mat[i][j]);
			}
			System.out.println();
		}
		System.out.println();
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
	public static int[][] init_matrix(int N) {
		int[][] mat = new int[N][N];
		int count = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				mat[i][j] = count++;
			}
		}
		return mat;
	}
	public static void main(String[] args) {
		
		int[][] mat;
		int N = 8;
		mat = init_matrix(N);
		print_matrix(mat, N);
		rotate_ccw_90(mat, N);
		print_matrix(mat, N);
		
	}

}
