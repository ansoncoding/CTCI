package strings_and_arrays;

public class IsPalindromePerm {

	public static boolean is_palindrome_perm(String s) {

		boolean[] counts = new boolean[128];
		for (int i = 0; i < s.length(); i++) {
			int index = s.charAt(i);
			counts[index] = !counts[index];
		}
		boolean oddFound = false;
		for (int i = 0; i < 128; i++) {
			if (counts[i] && oddFound) {
				
				return false;
			}
			if (counts[i]) {
				oddFound = true;
			}
		}
		return true;
	}
}
