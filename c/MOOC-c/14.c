#include <stdio.h>
int main(){
   int random, maxtime, user_input, count=0;
   scanf("%d%d%d",&random,&maxtime,&user_input);
   while(++count, user_input!=random){
   	if(user_input<0){
   		printf("Game Over\n");
   		return 0;
   		}
   	if(user_input > random)
   		printf("Too big\n");
   	else
   		printf("Too small\n");
   			
   	if(count>=maxtime){
   		printf("Game Over\n");
   		return 0;
   		}
   	scanf("%d",&user_input);
   		
   	}
   if(count == 1)
   	printf("Bingo!\n");
   else if(count	<= 3)
   	printf("Lucky You!\n");
   else
     printf("Good Guess!\n");
   system("pause");
   	
}