//������գ���Ҫ�ı�����������йص���䡣
//����һ��������repeat (0<repeat<10)����repeat���������㣺
//����һ�������� n������1��1/4��1/7��1/10��������ǰ n ��֮�ͣ����ʱ����3λС����
//�������ʾ������������˵��
//����
//2   (repeat=2)
//3
//10
//���
//sum = 0.893
//sum = 0.819
//

#include <stdio.h>
int main(void)
{
    int flag, i, n, t;
    int repeat, ri;
    double item, sum;

    scanf("%d", &repeat);
    
    for(ri = 1; ri <= repeat; ri++){
        scanf("%d", &n);
        sum=0;
        flag=1;
//      pay attention to the original value

        for(i=1;i<=n;i++){
        item=(float)flag*1/(3*i-2);
//        remeber to replace the n with i
        sum=sum+item;
        flag=-flag;
/*---------*/}
      	printf("sum = %.3f\n", sum);
    }
}