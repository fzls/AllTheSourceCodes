import java.util.Scanner;

public class TimeTransform {
	private static Scanner in;

	public static void main(String[] args) {
		in = new Scanner(System.in);
	int time, hour, minute;
	time = in.nextInt();
	time = (time+2400-800)%2400;
	hour = time /100;
	minute=time%100;
	if(hour>0)
		System.out.print(hour);
	if(minute<10)
		System.out.print("0"+minute);
	else 
		System.out.print(minute);
	
	
	
	
	
	}

}
