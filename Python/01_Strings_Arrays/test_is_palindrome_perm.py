import unittest
from IsPalindromePerm import is_palindrome_perm

class TestIsPalindromePerm(unittest.TestCase):
    def test_regular(self):
        self.assertTrue(is_palindrome_perm("abba"))
        self.assertTrue(is_palindrome_perm("abcba"))
        self.assertTrue(is_palindrome_perm("abbac"))
        self.assertFalse(is_palindrome_perm("ab"))
        self.assertTrue(is_palindrome_perm("a"))
        self.assertFalse(is_palindrome_perm("abcde"))
        self.assertFalse(is_palindrome_perm("abcda"))

if __name__ == '__main__':
    unittest.main()