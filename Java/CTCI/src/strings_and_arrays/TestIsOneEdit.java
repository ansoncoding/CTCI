package strings_and_arrays;

import static org.junit.Assert.*;
import org.junit.Test;

public class TestIsOneEdit {
	@Test
    public void testIsOneEdit() {
        
		assertTrue(IsOneEdit.is_one_edit("asdf", "asd"));
        assertTrue(IsOneEdit.is_one_edit("ab", "a"));
        assertFalse(IsOneEdit.is_one_edit("abb", "acc"));
        assertFalse(IsOneEdit.is_one_edit("aabb", "aa"));
    }
}
