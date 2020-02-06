#include "pch.h"
#include "MatrixClass.h"

TEST(ZeroMatrixTests, SquareCases) {

	int N = 2; 
	Matrix_2D m = Matrix_2D(N);
	m.zero_matrix();

	int s2[] = { 
		0, 0, 
		0, 3 };
	Matrix_2D soln = Matrix_2D(N, N, s2);
	EXPECT_TRUE(m.compare(soln));

	// ====================================
	N = 3;
	m = Matrix_2D(N);
	m.zero_matrix();

	int s3[] = { 
		0, 0, 0,
		0, 4, 5,
		0, 7, 8};
	soln = Matrix_2D(N, N, s3);
	EXPECT_TRUE(m.compare(soln));
	
	// =====================================
	N = 4;
	int d4[] = {
		0, 1, 0, 2,
		2, 4, 5, 2,
		4, 7, 8, 2,
		1, 2, 3, 4};

	m = Matrix_2D(N, N, d4);
	m.zero_matrix();

	int s4[] = {
		0, 0, 0, 0,
		0, 4, 0, 2,
		0, 7, 0, 2,
		0, 2, 0, 4};
	soln = Matrix_2D(N, N, s4);
	EXPECT_TRUE(m.compare(soln));

	// =====================================
	N = 5;
	int d5[] = {
		7, 5, 1, 0, 2,
		7, 2, 4, 5, 0,
		6, 4, 7, 8, 2,
		8, 7, 8, 9, 10,
		1, 2, 4, 7, 9};

	m = Matrix_2D(N, N, d5);
	m.zero_matrix();

	int s5[] = {
		0, 0, 0, 0, 0,
		0, 0, 0, 0, 0,
		6, 4, 7, 0, 0,
		8, 7, 8, 0, 0,
		1, 2, 4, 0, 0 };
	soln = Matrix_2D(N, N, s5);
	EXPECT_TRUE(m.compare(soln));
}

TEST(ZeroMatrixTests, RectangleCases) {
	
	int N = 2;
	int M = 1;
	int d[] = { 7,8 };
	Matrix_2D m = Matrix_2D(N, M, d);
	m.zero_matrix();
	EXPECT_TRUE(m.compare(m));

	// =====================================

	N = 2;
	M = 1;
	int d1[] = { 0,8 };
	m = Matrix_2D(N, M, d1);
	m.zero_matrix();
	int s1[] = { 0,0 };
	Matrix_2D soln = Matrix_2D(N, M, s1);
	EXPECT_TRUE(m.compare(soln));

	// =====================================

	N = 2;
	M = 3;
	int d2[] = { 
		0, 8, 0,
		1, 1, 1};
	m = Matrix_2D(N, M, d2);
	m.zero_matrix();
	int s2[] = { 
		0, 0, 0,
		0, 1, 0};
	soln = Matrix_2D(N, M, s2);
	EXPECT_TRUE(m.compare(soln));

	// =====================================

	N = 5;
	M = 3;
	int d3[] = {
		0, 8, 0,
		1, 1, 1,
		2, 4, 5,
		7, 8, 0,
		7, 1, 2};
	m = Matrix_2D(N, M, d3);
	m.zero_matrix();
	int s3[] = {
		0, 0, 0,
		0, 1, 0,
		0, 4, 0,
		0, 0, 0,
		0, 1, 0 };

	soln = Matrix_2D(N, M, s3);
	EXPECT_TRUE(m.compare(soln));
}