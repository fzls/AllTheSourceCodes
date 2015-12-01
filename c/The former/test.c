
#include <stdio.h>

void dgf(long int x)
{
 if (x>=10) dgf(x/10);
 printf("%d ",x%10);
}
int main(void)
{
 long int a;
 scanf("%d",&a);
 dgf(a);
 system("pause");
 return 0;
}