#include <stdio.h>
int Ack(int m, int n);
int main(void)
{
   int m,n;
   int result;
   int i,repeat;

   scanf("%d",&repeat);
   for(i=1; i<=repeat; i++)
   {
       scanf("%d%d", &m, &n);
       result = Ack(m,n);
       printf("Ackerman(%d,%d)=%d\n", m, n, result);
   }
}
int Ack(int m, int n){
	int result;
	if(m==0)
		result=n+1;
		else if (n==0) 
			{
				result=Ack(m-1,1);
			}
			else 
				result = Ack(m-1, Ack(m,n-1));
				return result;
	}



