//������գ���Ҫ�ı�����������йص���䡣
////����һ��������repeat (0<repeat<10)����repeat���������㣺
//����2������ lower �� upper�����һ�Ż��ϡ������¶�ת���������¶ȵ�ȡֵ��Χ��[lower, upper]��ÿ������2F��
//���㹫ʽ��c = 5 * (f - 32) / 9�����У�c��ʾ�����¶ȣ�f��ʾ�����¶ȡ�
//�����ʹ����� printf("%3.0f %6.1f\n", fahr, celsius);
//�������ʾ������������˵��
//����
//2       (repeat=2)
//32 35   (lower=32,upper=35)
//40 30   (lower=40,upper=30)
//���
//fahr  celsius
// 32    0.0
// 34    1.1
//fahr  celsius

#include <stdio.h>
double fact(int n)
{
	double y;
	int j;
//	to define a function ,we don't need to scanf the n.
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
