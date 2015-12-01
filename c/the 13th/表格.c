#include<stdio.h>
#include<string.h>
void main()
{
	int i,ri,repeat,flag;
	char *date[]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
	char str[80];

	scanf("%d",&repeat);
	getchar();
	for(ri=1;ri<=repeat;ri++){
		scanf("%s",str);
		flag=0;
		for(i=0;*(date+i)!='\0';i++)
		if(strcmp(str,*(date+i))==0){
			printf("%d\n",i+1);
			flag=1;
			break;
			}
		if(flag==0)
			printf("-1\n");

	}
	system("pause");

}
