//������գ���Ҫ�ı�����������йص���䡣
//����һ��������repeat (0<repeat<10)����repeat���������㣺
//����һ�������� n������1��2/3��3/5��4/7��5/9-6/11+������ǰn��֮�ͣ����ʱ����3λС����
//�������ʾ������������˵��
//����
//3        (repeat=3)
//1        (n=1)
//3        (n=3)
//5        (n=5)
//���
//sum = 1.000
//sum = 0.933
//sum = 0.917


#include <stdio.h>
int main(void)
{
    int flag, i, n;
    int repeat, ri;
    double item, sum;

    scanf("%d", &repeat);
    for(ri = 1; ri <= repeat; ri++){
        scanf("%d", &n);
        sum=0;
        flag=1;
//the original value        
        for(i=1;i<=n;i++){
        	item=(float)flag*i/(2*i-1);
        	sum=sum+item;
        	flag=-flag;
        	}
/*---------*/
      	printf("sum = %.3f\n", sum);
    }
}