package strings_and_arrays;
import org.junit.Test;
import static org.junit.Assert.*;

public class TestIsStringRotation {
	@Test
	public void testStringRotation() {
		assertFalse(IsStringRotation.is_string_rotation("abc", "cba"));
		assertFalse(IsStringRotation.is_string_rotation("abc", "cabc"));
		assertFalse(IsStringRotation.is_string_rotation("abc", "c"));
		assertFalse(IsStringRotation.is_string_rotation("c", "cd"));
		assertTrue(IsStringRotation.is_string_rotation("c", "c"));
		assertTrue(IsStringRotation.is_string_rotation("abc", "abc"));
		assertTrue(IsStringRotation.is_string_rotation("abc", "cab"));
		assertTrue(IsStringRotation.is_string_rotation("asdfasdfdc", "casdfasdfd"));
	}
}
