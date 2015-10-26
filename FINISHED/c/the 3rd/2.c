//程序填空，不要改变与输入输出有关的语句。
////输入一个正整数repeat (0<repeat<10)，做repeat次下列运算：
//读入2个整数 lower 和 upper，输出一张华氏—摄氏温度转换表，华氏温度的取值范围是[lower, upper]，每次增加2F。
//计算公式：c = 5 * (f - 32) / 9，其中：c表示摄氏温度，f表示华氏温度。
//输出请使用语句 printf("%3.0f %6.1f\n", fahr, celsius);
//输入输出示例：括号内是说明
//输入
//2       (repeat=2)
//32 35   (lower=32,upper=35)
//40 30   (lower=40,upper=30)
//输出
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
