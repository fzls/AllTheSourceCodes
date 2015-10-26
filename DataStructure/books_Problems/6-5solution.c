#include<stdio.h>
#include<stdlib.h>

#define MAXV 500
#define Inf 100000000

typedef struct {
    int Dist[MAXV][MAXV]; /* 长度邻接表 */
    int Cost[MAXV][MAXV]; /* 费用邻接表 */
    int Visited[MAXV];    /* 顶点标记 */
    int MinDist[MAXV];    /* 到该结点的最短距离 */
    int MinCost[MAXV];    /* 到该结点的最小费用 */
    int VertexN, EdgeN;   /* 顶点和边数 */
} Graph; /* 用邻接表存储的图结构体 */

void InitializeG ( Graph *G )
{ /* 图的初始化 */
    int i, j;

    for (i=0; i<MAXV; i++) {
        for (j=0; j<MAXV; j++)
            G->Dist[i][j] = G->Cost[i][j] = Inf;
        G->Visited[i] = 0;
        G->MinDist[i] = G->MinCost[i] = Inf;
    }
    G->VertexN = G->EdgeN = 0;
}

void ReadG ( Graph *G, int *S, int *D )
{ /* 读入并存储一个图G */
    int i, V1, V2;

    scanf("%d %d %d %d", &G->VertexN, &G->EdgeN, S, D);
    for (i=0; i<G->EdgeN; i++) {
        scanf("%d %d", &V1, &V2);
        scanf("%d %d", &G->Dist[V1][V2], &G->Cost[V1][V2]);
        G->Dist[V2][V1] = G->Dist[V1][V2];
        G->Cost[V2][V1] = G->Cost[V1][V2];
    }
}

void Dijkstra ( Graph *G, int S )
{
    int v, w, minD, minV;

    /* 针对起点进行初始化 */
    G->Visited[S] = 1;
    G->MinDist[S] = G->MinCost[S] = 0;
    for (v=0; v<G->VertexN; v++) {
        G->MinDist[v] = G->Dist[S][v];
        G->MinCost[v] = G->Cost[S][v];
    }
    for (w=1; w<G->VertexN; w++) {
        /* 找当前未访问过的距离最短的结点 */
        minD = Inf;
        for (v=0; v<G->VertexN; v++)
            if (!G->Visited[v] && (G->MinDist[v]<=minD)) {
                minD = G->MinDist[v]; minV = v;
            }
        if (minD < Inf) G->Visited[minV] = 1; /* minV加入集合 */
        else break; /* 图不连通！*/
        /* 更新最短路 */
        for (v=0; v<G->VertexN; v++)
            if (!G->Visited[v]) /* 对每个尚未收入集合的结点 */ {
                if (G->MinDist[minV]+G->Dist[minV][v] < G->MinDist[v]) {
                    /* 如果路径更短，则更新路径和费用 */
                    G->MinDist[v] = G->MinDist[minV]+G->Dist[minV][v];
                    G->MinCost[v] = G->MinCost[minV]+G->Cost[minV][v];
                }
                else if ((G->MinDist[minV]+G->Dist[minV][v]==G->MinDist[v])
                    && (G->MinCost[minV]+G->Cost[minV][v] < G->MinCost[v]))
                    /* 如果路径等长但是更便宜，则更新费用 */
                    G->MinCost[v] = G->MinCost[minV]+G->Cost[minV][v];
            }
    }
}

int main()
{
    int S, D;
    Graph *G = malloc( sizeof(Graph) );

    InitializeG( G );
    ReadG( G, &S, &D );
    Dijkstra( G, S );
    printf("%d %d\n", G->MinDist[D], G->MinCost[D]);

    return 0;
}
