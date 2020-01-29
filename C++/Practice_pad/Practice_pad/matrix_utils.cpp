#include "matrix_utils.h"

#include <string>
#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

int ** init_matrix(int N) {
    return init_matrix(N, N);
}

int ** init_matrix(int N, int M) {
    int ** mat;
    int count = 0;
    mat = new int*[N];

    for (int i = 0; i < N; i++) {
        mat[i] = new int[M];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            mat[i][j] = count++;
        }
    }
    return mat;
}

int ** init_matrix_rand(int N, int M) {
    int ** mat;
    int count;
    int rand_int = rand()%15;
    mat = new int*[N];

    for (int i = 0; i < N; i++) {
        mat[i] = new int[M];
    }
    count = 5;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            mat[i][j] = count % rand_int;
            count++;
        }
    }
    return mat;
}


void print_matrix(int ** mat, int N) {
    print_matrix( mat, N, N);
}

void print_matrix(int ** mat, int N, int M) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << setfill('0') << setw(2) << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void swap(int ** mat, int i1, int j1, int i2, int j2) {
    int temp = mat[i1][j1];
    mat[i1][j1] = mat[i2][j2];
    mat[i2][j2] = temp;
}