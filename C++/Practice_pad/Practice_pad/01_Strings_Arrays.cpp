#include "is_unique.h"
#include "is_permutation.h"
#include "urlfy.h"
#include "is_palindrome_perm.h"
#include "is_one_edit.h"
#include "compress_string.h"
#include "rotate_matrix.h"
#include "matrix_utils.h"
#include "zero_matrix.h"
#include "is_string_rotation.h"
#include "HashTable.h"
#include "ArrayList.h"
#include "StringBuilder.h"

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

    //int N = 5;
    //int M = 7;
    //int ** mat = init_matrix_rand(N, M);
    //print_matrix(mat, N, M);
    //zero_matrix_2(mat, N, M);
    //print_matrix(mat, N, M);

    //string s1 = "edabcd";
    //string s2 = "dabcd";
    //cout << is_substring(s1, s2) << endl;

    //s1 = "abc";
    //s2 = "ab";
    //cout << is_substring(s1, s2) << endl;

    //s1 = "abc";
    //s2 = "abc";
    //cout << is_substring(s1, s2) << endl;

    //s1 = "dabc";
    //s2 = "abc";
    //cout << is_substring(s1, s2) << endl;

    //s1 = "abc";
    //s2 = "abcd";
    //cout << is_substring(s1, s2) << endl;

    /*string s1 = "abc";
    string s2 = "bca";
    cout << is_string_rotation(s1, s2)<< endl;

    s1 = "abc";
    s2 = "bcb";
    cout << is_string_rotation(s1, s2)<< endl;

    s1 = "waterbottle";
    s2 = "terbottlewa";
    cout << is_string_rotation(s1, s2)<< endl;*/

    //HashTable ht = HashTable();
    //ht.insert("hi");
    //ht.insert("hello");
    //ht.insert("good");
    //ht.insert("terrible");
    //ht.insert("computer");
    //ht.insert("oh");
    //ht.insert("science");
    //ht.insert("coding");
    //ht.insert("insomnia");
    //ht.insert("geez");
    //ht.insert("oh no!");
    //ht.insert("love");
    //ht.print();
    //ht.remove("hi");
    //ht.remove("insomnia");
    //ht.print();
    //cout << ht.contains("hi") << endl;
    //cout << ht.contains("hello") << endl;
    //ht.delete_ht();


    //ArrayList al = ArrayList();
    //for (int i = 0; i < 20; i++){
    //    al.add(i);
    //}
    //al.print();
    //cout << "Capacity: " << al.getCapacity() << " size: " << al.getSize() << endl;
    //if (al.remove(20)) {
    //    al.print();
    //    cout << "Capacity: " << al.getCapacity() << " size: " << al.getSize() << endl;
    //}

    StringBuilder sb = StringBuilder(); 
    sb.append("hello");
    sb.append(" how");
    sb.append(" are");
    sb.append(" you");
    cout << sb.toString() << endl;
    sb.delete_all();

    system("pause");
}