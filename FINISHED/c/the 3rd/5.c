//������գ���Ҫ�ı�����������йص���䡣
//����һ��������repeat (0<repeat<10)����repeat���������㣺
//��дһ����������һ�������� n������ e = 0!��1!��2!��������n!��Ҫ����͵��ú���fact(n)����n!������������double��
//������������˵��
//����
//3   (repeat=3)
//1
//2
//4
//���
//sum = 2
//sum = 4
//sum = 34


#include <stdio.h>
double fact(int n)
{
	double y;
	int j;
	y=1;
	for(j=1;j<=n;j++){
		y=y*j;
		}
		return y;
	}
int main(void)
{
    int i,n;
    int repeat, ri;
    double sum;
    double fact(int n);

    scanf("%d", &repeat);
    for(ri = 1; ri <= repeat; ri++){
        scanf("%d", &n);
        sum=0;
        for(i=0;i<=n;i++){
        	sum=sum+fact(i);}
/*---------*/
        printf("sum = %.0f\n", sum);
    }
}

/*---------*/

