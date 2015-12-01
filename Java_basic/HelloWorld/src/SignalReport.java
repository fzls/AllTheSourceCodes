import java.util.Scanner;

public class SignalReport {

	private static Scanner in;

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		in = new Scanner(System.in);
	int signal;
	signal = in.nextInt();
	switch(signal%10){
	case 1: System.out.print("Faint signals, barely perceptible, "); break;
	case 2: System.out.print("Very weak signals,"); break;
	case 3: System.out.print("Weak signals,"); break;
	case 4: System.out.print("Fair signals,"); break;
	case 5: System.out.print("Fairly good signals,"); break;
	case 6: System.out.print("Good signals,"); break;
	case 7: System.out.print("Moderately strong signals,"); break;
	case 8: System.out.print("Strong signals,"); break;
	case 9: System.out.print("Strong signals,"); break;
	}
	switch(signal/10){
	case 1: System.out.print("Unreadable"); break;
	case 2: System.out.print("Barely readable, occasional words distinguishable"); break;
	case 3: System.out.print("Readable with considerable difficulty"); break;
	case 4: System.out.print("Readable with practically no difficulty"); break;
	case 5: System.out.print("Perfectly readable"); break;
	}
	
	}

}
