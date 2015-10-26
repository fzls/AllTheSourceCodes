import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		Fraction a = new Fraction(in.nextInt(), in.nextInt());
		Fraction b = new Fraction(in.nextInt(), in.nextInt());
		a.print();
		b.print();
		a.plus(b).print();
		a.multiply(b).plus(new Fraction(5, 6)).print();
		a.print();
		b.print();
		in.close();
	}

}

class Fraction {
	private int a;
	private int b;
	Fraction(int a, int b) {

		int gcd = 1;
		for (int i = 2; i <= a && i <= b; i++) {
			if (a % i == 0 && b % i == 0) {
				gcd = i;
			}
		}
		a /= gcd;
		b /= gcd;

		this.a = a;
		this.b = b;
	}
	double toDouble() {
		return 1.0 * a / b;
	}
	Fraction plus(Fraction r) {
		int a_, b_;
		a_ = this.a * r.b + this.b * r.a;
		b_ = this.b * r.b;
		Fraction sum = new Fraction(a_, b_);
		return sum;
	}
	Fraction multiply(Fraction r) {
		int a_, b_;
		a_ = this.a * r.a ;
		b_ = this.b * r.b;
		Fraction product = new Fraction(a_, b_);
		return product;
	}
	void print() {
		if (a == b) {
			System.out.println("1");
		} else {
			System.out.println(a + "/" + b);
		}
	}
}
