/* This program appears to act as a command-prompt gone wild. It
displays the command prompt but displays every character
the user types as the next letter in the alphabet.
*/
#include <stdio.h>
#include <conio.h>
int main(void)
{
char ch;
do {
printf("C>");
for(;;) {
ch = getch(); /* read chars without echo */
if(ch=='\r' || ch==1) {
printf("\n");
break;
}
putchar(ch+1);
}
} while(ch!=1) ; /* exit on control-A */
return 0;
}