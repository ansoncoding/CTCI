#include "pch.h"
#include "rotate_matrix.h"
#include "matrix_utils.h"

using namespace std;

void rotate_cw_90(int** mat, int N){
    int num_layers = N / 2;
    
    for (int li = 0; li < N / 2; li++) { //li is layer index
        int start = li;
        int end = N - li - 1;
        for (int i = 0; i < end-li; i++) { // i will be offset
            int temp = mat[start+i][end];

            mat[start+i][end] = mat[start][start+i];
            mat[start][start+i] = mat[end-i][start];
            mat[end-i][start] = mat[end][end-i];
            mat[end][end-i] = temp;
        }
    }
}

void rotate_ccw_90(int** mat, int N){
    
    for (int li = 0; li < N / 2; li++) { //li is layer index
        int start = li;
        int end = N - li - 1;
        for (int i = 0; i < end-li; i++) { // i will be offset
            int temp = mat[end][end-i];
            mat[end][end-i] = mat[end-i][start];
            mat[end-i][start] = mat[start][start+i];
            mat[start][start+i] =  mat[start+i][end];
            mat[start + i][end] = temp;
        }
    }
}

void flip_180(int** mat, int N, int M) {
    for (int i = 0; i < N/2; i++) {
        for (int j = 0; j < M; j++) {
            swap(mat, i, j, N - i - 1, j);
        }
    }
}

void rotate_180(int ** mat, int N, int M) {
    int r = 0;
    for (r; r < N / 2; r++) { // going by rows
        int start = r;
        
        for (int c = 0; c < M; c++) { // going by columns
            swap(mat, r, c, N-r-1, M-c-1);
        }
    }
    if (N % 2) {
        // we're on middle row right now
        for (int i = 0; i < M /2; i++) {
            swap(mat, r, i, r, M-i-1);
        }
    }
}