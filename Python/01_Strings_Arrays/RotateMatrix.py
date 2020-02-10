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


def rotate_180_rect(mat, N, M):
    for i in range (0, N//2):
        for j in range(0, M):
            matrix_utils.swap(mat, i, j, N-i-1, M-j-1)
    if (N % 2):
        row = N//2
        for c in range(0, M//2):
            matrix_utils.swap(mat,row, c, row, M-c-1)


#================================================================================
# N = 3
# mat_3 = matrix_utils.init_matrix(N, N)
# matrix_utils.print_matrix(mat_3, N, N)
# print("Rotate\n")
# rotate_ccw_90(mat_3, N)
# matrix_utils.print_matrix(mat_3, N, N)

# N = 4
# mat_4 = matrix_utils.init_matrix(N, N)
# matrix_utils.print_matrix(mat_4, N, N)
# print("Rotate\n")
# rotate_ccw_90(mat_4, N)
# matrix_utils.print_matrix(mat_4, N, N)

# N = 5
# mat_5 = matrix_utils.init_matrix(N, N)
# matrix_utils.print_matrix(mat_5, N, N)
# print("Rotate\n")
# rotate_ccw_90(mat_5, N)
# matrix_utils.print_matrix(mat_5, N, N)

# N = 6
# mat_6 = matrix_utils.init_matrix(N, N)
# matrix_utils.print_matrix(mat_6, N, N)
# print("Rotate\n")
# rotate_ccw_90(mat_6, N)
# matrix_utils.print_matrix(mat_6, N, N)


# N = 3
# mat_3 = matrix_utils.init_matrix(N, N)
# matrix_utils.print_matrix(mat_3, N, N)
# flip_180(mat_3, N, N)
# matrix_utils.print_matrix(mat_3, N, N)

# N = 3
# M = 4
# mat_3x4 = matrix_utils.init_matrix(N, M)
# matrix_utils.print_matrix(mat_3x4, N, M)
# flip_180(mat_3x4, N, M)
# matrix_utils.print_matrix(mat_3x4, N, M)

# N = 4
# M = 4
# mat_4x4 = matrix_utils.init_matrix(N, M)
# matrix_utils.print_matrix(mat_4x4, N, M)
# flip_180(mat_4x4, N, M)
# matrix_utils.print_matrix(mat_4x4, N, M)


# N = 3
# mat_3 = matrix_utils.init_matrix(N, N)
# matrix_utils.print_matrix(mat_3, N, N)
# rotate_180(mat_3, N, N)
# matrix_utils.print_matrix(mat_3, N, N)

# N = 4
# M = 4
# mat_4x4 = matrix_utils.init_matrix(N, M)
# matrix_utils.print_matrix(mat_4x4, N, M)
# rotate_180(mat_4x4, N, N)
# matrix_utils.print_matrix(mat_4x4, N, M)


# N = 4
# M = 5
# mat = matrix_utils.init_matrix(N, M)
# matrix_utils.print_matrix(mat, N, M)
# rotate_180(mat, N, M)
# matrix_utils.print_matrix(mat, N, M)

# N = 5
# M = 6
# mat = matrix_utils.init_matrix(N, M)
# matrix_utils.print_matrix(mat, N, M)
# ZeroMatrix.zero_matrix_2(mat, N, M)
# matrix_utils.print_matrix(mat, N, M)
