//����֪�����������������ڣ����ж��µ�����ʱֻ���ж���2������n�е��������ɣ�����Ч����������
import java.util.Scanner;
public class SumOfPrime {
	final static int MaxNumber=10000000;
	private static Scanner in;
	public static void main(String[] args) {
		in = new Scanner(System.in);
		int n,m,sum=0,counter=0,i;
		int[] prime = new int[MaxNumber];
		prime[0]=2;
		counter++;
		n=in.nextInt();
		m=in.nextInt();
		if(n==1){
			sum+=2;
			System.out.print("2   ");
		}
			
		//�ҵ���n-1������
		for(i=3;counter<n-1;i++){
			if(isPrime(i,prime)){
				prime[counter]=i;
				counter++;
			}
		}
		//�����n����������m�������ĺ�
		for(;counter<m;i++){
			if(isPrime(i,prime)){
				prime[counter]=i;
				sum+=i;
				if(counter%5==0)
					System.out.print("\n");
				System.out.print(i+"   ");
				counter++;
			}
		}
		//���������
		System.out.println("\n"+sum);
	}
	//ʵ��isPrime����,counter ��ʾnumber֮ǰ���е���������,������������
	//����ò���ǽ�prime�������������˷����ڣ��������յ������ٶȽ������ʶ��´ε��˽�������ô���������ı�
	public static boolean isPrime(int number, int[] prime){
		int i,sqrt;
		boolean isprime=true;
		sqrt =(int) Math.sqrt(number);
		if(number==0||number==1){
			isprime=false;
		}
		for(i=0;prime[i]<=sqrt;i++){
			if(number%(prime[i]) == 0&&number >2){
				isprime=false;
			}
		}
		return isprime;
	}
//	public static boolean isPrime(int number){
//		int i,sqrt;
//		boolean isprime=true;
//		sqrt =(int) Math.sqrt(number);
//		if(number==0||number==1){
//			isprime=false;
//		}
//		for(i=2;i<=sqrt;i++){
//			if(number%i == 0){
//				isprime=false;
//			}
//		}
//		return isprime;
//		
//	}
}