#include <stdio.h>
#include<stdlib.h>
int main()
{
	FILE *stream;
	if ((stream = freopen("text.txt", "w", stdout)) == NULL)
		exit(-1);
	printf("this is a test");  // 输出到了文件中
	stream = freopen("CON", "w", stdout); //
	printf("And now back to the console once again\n");//输出到了控制台上
	system("pause");

}
