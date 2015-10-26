//this program is to count the number of character iin each word
//and then display it in the form of vertical histogram  

#include <stdio.h>
#define MAXLENS 15
int main(){
   int flag = 0, count = 0, w[MAXLENS + 1], i, j, MAXWORDS;
   char ch;
   for(i = 0;i < MAXLENS + 1; i++)
      w[i] = 0;
   while( (ch = getchar() )!= '#'){
   	if(ch != ' '&& ch != '\n' && ch != '\t'){
   		count++;
   		flag = 1;
   		}
   	else if(flag == 1){
   		w[count]++;
   		count = 0;
   		}
   	}
   if(flag)
   	w[count]++;
   MAXWORDS = 0;
   for(i = 1; i < MAXLENS + 1; i++)
       if(w[i] > MAXWORDS)
       	MAXWORDS = w[i];

   for(i = MAXWORDS; i > 0; i--)	{
   	printf("              ");

     for(j = 1; j <= MAXLENS; j++)
        if(w[j] >= i)
        	printf("#   ");
        else
        	printf("    ");
     printf("\n");

        }
   printf("char nums    :");

   for(i = 1; i <= MAXLENS; i++)
   printf("%-4d",i);

   printf("\n");

   printf("appear times :");

   for(i = 1; i <= MAXLENS; i++)
   printf("%-4d",w[i]);




}
