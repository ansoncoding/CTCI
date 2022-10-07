#ifndef MATRIX_CLASS_H
#define MATRIX_CLASS_H

using namespace std;

class Matrix_2D {

private:
    int** mat;
    int N = 0; //num rows
    int M = 0; // num cols
    void initialize_mem();
    void initialize_mat(int rows, int cols);
    void copy(const Matrix_2D& other);
    void cleanup();
public:
    Matrix_2D(int N);
    Matrix_2D(int N, int M);
    Matrix_2D(int N, int M, int* vals);
    Matrix_2D(const Matrix_2D& other);
    Matrix_2D& operator=(const Matrix_2D& other);
    ~Matrix_2D();
    void setCell(const int row, const int col, const int val);
    int getCell(const int row, const int col) const;
    void print () const;
    void rotate_cw_90();
    void rotate_cw_90_ver2();
    void rotate_ccw_90();
    void rotate_ccw_90_ver2();
    void flip_180();
    void transpose();
    void rotate_180();
    void zero_matrix();
    void zero_matrix_2();
    void clear_col(int col);
    void clear_row(int row);
    void swap(int i1, int j1, int i2, int j2);
    bool compare(const Matrix_2D & comp) const;
};


#endif
