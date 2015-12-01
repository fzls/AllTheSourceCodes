#include <stdio.h>
int main(int argc, char *argv[])
{
if(argc!=2) {
printf("You forgot to type your name\n");
return 1;
}
printf("Hello %s", argv[1]);
return 0;
system("pause");
}