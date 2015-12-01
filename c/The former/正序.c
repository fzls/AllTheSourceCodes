#include <stdio.h>
int main(void)
{
    int digit, in, power, temp;
    int repeat, ri,i;
    void zx(int x){
    	if(x>9)zx(x/10);
    		printf("%d ",x%10);
    	}
    

    scanf("%d", &repeat);
    for(ri = 1; ri <= repeat; ri++){
      scanf("%d", &in);
     	printf("\n");
     	zx(in);
     	printf("\n");
   }
   system("pause");
}