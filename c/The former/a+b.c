#include <stdio.h>
int main(void){
	  long int a,b,sum,i,j,k,flag,ri;
	  char str[100],num[100];
	  for(ri=1;ri<=1000;ri++){
	  	i=0;j=0;flag=0;
     scanf("%d%d",&a,&b);
     sum=a+b;
     if(sum<0){
     	flag=1;
     	sum=-sum;
     	}
     do{
     	str[i]=sum%10+'0';
     	sum/=10;
     	i++;
     	}while(sum!=0);
     	str[i]=0;
     	for(i=0;str[i]!=0;i++){
     		num[j]=str[i];
     	if(i%3==2&&str[i+1]!=0){
     		num[j+1]=',';
     		j+=2;
     	}
     	else 
     		j++;
     	}
     	if(flag==1)
     		printf("-");
     	for(k=j-1;k>=0;k--)
     	printf("%c",num[k]);
       printf("\n");
    	}
     system("pause");
     return 0;
}