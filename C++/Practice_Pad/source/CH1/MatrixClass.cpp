#include "pch.h"
#include "MatrixClass.h"
#include "practice_exceptions.h"
#include <iostream>
#include <iomanip>
//#include <ctime>
//#include <cstdlib>


Matrix_2D::Matrix_2D(int N) {
    initialize_mat(N, N);
}

Matrix_2D::Matrix_2D(int N, int M) {
    initialize_mat(N, M);
}

void Matrix_2D::initialize_mem() {
    mat = new int* [N];
    for (int i = 0; i < N; i++) {
        mat[i] = new int[M];
    }
}
void Matrix_2D::initialize_mat(int rows, int cols) {

    N = rows;
    M = cols;

    int count = 0;

    initialize_mem();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            mat[i][j] = count++;
        }
    }    
}

Matrix_2D::Matrix_2D(int rows, int cols, int* init_vals) {
    N = rows;
    M = cols;
    int count = 0;

    initialize_mem();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            mat[i][j] = init_vals[count];
            count++;
        }
    }
}

Matrix_2D& Matrix_2D::operator=(const Matrix_2D& other) {
    return Matrix_2D(other);
}

// copy constructor
Matrix_2D::Matrix_2D(const Matrix_2D& other) {
    copy(other);
}

void Matrix_2D::copy(const Matrix_2D& other) {
    
    N = other.N;
    M = other.M;
    initialize_mem();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            mat[i][j] = other.getCell(i, j);
        }
    }

}

void Matrix_2D::setCell(const int row, const int col, const int val) {
    if (row < N && col < M)
        mat[row][col] = val;
    else
        throw OutofBoundsException();
}

int Matrix_2D::getCell(const int row, const int col) const {
    if (row < N && col < M)
        return mat[row][col];
    else
        throw OutofBoundsException();
}

void Matrix_2D::print() const {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << setfill('0') << setw(2) << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}


void Matrix_2D::rotate_cw_90() {
    int num_layers = N / 2;

    for (int li = 0; li < N / 2; li++) { //li is layer index
        int start = li;
        int end = N - li - 1;
        for (int i = 0; i < end - li; i++) { // i will be offset
            int temp = mat[start + i][end];

            mat[start + i][end] = mat[start][start + i];
            mat[start][start + i] = mat[end - i][start];
            mat[end - i][start] = mat[end][end - i];
            mat[end][end - i] = temp;
        }
    }
}

void Matrix_2D::rotate_ccw_90() {
    for (int li = 0; li < N / 2; li++) { //li is layer index
        int start = li;
        int end = N - li - 1;
        for (int i = 0; i < end - li; i++) { // i will be offset
            int temp = mat[end][end - i];
            mat[end][end - i] = mat[end - i][start];
            mat[end - i][start] = mat[start][start + i];
            mat[start][start + i] = mat[start + i][end];
            mat[start + i][end] = temp;
        }
    }
}

void Matrix_2D::flip_180() {
    for (int i = 0; i < N / 2; i++) {
        for (int j = 0; j < M; j++) {
            swap(i, j, N - i - 1, j);
        }
    }
}
void Matrix_2D::rotate_180() {
    int r = 0;
    for (r; r < N / 2; r++) { // going by rows
        int start = r;

        for (int c = 0; c < M; c++) { // going by columns
            swap(r, c, N - r - 1, M - c - 1);
        }
    }
    if (N % 2) {
        // we're on middle row right now
        for (int i = 0; i < M / 2; i++) {
            swap(r, i, r, M - i - 1);
        }
    }
}

void Matrix_2D::swap(int i1, int j1, int i2, int j2) {
    int temp = mat[i1][j1];
    mat[i1][j1] = mat[i2][j2];
    mat[i2][j2] = temp;
}

bool Matrix_2D::compare(const Matrix_2D & mat_comp) const {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (mat[i][j] != mat_comp.getCell(i, j))
                return false;
        }
    }
    return true;
}

void Matrix_2D::clear_row(const int row) {
    for (int j = 0; j < M; j++) {
        mat[row][j] = 0;
    }
}

void Matrix_2D::clear_col(const int col) {
    for (int i = 0; i < N; i++) {
        mat[i][col] = 0;
    }
}
// O(n^2) time O(N+M) space
void Matrix_2D::zero_matrix()
{
    bool* count_rows = new bool[N];
    bool* count_cols = new bool[M];
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
            clear_row(i);
        }
    }
    for (int j = 0; j < M; j++) {
        if (count_cols[j]) {
            clear_col(j);
        }
    }
}

// O(n^2) time O(1) space
void Matrix_2D::zero_matrix_2() {
    bool clear_row_0 = false;
    bool clear_col_0 = false;

    for (int i = 0; i < N; i++) {
        if (mat[i][0] == 0) {
            clear_col_0 = true;
            break;
        }
    }
    for (int j = 0; j < M; j++) {
        if (mat[0][j] == 0) {
            clear_row_0 = true;
            break;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (mat[i][j] == 0) {
                mat[0][j] = 0;
                mat[i][0] = 0;
            }
        }
    }
    for (int i = 1; i < N; i++) {
        if (mat[i][0] == 0) {
            clear_row(i);
        }
    }
    for (int j = 1; j < M; j++) {
        if (mat[0][j] == 0) {
            clear_col(j);
        }
    }
    if (clear_col_0)
        clear_col(0);

    if (clear_row_0)
        clear_row(0);
}
Matrix_2D::~Matrix_2D() {
    for (int i = 0; i < N; i++) {
        delete[]mat[i];
    }
    delete[] mat;
}