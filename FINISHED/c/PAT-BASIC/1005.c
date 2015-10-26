#include <stdio.h>//如果程序有点复杂，可以先将关键部分想明白，再将大体思路写在纸上，然后依次予以实现即可。
int main(){
   int a[100], k, n, i, index_min, j, temp, count;
   scanf("%d",&k);
//存入数组   
   for(i = 0; i < k; i++)
   scanf("%d",&a[i]);
   a[i] = 0;
//冒泡排序：顺序   
   for(i = 0; i < k; i++){
   	index_min = i;
   	for( j = i; j < k; j++)
   		if(a[j] < a[i])
   			index_min = j;
   	temp = a[i];
   	a[i] = a[index_min];
   	a[index_min] = temp;	
   	}
//依次排除
   for(i = 0; i < k; i++){
   	if(a[i]){//应确认a[i]不为零，否则程序会陷入无限循环
   	temp = a[i];
   	while(temp != 1){
   	   if(temp % 2)//得到新值
   	   	temp = (3 * temp + 1) / 2;
   	   else
   	   	temp = temp / 2;
   	   		//排除相同
   	   	for(j = 0; j < k; j++)
   	   	if(a[j] && a[j] == temp)
   	   		a[j] = 0;
   	   	}
   	  }
   }
   //计算非负值的元素的个数，方便格式布置
   count = 0;
   for(i = k - 1; i >= 0; i--)
   	if(a[i])
   		count ++;
   
   //输出非零值，即是所求值	
   	for(i = k - 1; i >= 0; i--)
   	if(a[i]){
   		printf("%d",a[i]);
   		if(count-- > 1)
   			printf(" ");
   			
   	}
  }   
   
   	