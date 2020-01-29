
public class CompressString {

	public static String compress(String s) {
		int len = s.length();
		if (len <= 2) {
			return s;
		}
		
		int count = 0;
		int i = 0;
		String result = "";
		while( i < len) {
			
			char current = s.charAt(i);
			result += current;
			count = 0;
			while((i < len) && current == (s.charAt(i))) {
				i++;
				count++;
			}
			result +=  Integer.toString(count);
		}
		if (result.length() > len) {
			return s;
		}
		return result;
	}
	// use StringBuilder is more efficient because it doesn't create a new string every append 
	public static String compress2(String s) {
		StringBuilder result = new StringBuilder();
		int len = s.length();
		if (len <= 2) {
			return s;
		}
		int count = 0;
		int i = 0;
		while( i < len) {
			
			char current = s.charAt(i);
			result.append(current);
			count = 0;
			while((i < len) && current == (s.charAt(i))) {
				i++;
				count++;
			}
			result.append(Integer.toString(count));
		}
		return result.toString();
	}
	public static void main(String[] args) {
	    System.out.println(compress("abb")); //abb
	    System.out.println(compress("abc")); //abc
	    System.out.println(compress("aabb")); //a2b2
	    System.out.println(compress("ab")); //ab
	    System.out.println(compress("aaaabb")); //a4b2
	    System.out.println(compress("aaaab")); //a4b1
	    System.out.println(compress("aab")); //aab
	    System.out.println(compress("aabbcc")); //a2b2c2
	    System.out.println(compress("aabbcccdddd")); //a2b2c3d4
	    System.out.println(compress("abcabdaca")); //abcabdaca

	}

}
