#include <stdio.h>
int main(){
    int i, n;
   double s=0, denominator=1, numerator=2;
   scanf("%d",&n);
   for(i=0;i<n;i++){
   	s+=1.0*numerator/denominator;
   	numerator+=denominator;
   	denominator=numerator-denominator;
   	
   	}
   printf("%.2lf\n",s);
   system("pause");
   	
}