import matrix_utils

def clear_row(mat, N, M, row):
    for j in range(0, M):
        mat[row][j] = 0
    return


def clear_col(mat, N, M, col):
    for i in range(0, N):
        mat[i][col] = 0;
    return


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
    return


def zero_matrix_2(mat, N, M):
    clear_row_0 = False
    clear_col_0 = False

    for i in range(0, N):
        if mat[i][0] == 0:
            clear_col_0 = True
            break

    for j in range(0, M):
        if mat[0][j] == 0:
            clear_row_0 = True
            break

    for i in range(0, N):
        for j in range(0, M):
            if mat[i][j] == 0:
                mat[0][j] = 0
                mat[i][0] = 0

    for i in range(1, N):
        if mat[i][0] == 0:
            clear_row(mat, N, M, i)

    for j in range(1, M):
        if mat[0][j] == 0:
            clear_col(mat, N, M, j)

    if clear_row_0:
        clear_row(mat, N, M, 0)
        
    if clear_col_0:
        clear_col(mat, N, M, 0)
    return