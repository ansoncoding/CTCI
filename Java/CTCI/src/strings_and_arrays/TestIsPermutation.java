package strings_and_arrays;
import org.junit.Test;
import static org.junit.Assert.*;

public class TestIsPermutation {
	@Test
	public void testIsPermutation() {
		assertTrue(IsPermutation.is_permutation_3("abc", "acb"));
		assertFalse(IsPermutation.is_permutation_3("abb", "acb"));
		assertTrue(IsPermutation.is_permutation_3("abab", "abba"));
		assertTrue(IsPermutation.is_permutation_3("abccde", "adebcc"));
	}
}
