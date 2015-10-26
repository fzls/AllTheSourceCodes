import java.util.Scanner;

public class temperatureTransformation {

	private static Scanner in;

	public static void main(String[] args) {
		in = new Scanner(System.in);
	int f;
	f = in.nextInt();
	System.out.println((int)((f-32)*5.0/9));
		
	}

}
