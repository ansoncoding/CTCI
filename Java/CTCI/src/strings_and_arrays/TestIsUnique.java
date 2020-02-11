package strings_and_arrays;
import org.junit.Test;
import static org.junit.Assert.*;


public class TestIsUnique {

	@Test
    public void testIsUniqueRegular() throws StringEmptyException {
        
		assertTrue(IsUnique.is_unique("asdf"));
        assertTrue(IsUnique.is_unique("ab"));
        assertFalse(IsUnique.is_unique("abb"));
        assertFalse(IsUnique.is_unique("aabb"));
    }
	
	@Test(expected = IllegalArgumentException.class)
	public void testIsUniqueException() throws IllegalArgumentException, Exception {
    	IsUnique.is_unique_2("120481");
	}
	
	@Test(expected = StringEmptyException.class)
	public void testIsUniqueExceptionES() throws IllegalArgumentException, Exception {
		IsUnique.is_unique_2("");
	}
}
