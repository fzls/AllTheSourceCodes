#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
void main() 
{ 
int computer_number, my_number,count=0; 
srand((unsigned)time(NULL)); 
computer_number=rand()%100+1; 
do 
{ 
count ++;
printf("Please input a number\n"); 
scanf("%d", &my_number); 
if(my_number > computer_number) 
	printf("Too big!\n"); 
else if(my_number < computer_number) 
   printf("Too small!\n"); 
else 
   printf("You have got it!\n");    
} while(computer_number != my_number); 
printf("the total tries are %d\n",count);
} 