/* fflush example */
#include <stdio.h>
int main()
{
   int n;
   char string[80];
   for ( n=0 ; n<2 ; n++ )
   {
     printf( "Enter some words: " );
     scanf( "%s", string );
     printf( "The first word you entered is : %s\n", string );
     fflush ( stdin );
   }
   system("pause");
   return 0;
}
