import java.util.Scanner;
public class oddAndEvenNumber {

	private static Scanner in;

	public static void main(String[] args) {
		in = new Scanner(System.in);
		int odd=0, even=0, number;
		number = in.nextInt();
		while(number != -1){
			if(number>0){
				if(number%2 == 0){
					even++;
				}
				else{
					odd++;
				}
			}
			number =in.nextInt();
		}
		System.out.println(odd+" "+even);
	}

}
