#include <stdio.h>
int main(){
   int n, number[10], i, in, index = 0, count = 0;
   scanf("%d",&n);
   for(i = 0; i < 10; i++)
   number[i] = 0;
   
   for(i = 0; i < n; i++){       //计算各数出现的次数并放到number数组中
   	scanf("%d",&in);
   	while(in > 0){
   		number[in % 10]++;
   		in /= 10;
   		}
   	}
   	
   for(i = 0; i < 10; i++)
   if(number[i] > number[index])
   	index = i;
   	
   printf("%d: ",number[index]);
   
   for(i = 0; i < 10; i++)
   if(number[i] == number[index])
   	count++;
   	
   for(i = 0; i < 10; i++)
   if(number[i] == number[index])
   	if(count-- > 1)
   		printf("%d ",i);
   	else
   	  printf("%d",i);
   	  	
   system("pause");
   	
   	
}