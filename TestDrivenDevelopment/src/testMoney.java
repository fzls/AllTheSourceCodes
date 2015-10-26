import static org.junit.Assert.*;

import org.junit.Test;

public class testMoney {

	@Test
	public void test() {
		Money five = Money.dollar(5);
		assertEquals(Money.dollar(10), five.times(2));
//		assertEquals(Money.dollar(10), five.times(2), "testMultiplication-Dollar");
//		assertEquals(Money.dollar(15), five.times(3), "testMultiplication-Dollar");

//		five = Money.franc(5);
//		assertEquals(Money.franc(10), five.times(2), "testMultiplication-Franc");
//		assertEquals(Money.franc(15), five.times(3), "testMultiplication-Franc");
	}

}
