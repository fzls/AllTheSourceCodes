#include <stdio.h>//��������е㸴�ӣ������Ƚ��ؼ����������ף��ٽ�����˼·д��ֽ�ϣ�Ȼ����������ʵ�ּ��ɡ�
int main(){
   int a[100], k, n, i, index_min, j, temp, count;
   scanf("%d",&k);
//��������   
   for(i = 0; i < k; i++)
   scanf("%d",&a[i]);
   a[i] = 0;
//ð������˳��   
   for(i = 0; i < k; i++){
   	index_min = i;
   	for( j = i; j < k; j++)
   		if(a[j] < a[i])
   			index_min = j;
   	temp = a[i];
   	a[i] = a[index_min];
   	a[index_min] = temp;	
   	}
//�����ų�
   for(i = 0; i < k; i++){
   	if(a[i]){//Ӧȷ��a[i]��Ϊ�㣬����������������ѭ��
   	temp = a[i];
   	while(temp != 1){
   	   if(temp % 2)//�õ���ֵ
   	   	temp = (3 * temp + 1) / 2;
   	   else
   	   	temp = temp / 2;
   	   		//�ų���ͬ
   	   	for(j = 0; j < k; j++)
   	   	if(a[j] && a[j] == temp)
   	   		a[j] = 0;
   	   	}
   	  }
   }
   //����Ǹ�ֵ��Ԫ�صĸ����������ʽ����
   count = 0;
   for(i = k - 1; i >= 0; i--)
   	if(a[i])
   		count ++;
   
   //�������ֵ����������ֵ	
   	for(i = k - 1; i >= 0; i--)
   	if(a[i]){
   		printf("%d",a[i]);
   		if(count-- > 1)
   			printf(" ");
   			
   	}
  }   
   
   	