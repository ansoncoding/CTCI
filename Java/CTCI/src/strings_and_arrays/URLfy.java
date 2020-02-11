package strings_and_arrays;


public class URLfy {
	
	public static String URLify(String s, int length) {
		return s.replace(" ", "%20");
	}
	
	// whenever we encounter a space, copy the rest of the string first then replace the space with "%20"
	// this is bad because if we have many spaces we end up doing a lot of wasted work
	public static void URLify_2(char[] charArray, int length ) {
		char SPACE[] = {'%', '2', '0'};
		for (int i = 0; i < length; i++) {
			if (charArray[i] == ' ') {
				//arraycopy(Object src, int srcPos, Object dest, int destPos, int length)
				System.arraycopy(charArray, i+1, charArray, i+3, length-i-1);
				System.arraycopy(SPACE, 0, charArray, i, 3);
				length+= 2;
			}
		}
	}
	
	// do it backwards to avoid copying the array so many times
	public static void URLify_3(char[] charArray, int length) {
		int num_space = 0;
		char SPACE[] = {'%', '2', '0'};
		
		// count # of spaces to determine last index of changed string
		for (int i = 0; i < length; i++) {
			if (charArray[i] == ' ') {
				num_space++;
			}
		}
		
		if (num_space == 0)
			return;
		
		int end = length + (num_space << 1);
		
		System.out.println(end);
		charArray[end-1] = '\0';
		end--;
		for (int i = length-1; i >= 0; i--) {
			if (charArray[i]== ' ') {
				System.arraycopy(SPACE, 0, charArray, end-2, 3);
				end-=3;
			} else {
				charArray[end] = charArray[i];
				end--;
			}
		}		
	}
}
