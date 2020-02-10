import unittest
from ZeroMatrix import zero_matrix, zero_matrix_2
from matrix_utils import init_matrix_with_list, print_matrix, compare, init_zero_matrix
import matrix_utils


class TestZeroMatrix(unittest.TestCase):

    def test_zero_matrix(self):
        N = 4
        M = 5
        mat = matrix_utils.init_matrix(N, M)
        s = [ 0,  0,  0,  0,  0,
              0,  6,  7,  8,  9, 
              0, 11, 12, 13, 14,
              0, 16, 17, 18, 19]
        soln = init_matrix_with_list(N, M, s)
        zero_matrix(mat, N, M)
        self.assertTrue(compare(mat, soln, N, M))


    def test_zero_matrix_no_change(self):
        d = [1, 3, 6, 18,
             9, 11, 1, 7,
             1, 1 , 9, 1,
             22, -40, -1, 9]
        N = 3
        M = 4
        mat = init_matrix_with_list(N, M, d)
        soln = init_matrix_with_list(N, M, d)
        zero_matrix(mat, N, M)
        self.assertTrue(compare(mat, soln, N, M))

    def test_zero_matrix_all_zero(self):
        N = 4
        M = 5
        d = [ 0,  0,  0,  0,  0,
              0,  6,  7,  8,  9, 
              0, 11, 12, 13, 14,
              0, 16, 17, 18, 19]
        soln = init_zero_matrix(N, M)
        mat = init_matrix_with_list(N, M, d)

        zero_matrix(mat, N, M)
        self.assertTrue(compare(mat, soln, N, M))

    def test_zero_matrix_all_zero2(self):
        N = 4
        M = 5
        d = [ 8,  2,  5,  0,  7,
              0,  6,  7,  8,  9, 
              1, 11,  0, 13,  0,
              3,  0, 17, 18, 19]
        soln = init_zero_matrix(N, M)
        mat = init_matrix_with_list(N, M, d)

        zero_matrix(mat, N, M)
        self.assertTrue(compare(mat, soln, N, M))

    def test_zero_matrix_rand(self):
        N = 3
        M = 5
        d = [ 8,  2,  5,  0,  7,
              1,  6,  7,  8,  9, 
              3,  0, 17, 18, 19]

        s = [ 0,  0,  0,  0,  0,
              1,  0,  7,  0,  9, 
              0,  0,  0,  0,  0]

        soln = init_matrix_with_list(N, M, s)
        mat = init_matrix_with_list(N, M, d)

        zero_matrix(mat, N, M)
        self.assertTrue(compare(mat, soln, N, M))


if __name__ == '__main__':
    unittest.main()
