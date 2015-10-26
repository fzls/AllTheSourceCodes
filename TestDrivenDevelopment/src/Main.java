
public class Main {

	public static void main(String[] args) {
		Money fiveBucks = Money.dollar(5);
		Money fiveFrances = Money.franc(5);
		Bank bank = new Bank();
		bank.addRate("CHF", "USD", 2);
		bank.addRate("USD", "CHF", 1);
		Expression sum = new Sum(fiveBucks, fiveFrances).times(1);
		Money result = bank.reduce(sum, "CHF");
		System.out.println(fiveBucks);
		System.out.println(fiveFrances);
		System.out.println(result);
	}

}
