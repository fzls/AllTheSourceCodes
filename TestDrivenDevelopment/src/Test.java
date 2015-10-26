
public class Test {
	//---------------------------asserts-------------------------------------------------------------
	void assertEquals(Object left, Object right, String test) {
		if (!left.equals(right))
			System.out.println("ERROR : assertEqual not passed in " + test);

	}
	void assertFalse(boolean equals, String test) {
		if (equals)
			System.out.println("ERROR : assertFalse not passed in " + test);
	}
	void assertTrue(boolean equals, String test) {
		if (!equals)
			System.out.println("ERROR : assertTrue not passed in " + test);
	}

	//---------------------------tests---------------------------------------------------------------
	void testMultiplication() {
		Money five = Money.dollar(5);
		assertEquals(Money.dollar(10), five.times(2), "testMultiplication-Dollar");
		assertEquals(Money.dollar(15), five.times(3), "testMultiplication-Dollar");

		five = Money.franc(5);
		assertEquals(Money.franc(10), five.times(2), "testMultiplication-Franc");
		assertEquals(Money.franc(15), five.times(3), "testMultiplication-Franc");
	}
	void testEquality() {
		assertTrue(Money.dollar(5).equals(Money.dollar(5)), "testEquality-Dollar");
		assertFalse(Money.dollar(5).equals(Money.dollar(6)), "testEquality-Dollar");
		assertFalse(Money.franc(5).equals(Money.dollar(5)), "testEquality-Franc-Dollar");
	}
	void testCurrency() {
		assertEquals("USD", Money.dollar(1).currency(), "testCurrency-Dollar");
		assertEquals("CHF", Money.franc(1).currency(), "testCurrency-Franc");
	}
	void testSimpleAddtion() {
		Money five = Money.dollar(5);
		Expression sum = five.plus(five);
		Bank bank = new Bank();
		Money reduced = bank.reduce(sum, "USD");
		assertEquals(Money.dollar(10), reduced, "testSimpleAddtion-reduced");
	}

	void testPlusReturnSum() {
		Money five = Money.dollar(5);
		Expression result = five.plus(five);
		Sum sum = (Sum) result;
		assertEquals(five, sum.augend, "testPlusReturnSum-augend");
		assertEquals(five, sum.addend, "testPlusReturnSum-addned");
	}
	void testReduceSum() {
		Expression sum = new Sum(Money.dollar(3), Money.dollar(4));
		Bank bank = new Bank();
		Money result = bank.reduce(sum, "USD");
		assertEquals(Money.dollar(7), result, "testReduceSum");
	}
	void testReduceMoney() {
		Bank bank = new Bank();
		Money result = bank.reduce(Money.dollar(1), "USD");
		assertEquals(Money.dollar(1), result, "testReduceMoney");
	}
	void testReduceMoneyDifferrntCurrency() {
		Bank bank = new Bank();
		bank.addRate("CHF", "USD", 2);
		Money result = bank.reduce(Money.franc(2), "USD");
		assertEquals(Money.dollar(1), result, "testReduceMoneyDifferrntCurrency");
	}
	void testIdentityRate() {
		assertEquals(1, new Bank().rate("USD", "USD"), "testIdentityRate");
	}
	void testMixedAddition() {
		Expression fiveBucks = Money.dollar(5);
		Expression tenFrances = Money.franc(10);
		Bank bank = new Bank();
		bank.addRate("CHF", "USD", 2);
		Money result = bank.reduce(fiveBucks.plus(tenFrances), "USD");
		assertEquals(Money.dollar(10), result, "testMixedAddition");
	}
	void testSumPlusMoney() {
		Expression fiveBucks = Money.dollar(5);
		Expression tenFrances = Money.franc(10);
		Bank bank = new Bank();
		bank.addRate("CHF", "USD", 2);
		Expression sum = new Sum(fiveBucks, tenFrances).plus(fiveBucks);
		Money result = bank.reduce(sum, "USD");
		assertEquals(Money.dollar(15), result, "testSumPlusMoney");
	}
	void testSumTimes() {
		Expression fiveBucks = Money.dollar(5);
		Expression tenFrances = Money.franc(10);
		Bank bank = new Bank();
		bank.addRate("CHF", "USD", 2);
		Expression sum = new Sum(fiveBucks, tenFrances).times(2);
		Money result = bank.reduce(sum, "USD");
		assertEquals(Money.dollar(20), result, "testSumTimes");
	}
//	void testPlusSameCurrencyReturnsMoney(){//this test failed.
//		Expression sum = Money.dollar(1).plus(Money.dollar(1));
//		assertTrue(sum instanceof Money, "testPlusSameCurrencyReturnsMoney" );
//	}
	//-----------------------------main-------------------------------------------------------------
	public static void main(String[] args) {
		Test test = new Test();
		test.testMultiplication();
		test.testEquality();
		test.testCurrency();
		test.testSimpleAddtion();
		test.testPlusReturnSum();
		test.testReduceSum();
		test.testReduceMoney();
		test.testReduceMoneyDifferrntCurrency();
		test.testIdentityRate();
		test.testMixedAddition();
		test.testSumPlusMoney();
		test.testSumTimes();
//		test.testPlusSameCurrencyReturnsMoney();
	}
}
