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
   
   //���iͣ���ڿո񴦣��ٴν���ѭ��ʱ����һ��ѭ��ֱ����������ʱ���ڿո񴦣���
   //�º���ѭ�������һ������ĵ��ʣ�����Ӧ���ڵ�һ��ѭ�����i����һ���Լ�������
   //���ܱ�֤ѭ���������У�֮��ֻ�迼�����һ�����ʵ�������⣬������з�������
   while(i >= 0 && s[i] == ' ')
   printf("%c",s[i--]);
 }
 

}
