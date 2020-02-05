#ifndef MATRIX_UTILS_H
#define MATRIX_UTILS_H


int ** init_matrix(int N);
int ** init_matrix(int N, int M);
int ** init_matrix_rand(int N, int M);
void print_matrix(int ** mat, int N);
void print_matrix(int ** mat, int N, int M);
void swap(int ** mat, int i1, int j1, int i2, int j2);


#endif