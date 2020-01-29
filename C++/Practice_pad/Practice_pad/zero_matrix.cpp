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
// O(n^2) time
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