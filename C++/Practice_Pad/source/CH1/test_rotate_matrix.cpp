#include "pch.h"
#include "MatrixClass.h"

TEST(RotateMatrixTest, 2x2_CW90) {
	
	Matrix_2D m = Matrix_2D(2);
	m.rotate_cw_90();
	
	int s[] = {2, 0, 3, 1 };
	Matrix_2D soln = Matrix_2D(2, 2, s);
	EXPECT_TRUE(m.compare(soln));
}

TEST(RotateMatrixTest, 3x3_CW90) {

	Matrix_2D m = Matrix_2D(3);
	m.rotate_cw_90();

	int s[] = {
		6, 3, 0,
		7, 4, 1, 
	    8, 5, 2};
	Matrix_2D soln = Matrix_2D(3, 3, s);
	EXPECT_TRUE(m.compare(soln));
}

TEST(RotateMatrixTest, 4x4_CW90) {

	Matrix_2D m = Matrix_2D(4);
	m.rotate_cw_90();

	int s[] = {
		12, 8, 4, 0,
		13, 9, 5, 1,
		14, 10, 6, 2,
		15, 11, 7, 3};
	Matrix_2D soln = Matrix_2D(4, 4, s);
	EXPECT_TRUE(m.compare(soln));
}

TEST(RotateMatrixTest, 5x5_CW90) {
	
	Matrix_2D m = Matrix_2D(5);
	m.rotate_cw_90();

	int s[] = {
		20, 15, 10, 5, 0,
		21, 16, 11, 6, 1,
		22, 17, 12, 7, 2,
		23, 18, 13, 8, 3,
		24, 19, 14, 9, 4,
	};
	Matrix_2D soln = Matrix_2D(5, 5, s);
	EXPECT_TRUE(m.compare(soln));
}

TEST(RotateMatrixTest, 6x6_CW90) {

	Matrix_2D m = Matrix_2D(6);
	m.rotate_cw_90();

	int s[] = {
		30, 24, 18, 12, 6, 0,
		31, 25, 19, 13, 7, 1,
		32, 26, 20, 14, 8, 2,
		33, 27, 21, 15, 9, 3,
		34, 28, 22, 16, 10, 4,
		35, 29, 23, 17, 11, 5,
	};
	Matrix_2D soln = Matrix_2D(6, 6, s);
	EXPECT_TRUE(m.compare(soln));
}


