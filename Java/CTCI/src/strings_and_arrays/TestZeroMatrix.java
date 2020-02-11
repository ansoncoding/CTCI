package strings_and_arrays;
import org.junit.Test;
import static org.junit.Assert.*;

public class TestZeroMatrix {
	
	@Test
	public void testZeroMatrix() {
		int[][] mat, soln;
		int N = 3; 
		int[] s = {
				0, 0, 0,
				0, 4, 5,
				0, 7, 8,};
		
		mat = MatrixUtils.init_matrix(N);
		soln = MatrixUtils.init_matrix(N, N, s);	
		ZeroMatrix.zero_matrix(mat, N, N);
		assertTrue(MatrixUtils.compare(mat,  soln, N, N));
	}
	
	@Test
	public void testZeroMatrixAllZero() {
		int[][] mat, soln;
		int N = 4; 
		int M = 4;
		int[] d = {
				0, 1, 3, 7,
				2, 5, 8, 0,
				1, 0, 4, 2,
				9, 3, 0, 5,};
		mat = MatrixUtils.init_matrix(N, M, d);
		soln = MatrixUtils.init_zero_matrix(N, M);
		ZeroMatrix.zero_matrix(mat, N, M);
		assertTrue(MatrixUtils.compare(mat,  soln, N, M));
	}
	
	@Test
	public void testZeroMatrixRect() {
		int[][] mat, soln;
		int N = 4; 
		int M = 7;
		int[] d = {
				1, 1, 3, 7, 1, 2, 3,
				2, 5, 8, 0, 1, 2, 3,
				1, 3, 4, 2, 1, 2, 3,
				9, 7, 2, 5, 1, 2, 3,};
		int[] s = {                   
				1, 1, 3, 0, 1, 2, 3,  
				0, 0, 0, 0, 0, 0, 0,  
				1, 3, 4, 0, 1, 2, 3,  
				9, 7, 2, 0, 1, 2, 3,};
		mat = MatrixUtils.init_matrix(N, M, d);
		soln = MatrixUtils.init_matrix(N, M, s);
		ZeroMatrix.zero_matrix(mat, N, M);
		assertTrue(MatrixUtils.compare(mat,  soln, N, M));
	}
	
	@Test
	public void testZeroMatrixNoChange() {
		int[][] mat, soln;
		int N = 3; 
		int M = 5;
		int[] d = {
				2, 5, 8, 1, 1,
				1, 1, 3, 7, 1,
				9, 7, 2, 5, 1,};

		mat = MatrixUtils.init_matrix(N, M, d);
		soln = MatrixUtils.init_matrix(N, M, d);
		ZeroMatrix.zero_matrix(mat, N, M);
		assertTrue(MatrixUtils.compare(mat,  soln, N, M));
	}
	
	
	/////////// V2 ///////////
	@Test
	public void testZeroMatrix2() {
		int[][] mat, soln;
		int N = 3; 
		int[] s = {
				0, 0, 0,
				0, 4, 5,
				0, 7, 8,};
		
		mat = MatrixUtils.init_matrix(N);
		soln = MatrixUtils.init_matrix(N, N, s);	
		ZeroMatrix.zero_matrix_2(mat, N, N);
		assertTrue(MatrixUtils.compare(mat,  soln, N, N));
	}
	
	@Test
	public void testZeroMatrix2AllZero() {
		int[][] mat, soln;
		int N = 4; 
		int M = 4;
		int[] d = {
				0, 1, 3, 7,
				2, 5, 8, 0,
				1, 0, 4, 2,
				9, 3, 0, 5,};
		mat = MatrixUtils.init_matrix(N, M, d);
		soln = MatrixUtils.init_zero_matrix(N, M);
		ZeroMatrix.zero_matrix_2(mat, N, M);
		assertTrue(MatrixUtils.compare(mat,  soln, N, M));
	}
	
	@Test
	public void testZeroMatrix2Rect() {
		int[][] mat, soln;
		int N = 4; 
		int M = 7;
		int[] d = {
				1, 1, 3, 7, 1, 2, 3,
				2, 5, 8, 0, 1, 2, 3,
				1, 3, 4, 2, 1, 2, 3,
				9, 7, 2, 5, 1, 2, 3,};
		int[] s = {                   
				1, 1, 3, 0, 1, 2, 3,  
				0, 0, 0, 0, 0, 0, 0,  
				1, 3, 4, 0, 1, 2, 3,  
				9, 7, 2, 0, 1, 2, 3,};
		mat = MatrixUtils.init_matrix(N, M, d);
		soln = MatrixUtils.init_matrix(N, M, s);
		ZeroMatrix.zero_matrix_2(mat, N, M);
		assertTrue(MatrixUtils.compare(mat,  soln, N, M));
	}
	@Test
	public void testZeroMatrix2NoChange() {
		int[][] mat, soln;
		int N = 3; 
		int M = 5;
		int[] d = {
				2, 5, 8, 1, 1,
				1, 1, 3, 7, 1,
				9, 7, 2, 5, 1,};

		mat = MatrixUtils.init_matrix(N, M, d);
		soln = MatrixUtils.init_matrix(N, M, d);
		ZeroMatrix.zero_matrix_2(mat, N, M);
		assertTrue(MatrixUtils.compare(mat,  soln, N, M));
	}
}
