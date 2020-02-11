package strings_and_arrays;

import static org.junit.Assert.*;
import org.junit.Test;

public class TestIsOneEdit {
	@Test
    public void testIsOneEdit() {
               
        assertTrue(IsOneEdit.is_one_edit("abc", "abcd")); // true
        assertTrue(IsOneEdit.is_one_edit("abc", "ab")); //true
        assertTrue(IsOneEdit.is_one_edit("abc", "abb")); // true
        assertTrue(IsOneEdit.is_one_edit("abc", "bbc")); //true
        assertFalse(IsOneEdit.is_one_edit("abc", "abdd")); //false
        assertFalse(IsOneEdit.is_one_edit("abc", "a")); //false
        assertFalse(IsOneEdit.is_one_edit("abc", "add")); //false
        assertFalse(IsOneEdit.is_one_edit("aaaaa", "bcd")); //false
    }
}
