package strings_and_arrays;
import org.junit.Test;
import static org.junit.Assert.*;

public class TestMatrixRotation {
	
	public int[][] soln_for_CW_90(int N) {
		int[][] soln = new int[N][N];
		int count = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				soln[j][N-i-1] =count++; 
			}
		}
		return soln;
	}
	
	public int[][] soln_for_CCW_90(int N) {
		int[][] soln = new int[N][N];
		int count = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				soln[N-j-1][i] = count++; 
			}
		}
		return soln;
	}
	
	public int[][] soln_for_flip_180(int N, int M){
		int[][] soln = new int[N][M];
		int count = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				soln[N-i-1][j] = count++; 
			}
		}
		return soln;
	}
	public int[][] soln_for_rotate_180(int N, int M){
		int count = 0;
		int[][] soln = new int[N][M];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				soln[N-i-1][M-j-1] = count++; 
			}
		}
		return soln;
	}
	
	@Test
	public void testMatrixRotationCW90() {
		int[][] mat, soln;
		
		for (int N = 1; N < 8; N++) {
		
			mat = MatrixUtils.init_matrix(N);
			soln = soln_for_CW_90(N);
			RotateMatrix.rotate_cw_90(mat, N);
			assertTrue(MatrixUtils.compare(soln,  mat, N, N));
		}
	}
	
	@Test
	public void testMatrixRotationCCW90() {
		int[][] mat, soln;
		
		for (int N = 1; N < 8; N++) {

			mat = MatrixUtils.init_matrix(N);
			soln = soln_for_CCW_90(N);
			RotateMatrix.rotate_ccw_90(mat, N);
			assertTrue(MatrixUtils.compare(soln,  mat, N, N));
		}
	}
	
	@Test
	public void testMatrixFlip180Square() {
		int[][] mat, soln;
		
		for (int N = 1; N < 8; N++) {

			mat = MatrixUtils.init_matrix(N);
			soln = soln_for_flip_180(N, N);
			RotateMatrix.flip_180(mat, N, N);
			assertTrue(MatrixUtils.compare(soln,  mat, N, N));
		}
	}

	@Test
	public void testMatrixFlip180Rect() {
		int[][] mat, soln;
		int M;
		for (int N = 2; N < 8; N++) {
			M = N/2;
			mat = MatrixUtils.init_matrix(N, M);
			soln = soln_for_flip_180(N, M);
			RotateMatrix.flip_180(mat, N, M);
			assertTrue(MatrixUtils.compare(soln,  mat, N, M));
		}
	}

	@Test
	public void testMatrixFlip180RectOdd() {
		int[][] mat, soln;
		int M;
		for (int N = 2; N < 8; N++) {
			M = N-1;
			mat = MatrixUtils.init_matrix(N, M);
			soln = soln_for_flip_180(N, M);
			RotateMatrix.flip_180(mat, N, M);
			assertTrue(MatrixUtils.compare(soln,  mat, N, M));
		}
	}

	@Test
	public void testMatrixRotate180Rect() {
		int[][] mat, soln;
		int M;
		for (int N = 2; N < 8; N++) {
			M = N/2;
			mat = MatrixUtils.init_matrix(N, M);
			soln = soln_for_rotate_180(N, M);
			RotateMatrix.rotate_180(mat, N, M);
			assertTrue(MatrixUtils.compare(soln,  mat, N, M));
		}
	}
	
	@Test
	public void testMatrixRotate180Square() {
		int[][] mat, soln;

		for (int N = 2; N < 8; N++) {

			mat = MatrixUtils.init_matrix(N, N);
			soln = soln_for_rotate_180(N, N);
			RotateMatrix.rotate_180(mat, N, N);
			assertTrue(MatrixUtils.compare(soln,  mat, N, N));
		}
	}
}
