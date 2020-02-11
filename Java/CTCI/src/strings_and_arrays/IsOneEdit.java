package strings_and_arrays;
import java.lang.Math; 
public class IsOneEdit {

	public static boolean is_one_edit(String s1, String s2) {
		//System.out.println(s1 + " " + s2);
		int len1 = s1.length();
		int len2 = s2.length();
		int abs_len_diff = Math.abs(len1 - len2);
		if (abs_len_diff > 1) {
			//System.out.println("False");
			return false;
		}
		if (abs_len_diff == 0) {
			boolean diffFound = false;
			for (int i = 0; i < len1; i++) {
				if (s1.charAt(i) != s2.charAt(i)) {
					if (diffFound) {
						//System.out.println("False");
						return false;
					}
					diffFound = true;
				}
			}
			//System.out.println("True");
			return true;
		} else {
			int i =0; int j= 0;
			boolean skipped = false;
			int shorter_len = (len1 > len2) ? len2: len1;
			while(i < shorter_len ) {
				if (s1.charAt(i) != s2.charAt(j)) {
					if (skipped) {
						//System.out.println("False");
						return false;
					}
					skipped = true;
					if (len1 < len2) 
						j++;
					else
						i++;
				} else {
					i++;
					j++;
				}
			}
			//System.out.println("True");
			return true;
		}
	}
	public static void main(String[] args) {
	    is_one_edit("abc", "abcd"); // true
	    is_one_edit("abc", "ab"); //true
	    is_one_edit("abc", "abb"); // true
	    is_one_edit("abc", "bbc"); //true
	    is_one_edit("abc", "abdd"); //false
	    is_one_edit("abc", "a"); //false
	    is_one_edit("abc", "add"); //false
	    is_one_edit("aaaaa", "bcd"); //false

	}

}
