#include <stdio.h>
double tax;
int main()
{
	printf("input the salary\n");
	scanf("%lf",&salary);
	if (salary<=3500) 
	 {
	 	tax=f(0,0,salary);
	 }
	 else if (salary<=5000) 
	 	{
	 		tax=f(0,0,3500)+f(0.03,0,salary-3500);
	 	}
	 	else if (salary<=8000)
	 	{
	 		tax=f(0,0,3500)+f(0.03,0,1500)+f(0.10,105,salary-5000);
	 	}
	 	else if (salary<=12500)
	 	{
	 		tax=f(0,0,3500)+f(0.03,0,1500)+f(0.10,105,;3000)+f(0.20,555,salary-8000);
	 	}
	 	else if (salary<=38500)
	 	{
	 		tax=f(0,0,3500)+f(0.03,0,1500)+f(0.10,105,;3000)+f(0.20,555,4500)+f(0.25,1005,salary-12500);
	 	}
	 	 else 
	 	 {
	 	 	tax=f(0,0,3500)+f(0.03,0,1500)+f(0.10,105,;3000)+f(0.20,555,4500)+f(0.25,1005,26000)+f(0.45,13505,salary-38500);
	 	 }
	 printf("the tax is %.2f\n",tax);
	 system("pause");	 
	}
double f(double rate,double deduction,double salary){
	 	 tax=rate*(salary-3500)-deduction;
	 	 return tax;
	 }	