#ifndef ROTATE_MATRIX_H// include guard
#define ROTATE_MATRIX_H

#pragma once

#include <string>
#include <iostream>
#include <iomanip>

using namespace std;
int ** init_matrix(int N);
int ** init_matrix(int N, int M);
void print_matrix(int ** mat, int N);
void print_matrix(int ** mat, int N, int M);
void rotate_cw_90(int** mat, int N);
void rotate_ccw_90(int** mat, int N);
void flip_180(int ** mat, int N, int M);
void rotate_180(int ** mat, int N, int M);

#endif