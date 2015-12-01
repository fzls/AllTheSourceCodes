#include <stdio.h>
int main(void)
{
    int gcd, lcm, m, n;  
    int repeat, ri;  

    scanf("%d", &repeat);
    for(ri = 1; ri <= repeat; ri++){
        scanf("%d", &m);
        scanf("%d", &n);
        if(m <= 0 || n <= 0)
            printf("m <= 0 or n <= 0");
        else{
        	for(lcm=m;lcm%m!=0||lcm%n!=0;lcm++);
        	for(gcd=m;m%gcd!=0||n%gcd!=0;gcd--);
            printf("%d is the least common multiple of %d and %d, %d is the greatest common divisor of %d and %d.\n", lcm, m, n, gcd, m, n);
        }
    }
}

 
