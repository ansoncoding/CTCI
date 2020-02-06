#include "pch.h"
#include "MatrixClass.h"

TEST(ZeroMatrixTests, RegularCases) {
	
	Matrix_2D m = Matrix_2D(2);
	m.zero_matrix();

	int s[] = { 0, 0, 0, 3 };
	Matrix_2D soln = Matrix_2D(2, 2, s);
	EXPECT_TRUE(m.compare(soln));
}