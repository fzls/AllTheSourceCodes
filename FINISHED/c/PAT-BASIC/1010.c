#include <stdio.h>
int main(){
   int xi[10000], zhi[10000], i, end;
   char c;

   i = 0;
   while(1){
   	scanf("%d",&xi[i]);
   	scanf("%d",&zhi[i]);
   	++i;
   	if( ( c = getchar() ) == '\n')
   		break;
   	}

   end = i;
   if( zhi[end - 1] == 0)
   	--end;

  for(i = 0; i < end; i++){
  printf("%d %d", xi[i] * zhi[i] , zhi[i] - 1);
  if(!(i == end - 1))
  	printf(" ");
  }
  if(!zhi[0])
  	printf("0 0\n");
  	


  system("pause");
  
}
