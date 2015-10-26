#include <stdio.h>
#include <math.h>
/* ���������� */
int isPrime(int n) {
    int i, limit, flag = 1;
    if(n <= 1)
        flag = 0;
    else if(n == 2)
        flag = 1;
    else if(n % 2 == 0)
        flag = 0;
    else {
        limit = sqrt(n) + 1;
        for(i = 3; i <= limit; i += 2) {
            if(n % i == 0) {
                flag = 0;
                break;
            }
        }
    }
    return flag;
}
int main(void) {
	int a[10001];
    int i, count = 1;
    int start, end;
    scanf("%d%d", &start, &end);
    /* �����1������end�����������������a�� */
    for(i = 2; count <= end; ++i) {
        if (isPrime(i)) {
        	a[count] = i;
        	++count;
    	}
    }
    /* �����start������end������ */
    count = 1;
    for(i = start; i <= end; ++i) {
    	printf("%d", a[i]);
        if(count % 10 != 0 && i < end)
            printf(" ");
        if(count % 10 == 0)
            printf("\n");
		++count;
	}
    return 0;
}
