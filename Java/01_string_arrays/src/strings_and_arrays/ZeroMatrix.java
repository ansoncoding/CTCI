package strings_and_arrays;
import java.util.*; 

public class ZeroMatrix {

	public static void clear_row(int[][] mat, int N, int M, int row ) {
		for (int j = 0; j < M; j++) {
			mat[row][j] = 0;
		}
	}
	public static void clear_col(int[][] mat, int N, int M, int col) {
		for (int i = 0; i < N; i++) {
			mat[i][col] = 0;
		}
	}
	public static void zero_matrix(int[][] mat, int N, int M ) {
		Set<Integer> rows = new HashSet<Integer>();
		Set<Integer> cols = new HashSet<Integer>();
		for (int i =0; i < N; i++) {
			for (int j =0; j < M; j++) {
				if (mat[i][j] == 0) {
					rows.add(i);
					cols.add(j);
				}
			}
		}
		for (Integer row : rows) {
			clear_row(mat, N, M , row);
		}
		
		for (Integer col : cols) {
			clear_col(mat, N, M, col);
		}
		
	}
	
	public static void main(String[] args) {

		int N = 5; 
		int M = 7;
		int [][] mat = MatrixUtils.init_rand_matrix(N, M);
		MatrixUtils.print_matrix(mat, N, M);
		zero_matrix(mat, N, M);
		MatrixUtils.print_matrix(mat, N, M);
		
	}
}
