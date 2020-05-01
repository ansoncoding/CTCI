package project_euler;
import org.junit.Test; 
import static org.junit.Assert.*;


public class TestGCD {
	@Test
	public void testGCD() {
		assertEquals(1, PythagoreanTriplet.GCD(1, 2));
		assertEquals(4, PythagoreanTriplet.GCD(8, 12));
		assertEquals(1, PythagoreanTriplet.GCD(11, 12));
		assertEquals(12, PythagoreanTriplet.GCD(24, 36));
		assertEquals(24, PythagoreanTriplet.GCD(24, 24));
	}
}
	