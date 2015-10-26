/* Display a software timer. */
#include <stdio.h>
#include <conio.h>
#include <time.h>

#define DELAY 12800000
struct my_time {
int hours;
int minutes;
int seconds;
};
void update(struct my_time *t), display(struct my_time *t);
void mydelay(void);
int main(void)
{
struct my_time systime;
systime.hours = 0;
systime.minutes = 0;
systime.seconds = 0;
for(;;) {
update(&systime);
display(&systime);
if(kbhit()) return 0;
}
}
void update(struct my_time *t)
{
t->seconds++;
if(t->seconds==60) {
t->seconds = 0;
t->minutes++;
}
if(t->minutes==60) {
t->minutes = 0;
t->hours++;
}
if(t->hours==24) t->hours = 0;
mydelay();
}
void display(struct my_time *t)
{
printf("%02d:%02d:%02d\r", t->hours, t->minutes, t->seconds);
}
void mydelay(void)
{
long int t;
for(t=1; t<DELAY; ++t);
}