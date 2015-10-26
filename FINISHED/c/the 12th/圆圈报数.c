/*输入两个正整数 n 和 m（ (1<m<n<=50)），有 n 个人围成一圈，按顺序从 1 到 n 编号。从第一个人开始报数，报数 m 的人退出圈子，下一个人从 1 开始重新报数，报数 m 的人退出圈子。如此循环，直到留下最后一个人。请按退出顺序输出退出圈子的人的编号，以及最后一个人的编号。
提示：将每个人的编号存入数组，从第一个人开始报数，输出报数 m 的人的编号，并将该编号清除为0，重复这样的操作直至只剩下一个不为0的数，该数就是最后一个人的编号。*/

#include<stdio.h>
int main(void)
{
    int count=0, i, m, n, no=1;
    int num[50];
    int *p;

    scanf("%d%d", &n, &m);
    for(i = 0; i < n; i++)
        num[i] = i + 1;
    p = num;
    
    while(n>1){
    	count=(count+m-1)%n;
    printf("No%d: %d\n", no++, *(p+count));
    for(i=count;i<n-1;i++)
       *(p+i)=*(p+i+1);
    n--;
  }
    printf("Last No is: %d\n", *p);
    system("pause");
    
}
