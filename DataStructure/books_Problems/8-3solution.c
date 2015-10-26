#include <stdio.h>
#include <malloc.h>

#define MAXN 1000

struct TableRecord { /* 哈希表 */
    int TableSize;
    int T[MAXN];
};
typedef struct TableRecord *Table;

struct GraphRecord { /* 图 */
    int NumVert;
    int M[MAXN][MAXN];
};
typedef struct GraphRecord *Graph;

/*------------ 定义最小堆 -------------*/
struct HeapRecord {
    int Index;
    int Num;
};
typedef struct HeapRecord *HeapNode;

struct HeapStruct {
    int HeapSize;
    HeapNode Elements;
};
typedef struct HeapStruct *MinHeap;

void InsertHeap( HeapNode X, MinHeap Q );
HeapNode DeleteMin( MinHeap Q );
/*-------------------------------------*/

Table Read( int N )
{   /* 读入哈希表 */
    int i;
    Table HT = (Table)malloc( sizeof( struct TableRecord ) );

    HT->TableSize = N;
    for (i=0; i<N; i++)
        scanf("%d", &HT->T[i]);
    
    return HT;
}

Graph ConstructG( Table HT, int N )
{    /* 根据哈希表建立有向图 */
    int i, j;
    Graph G = (Graph)malloc( sizeof( struct GraphRecord ) );

    /* 初始化空图 */
    for ( i=0; i<HT->TableSize; i++ )
        for ( j=0; j<HT->TableSize; j++ )
            G->M[i][j] = 0;

    /* 建立图 */
    for ( i=0; i<HT->TableSize; i++ ) {
        if ( !(HT->T[i] < 0) ) {  /* 只处理非空的单元 */
            j = HT->T[i]% HT->TableSize; /* 计算初始散列值 */
            while ( i != j )    {  /* 若当前位置i与探测位置j不同 */
                G->M[j][i] = 1;    /* 在图中添加一条指向i的边 */
                j = (j+1)% HT->TableSize; /* 探测下一个位置 */
            }
        }
    }
    G->NumVert = HT->TableSize;
    return G;
}

void InsertHeap( HeapNode X, MinHeap Q )
{   /* 插入最小堆 */
    int i;

    for ( i = ++Q->HeapSize; Q->Elements[i/2].Num>X->Num; i/=2 ) {
        Q->Elements[i].Num = Q->Elements[i/2].Num;
        Q->Elements[i].Index = Q->Elements[i/2].Index;
    }
    Q->Elements[i].Num = X->Num;
    Q->Elements[i].Index = X->Index;
}

HeapNode DeleteMin( MinHeap Q )
{   /* 删除最小堆顶 */
    int i, child;
    HeapNode MinT = (HeapNode)malloc( sizeof( struct HeapRecord ) );
    HeapNode LastT = (HeapNode)malloc( sizeof( struct HeapRecord ) );

    MinT->Num = Q->Elements[1].Num;
    MinT->Index = Q->Elements[1].Index;
    LastT->Num = Q->Elements[Q->HeapSize].Num;
    LastT->Index = Q->Elements[Q->HeapSize--].Index;

    for (i=1; i*2<=Q->HeapSize; i=child ) {
        child = i*2;
        if ( child!=Q->HeapSize && 
Q->Elements[child+1].Num<Q->Elements[child].Num )
            child++;
        if ( LastT->Num > Q->Elements[child].Num ){
            Q->Elements[i].Num = Q->Elements[child].Num;
            Q->Elements[i].Index = Q->Elements[child].Index;
        }
        else break;
    }
    Q->Elements[i].Num = LastT->Num;
    Q->Elements[i].Index = LastT->Index;

    return MinT;
}


void Topsort( Graph G, Table HT, int N )
{   /* 拓扑排序得到解并输出 */
    MinHeap Q = (MinHeap)malloc( sizeof( struct HeapStruct ) );
    HeapNode Tmp = (HeapNode)malloc( sizeof( struct HeapRecord ) );
    int  i, j, InDegree[MAXN];
    int flag = 0;

    /* 初始化最小堆 */
    Q->Elements = 
(HeapNode)malloc((G->NumVert+1)*sizeof(struct HeapRecord));
    Q->HeapSize = 0;
    Q->Elements[0].Num = -1;

    /* 计算初始入度，建立0入度结点的最小堆 */
    for ( i=0; i<G->NumVert; i++ ) {
        InDegree[i] = 0;
        if ( !(HT->T[i]<0) ) { /* 只对每个非空单元的元素计算入度 */
            for ( j=0; j<G->NumVert; j++ )
                InDegree[i] += G->M[j][i];
            if ( !InDegree[i] ){ /* 入度为0者存入最小堆 */
                Tmp->Index = i;  Tmp->Num = HT->T[i];
                InsertHeap( Tmp, Q );
            }
        }
    }

    /* 拓扑排序 */
    while ( Q->HeapSize ) {
        Tmp = DeleteMin( Q ); /* 输出当前数值最小的入度为0的元 */
        if ( flag )
            printf(" %d", Tmp->Num); /* 输出其它元素，元素前有空格*/
        else {
            printf("%d", Tmp->Num); /* 输出第1个元素，元素前没有空格*/
            flag = 1;
        }
        /* 将该结点从图中删去 */
        i = Tmp->Index;
        for (j=0; j<G->NumVert; j++ ) {
            if ( G->M[i][j] ) {
                InDegree[j]--;
                if ( !InDegree[j] ) {  /* 更新后入度为0者存入最小堆 */
                    Tmp->Index = j;  Tmp->Num = HT->T[j];
                    InsertHeap( Tmp, Q );
                }
            }
        }
    }
    printf("\n");
}

int main()
{
    Graph G;
    Table HT;
    int N;

    scanf("%d", &N);
    HT = Read(N);            /* 读入哈希表           */
    G = ConstructG(HT, N); /* 根据哈希表建立有向图 */
    Topsort(G, HT, N);      /* 拓扑排序得到解并输出 */

    return 0;
}

