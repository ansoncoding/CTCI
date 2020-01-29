import matrix_utils

def clear_row(mat, N, M, row):
    for j in range(0, M):
        mat[row][j] = 0

def clear_col(mat, N, M, col):
    for i in range(0, N):
        mat[i][col] = 0;

def zero_matrix(mat, N, M):
    row_count = set()
    col_count = set()

    for i in range(0, N):
        for j in range(0, M):
            if mat[i][j] == 0:
                row_count.add(i)
                col_count.add(j)
    for row in row_count:
        clear_row(mat, N, M, row)
    for col in col_count:
        clear_col(mat, N, M, col)
