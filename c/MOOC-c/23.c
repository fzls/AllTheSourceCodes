#include <stdio.h>
//大数可以选择用字符数组来进行表示
//对于一个问题，可以分步解决，每一步通过一个函数得以实现
#include <math.h>
char *yin ( int digit){
	switch(digit){
	   case 0: return "ling";break;
	   case 1: return "yi";break;
	   case 2: return "er";break;
	   case 3: return "san";break;
	   case 4: return "si";break;
	   case 5: return "wu";break;
	   case 6: return "liu";break;
	   case 7: return "qi";break;
	   case 8: return "ba";break;
	   case 9: return "jiu";break;
	}

	}

void ping(int n){
	int count = 0, i, j;
	int k = n;
	while(k > 0){
		++count;
		k/=10;
		}
	j = count;
	for(i = 1; i <= count; i++, j--)
		if(j > 1)
			printf("%s ", yin( ( n/(int)(pow(10, count - i)) ) % 10 ));
		else
			printf("%s", yin(  (n/(int)(pow(10, count - i)) ) %10 ));
	}

int main(){
   char str[1000];
   int sum=0, i;
   gets(str);
   if((str[0]-'0') == 0)
   	printf("ling");
   else{
     for(i = 0; str[i] != 0; i++)
        sum += (str[i] - '0');
     ping( sum );
     
     }
   system("pause");
     
}
