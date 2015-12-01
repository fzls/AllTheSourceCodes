//不利用已知的素数信息，判定时判定因数从2判定到根号n
import java.util.Scanner;
public class SumOfPrime_v0 {
//	final static int MaxNumber=100000;
	private static Scanner in;
	public static void main(String[] args) {
		in = new Scanner(System.in);
		int n,m,sum=0,counter=0,i;
//		int[] prime = new int[MaxNumber];
//		prime[0]=2;
		n=in.nextInt();
		m=in.nextInt();
			
		//找到第n-1个素数
		for(i=2;counter<n-1;i++){
			if(isPrime(i)){
//				prime[counter]=i;
				counter++;
			}
		}
		//计算第n个素数到第m个素数的和
		for(;counter<m;i++){
			if(isPrime(i)){
//				prime[counter]=i;
				sum+=i;
				if(counter%5==0)
					System.out.print("\n");
				System.out.print(i+"   ");
				counter++;
			}
		}
		//输出素数和
		System.out.println("\n"+sum);
	}
	//实现isPrime函数,counter 表示number之前共有的素数个数,利用已求素数
	//这里貌似是将prime数组整个传入了方法内，导致最终的运行速度较慢，故而下次等了解如何引用传入后再做改变
//	public static boolean isPrime(int number, int[] prime){
//		int i,sqrt;
//		boolean isprime=true;
//		sqrt =(int) Math.sqrt(number);
//		if(number==0||number==1){
//			isprime=false;
//		}
//		for(i=0;prime[i]<=sqrt;i++){
//			if(number%(prime[i]) == 0&&number >2){
//				isprime=false;
//			}
//		}
//		return isprime;
//	}
	public static boolean isPrime(int number){
		int i,sqrt;
		boolean isprime=true;
		sqrt =(int) Math.sqrt(number);
		if(number==0||number==1){
			isprime=false;
		}
		for(i=2;i<=sqrt;i++){
			if(number%i == 0){
				isprime=false;
			}
		}
		return isprime;
		
	}
}