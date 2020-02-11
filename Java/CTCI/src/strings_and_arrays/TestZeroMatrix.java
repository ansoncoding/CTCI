package strings_and_arrays;
import org.junit.Test;
import static org.junit.Assert.*;

public class TestZeroMatrix {
	
	@Test
	public void testMatrixRotationCW90() {
		int[][] mat, soln;
		mat = MatrixUtils.init_matrix(3);
		int[] s = {
				0, 0, 0,
				0, 4, 5,
				0, 7, 8 };
		soln = MatrixUtils.init_matrix(3, 3, s);
		int N = 3; 
		int M = 3;
		
		ZeroMatrix.zero_matrix_2(mat, N, M);
		assertTrue(MatrixUtils.compare(mat,  soln, N, M));
	}
}
