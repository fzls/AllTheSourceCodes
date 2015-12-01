#include <stdio.h>
int main(){
   char s[100];
   int count = 0,flag =0, i = 0, flag2 = 0,count2= 0;
   while( (s[i] = getchar() ) != '.' ){
   	if(s[i] != ' '&&s[i] != '\n'){
   		if(flag ==0)
   			 count2++;
   		 flag =1;
   		}
   	else
   	  flag = 0;
   		i++;
   	}
   s[++i] = '\0';
   if(i>=2){
       if(s[i-2] == ' '||s[i-2] == '\n')
           flag2 = 1;}
   	flag =0;
   for(i = 0; s[i] != '.'; i++){
   	if( s[i] != ' '&&s[i] != '\n' ){

   		++count;
   		flag = 1;
   		}
   	else if(flag == 1 ){
   		if(count2 == 1 && flag2 == 1)
   			printf("%d",count);
   		else
   			printf("%d ",count);
   		count2--;
   		count = 0;
   		flag = 0;
   	}
   	}
   if( flag2 == 0 && i != 0)
   printf("%d",count);
   system("pause");

}
