#include <stdio.h>//the realization of the function replace
#include <stdlib.h>
#define MAXSIZE 100
#define INCREMENT 50
#define OVERFLOW -2
void MakeNext(int *s, int *next){
	int i,j,k;
	for(i=1,j=1;i<=s[0];++i,++j){
		next[j]=0;
		for(k=1;k<i;k++)
			if(s[k]==s[i+1-k])
				next[j]++;

	}

}

void replace(int *s,int *t,int *v,int *next){
	int i,j=1,k,flag;
	for(i=1;i<=s[0]-t[0]+1;){
		k=i;
        if(j!=1)
            j=next[j-1]+1;
		for(;j<=t[0];)
			if(s[k++]==t[j]){
				flag = 1;
				++j;
			}
			else{
				i=k;
				flag = 0;
				break;
			}

		if(j==t[0]+1 && flag){
			for(k=i;k<=i+t[0]-1;k++)
				s[k] = v[k-i+1];
			i+=t[0];
		}
	}
}

void input(int * &d, int &lenth){
	char ch;
	int i=1;
	ch = getchar();
	d[0]=0;
	while(ch!='\n'){
		d[i++]=ch;
		if(d[0]>=lenth){
			d=(int *)realloc(d,(lenth+INCREMENT)*sizeof(int));
			lenth+=INCREMENT;
		}
		++d[0];
		ch=getchar();
	}

}



int main(){
	int *s;
	int *t;
	int *v;
	int *next;
	int MaxLenthOf_S =MAXSIZE;
	int MaxLenthOf_t=MAXSIZE;
	int MaxLenthOf_v=MAXSIZE;
	s=(int *)malloc((MAXSIZE+1)*sizeof(int));
	t=(int *)malloc((MAXSIZE+1)*sizeof(int));
	v=(int *)malloc((MAXSIZE+1)*sizeof(int));
	next=(int *)malloc((MAXSIZE+1)*sizeof(int));
	if(!s||!t||!v||!next)
		return OVERFLOW;
	int i;
	printf("please input three strings  respectively and don't forget to split them with the enter\n");
	input(s,MaxLenthOf_S);
	input(t,MaxLenthOf_t);
	input(v,MaxLenthOf_v);
	MakeNext(s,next);
	replace(s,t,v,next);
	for (i = 1; i <= s[0]; ++i)
	{
		printf("%c", s[i]);
	}
	printf("\n");
}
