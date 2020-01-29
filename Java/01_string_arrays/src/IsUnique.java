
public class IsUnique {
	// determine if the string given has all unique characters
	// E.g. "abc" true, "abbc" false
	// O(n^2) the simplest - most straight-forward way, not most efficient
	public static boolean is_unique(String s) {
		System.out.println(s);
		for (int i = 0; i < s.length(); i++) {
			for (int j = i+1; j < s.length() ; j++) {
				if (s.charAt(i) == s.charAt(j)) {
					System.out.println("False");
					return false;
				}
			}
		}
		System.out.println("True");
		return true;
	}
	
	// determine if the string given has all unique characters
	// E.g. "abc" true, "abbc" false
	// O(n) using a character array to store a count. As soon as the count goes to 2 we know
	// There is a duplicate character
	public static boolean is_unique_2(String s) {
		s = s.toLowerCase();
		System.out.println(s);
		int[] counts = new int[26]; //assume English alphabet and to save space you can use a boolean array as well
		for (int i = 0; i < s.length(); i++) {
			
			int index = s.charAt(i)- 'a';
			if ((index > 26) || (index < 0)){
				System.out.println("Error");
				return false;
			}
			//System.out.println(index);
			if (counts[index] >= 1) {
				System.out.println("false");
				return false;
			}
			else {
				counts[index]++;
			}
		}
		System.out.println("true");
		return true;
	}
		

	public static void main(String[] args) {
		is_unique_2("abc");
		is_unique_2("abb");
		
	}

}
