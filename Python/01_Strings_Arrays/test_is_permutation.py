import unittest
from IsPermutation import is_permutation, is_permutation_2, is_permutation_3

class TestIsPermutation(unittest.TestCase):

    def test_regular(self):
        self.assertFalse(is_permutation("str", ""))
        self.assertFalse(is_permutation("", "str"))
        self.assertFalse(is_permutation("str", "st"))
        self.assertFalse(is_permutation("strr", "Str"))
        self.assertFalse(is_permutation("strr", "rtrt"))
        self.assertTrue(is_permutation("str", "srt"))
        self.assertTrue(is_permutation("str", "tsr"))
        self.assertTrue(is_permutation("str", "trs"))
        self.assertTrue(is_permutation("abcdd", "dbcad"))

class TestIsPermutation2(unittest.TestCase):

    def test_regular(self):
        self.assertFalse(is_permutation_2("str", ""))
        self.assertFalse(is_permutation_2("", "str"))
        self.assertFalse(is_permutation_2("str", "st"))
        self.assertFalse(is_permutation_2("strr", "Str"))
        self.assertFalse(is_permutation_2("strr", "rtrt"))
        self.assertTrue(is_permutation_2("str", "srt"))
        self.assertTrue(is_permutation_2("str", "tsr"))
        self.assertTrue(is_permutation_2("str", "trs"))
        self.assertTrue(is_permutation_2("abcdd", "dbcad"))

class TestIsPermutation3(unittest.TestCase):

    def test_regular(self):
        self.assertFalse(is_permutation_3("str", ""))
        self.assertFalse(is_permutation_3("", "str"))
        self.assertFalse(is_permutation_3("str", "st"))
        self.assertFalse(is_permutation_3("strr", "Str"))
        self.assertFalse(is_permutation_3("strr", "rtrt"))
        self.assertTrue(is_permutation_3("str", "srt"))
        self.assertTrue(is_permutation_3("str", "tsr"))
        self.assertTrue(is_permutation_3("str", "trs"))
        self.assertTrue(is_permutation_3("abcdd", "dbcad"))


if __name__ == '__main__':
    unittest.main()
