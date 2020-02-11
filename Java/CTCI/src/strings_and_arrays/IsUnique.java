package strings_and_arrays;

public class IsUnique {
	// determine if the string given has all unique characters
	// E.g. "abc" true, "abbc" false
	// O(n^2) the simplest - most straight-forward way, not most efficient
	public static boolean is_unique(String s) throws StringEmptyException {
		if (s.length() == 0) {
			throw new StringEmptyException();
		}
		for (int i = 0; i < s.length(); i++) {
			for (int j = i+1; j < s.length() ; j++) {
				if (s.charAt(i) == s.charAt(j)) {
					return false;
				}
			}
		}
		return true;
	}
	
	// determine if the string given has all unique characters
	// E.g. "abc" true, "abbc" false
	// O(n) using a character array to store a count. As soon as the count goes to 2 we know
	// There is a duplicate character
	public static boolean is_unique_2(String s) throws IllegalArgumentException, Exception {
		if (s.length() == 0) {
			throw new StringEmptyException();
		}
		s = s.toLowerCase();
		int[] counts = new int[26]; //assume English alphabet and to save space you can use a boolean array as well
		for (int i = 0; i < s.length(); i++) {
			
			int index = s.charAt(i)- 'a';
			if ((index > 26) || (index < 0)){
				throw new IllegalArgumentException();
			}
			if (counts[index] >= 1) {
				return false;
			}
			else {
				counts[index]++;
			}
		}
		return true;
	}
}
