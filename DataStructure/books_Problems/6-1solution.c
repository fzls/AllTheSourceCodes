#include<stdio.h>
#include<stdlib.h>

#define MAXV 1000

typedef struct {
    int Visited[MAXV]; /* 顶点标记 */
    int Edges[MAXV][MAXV]; /* 邻接表 */
    int VertexN, EdgeN; /* 顶点和边数 */
} Graph; /* 用邻接表存储的图结构体 */

void InitializeG ( Graph *G )
{ /* 图的初始化 */
    int i, j;

    for (i=0; i<MAXV; i++) {
        for (j=0; j<MAXV; j++)
            G->Edges[i][j] = 0;
        G->Visited[i] = 0;
    }
    G->VertexN = G->EdgeN = 0;
}

void ReadG ( Graph *G )
{ /* 读入并存储一个图G */
    int i, V1, V2;

    scanf("%d %d", &G->VertexN, &G->EdgeN);
    for (i=0; i<G->EdgeN; i++) {
        scanf("%d %d", &V1, &V2);
        G->Edges[V1-1][V2-1] = G->Edges[V2-1][V1-1] = 1;
    }
}

void DFS ( Graph *G, int V )
{ /* 图G的深度优先搜索 */
    int W;

    G->Visited[V] = 1; /* 将访问到的结点进行标记 */
    for (W=0; W<G->VertexN; W++)
        if (G->Edges[V][W] && !G->Visited[W])
            DFS(G, W);
}

int CheckG ( Graph *G )
{ /* 检查边的度是否全为偶数 */
    int r, i, j;

    for (i=0; i<G->VertexN; i++) {
        r = 0;
        for (j=0; j<G->VertexN; j++)
            r += G->Edges[i][j];
        if (r%2) return 0; /* 发现奇数度的边则返回0 */
    }
    return 1; /* 全是偶数度的边则返回1 */
}

int main()
{
    int i;
    Graph *G = malloc( sizeof(Graph) );

    InitializeG( G );
    ReadG( G );
    DFS( G, 0 ); /* 检查连通性 */
    for (i=0; i<G->VertexN; i++)
        if (!G->Visited[i]) break;
    if (i<G->VertexN) /* 若有结点没被DFS访问到 */
        printf("0\n");  /* 则图不连通 */
    else /* 若图连通 */
        printf("%d\n", CheckG(G));

    return 0;
}
