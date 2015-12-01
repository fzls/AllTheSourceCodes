#include <stdio.h>
int main(){
   int n, m, a[1000], i;
   scanf("%d%d",&n, &m);
   m = m % n;
   for(i = 0 ; i < n; i++)
   scanf("%d",&a[i]);

   for(i = n - 1 + m; i >= m; i--)
   a[i] = a[i - m];

   for(i = 0; i < m; i++)
   a[i] = a[n + i];

   for(i = 0; i < n; i++){
   	printf("%d",a[i]);
   	if(i < n - 1)
   		printf(" ");


   	}

}
