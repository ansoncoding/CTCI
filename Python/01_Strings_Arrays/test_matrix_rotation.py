import unittest
from RotateMatrix import rotate_cw_90, rotate_ccw_90, flip_180, rotate_180, rotate_180_rect
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


class TestMatrixRotate180(unittest.TestCase):

    def test_rotate_180_3x3(self):
        N = 3
        mat = matrix_utils.init_matrix(N, N)
        s = [8, 7, 6,
             5, 4, 3, 
             2, 1, 0]
        soln = init_matrix_with_list(N, N, s)
        rotate_180(mat, N)
        self.assertTrue(compare(mat, soln, N, N))

    def test_rotate_180_4x4(self):
        N = 4
        mat = matrix_utils.init_matrix(N, N)
        s = [15, 14, 13, 12,
             11, 10,  9,  8, 
              7,  6,  5,  4,
              3,  2,  1,  0]
        soln = init_matrix_with_list(N, N, s)
        rotate_180(mat, N)
        self.assertTrue(compare(mat, soln, N, N))

    def test_rotate_180_5x5(self):
        N = 5
        mat = matrix_utils.init_matrix(N, N)
        s = [24, 23, 22, 21, 20,
             19, 18, 17, 16, 15, 
             14, 13, 12, 11, 10,
              9,  8,  7,  6,  5,
              4,  3,  2,  1,  0]
        soln = init_matrix_with_list(N, N, s)
        rotate_180(mat, N)
        self.assertTrue(compare(mat, soln, N, N))



class TestMatrixRotate180Rect(unittest.TestCase):
    def test_rotate_180rect_1x2(self):
        N = 1
        M = 2
        mat = matrix_utils.init_matrix(N, M)
        s = [1, 0]

        soln = init_matrix_with_list(N, M, s)
        rotate_180_rect(mat, N, M)
        self.assertTrue(compare(mat, soln, N, M))

    def test_rotate_180rect_1x3(self):
        N = 1
        M = 3
        mat = matrix_utils.init_matrix(N, M)
        s = [2, 1, 0]

        soln = init_matrix_with_list(N, M, s)
        rotate_180_rect(mat, N, M)
        self.assertTrue(compare(mat, soln, N, M))

    def test_rotate_180rect_2x3(self):
        N = 2
        M = 3
        mat = matrix_utils.init_matrix(N, M)
        s = [5, 4, 3, 
             2, 1, 0]

        soln = init_matrix_with_list(N, M, s)
        rotate_180_rect(mat, N, M)
        self.assertTrue(compare(mat, soln, N, M))

    def test_rotate_180rect_4x3(self):
        N = 4
        M = 3
        mat = matrix_utils.init_matrix(N, M)
        s = [11, 10,  9,
              8,  7,  6, 
              5,  4,  3,
              2,  1,  0]
        soln = init_matrix_with_list(N, M, s)
        rotate_180_rect(mat, N, M)
        self.assertTrue(compare(mat, soln, N, M))

    def test_rotate_180rect_3x5(self):
        N = 3
        M = 5
        mat = matrix_utils.init_matrix(N, M)
        s = [ 14, 13, 12, 11, 10,
               9,  8,  7,  6,  5,
               4,  3,  2,  1,  0]
        soln = init_matrix_with_list(N, M, s)
        rotate_180_rect(mat, N, M)
        self.assertTrue(compare(mat, soln, N, M))



class TestMatrixFlip180(unittest.TestCase):
    def test_flip_180_1x2(self):
        N = 1
        M = 2
        mat = matrix_utils.init_matrix(N, M)
        s = [0, 1]

        soln = init_matrix_with_list(N, M, s)
        flip_180(mat, N, M)
        self.assertTrue(compare(mat, soln, N, M))

    def test_flip_180_1x3(self):
        N = 1
        M = 3
        mat = matrix_utils.init_matrix(N, M)
        s = [0, 1, 2]

        soln = init_matrix_with_list(N, M, s)
        flip_180(mat, N, M)
        self.assertTrue(compare(mat, soln, N, M))

    def test_flip_180_2x2(self):
        N = 2
        M = 2
        mat = matrix_utils.init_matrix(N, M)
        s = [2, 3, 
             0, 1]

        soln = init_matrix_with_list(N, M, s)
        flip_180(mat, N, M)
        self.assertTrue(compare(mat, soln, N, M))

    def test_flip_180_2x3(self):
        N = 2
        M = 3
        mat = matrix_utils.init_matrix(N, M)
        s = [3, 4, 5, 
             0, 1, 2]

        soln = init_matrix_with_list(N, M, s)
        flip_180(mat, N, M)
        self.assertTrue(compare(mat, soln, N, M))

    def test_flip_180_3x3(self):
        N = 3
        M = 3
        mat = matrix_utils.init_matrix(N, M)
        s = [6, 7, 8,
             3, 4, 5,
             0, 1, 2]

        soln = init_matrix_with_list(N, M, s)
        flip_180(mat, N, M)
        self.assertTrue(compare(mat, soln, N, M))

    def test_flip_180_4x3(self):
        N = 4
        M = 3
        mat = matrix_utils.init_matrix(N, M)
        s = [ 9, 10, 11,
              6,  7,  8, 
              3,  4,  5,
              0,  1,  2]
        soln = init_matrix_with_list(N, M, s)
        flip_180(mat, N, M)
        self.assertTrue(compare(mat, soln, N, M))

    def test_flip_180_3x5(self):
        N = 3
        M = 5
        mat = matrix_utils.init_matrix(N, M)
        s = [ 10, 11, 12, 13, 14,
               5,  6,  7,  8,  9,
               0,  1,  2,  3,  4]
        soln = init_matrix_with_list(N, M, s)
        flip_180(mat, N, M)
        self.assertTrue(compare(mat, soln, N, M))

if __name__ == '__main__':
    unittest.main()

