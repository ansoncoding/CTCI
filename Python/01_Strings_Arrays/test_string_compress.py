import unittest
from CompressString import compress_efficient
from CompressString import compress

class TestCompress(unittest.TestCase):

    def test_regular(self):
        self.assertEqual(compress("abb"), "abb")
        self.assertEqual(compress("abc"), "abc")
        self.assertEqual(compress("aabb"), "a2b2")
        self.assertEqual(compress("ab"), "ab")
        self.assertEqual(compress("aaaabb"), "a4b2")
        self.assertEqual(compress("aaaab"), "a4b1")
        self.assertEqual(compress("aab"), "aab")
        self.assertEqual(compress("aabbcc"), "a2b2c2")
        self.assertEqual(compress("aabbcccdddd"), "a2b2c3d4")
        self.assertEqual(compress("abcabdaca"), "abcabdaca")

    def test_edge(self):
        self.assertEqual(compress_efficient(""), "") #empty
        self.assertEqual(compress_efficient("T"), "T") # one letter string


class TestCompressEfficient(unittest.TestCase):

    def test_regular(self):
        self.assertEqual(compress_efficient("abb"), "abb")
        self.assertEqual(compress_efficient("abc"), "abc")
        self.assertEqual(compress_efficient("aabb"), "a2b2")
        self.assertEqual(compress_efficient("ab"), "ab")
        self.assertEqual(compress_efficient("aaaabb"), "a4b2")
        self.assertEqual(compress_efficient("aaaab"), "a4b1")
        self.assertEqual(compress_efficient("aab"), "aab")
        self.assertEqual(compress_efficient("aabbcc"), "a2b2c2")
        self.assertEqual(compress_efficient("aabbcccdddd"), "a2b2c3d4")
        self.assertEqual(compress_efficient("abcabdaca"), "abcabdaca")

    def test_edge(self):
        self.assertEqual(compress_efficient(""), "") #empty
        self.assertEqual(compress_efficient("T"), "T") # one letter string

if __name__ == '__main__':
    unittest.main()
