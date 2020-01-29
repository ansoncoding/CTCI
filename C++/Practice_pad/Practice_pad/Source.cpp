#include "is_unique.h"
#include "is_permutation.h"
#include "urlfy.h"
#include "is_palindrome_perm.h"
#include "is_one_edit.h"
#include "compress_string.h"
#include "rotate_matrix.h"
#include "matrix_utils.h"
#include "zero_matrix.h"
int main() {
    //string s1 = "adbdb"; // true
    //string s2 = "1b";     // false
    //string s3 = "abbb"; // false
    //string s4 = "abba"; //true
    //string s5 = "abcba"; //true
    //is_palindrome_perm(s1);
    //is_palindrome_perm(s2);
    //is_palindrome_perm(s3);
    //is_palindrome_perm(s4);
    //is_palindrome_perm(s5);
    
    //is_one_edit("abc", "abcd"); // true
    //is_one_edit("abc", "ab"); //true
    //is_one_edit("abc", "abb"); // true
    //is_one_edit("abc", "bbc"); //true
    //is_one_edit("abc", "abdd"); //false
    //is_one_edit("abc", "a"); //false
    //is_one_edit("abc", "add"); //false
    //is_one_edit("aaaaa", "bcd"); //false

    //compress("abb"); //abb
    //compress("abc"); //abc
    //compress("aabb"); //a2b2
    //compress("ab"); //ab
    //compress("aaaabb"); //a4b2
    //compress("aaaab"); //a4b1
    //compress("aab"); //aab
    //compress("aabbcc"); //a2b2c2
    //compress("aabbcccdddd"); //a2b2c3d4
    //compress("abcabdaca"); //abcabdaca
   
    /*int ** matrix = NULL;
    int ** mat = NULL;
    int N = 3;
    mat = init_matrix(N);
    print_matrix(mat, N);
    cout << "Rotate" << endl;
    rotate_ccw_90(mat, N);
    print_matrix(mat, N);
    delete[] mat;

    N = 4;
    mat = init_matrix( N);
    print_matrix(mat, N);
    cout << "Rotate" << endl;
    rotate_ccw_90(mat, N);
    print_matrix(mat, N);

    delete[] mat;


    N = 5;
    mat = init_matrix( N);
    print_matrix(mat, N);
    cout << "Rotate" << endl;
    rotate_ccw_90(mat, N);
    print_matrix(mat, N);
    delete[] mat;

    N = 6;
    mat = init_matrix( N);
    print_matrix(mat, N);
    cout << "Rotate" << endl;
    rotate_ccw_90(mat, N);
    print_matrix(mat, N);
    delete[] mat;*/


    //int N = 5;
    //int M = 4;
    //int ** mat = init_matrix(N, M);
    //print_matrix(mat, N, M);
    //rotate_180(mat, N, M);
    //print_matrix(mat, N, M);

    int N = 5;
    int M = 4;
    int ** mat = init_matrix_rand(N, M);
    print_matrix(mat, N, M);
    zero_matrix(mat, N, M);
    print_matrix(mat, N, M);

    system("pause");
}