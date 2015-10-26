#include <stdio.h>
#include <string.h>
void stob(int *p);
void btos(int *p);
int main(){
   int a[6],*p,i,ri;
   char choice;
   for(ri=0;ri<100;ri++){
   for(i=0;i<5;i++)
   scanf("%d",&a[i]);
   a[i]=-1;
   p=a;
   getchar();
   scanf("%c",&choice);
   switch(choice){
      case 'A': stob(p);break;
      case 'D': btos(p);break;
      default:;
   }
   }
}
void stob(int *p){
	int i,k,index,t;
	for(i=0;*(p+i)!=-1;i++){
		index=i;
		for(k=i;*(p+k)!=-1;k++)
		if(*(p+k)<*(p+index))
			index=k;
		t=*(p+index);*(p+index)=*(p+i);*(p+i)=t;
		}
	for(i=0;*(p+i)!=-1;i++)
	printf("%d ",*(p+i));
	}

void btos(int *p){
	int i,k,index,t;
	for(i=0;*(p+i)!=-1;i++){
		index=i;
		for(k=i;*(p+k)!=-1;k++)
		if(*(p+k)>*(p+index))
			index=k;
		t=*(p+index);*(p+index)=*(p+i);*(p+i)=t;
		}
	for(i=0;*(p+i)!=-1;i++)
	printf("%d ",*(p+i));
	}
