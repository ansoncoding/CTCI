package strings_and_arrays;
import org.junit.Test;
import static org.junit.Assert.*;

public class TestMatrixRotation {
	@Test
	public void testMatrixRotationCW90() {
		int[][] mat, soln;
		
		for (int N = 1; N < 8; N++) {
		
			mat = MatrixUtils.init_matrix(N);
			soln = MatrixUtils.init_matrix(N);
			int count = 0;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					soln[j][N-i-1] =count++; 
				}
			}
			RotateMatrix.rotate_cw_90(mat, N);
			assertTrue(MatrixUtils.compare(soln,  mat, N, N));
		}
	}
	
	@Test
	public void testMatrixRotationCCW90() {
		int[][] mat, soln;
		
		for (int N = 1; N < 8; N++) {

			mat = MatrixUtils.init_matrix(N);
			soln = MatrixUtils.init_matrix(N);
			int count = 0;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					soln[N-j-1][i] = count++; 
				}
			}
			RotateMatrix.rotate_ccw_90(mat, N);
			assertTrue(MatrixUtils.compare(soln,  mat, N, N));
		}
	}
	
	@Test
	public void testMatrixFlip180Square() {
		int[][] mat, soln;
		
		for (int N = 1; N < 8; N++) {

			mat = MatrixUtils.init_matrix(N);
			soln = MatrixUtils.init_matrix(N);
			int count = 0;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					soln[N-i-1][j] = count++; 
				}
			}
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
			soln = MatrixUtils.init_matrix(N, M);
			int count = 0;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					soln[N-i-1][j] = count++; 
				}
			}
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
			soln = MatrixUtils.init_matrix(N, M);
			int count = 0;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					soln[N-i-1][j] = count++; 
				}
			}
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
			soln = MatrixUtils.init_matrix(N, M);
			int count = 0;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					soln[N-i-1][M-j-1] = count++; 
				}
			}
			RotateMatrix.rotate_180(mat, N, M);
			assertTrue(MatrixUtils.compare(soln,  mat, N, M));
		}
	}
}
