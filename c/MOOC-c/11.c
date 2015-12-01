#include <stdio.h>
#include <math.h>
int main(){
   int N, i, s, t, low=1, high, digit,j;
   scanf("%d",&N);
   for(i=1;i<N;i++)
       low*=10;
   high = low * 10;
   for(i=low;i<high;i++){
   	t=i;
   	s=0;
   	while(t!=0){
   		digit=1;
   		for(j=1;j<N+1;j++)
   		   digit*=(t%10);
   		s+=digit;
   		t/=10;
   		}
   	if(s==i)
   		printf("%d\n",i);



   	}

}
