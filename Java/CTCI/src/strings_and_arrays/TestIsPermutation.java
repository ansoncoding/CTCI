package strings_and_arrays;
import org.junit.Test;
import static org.junit.Assert.*;

public class TestIsPermutation {
	
	@Test
	public void testIsPermutation() {
		assertTrue(IsPermutation.is_permutation("abc", "acb"));
		assertTrue(IsPermutation.is_permutation("abab", "abba"));
		assertTrue(IsPermutation.is_permutation("abccde", "adebcc"));
		assertFalse(IsPermutation.is_permutation("abb", "acb"));
	}
	
	@Test
	public void testIsPermutation2() {
		assertTrue(IsPermutation.is_permutation_2("abc", "acb"));
		assertTrue(IsPermutation.is_permutation_2("abab", "abba"));
		assertTrue(IsPermutation.is_permutation_2("abccde", "adebcc"));
		assertFalse(IsPermutation.is_permutation_2("abb", "acb"));
	}
	
	@Test
	public void testIsPermutation3() {
		assertTrue(IsPermutation.is_permutation_3("abc", "acb"));
		assertFalse(IsPermutation.is_permutation_3("abb", "acb"));
		assertTrue(IsPermutation.is_permutation_3("abab", "abba"));
		assertTrue(IsPermutation.is_permutation_3("abccde", "adebcc"));
	}
}
