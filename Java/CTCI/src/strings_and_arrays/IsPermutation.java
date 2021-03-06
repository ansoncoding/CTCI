package strings_and_arrays;
import java.util.Arrays;

public class IsPermutation {
	
	public static String sortString(String inputString) 
    { 
        // convert input string to char array 
        char tempArray[] = inputString.toCharArray(); 
          
        // sort tempArray 
        Arrays.sort(tempArray); 
          
        // return new sorted string 
        return new String(tempArray); 
    }
	
	public static boolean is_permutation(String s1, String s2) {

		int[] counts_s1 = new int[128]; // for all ASCII possibilities
		int[] counts_s2 = new int[128]; // for all ASCII possibilities
		
		for (int i = 0; i < s1.length(); i++) {
			counts_s1[s1.charAt(i)]++;
		}
		
		for (int i = 0; i < s2.length(); i++) {
			counts_s2[s2.charAt(i)]++;
		}
		
		for (int i = 0; i < 128; i++) {
			//System.out.println(counts_s1[i] + " " + counts_s2[i]);
			if (counts_s1[i] != counts_s2[i]) {

				return false;
			}
		}

		return true;
	}
	
	public static boolean is_permutation_2(String s1, String s2) {

		int[] counts = new int[128]; // for all ASCII possibilities
		
		for (int i = 0; i < s1.length(); i++) {
			counts[s1.charAt(i)]++;  
		}
		
		for (int i = 0; i < s2.length(); i++) {
			if (counts[s2.charAt(i)] < 1) {
				return false;
			}
			counts[s2.charAt(i)]--;
		}

		return true;
	}

	public static boolean is_permutation_3(String s1, String s2) {

		if (s1.length()!= s2.length()) {

			return false;
		}
		String s1_sorted = sortString(s1);
		String s2_sorted = sortString(s2);
		for (int i = 0; i < s1.length(); i++) {
			if (s1_sorted.charAt(i) != s2_sorted.charAt(i)) {

				return false;
			}
		}
		return true;
	}
}
