//程序填空，不要改变与输入输出有关的语句。
//输入一个正整数repeat (0<repeat<10)，做repeat次下列运算：
//编写一个程序，输入一个正整数 n，计算 e = 0!＋1!＋2!＋……＋n!，要求定义和调用函数fact(n)计算n!，函数类型是double。
//例：括号内是说明
//输入
//3   (repeat=3)
//1
//2
//4
//输出
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

