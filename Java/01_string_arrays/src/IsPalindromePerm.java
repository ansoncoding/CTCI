
public class IsPalindromePerm {

	public static boolean is_palindrome_perm(String s) {
		System.out.print(s);

		boolean[] counts = new boolean[128];
		for (int i = 0; i < s.length(); i++) {
			int index = s.charAt(i);
			counts[index] = !counts[index];
		}
		boolean oddFound = false;
		for (int i = 0; i < 128; i++) {
			if (counts[i] && oddFound) {
				System.out.println(" False");
				return false;
			}
			if (counts[i]) {
				oddFound = true;
			}
		}
		System.out.println(" True");
		return true;
		
	}
	public static void main(String[] args) {
		is_palindrome_perm("abc"); //False
		is_palindrome_perm("ab");  //False
		is_palindrome_perm("a");   // True
		is_palindrome_perm("aba"); // True
		is_palindrome_perm("abba"); // False
		is_palindrome_perm("abcba"); //True
		is_palindrome_perm("abcbA"); // 

	}

}
