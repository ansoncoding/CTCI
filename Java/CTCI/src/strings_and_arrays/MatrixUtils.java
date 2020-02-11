package strings_and_arrays;
import java.util.Random; 

public class MatrixUtils {
	
	public static int[][] init_matrix(int N, int M, int[] vals) {
		int[][] mat = new int[N][M];
		int count = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				mat[i][j] = vals[count++];
			}
		}
		return mat;
	}
	
	public static int[][] init_zero_matrix(int N, int M) {
		int[][] mat = new int[N][M];

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				mat[i][j] = 0;
			}
		}
		return mat;
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
	
	public static boolean compare(int[][] mat1, int[][] mat2, int N, int M) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (mat1[i][j] != mat2[i][j]) {
					return false;
				}
			}
		}
		return true;
	}
	public static int[][] init_matrix(int N) {
		return init_matrix(N, N);
	}
	
	public static int[][] init_rand_matrix(int N, int M) {
		int[][] mat = new int[N][M];
		Random rand = new Random(); 
		int randint;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				randint = rand.nextInt(1000);
				mat[i][j] = randint%(N*M/2);
			}
		}
		return mat;
	}
	
	public static void swap(int[][] mat, int i1, int j1, int i2, int j2) {
		int temp = mat[i1][j1];
		mat[i1][j1] = mat[i2][j2];
		mat[i2][j2] = temp;
	}
	
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
}
