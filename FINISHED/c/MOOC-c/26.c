#include <stdio.h>
#include <math.h>
#define MAXNUM 10001
int prime( int n ){
	int i, limit = sqrt(n) +1;
	for(i = 2;i < limit; i++)
	   if( n % i == 0)
	   	return 0;
	return 1;
	}
void assign( int *p, int n){
	int i, j=3;
	for(i = 2; i <= n; i++)

	   while(1){
	   if( prime(j) ){
	   	*(p+i) = j;
	   	j += 2;
	   	break;
	  }
	   else
	   		j += 2;
	  }


	}
int main(){
   int m, n, i, p[MAXNUM], *pn;
   pn = p;
   
   pn[1] = 2;
   scanf("%d%d",&m,&n);
   assign( pn , n);
   for(i = m;i <= n; i++){
       	printf("%d",pn[i]);
       	if( (i - m) % 10 == 9)
       		printf("\n");
        else if( i < n)
        	printf(" ");
      }
   
   system("pause");

}
