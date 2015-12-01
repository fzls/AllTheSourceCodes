import java.util.Scanner;

public class Main {
	private static Scanner in;

	public static void main(String[] args) {
		int foot;
		int inch;
		in = new Scanner(System.in);
		foot=in.nextInt();
		inch=in.nextInt();
		System.out.println("foot="+foot+"\tinch="+inch);
		System.out.println((int)((foot+(double)inch/12)*0.3048*100));
		
	}
}
