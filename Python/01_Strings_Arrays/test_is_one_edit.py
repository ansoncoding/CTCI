import unittest
from IsOneEdit import is_one_edit

class TestIsOneEdit(unittest.TestCase):

    def test_regular(self):
        self.assertTrue(is_one_edit("a", "ab")) #true
        self.assertFalse(is_one_edit("a", "abc")) #false
        self.assertTrue(is_one_edit("ac", "ab")) #true
        self.assertFalse(is_one_edit("acee", "ab")) #false
        self.assertTrue(is_one_edit("ab", "abc")) #true
        self.assertFalse(is_one_edit("aee", "aecc")) #false

if __name__ == '__main__':
    unittest.main()