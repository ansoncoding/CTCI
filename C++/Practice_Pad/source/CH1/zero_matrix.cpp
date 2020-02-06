#include "pch.h"
#include "zero_matrix.h"
#include "matrix_utils.h"

#include <cstdbool>

void clear_row(int ** mat, int N, int M, int row) {
    for (int j = 0; j < M; j++) {
        mat[row][j] = 0;
    }
}

void clear_col(int ** mat, int N, int M, int col) {
    for (int i = 0; i < N; i++) {
        mat[i][col] = 0;
    }
}
// O(n^2) time O(N+M) space
void zero_matrix(int** mat, int N, int M)
{
    bool *count_rows = new bool[N];
    bool *count_cols = new bool[M];
    for (int i = 0; i < N; i++) {
        count_rows[i] = false;
    }
    for (int j = 0; j < M; j++) {
        count_cols[j] = false;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (mat[i][j] == 0) {
                count_rows[i] = true;
                count_cols[j] = true;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        if (count_rows[i]) {
            clear_row(mat, N, M, i);
        }
    }
    for (int j = 0; j < M; j++) {
        if (count_cols[j]) {
            clear_col(mat, N, M, j);
        }
    }
}

// O(n^2) time O(1) space
void zero_matrix_2(int** mat, int N, int M) {
    bool clear_row_0 = false;
    bool clear_col_0 = false;

    for (int i = 0; i < N; i++) {
        if (mat[i][0] == 0) {
            clear_col_0 = true;
            break;
        }
    }
    for (int j = 0; j < M; j++) {
        if (mat[0][j] == 0) {
            clear_row_0 = true;
            break;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (mat[i][j] == 0){
                mat[0][j] = 0;
                mat[i][0] = 0;
            }
        }
    }
    for (int i = 1; i < N; i++) {
        if (mat[i][0] == 0) {
            clear_row(mat, N, M, i);
        }
    }
    for (int j = 1; j < M; j++) {
        if (mat[0][j] == 0) {
            clear_col(mat, N, M, j);
        }
    }
    if (clear_col_0)
        clear_col(mat, N, M, 0);

    if (clear_row_0)
        clear_row(mat, N, M, 0);
}