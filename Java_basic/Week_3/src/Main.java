import java.util.HashMap;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		HashMap<String, Integer> citynames = new HashMap<String, Integer>();
//		建立城市的哈希表
		String city=in.next();
		int i;
		for(i =0; !city.equals("###");i++){
			citynames.put(city, i);
			city=in.next();
		}
	
//	建立二维数组存储距离信息
		int[][] distance = new int [i][i];
		for(int k=0;k<distance.length;k++){
			for(int j=0;j<distance.length;j++){
			distance[k][j]=in.nextInt();
			}
		}
		

//	利用哈希表查找两个城市的序号，然后利用数组输出
		System.out.println(distance[citynames.get(in.next())][citynames.get(in.next())]);
	}
	
	
}

