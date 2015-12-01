#include<stdio.h>
#include<string.h>

#define N 100
int main(int argc, char *argv[])
{
	char str[N];
	int i, n, flag, flag2;
	int A1, A2, A3; //分别记录P之前A的个数，PT之间A的个数，T之后A的个数
	scanf("%d", &n);
	getchar();
	while (n--)
	{
		A1 = 0;
		A2 = 0;
		A3 = 0;
		flag = flag2 = 1;
		scanf("%s", str);
		for (i = 0; str[i] != '\0'; i++)
			if (str[i] != 'P' && str[i] != 'A' && str[i] != 'T')
				flag2 = 0;
		for (i = 0; str[i] != 'P'; i++)
			A1++;
		for (i = i + 1; str[i] != 'T'; i++)
			A2++;
		for (i = i + 1; str[i] != '\0'; i++)
			A3++;
		if (flag2 == 0)
		{
			printf("NO\n");
			continue;
		}
		if (A1 == 0 && A3 == 0 && A2 >= 1)
			flag = 1;
		else if (A1 != 0 && A2 == A3 / A1)
			flag = 1;
		else
			flag = 0;
		if (flag)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}

