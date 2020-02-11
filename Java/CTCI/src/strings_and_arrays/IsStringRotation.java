package strings_and_arrays;

public class IsStringRotation {
	public static boolean is_substring(String src, String substr) {
		int len_src= src.length();
		int len_substr = substr.length();
		if (len_substr> len_src) {
			return false;
		}
		for (int i = 0; i < len_src-len_substr+1; i++) {
			if (src.substring(i, i+len_substr).equals(substr))
				return true;
		}
		return false;
	}

	public static boolean is_string_rotation(String s1, String s2) {
		
		if (s1.length()!= s2.length()) {
			return false;
		}
		String test = s1.concat(s1);
		
		return is_substring(test, s2);
	}

}
