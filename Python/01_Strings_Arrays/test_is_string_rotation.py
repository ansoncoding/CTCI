import unittest
from IsStringRotation import is_string_rotation

class TestIsStringRotation(unittest.TestCase):
    
    def test_regular(self):
        self.assertFalse(is_string_rotation("water", "waterr"))
        self.assertFalse(is_string_rotation("water", "wat"))
        self.assertFalse(is_string_rotation("water", "atern"))
        self.assertTrue(is_string_rotation("water", "terwa"))
        self.assertTrue(is_string_rotation("water", "erwat"))
        self.assertTrue(is_string_rotation("water", "aterw"))

    def test_edge(self):
        self.assertFalse(is_string_rotation("water", ""))
        self.assertFalse(is_string_rotation("", ""))
        self.assertFalse(is_string_rotation("", "a"))

if __name__ == '__main__':
    unittest.main()