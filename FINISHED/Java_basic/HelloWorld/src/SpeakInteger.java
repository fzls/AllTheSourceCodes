import java.util.*;
public class SpeakInteger {

	private static Scanner in;
	public static void main(String[] args) {
		in = new Scanner(System.in);
		int number;
		number = in.nextInt();
		if(number<0){
			System.out.print("fu ");
			number=-number;
		}
		print_pinyin(number);
		
	}
	static void speak_excp_lastone(int number){
		if(number>0){
			speak_excp_lastone(number/10);
			speak(number%10);
			System.out.print(" ");
		}
	}
	static void speak_lastone(int number){
		speak(number%10);
	}
	static void speak(int digit){
		switch (digit) {
		case 0: System.out.print("ling"); break;
		case 1: System.out.print("yi"); break;
		case 2: System.out.print("er"); break;
		case 3: System.out.print("san"); break;
		case 4: System.out.print("si"); break;
		case 5: System.out.print("wu"); break;
		case 6: System.out.print("liu"); break;
		case 7: System.out.print("qi"); break;
		case 8: System.out.print("ba"); break;
		case 9: System.out.print("jiu"); break;

		}
	}
	static void print_pinyin(int number){
		speak_excp_lastone(number/10);
		speak_lastone(number);
	}
}
