import java.util.*;
public class characteristicValueOfNumber {

	private static Scanner in;

	public static void main(String[] args) {
		in = new Scanner(System.in);
		int number, charValue=0,count=0;
		number = in.nextInt();
		do{
			if((number%10 -(count+1))%2 == 0){
				charValue+=(int)Math.pow(2, count);
			}
			count++;
			number/=10;
		}while(number >0);
		System.out.println(charValue);
	}

}
