#include <stdio.h>
#include <math.h>
int main(void) {
	int n, temp, count = 0, bit;
	scanf("%d", &n);
	if(n == 0)
		printf("ling\n");
	else {
		if(n < 0) {
			n = -n;
			printf("fu ");
		}
		temp = n;
		while(temp > 0) {	/* 计算整数位数 */ 
			++count;
			temp /= 10;
		}
		--count;
		while(count >= 0) {
			/* 分离数字 */ 
			bit = (n / (int)pow(10, count)) % 10;
			switch(bit) {
				case 0:
					printf("ling");
					break;
				case 1:
					printf("yi");
					break;
				case 2:
					printf("er");
					break;
				case 3:
					printf("san");
					break;
				case 4:
					printf("si");
					break;
				case 5:
					printf("wu");
					break;
				case 6:
					printf("liu");
					break;
				case 7:
					printf("qi");
					break;
				case 8:
					printf("ba");
					break;
				case 9:
					printf("jiu");
					break;
			}
			if(count != 0)
				printf(" ");
			--count;
		}
		printf("\n");
	}
	return 0;
}