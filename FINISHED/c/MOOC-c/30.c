#include <stdio.h>
#define ROW 20
#define COLUM 20
int main(){
   int m, n, martrix[ROW][COLUM], i, j, flag = 0;
   scanf("%d%d",&m,&n);
   for(i = 0; i < m; i++)
     for(j = 0; j < n; j++)
     scanf("%d",&martrix[i][j]);
   
   for(i = 1; i < m - 1; i++)
     for(j = 1; j < n - 1; j++){
     if( martrix[i][j] <= martrix[i + 1][j] || martrix[i][j] <= martrix[i - 1][j]	 )
     	continue;
     	
     if( martrix[i][j] <= martrix[i][j + 1] || martrix[i][j] <= martrix[i][j - 1]	 )
     	continue;		
     flag = 1;
     printf("%d %d %d\n",martrix[i][j], i + 1, j + 1);
   }
   
   if(!flag)
   	printf("None %d %d\n",m, n);
   	
   system("pause");
   	
}