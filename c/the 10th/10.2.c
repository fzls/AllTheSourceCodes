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
	int a[13],i,days=0;
	int *p= a;
	*(p+1)=*(p+3)=*(p+5)=*(p+7)=*(p+8)=*(p+10)=*(p+12)=31;
	*(p+4)=*(p+6)=*(p+9)=*(p+11)=30;
	if(year%4==0&&year%100!=0||year%400==0)
		*(p+2)=29;
	else 
		*(p+2)=28;	
	for(i=1;i<month;i++)
	   days+=*(p+i);
	return days+day;   
	}