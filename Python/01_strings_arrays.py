import IsUnique
import IsPermutation
import MakeURL
import IsPalindromePerm
import IsOneEdit
import CompressString
import RotateMatrix
# print(IsUnique.is_unique_3("str")) # true
# print(IsUnique.is_unique_3("strr")) # false
# print(IsUnique.is_unique_3("abcd")) # true

# print(IsPermutation.is_permutation_3("str", "")) #false
# print(IsPermutation.is_permutation_3("str", "st")) #false
# print(IsPermutation.is_permutation_3("str", "Str")) #false
# print(IsPermutation.is_permutation_3("str", "srt")) #true
# print(IsPermutation.is_permutation_3("strr", "rtrt")) #false
# print(IsPermutation.is_permutation_3("abcdd", "dbcad")) #true

# print(MakeURL.urlfy("a b c"))
# print(MakeURL.urlfy("a b"))

# print(IsPalindromePerm.is_palindrome_perm("abba")) #true
# print(IsPalindromePerm.is_palindrome_perm("abcba")) # true
# print(IsPalindromePerm.is_palindrome_perm("abbac"))#true
# print(IsPalindromePerm.is_palindrome_perm("ab")) #false
# print(IsPalindromePerm.is_palindrome_perm("a")) #true
# print(IsPalindromePerm.is_palindrome_perm("abcde")) #false
# print(IsPalindromePerm.is_palindrome_perm("abcda")) #false

# print(IsOneEdit.is_one_edit("a", "ab")) #true
# print(IsOneEdit.is_one_edit("a", "abc")) #false
# print(IsOneEdit.is_one_edit("ac", "ab")) #true
# print(IsOneEdit.is_one_edit("acee", "ab")) #false
# print(IsOneEdit.is_one_edit("ab", "abc")) #true
# print(IsOneEdit.is_one_edit("aee", "aecc")) #false

# print(CompressString.compress_efficient("abb")) #abb
# print(CompressString.compress_efficient("abc")) #abc
# print(CompressString.compress_efficient("aabb")) #a2b2
# print(CompressString.compress_efficient("ab")) #ab
# print(CompressString.compress_efficient("aaaabb")) #a4b2
# print(CompressString.compress_efficient("aaaab")) #a4b1
# print(CompressString.compress_efficient("aab")) #aab
# print(CompressString.compress_efficient("aabbcc")) #a2b2c2
# print(CompressString.compress_efficient("aabbcccdddd")) #a2b2c3d4
# print(CompressString.compress_efficient("abcabdaca")) #abcabdaca))


# N = 3
# mat_3 = RotateMatrix.init_matrix(N, N)
# RotateMatrix.print_matrix(mat_3, N, N)
# print("Rotate\n")
# RotateMatrix.rotate_ccw_90(mat_3, N)
# RotateMatrix.print_matrix(mat_3, N, N)

# N = 4
# mat_4 = RotateMatrix.init_matrix(N, N)
# RotateMatrix.print_matrix(mat_4, N, N)
# print("Rotate\n")
# RotateMatrix.rotate_ccw_90(mat_4, N)
# RotateMatrix.print_matrix(mat_4, N, N)

# N = 5
# mat_5 = RotateMatrix.init_matrix(N, N)
# RotateMatrix.print_matrix(mat_5, N, N)
# print("Rotate\n")
# RotateMatrix.rotate_ccw_90(mat_5, N)
# RotateMatrix.print_matrix(mat_5, N, N)

# N = 6
# mat_6 = RotateMatrix.init_matrix(N, N)
# RotateMatrix.print_matrix(mat_6, N, N)
# print("Rotate\n")
# RotateMatrix.rotate_ccw_90(mat_6, N)
# RotateMatrix.print_matrix(mat_6, N, N)


# N = 3
# mat_3 = RotateMatrix.init_matrix(N, N)
# RotateMatrix.print_matrix(mat_3, N, N)
# RotateMatrix.flip_180(mat_3, N, N)
# RotateMatrix.print_matrix(mat_3, N, N)

# N = 3
# M = 4
# mat_3x4 = RotateMatrix.init_matrix(N, M)
# RotateMatrix.print_matrix(mat_3x4, N, M)
# RotateMatrix.flip_180(mat_3x4, N, M)
# RotateMatrix.print_matrix(mat_3x4, N, M)

# N = 4
# M = 4
# mat_4x4 = RotateMatrix.init_matrix(N, M)
# RotateMatrix.print_matrix(mat_4x4, N, M)
# RotateMatrix.flip_180(mat_4x4, N, M)
# RotateMatrix.print_matrix(mat_4x4, N, M)


N = 3
mat_3 = RotateMatrix.init_matrix(N, N)
RotateMatrix.print_matrix(mat_3, N, N)
RotateMatrix.rotate_180(mat_3, N, N)
RotateMatrix.print_matrix(mat_3, N, N)

N = 4
M = 4
mat_4x4 = RotateMatrix.init_matrix(N, M)
RotateMatrix.print_matrix(mat_4x4, N, M)
RotateMatrix.rotate_180(mat_4x4, N, N)
RotateMatrix.print_matrix(mat_4x4, N, M)


N = 4
M = 5
mat = RotateMatrix.init_matrix(N, M)
RotateMatrix.print_matrix(mat, N, M)
RotateMatrix.rotate_180(mat, N, M)
RotateMatrix.print_matrix(mat, N, M)