#include <stdio.h>
int main()
{
	int i,choice;
	for (i=1; i<=5; i++)
	{
	printf("[1]apples\n[2]pears\n[3]oranges\n[4]grapes\n[0]Exit\n");
	printf("input a number form 0~4\n");
	scanf("%d",&choice);
	if (choice == 0)
		break;
	switch (choice)
	{
		case 1:printf("The price is 3.00\n\n");break;
		case 2:printf("The price is 2.50\n\n");break;
		case 3:printf("The price is 4.10\n\n");break;
		case 4:printf("The price is 10.20\n\n");break;
		default:printf("The price is 0.00\n\n");break;
	}
}
   printf("Thanks\n");
   system("pause");
   return 0;
	}