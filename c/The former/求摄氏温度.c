#include <stdio.h>
int main()
{
	int c,f;
	printf("请输入一个华氏温度值=");
	scanf("%d",&f);
	c=5*(f-32)/9;
   printf("摄氏温度为%d\n",c);
	system("pause");
	return 0;
}
