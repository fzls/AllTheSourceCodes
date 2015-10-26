#include<stdio.h>
#include<stdlib.h>

#define MAXV 1000

typedef int DisjSet[MAXV+1];
typedef int Vertex;

struct EdgeType {
    Vertex V1, V2;
    int W; /* 权重 */
};

DisjSet VSet; /* 结点数组 */
struct EdgeType *ESet; /* 边数组 */

/*---------- 结点并查集相关函数 ----------*/
void InitializeVSet ( int N )
{ /* 并查集初始化 */
    while (N)
        VSet[N--] = -1;
}

Vertex Find ( Vertex V )
{   /* 查找V所在的集合 */
    Vertex  root,  trail,  lead;

    for ( root=V; VSet[root]>0; root=VSet[root] )
        ;  /* 查找V所在集合的根root */
    for ( trail = V; trail != root; trail = lead ) {
       lead = VSet[trail] ;   
       VSet[trail] = root ;   
    }  /* 路径压缩 */
    return  root ;
}

void SetUnion( Vertex Root1, Vertex Root2 )
{    /* 按规模求并，把小集合并入大集合   */
    /* 这里保证Root1和Root2都是集合的根 */
    if ( VSet[Root2] < VSet[Root1] ) { /* 如果Root1比较大 */
        VSet[Root2] += VSet[Root1];     /* Root1并入Root2 */
        VSet[Root1] = Root2;
    }
    else {    /* 如果Root2比较大 */
        VSet[Root1] += VSet[Root2];     /* Root2并入Root1 */
        VSet[Root2] = Root1;
    }
}
/*------------------------------------------*/
/*----------- 边的最小堆相关函数 -----------*/
void MinHeap( int i, int M )
{   /* 将M个元素的数组中以ESet[i]为根的子堆调整为最小堆 */
    int child;
    struct EdgeType temp;

    temp = ESet[i];
    for(; ((i<<1) + 1) < M; i = child){
        child = (i<<1)+1;
        if(child != M-1 && ESet[child+1].W < ESet[child].W)
            child++;
        if(temp.W > ESet[child].W) 
            ESet[i] = ESet[child];
        else
            break;
    }
    ESet[i] = temp;  
}

void InitializeESet ( int M )
{ /* 初始化最小堆 */
    int i;
    for (i=M/2; i>=0; i--)  MinHeap(i, M);
}

int GetEdge( int CurrentSize )
{   /* 给定当前堆的大小CurrentSize，将当前最小边位置弹出并调整堆 */
    struct EdgeType temp;

    /* 将最小边与当前堆的最后一个位置的边交换 */
    temp = ESet[0];
    ESet[0] = ESet[CurrentSize-1];
    ESet[CurrentSize-1] = temp;  
    /* 将剩下的边继续调整成最小堆 */
    MinHeap(0, CurrentSize-1);
    return CurrentSize-1; /* 返回最小边所在位置 */
}
/*------------------------------------------*/

int CheckCycle( Vertex V1, Vertex V2 )
{   /* 检查连接V1和V2的边是否在现有的最小生成树子集中构成回路 */
    Vertex Root1 = Find(V1); /* 得到V1所属的连通集名称 */
    Vertex Root2 = Find(V2); /* 得到V2所属的连通集名称 */

    if(Root1==Root2) /* 若V1和V2已经连通，则该边不能要，返回0 */
        return 0;
    else {  /* 否则该边可以被收集，同时将V1和V2并入同一连通集 */
        SetUnion(Root1, Root2);
        return 1;
    }
}

int Kruskal( int N, int M )
{   /* 给定结点和边的数目，返回最小生成树总权重 */
    int EdgeN = 0;     /* 生成树边集合计数器 */
    int Cost = 0;      /* 最小生成树权重累计 */
    int NextEdge = M; /* 下一个最小权重边的位置，初始化为总边数 */

    InitializeVSet( N );  /* 初始化结点并查集VSet */
    InitializeESet( M );  /* 根据边的权重建立最小堆ESet */
    while (EdgeN < N-1) { /* 当收集的边不足以构成树时 */
        if (NextEdge <= 0) /* 边集已空 */
            break;
        NextEdge = GetEdge(NextEdge); /* 从边集中得到最小边的位置 */
        if ( CheckCycle( ESet[NextEdge].V1, ESet[NextEdge].V2 ) ) {
        /* 如果该边的加入不构成回路，即两端结点不属于同一连通集 */
            Cost += ESet[NextEdge].W; /* 收入该边，累计权重 */
            EdgeN++; /* 生成树中边数加1 */
        }
    }
    if (EdgeN < N-1) Cost = -1; /* 若收集的边不足以构成树，设置信号 */
    return Cost;
}

int main()
{
    int N, M, i;

    scanf("%d %d", &N, &M);
    if ( M < N-1 ) /* 太少边肯定不可能连通 */
        printf("-1\n");
    else {
        ESet = malloc( sizeof(struct EdgeType) * M );
        for (i=0; i<M; i++)
            scanf("%d %d %d", &ESet[i].V1, &ESet[i].V2, &ESet[i].W);
        printf("%d\n", Kruskal(N, M));
    }

    return 0;
}
