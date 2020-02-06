#include "pch.h"
#include "rotate_matrix.h"
#include "matrix_utils.h"

TEST(RotateMatrixTest, 2x2_CW90) {
	int N = 2;
	int** mat = init_matrix(N);
	rotate_cw_90(mat, N);
	
	int soln[2][2] = { {2, 0},{3, 1} };
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			EXPECT_EQ(mat[i][j], soln[i][j]);
		}
	}
}

TEST(RotateMatrixTest, 3x3_CW90) {
	int N = 3;
	int** mat = init_matrix(N);
	rotate_cw_90(mat, N);

	int soln[3][3] = {
		{6, 3, 0},
		{7, 4, 1}, 
	    {8, 5, 2} };
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			EXPECT_EQ(mat[i][j], soln[i][j]);
		}
	}
}

TEST(RotateMatrixTest, 4x4_CW90) {
	int N = 4;
	int** mat = init_matrix(N);
	rotate_cw_90(mat, N);

	int soln[4][4] = {
		{12, 8, 4, 0},
		{13, 9, 5, 1},
		{14, 10, 6, 2},
		{15, 11, 7, 3} };

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			EXPECT_EQ(mat[i][j], soln[i][j]);
		}
	}
}

TEST(RotateMatrixTest, 5x5_CW90) {
	int N = 5;
	int** mat = init_matrix(N);
	rotate_cw_90(mat, N);

	int soln[5][5] = {
		{20, 15, 10, 5, 0},
		{21, 16, 11, 6, 1},
		{22, 17, 12, 7, 2},
		{23, 18, 13, 8, 3},
		{24, 19, 14, 9, 4},
	};

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			EXPECT_EQ(mat[i][j], soln[i][j]);
		}
	}
}

TEST(RotateMatrixTest, 6x6_CW90) {
	int N = 6;
	int** mat = init_matrix(N);
	rotate_cw_90(mat, N);

	int soln[6][6] = {
		{30, 24, 18, 12, 6, 0},
		{31, 25, 19, 13, 7, 1},
		{32, 26, 20, 14, 8, 2},
		{33, 27, 21, 15, 9, 3},
		{34, 28, 22, 16, 10, 4},
		{35, 29, 23, 17, 11, 5},
	};

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			EXPECT_EQ(mat[i][j], soln[i][j]);
		}
	}
}


