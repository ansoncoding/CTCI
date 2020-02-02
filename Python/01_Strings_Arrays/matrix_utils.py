import random


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
