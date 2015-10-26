#include <stdio.h>
int main(void)
{
    int time1, time2, hour, minutes,t;

   scanf("%d%d", &time1, &time2);
   t=time2%100+time2/100*60-time1%100-time1/100*60;
   hour=t/60;
   minutes=t%60;
   printf("The train journey time is %d hours %d minutes.\n", hour, minutes);
system("pause");}