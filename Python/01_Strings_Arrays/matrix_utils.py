import random

def compare(mat1, mat2, N, M):
    for i in range(0, N):
        for j in range(0, M):
            if mat1[i][j] != mat2[i][j]:
                return False
    return True


def print_matrix(mat, N, M):
    for i in range(0, N):
        for j in range(0, M):
            #print(str(i) + " " + str(j))
            print('{:02} '.format(mat[i][j]), end = '')
        print("\n")
    print("\n")
    return


def init_matrix(N, M):
    mat = [[i+N*j for i in range(M)] for j in range(N)]
    return mat

def init_matrix_with_list(N, M, li):
    count = 0
    mat = [[0 for i in range(M)] for j in range(N)]
    for i in range(0, N):
        for j in range(0, M):
            mat[i][j] = li[count]
            count+=1
    return mat

def init_rand_matrix(N, M):
    random.seed()

    mat = [[i+N*j for i in range(M)] for j in range(N)]#[[0]*M]*N
    for i in range(0, N):
        for j in range(0, M):
            
            value = random.randrange(N*M) % ((N*M)//2)
            #print("Value " + str(value) + " " + str(i) + " " + str(j))
            mat[i][j] = value
    #print_matrix(mat, N, M)
    return mat


def swap(mat, i1, j1, i2, j2):
    temp = mat[i1][j1]
    mat[i1][j1] = mat[i2][j2]
    mat[i2][j2] = temp
    return
