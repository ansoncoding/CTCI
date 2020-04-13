package project_euler;

import org.junit.Test; 
import static org.junit.Assert.*;

public class TestSumProperDivisor {
	@Test
	public void testProperDivisorsSum() {
		assertEquals(284, AmicableSum.sumDivisorsOfN(220));
		assertEquals(220, AmicableSum.sumDivisorsOfN(284));
	}
}
