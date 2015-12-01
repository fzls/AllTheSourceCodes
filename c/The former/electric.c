#include <stdio.h>
#include <time.h>
int main(void)
{   
    int e,ri;
    double cost;

    scanf("%d", &e);
    for(ri = 1; ri <= e; ri++){
        if(ri<=50)
        	cost=0.53*ri;
        else 
        	cost=0.53*50+0.58*(ri-50);	
        printf("when use %4d the cost is %6.2f\r", ri,cost);
        sleep(10);
    } 
    system("pause");
}
