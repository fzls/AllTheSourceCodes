#include <stdio.h>
int main(){
   int a[3],i,j,count;
   for(i=0;i<3;i++)
   scanf("%d",&a[i]);
   for(i=0;i<3;i++){
   	count=0;
   for(j=0;j<3;j++)
   if(a[i]==a[j])
   	count++;
   if(count==1){
   	printf("%c\n",'A'+i);
   	break;
   	
   	}
   		
 }
 system("pause");
 
}