#include <stdio.h>
#include <string.h>

#define MaxP 1000
#define MaxL 100
#define MaxC 81

struct PageType {
    int next; /* 记录下一页的位置*/
    /* -1表示本页是最后一页；-2表示本页还未加入排序 */
    char cont[MaxL][MaxC]; /* 存储本页内容 */
} Page[MaxP];

void ReadPages(int Pn, int Ln)
{ /* 将输入读入每张碎片 */
    int i, j;

    for (i=0; i<Pn; i++)
        for (j=0; j<Ln; j++) {
            gets(Page[i].cont[j]);
            Page[i].next = -2;
        }
}

int SortPages( int Pn, int Ln )
{ /* 将碎片排序，返回首页的位置 */
    int head, tail, i;

    head = tail = 0;
    Page[0].next = -1; /* 当前有序的序列只有第0页 */
    /* 如果只有1页，则第0页就是首页 */
    if (Pn == 1) return 0;

    /* 从Page[0]开始向后排序 */
    i = 1;
    while ( i!=tail ) {
        /* 若Page[i]未排序，且其头部能与当前有序序列的尾部匹配 */
        if ((Page[i].next == -2) && 
            (!strcmp(Page[tail].cont[Ln-1], Page[i].cont[0]))) {
            /* 将Page[i]贴到当前有序序列的尾部 */
            Page[tail].next = i;
            tail = i;
            Page[tail].next = -1;
        }
        i = (i+1)%Pn;
    }
    /* 从Page[0]开始向前排序 */
    i = 1;
    while ( i!=head ) {
        /* 若Page[i]未排序，且其尾部能与当前有序序列的头部匹配 */
        if ((Page[i].next == -2) &&
            (!strcmp(Page[i].cont[Ln-1], Page[head].cont[0]))) {
            /* 将Page[i]插到当前有序序列的头部 */
            Page[i].next = head;
            head = i;
        }
        i = (i+1)%Pn;
    }

    return head;
}

void Output( int head, int Ln )
{
    int i, j;

    /* 输出首页 */
    for (j=0; j<Ln; j++)
        printf("%s\n", Page[head].cont[j]);
    /* 输出剩下的碎片，每页从第2行开始输出 */
    for (i=Page[head].next; i!=-1; i=Page[i].next) {
        for (j=1; j<Ln; j++)
            printf("%s\n", Page[i].cont[j]);
    }
}

int main()
{
    int Pn, Ln;

    scanf("%d %d\n", &Pn, &Ln);
    ReadPages(Pn, Ln);
    Output( SortPages(Pn, Ln), Ln );

    return 0;
}
