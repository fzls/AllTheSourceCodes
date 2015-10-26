#include <stdio.h>
int main(void){
     long int N,i,count;
     scanf("%d",&N);
     printf("%d=",N);
     if(N==1){printf("1");goto end;}
     for(i=2;N!=1;i++){
     	count=0;
     	while(N%i==0){
     		count++;
     		N/=i;
     		}
     		if(count==1)
     			printf("%d*",i);
     	  else if(count>1)
     	     printf("%d^%d * ",i,count);
     	}
     	printf("\b\b\b   ");
     end:;
     	printf("\n");
     system("pause");	
     return 0;
}