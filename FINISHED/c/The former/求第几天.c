#include "stdio.h"
int main(void)
{
    int day, day_year, month, year;
    int repeat, ri;

    int day_of_year(int year, int month, int day);

    scanf("%d", &repeat);
    for(ri = 1; ri <= repeat; ri++){
        scanf("%d%d%d", &year, &month, &day);
        day_year=day_of_year(year,month,day);
        printf("days of year: %d\n", day_year);
    }
}
int day_of_year(int year, int month, int day){
	int i;
	int a[13],result=0;
	a[1]=a[3]=a[5]=a[7]=a[8]=a[10]=a[12]=31;
	a[4]=a[6]=a[9]=a[11]=30;
	if(year%4==0&&year%100!=0||year%400==0)
		a[2]=29;
	else 
		a[2]=28;
	for(i=1;i<month;i++)
   result+=a[i];
	result+=day;	
	return result;
	}
