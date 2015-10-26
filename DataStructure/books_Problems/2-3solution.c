#include <stdio.h>
#include <string.h>

#define MAXN 30
#define MAXString 64
/* 分解表达式的字符串最大长度，为2N+N的位数+2，即30=1+1+……1的长度 */

int Count; /* Count用来记录当前已输出的结果数 */

void Search( int Remainder, int Start, char *STerms );
/*将Remainder分解,要求分解出的每一项均不小于Start，字符串STerms为进入函数前已有的分解结果 */

int main()
{
    char STerms[MAXString] = "";
    int N;

    Count = 0;
    scanf("%d", &N); /* 输入待分解整数 */
    sprintf(STerms, "%d=", N); /* 初始化STerms串为"N="形式 */
    Search( N, 1, STerms );
    if (Count % 4 != 0) /* 输出最后一个结果后换行 */
        printf("\n");
    return 0;
}

void Search( int Remainder, int Start, char *STerms )
{
    int i;
    char TmpS[MAXString];

    strcpy(TmpS, STerms);      /* 保存之前的分解结果  */
    for (i = Start; i <= Remainder; i++)
        /* 从Start开始尝试Remainder分解第一项的所有可能 */
        if ( Remainder - i >= i )  {
            /* 如果剩余数Remainder-i不小于最近分解出的项 */
            sprintf(TmpS + strlen(STerms), "%d+", i);
            /* 保存当前分解结果 */
            Search( Remainder - i, i, TmpS ); /* 递归 */
        }
        else if (Remainder - i == 0) { /*没有剩余项，递归结束，输出 */
            sprintf( TmpS + strlen(STerms), "%d", i );
            Count ++;
            if (Count % 4 != 1)  printf(";");  /* 每个式子间加入分号*/
            printf("%s", TmpS);
            if (Count % 4 == 0) printf("\n");
        }
}
