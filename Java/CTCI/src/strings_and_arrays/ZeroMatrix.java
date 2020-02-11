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
	
	// improved solution using O(1) space
	public static void zero_matrix_2(int[][] mat, int N, int M ) {
		boolean col0_clear = false;
		boolean row0_clear = false;
		for (int i = 0; i < N; i++) {
			if (mat[i][0] == 0) {
				col0_clear = true;
				break;
			}
		}
		for (int j = 0; j < M; j++) {
			if (mat[0][j] == 0) {
				row0_clear = true;
				break;
			}
		}
		for (int i =0; i < N; i++) {
			for (int j =0; j < M; j++) {
				if (mat[i][j] == 0) {
					mat[0][j]=0;
					mat[i][0]=0;
				}
			}
		}
		for (int j = 1; j < M; j++) {
			if (mat[0][j]==0) {
				clear_col(mat, N, M, j);
			}
		}
		for (int i = 1; i < N; i++) {
			if (mat[i][0]==0) {
				clear_row(mat, N, M, i);
			}
		}
		if (col0_clear) {
			clear_col(mat, N, M, 0);
		}
		if (row0_clear) {
			clear_row(mat, N, M, 0);
		}
	}
}
