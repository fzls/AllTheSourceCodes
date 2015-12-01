#include <stdio.h>
int main(){
   int n, l, i ,j, not1[100],not2[100],key1,key2;
   char c[100][100];
   scanf("%d%d",&n,&l);
   
   for(i = 0; i < n; i++)
   for(j = 0; j <= l; j++)
   scanf("%c",&c[i][j]);
   for(i = 0; i < 100; i++){
   not1[i] = 0;
   not2[i] = 0;
 }

   for(i = 1; i < n; i++)
   for(j = 0; j <= l; j++)
   if(c[i][j] != c[0][j]){
   	not1[i] = 1;
   	key1 = i;
  break;}
  
  for(i = 1; i < n; i++)
   for(j = 0; j <= l; j++)
   if(c[i][j] != c[0][n-1-j]){
   	not1[i] = 1;
   	key2 = i;
  break;}
  
  if(not1[1] == 1 &&not1[2]== 1||not2[1] == 1 &&not2[2]== 1)
  	printf("1\n");
  	else
  	 printf("%d\n",key1+key2+1);

  	}
