package strings_and_arrays;

import static org.junit.Assert.*;

import org.junit.Test;

public class TestCompressString {
	
	@Test
	public void TestCompress() {
	    assertEquals(CompressString.compress("abb"), "abb"); //abb
	    assertEquals(CompressString.compress("abc"), "abc"); //abc
	    assertEquals(CompressString.compress("aabb"), "a2b2"); //a2b2
	    assertEquals(CompressString.compress("ab"), "ab"); //ab
	    assertEquals(CompressString.compress("aaaabb"), "a4b2"); //a4b2
	    assertEquals(CompressString.compress("aaaab"), "a4b1"); //a4b1
	    assertEquals(CompressString.compress("aab"), "aab"); //aab
	    assertEquals(CompressString.compress("aabbcc"), "a2b2c2"); //a2b2c2
	    assertEquals(CompressString.compress("aabbcccdddd"), "a2b2c3d4"); //a2b2c3d4
	    assertEquals(CompressString.compress("abcabdaca"), "abcabdaca"); //abcabdaca
	}
	
	@Test
	public void TestCompress2() {
	    assertEquals(CompressString.compress2("abb"), "abb"); //abb
	    assertEquals(CompressString.compress2("abc"), "abc"); //abc
	    assertEquals(CompressString.compress2("aabb"), "a2b2"); //a2b2
	    assertEquals(CompressString.compress2("ab"), "ab"); //ab
	    assertEquals(CompressString.compress2("aaaabb"), "a4b2"); //a4b2
	    assertEquals(CompressString.compress2("aaaab"), "a4b1"); //a4b1
	    assertEquals(CompressString.compress2("aab"), "aab"); //aab
	    assertEquals(CompressString.compress2("aabbcc"), "a2b2c2"); //a2b2c2
	    assertEquals(CompressString.compress2("aabbcccdddd"), "a2b2c3d4"); //a2b2c3d4
	    assertEquals(CompressString.compress2("abcabdaca"), "abcabdaca"); //abcabdaca
	}
}
