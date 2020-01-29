def init_matrix(N, M):
    mat = [[i+N*j for i in range(M)] for j in range(N)]
    return mat


def print_matrix(mat, N, M):
    for i in range(0, N):
        for j in range(0, M):
            print('{:02} '.format(mat[i][j]), end = '')
        print("\n")
    print("\n")

def swap(mat, i1, j1, i2, j2):
    temp = mat[i1][j1]
    mat[i1][j1] = mat[i2][j2]
    mat[i2][j2] = temp


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
            swap(mat, i, j, N-i-1, j)
    return mat


def rotate_180(mat, N):
    for li in range(0,  N // 2):
        start = li
        end = N - li - 1;
        for i in range (0, end-start):
            swap(mat, start+i, end, end-i, start)
            swap(mat, start, start+i, end, end-i)
    return mat


def rotate_180(mat, N, M):
    for i in range (0, N//2):
        for j in range(0, M):
            swap(mat, i, j, N-i-1, M-j-1)
    if (N % 2):
        row = N//2
        print("row " + str(row))
        for c in range(0, M//2):
            swap(mat,row, c, row, M-c-1)