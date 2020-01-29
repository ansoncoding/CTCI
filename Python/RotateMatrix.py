import matrix_utils

def rotate_cw_90(mat, N):

    for li in range(0,  N // 2):
        start = li
        end = N - li - 1;
        for i in range (0, end-start):
            temp = mat[start+i][end];
            mat[start+i][end] = mat[start][start+i];
            mat[start][start+i] = mat[end-i][start];
            mat[end-i][start] = mat[end][end-i];
            mat[end][end-i] = temp;
    return mat


def rotate_ccw_90(mat, N):

    for li in range(0,  N // 2):
        start = li
        end = N - li - 1;
        for i in range (0, end-start):
            temp = mat[start+i][end];
            mat[start+i][end] = mat[end][end-i];
            mat[end][end-i] = mat[end-i][start];
            mat[end-i][start] = mat[start][start+i];
            mat[start][start+i] = temp;
    return mat


# matrix is NxM N = numrows, M = numcols
def flip_180(mat, N, M):
    for i in range(0, N//2):
        for j in range (0, M):
            matrix_utils.swap(mat, i, j, N-i-1, j)
    return mat


def rotate_180(mat, N):
    for li in range(0,  N // 2):
        start = li
        end = N - li - 1;
        for i in range (0, end-start):
            matrix_utils.swap(mat, start+i, end, end-i, start)
            matrix_utils.swap(mat, start, start+i, end, end-i)
    return mat


def rotate_180(mat, N, M):
    for i in range (0, N//2):
        for j in range(0, M):
            matrix_utils.swap(mat, i, j, N-i-1, M-j-1)
    if (N % 2):
        row = N//2
        print("row " + str(row))
        for c in range(0, M//2):
            matrix_utils.swap(mat,row, c, row, M-c-1)