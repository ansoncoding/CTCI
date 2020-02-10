import unittest
from RotateMatrix import rotate_cw_90, rotate_ccw_90, flip_180, rotate_180
from matrix_utils import init_matrix_with_list, print_matrix, compare
import matrix_utils

class TestMatrixRotateCW(unittest.TestCase):

    def test_rotate_cw_90_3x3(self):
        N = 3
        mat = matrix_utils.init_matrix(N, N)
        s = [6, 3, 0,
             7, 4, 1, 
             8, 5, 2]
        soln = init_matrix_with_list(N, N, s)
        rotate_cw_90(mat, N)
        self.assertTrue(compare(mat, soln, N, N))

    def test_rotate_cw_90_4x4(self):
        N = 4
        mat = matrix_utils.init_matrix(N, N)
        s = [12, 8,  4, 0,
             13, 9,  5, 1, 
             14, 10, 6, 2,
             15, 11, 7, 3]
        soln = init_matrix_with_list(N, N, s)
        rotate_cw_90(mat, N)
        self.assertTrue(compare(mat, soln, N, N))

    def test_rotate_cw_90_5x5(self):
        N = 5
        mat = matrix_utils.init_matrix(N, N)
        s = [20, 15, 10, 5, 0,
             21, 16, 11, 6, 1, 
             22, 17, 12, 7, 2,
             23, 18, 13, 8, 3,
             24, 19, 14, 9, 4]
        soln = init_matrix_with_list(N, N, s)
        rotate_cw_90(mat, N)
        self.assertTrue(compare(mat, soln, N, N))

    def test_rotate_cw_90_6x6(self):
        N = 6
        mat = matrix_utils.init_matrix(N, N)
        s = [30, 24, 18, 12, 6,  0,
             31, 25, 19, 13, 7,  1, 
             32, 26, 20, 14, 8,  2,
             33, 27, 21, 15, 9,  3,
             34, 28, 22, 16, 10, 4,
             35, 29, 23, 17, 11, 5]
        soln = init_matrix_with_list(N, N, s)
        rotate_cw_90(mat, N)
        self.assertTrue(compare(mat, soln, N, N))


class TestMatrixRotateCCW(unittest.TestCase):

    def test_rotate_ccw_90_3x3(self):
        N = 3
        mat = matrix_utils.init_matrix(N, N)
        s = [2, 5, 8,
             1, 4, 7, 
             0, 3, 6]
        soln = init_matrix_with_list(N, N, s)
        rotate_ccw_90(mat, N)
        self.assertTrue(compare(mat, soln, N, N))

    def test_rotate_ccw_90_4x4(self):
        N = 4
        mat = matrix_utils.init_matrix(N, N)
        s = [3, 7, 11, 15,
             2, 6, 10, 14, 
             1, 5,  9, 13,
             0, 4,  8, 12]
        soln = init_matrix_with_list(N, N, s)
        rotate_ccw_90(mat, N)
        self.assertTrue(compare(mat, soln, N, N))

    def test_rotate_ccw_90_5x5(self):
        N = 5
        mat = matrix_utils.init_matrix(N, N)
        s = [4, 9, 14, 19, 24,
             3, 8, 13, 18, 23, 
             2, 7, 12, 17, 22,
             1, 6, 11, 16, 21,
             0, 5, 10, 15, 20]
        soln = init_matrix_with_list(N, N, s)
        rotate_ccw_90(mat, N)
        self.assertTrue(compare(mat, soln, N, N))

    def test_rotate_ccw_90_6x6(self):
        N = 6
        mat = matrix_utils.init_matrix(N, N)
        s = [5, 11, 17, 23, 29, 35,
             4, 10, 16, 22, 28, 34,
             3,  9, 15, 21, 27, 33,
             2,  8, 14, 20, 26, 32,
             1,  7, 13, 19, 25, 31,
             0,  6, 12, 18, 24, 30]
        soln = init_matrix_with_list(N, N, s)
        rotate_ccw_90(mat, N)
        self.assertTrue(compare(mat, soln, N, N))

if __name__ == '__main__':
    unittest.main()

#================================================================================
# N = 3
# mat_3 = matrix_utils.init_matrix(N, N)
# matrix_utils.print_matrix(mat_3, N, N)
# print("Rotate\n")
# rotate_ccw_90(mat_3, N)
# matrix_utils.print_matrix(mat_3, N, N)

# N = 4
# mat_4 = matrix_utils.init_matrix(N, N)
# matrix_utils.print_matrix(mat_4, N, N)
# print("Rotate\n")
# rotate_ccw_90(mat_4, N)
# matrix_utils.print_matrix(mat_4, N, N)

# N = 5
# mat_5 = matrix_utils.init_matrix(N, N)
# matrix_utils.print_matrix(mat_5, N, N)
# print("Rotate\n")
# rotate_ccw_90(mat_5, N)
# matrix_utils.print_matrix(mat_5, N, N)

# N = 6
# mat_6 = matrix_utils.init_matrix(N, N)
# matrix_utils.print_matrix(mat_6, N, N)
# print("Rotate\n")
# rotate_ccw_90(mat_6, N)
# matrix_utils.print_matrix(mat_6, N, N)


# N = 3
# mat_3 = matrix_utils.init_matrix(N, N)
# matrix_utils.print_matrix(mat_3, N, N)
# flip_180(mat_3, N, N)
# matrix_utils.print_matrix(mat_3, N, N)

# N = 3
# M = 4
# mat_3x4 = matrix_utils.init_matrix(N, M)
# matrix_utils.print_matrix(mat_3x4, N, M)
# flip_180(mat_3x4, N, M)
# matrix_utils.print_matrix(mat_3x4, N, M)

# N = 4
# M = 4
# mat_4x4 = matrix_utils.init_matrix(N, M)
# matrix_utils.print_matrix(mat_4x4, N, M)
# flip_180(mat_4x4, N, M)
# matrix_utils.print_matrix(mat_4x4, N, M)


# N = 3
# mat_3 = matrix_utils.init_matrix(N, N)
# matrix_utils.print_matrix(mat_3, N, N)
# rotate_180(mat_3, N, N)
# matrix_utils.print_matrix(mat_3, N, N)

# N = 4
# M = 4
# mat_4x4 = matrix_utils.init_matrix(N, M)
# matrix_utils.print_matrix(mat_4x4, N, M)
# rotate_180(mat_4x4, N, N)
# matrix_utils.print_matrix(mat_4x4, N, M)


# N = 4
# M = 5
# mat = matrix_utils.init_matrix(N, M)
# matrix_utils.print_matrix(mat, N, M)
# rotate_180(mat, N, M)
# matrix_utils.print_matrix(mat, N, M)

# N = 5
# M = 6
# mat = matrix_utils.init_matrix(N, M)
# matrix_utils.print_matrix(mat, N, M)
# ZeroMatrix.zero_matrix_2(mat, N, M)
# matrix_utils.print_matrix(mat, N, M)
