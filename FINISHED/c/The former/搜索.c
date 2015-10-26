#include <stdio.h>
void search (int *, int n, int x);
int main(){
   int a[10], x, i;
   for(i=0;i<10;i++)
   scanf("%d",&a[i]);
   scanf("%d",&x);
   search(a, 10, x);
   system("pause");
   	
}
void search (int *a, int n, int x){
	int i, flag=0;
	for(i=0;i<n;i++)
		if(*(a+i)==x){
			printf("%d\n",i);
		flag=1;
		break;
		}
	if(!flag)	
		printf("-1\n");
	
	}