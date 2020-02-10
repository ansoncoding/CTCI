import unittest
from IsUnique import is_unique, is_unique_3, is_unique_2


class TestIsUnique(unittest.TestCase):

    def test_regular(self):
        self.assertTrue(is_unique("str"))
        self.assertTrue(is_unique("abcd"))
        self.assertFalse(is_unique("strr"))

    def test_edge(self):
        self.assertTrue(is_unique(""))


class TestIsUnique2(unittest.TestCase):

    def test_regular(self):
        self.assertTrue(is_unique_2("str"))
        self.assertTrue(is_unique_2("abcd"))
        self.assertFalse(is_unique_2("strr"))

    def test_edge(self):
        self.assertTrue(is_unique_2(""))

class TestIsUnique3(unittest.TestCase):

    def test_regular(self):
        self.assertTrue(is_unique_3("str"))
        self.assertTrue(is_unique_3("abcd"))
        self.assertFalse(is_unique_3("strr"))

    def test_edge(self):
        self.assertTrue(is_unique_3(""))


if __name__ == '__main__':
    unittest.main()
