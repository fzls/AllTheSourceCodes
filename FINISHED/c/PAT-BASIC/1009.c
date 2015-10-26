#include <stdio.h>
#include <string.h>
int main(){
   char s[81];
   int i, j, lenth;
   gets(s);

  
   i = lenth = strlen(s) - 1;
   
   while(i >= 0){
   for(; i >= 0; i--)
   if(s[i] == ' ')
        break;
  
   for(j = i + 1;i < lenth && s[j] != 0 && s[j] != ' '; j++)
   printf("%c",s[j]);
   
   //最初i停留在空格处，再次进入循环时，第一个循环直接跳过，此时仍在空格处，导
   //致后续循环输出第一次输出的单词，所以应该在第一次循环后对i进行一次自减，这样
   //才能保证循环正常运行，之后只需考虑最后一个单词的输出问题，对其进行分析即可
   while(i >= 0 && s[i] == ' ')
   printf("%c",s[i--]);
 }
 

}
