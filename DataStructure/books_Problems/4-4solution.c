#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define MAXN 100000
#define MAXS 10

typedef struct Message {
    char Msg[MAXS+1];
    int P;
} ElementType;

typedef struct HeapStruct *MinHeap;
struct HeapStruct {
    ElementType *Elements;
    int Size;
};

MinHeap Create ( int MaxSize )
{ /* 创建空的容量为MaxSize的最小堆 */
    MinHeap H = malloc(sizeof(struct HeapStruct));
    H->Elements = malloc(sizeof(ElementType) * (MaxSize+1));
    H->Size = 0;
    H->Elements[0].P = -1; /* 哨兵优先级值小于所有可能的优先级值 */
    return H;
}

void Insert ( MinHeap H, ElementType X )
{ /* 将X插入H。这里省略检查堆是否已满的代码 */
    int i;

    for (i=++H->Size; H->Elements[i/2].P > X.P; i/=2) {
        H->Elements[i].P = H->Elements[i/2].P;
        strcpy(H->Elements[i].Msg, H->Elements[i/2].Msg);
    }
    H->Elements[i].P = X.P;
    strcpy(H->Elements[i].Msg, X.Msg);
}

ElementType DeleteMin ( MinHeap H )
{ /* 从H中取出堆顶元素并删除之 */
    int Parent, Child;
    ElementType MinX, tmp;

    if (!H->Size) { /* 如果堆为空 */
        MinX.P = -1; /* 标识错误 */
        return MinX;
    }
    MinX.P = H->Elements[1].P;
    strcpy(MinX.Msg, H->Elements[1].Msg);
    tmp.P = H->Elements[H->Size].P;
    strcpy(tmp.Msg, H->Elements[H->Size--].Msg);
    for (Parent=1; Parent*2<=H->Size; Parent=Child) {
        Child = Parent*2;
        if ((Child!=H->Size) && (H->Elements[Child].P>H->Elements[Child+1].P))
            Child++;
        if (tmp.P <= H->Elements[Child].P) break;
        else {
            H->Elements[Parent].P = H->Elements[Child].P;
            strcpy(H->Elements[Parent].Msg, H->Elements[Child].Msg);
        }
    }
    H->Elements[Parent].P = tmp.P;
    strcpy(H->Elements[Parent].Msg, tmp.Msg);
    return MinX;
}

int main()
{
    int N, i;
    char cmd[4];
    MinHeap H;
    ElementType X;

    scanf("%d\n", &N);
    H = Create(N); /* 创建空的最小堆 */
    for (i=0; i<N; i++) {
        scanf("%s", cmd);
        if (cmd[0] == 'P') { /* 如果是PUT则插入 */
            scanf("%s %d\n", X.Msg, &X.P);
            Insert(H, X);
        }
        else { /* 否则一定是GET，则删除并输出 */
            X = DeleteMin(H);
            if (X.P == -1) printf("EMPTY QUEUE!\n");
            else printf("%s\n", X.Msg);
        }
    }

    return 0;
}

