#include <stdio.h>
int main(){
   int i, del ,s[50], number, j = 0;
   for(i = 0; i < 10; i++){
   	scanf("%d",&number);
   	while(number--)
   	s[j++]=i;
   	}
   s[j] = -1;	
   
   for(i = 0; s[i] != -1; i++)
     if(s[i]){
     	printf("%d",s[i]);
     	del = i;
     	break;
     	}
   
   for(i = 0; s[i] != -1 ; i++)
     if(del != i)
     	printf("%d",s[i]);
   
   system("pause");
     		
}