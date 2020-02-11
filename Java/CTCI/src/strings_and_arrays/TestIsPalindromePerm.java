package strings_and_arrays;
import org.junit.Test;
import static org.junit.Assert.*;

public class TestIsPalindromePerm {
	@Test
	public void testIsPalindromePerm() {
		assertFalse(IsPalindromePerm.is_palindrome_perm("abc")); //False
		assertFalse(IsPalindromePerm.is_palindrome_perm("ab"));  //False
		assertFalse(IsPalindromePerm.is_palindrome_perm("abcbA")); //
		assertTrue(IsPalindromePerm.is_palindrome_perm("abba")); // True
		assertTrue(IsPalindromePerm.is_palindrome_perm("a"));   // True
		assertTrue(IsPalindromePerm.is_palindrome_perm("aba")); // True
		assertTrue(IsPalindromePerm.is_palindrome_perm("abcba")); //True
		 
	}
}
