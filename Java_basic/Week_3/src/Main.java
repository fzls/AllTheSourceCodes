import java.util.HashMap;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		HashMap<String, Integer> citynames = new HashMap<String, Integer>();
//		�������еĹ�ϣ��
		String city=in.next();
		int i;
		for(i =0; !city.equals("###");i++){
			citynames.put(city, i);
			city=in.next();
		}
	
//	������ά����洢������Ϣ
		int[][] distance = new int [i][i];
		for(int k=0;k<distance.length;k++){
			for(int j=0;j<distance.length;j++){
			distance[k][j]=in.nextInt();
			}
		}
		

//	���ù�ϣ������������е���ţ�Ȼ�������������
		System.out.println(distance[citynames.get(in.next())][citynames.get(in.next())]);
	}
	
	
}

