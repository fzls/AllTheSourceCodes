#include <stdio.h>
#include <stdlib.h>
/* A simple game of Tic-Tac-Toe. */
#define SPACE ' '
char matrix[3][3] = { /* the tic-tac-toe matrix */
{SPACE, SPACE, SPACE},
{SPACE, SPACE, SPACE},
{SPACE, SPACE, SPACE}
};
void get_computer_move(void), get_player_move(void);
void disp_matrix(void);
char check(void);
int main(void)
{
char done;
printf("This is the game of Tic-Tac-Toe.\n");
printf("You will be playing against the computer.\n");
do {
disp_matrix(); /* display the game board */
get_player_move(); /* get your move */
done = check(); /* see if winner */
if(done!=SPACE) break; /* winner! */
get_computer_move(); /* get computer's move */
done=check(); /* see if winner */
} while(done==SPACE);
if(done=='X') printf("You won!\n");
else printf("I won!!!!\n");
disp_matrix(); /* show final positions */
return 0;
}
/* Input the player's move. */
void get_player_move(void)
{
int x, y;
printf("Enter coordinates for your X.\n");
printf("Row? ");
scanf("%d", &x);
printf("Column? ");
scanf("%d", &y);
x--; y--;
if(x<0 || y<0 || x>2 || y>2 || matrix[x][y]!=SPACE) {
printf("Invalid move, try again.\n");
get_player_move();
}
else matrix[x][y]='X';
}
/* Get the computer's move */
void get_computer_move(void)
{
register int t;
char *p;
p = (char *) matrix;
for(t=0; *p!=SPACE && t<9; ++t) p++;
if(t==9) {
printf("draw\n");
exit(0); /* game over */
}
else *p = 'O';
}
/* Display the game board. */
void disp_matrix(void)
{
int t;
for(t=0; t<3; t++) {
printf(" %c | %c | %c ", matrix[t][0],
matrix[t][1], matrix [t][2]);
if(t!=2) printf("\n---|---|---\n");
}
printf("\n");
}
/* See if there is a winner. */
char check(void)
{
int t;
char *p;
for(t=0; t<3; t++) { /* check rows */
p = &matrix[t][0];
if(*p==*(p+1) && *(p+1)==*(p+2)) return *p;
}
for(t=0; t<3; t++) { /* check columns */
p = &matrix[0][t];
if(*p==*(p+3) && *(p+3)==*(p+6)) return *p;
}
/* test diagonals */
if(matrix[0][0]==matrix[1][1] && matrix[1][1]==matrix[2][2])
return matrix[0][0];
if(matrix[0][2]==matrix[1][1] && matrix[1][1]==matrix[2][0])
return matrix[0][2];
return SPACE;
}