package strings_and_arrays;
import org.junit.Test;
import static org.junit.Assert.*;


public class TestURLfy {
	char d1[] = "a b  ".toCharArray();
	char s1[] = "a%20b".toCharArray();
	char d2[] = "a  b    ".toCharArray();
	char s2[] = "a%20%20b".toCharArray();
	char d3[] = "a  b c      ".toCharArray();
	char s3[] = "a%20%20b%20c".toCharArray();
	char d4[] = "a  b cd      ".toCharArray();
	char s4[] = "a%20%20b%20cd".toCharArray();
	char d5[] = "nothing".toCharArray();
	char s5[] = "nothing".toCharArray();
	
	
	@Test
	public void TestURL2() {

		URLfy.URLify_2(d1, 3);
		URLfy.URLify_2(d2, 4);
		URLfy.URLify_2(d3, 6);
		URLfy.URLify_2(d4, 7);
		URLfy.URLify_2(d5, 7);
		
		assertArrayEquals(d1, s1);
		assertArrayEquals(d2, s2);
		assertArrayEquals(d3, s3);
		assertArrayEquals(d4, s4);
		assertArrayEquals(d5, s5);
	}
	
	@Test
	public void TestURL3() {

		URLfy.URLify_3(d1, 3);
		URLfy.URLify_3(d2, 4);
		URLfy.URLify_3(d3, 6);
		URLfy.URLify_3(d4, 7);
		URLfy.URLify_3(d5, 7);
		
		assertArrayEquals(d1, s1);
		assertArrayEquals(d2, s2);
		assertArrayEquals(d3, s3);
		assertArrayEquals(d4, s4);
		assertArrayEquals(d5, s5);
	}

}
