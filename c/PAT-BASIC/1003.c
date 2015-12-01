#include <stdio.h>
#include <string.h>
int main(){
   int n, i, flag, j, k, np, nt, flag2, nal, nac, nar;
   char s[100], PT[100];
   scanf("%d",&n);
   fflush(stdin);
   for(i = 0; i < n; i++){
   	scanf("%s",s);

   	flag = 0;
   	j = 0;
   	while(s[j] != 0){
   	if(s[j] != 'P' &&s[j] != 'A' &&s[j] != 'T'){
   		printf("NO\n");
   		flag = 1;
   		break;
   	}
   	++ j;
  }
   	if(flag)
   		continue;

   	j = 0; np =0; nt = 0;
   	for(k = 0; s[k] != 0; k++){
   		if(s[k] == 'P'){
   			PT[j++] = s[k];
   			np++;
   		}
   		if(s[k] == 'T'){
   			PT[j++] = s[k];
   			nt++;
   			}

   		}
   	if(np != 1 || nt != 1){
   		printf("NO\n");
   		continue;
   		}

   	if(PT[0] == 'T'){
   		printf("NO\n");
   		continue;
   		}

   	flag2 = 0; nal = nac = nar = 0; 
   	for(k = 0; s[k] != 0; k++)
   		if(s[k] == 'P' && s[k+1] == 'A'){
   			break;
   		}
   	nal = k;
   	for(j = k+1; s[j] != 'T'; j++)
   	nac++;
   	for(k = j+1; s[k] != 0; k++)
   	nar++;
   	

   	if(nar == nal * nac&& nac > 0)
   		printf("YES\n");
   	else
   		printf("NO\n");
   	}

}
