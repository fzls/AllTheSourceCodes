/* A simple inventory program using an array of structures */
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
struct inv {
char item[30];
float cost;
int on_hand;
} inv_info[MAX];
void init_list(void), list(void), del(void);
void enter(void);
int menu_select(void), find_free(void);
int main(void)
{
char choice;
init_list(); /* initialize the structure array */
for(;;) {
choice = menu_select();
switch(choice) {
case 1: enter();
break;
case 2: del();
break;
case 3: list();
break;
case 4: return 0;
}
}
}
/* Initialize the structure array. */
void init_list(void)
{
register int t;
for(t=0; t<MAX; ++t) inv_info[t].item[0] = '\0';
}
/* Input the user's selection. */
int menu_select(void)
{
char s[80];
int c;
printf("\n");
printf("1. Enter an item\n");
printf("2. Remove an item\n");
printf("3. List the inventory\n");
printf("4. Quit\n");
do {
printf("\nEnter your choice: ");
gets(s);
c = atoi(s);
} while(c<0 || c>4);
return c;
}
/* Input the inventory information. */
void enter(void)
{
int slot;
slot = find_free();
if(slot == -1) {
printf("\nList Full");
return;
}
printf("Enter item: ");
gets(inv_info[slot].item);
printf("Enter cost: ");
scanf("%f", &inv_info[slot].cost);
printf("Enter number on hand: ");
scanf("%d%*c", &inv_info[slot].on_hand);
}
/* Return the index of the first unused array
location or -1 if no free locations exist.
*/
int find_free(void)
{
register int t;
for(t=0; inv_info[t].item[0] && t<MAX; ++t) ;
if(t == MAX) return -1; /* no slots free */
return t;
}
/* Remove an item from the list. */
void del(void)
{
register int slot;
char s[80];
printf("enter record #: ");
gets(s);
slot = atoi(s);
if(slot >= 0 && slot < MAX) inv_info[slot].item[0] = '\0';
}
/* Display the list on the screen. */
void list(void)
{
register int t;
for(t=0; t<MAX; ++t) {
if(inv_info[t].item[0]) {
printf("Item: %s\n", inv_info[t].item);
printf("Cost: %f\n", inv_info[t].cost);
printf("On hand: %d\n\n", inv_info[t].on_hand);
}
}
printf("\n\n");
}
