#include<stdio.h>
#include<stdlib.h>
#define ERROR -1

#define  MaxVertexNum  1000     /* 最大顶点数为1000 */
typedef  struct  node{          /* 边表结点 */
    int AdjV;                   /* 邻接点域 */
    struct  node  *Next;        /* 指向下一个邻接点的指针域 */
  /* 若要表示边上的权值信息，则应增加一个数据域Weight */
} EdgeNode;        

typedef  char  VertexType;    /* 顶点用字符表示 */
typedef  struct  Vnode{       /* 顶点表结点 */
    char  Visited;               /* 顶点域，这里用于记录该结点是否已经访问 */
    EdgeNode  *FirstEdge;       /* 边表头指针 */
} VertexNode;   
    
typedef  VertexNode  AdjList[ MaxVertexNum ];
/* AdjList是邻接表类型 */
typedef  struct{  
    AdjList  adjlist;         /* 邻接表 */
    int  n, e;                  /* 顶点数和边数 */
} ALGraph;                   /*ALGraph是以邻接表方式存储的图类型 */

typedef int ElementType;
typedef struct {
    ElementType Data[MaxVertexNum];
    int Top;
} Stack;

void Initialize(Stack *PtrS)
{
    PtrS->Top = -1;
}

int Empty(Stack *PtrS)
{
    return PtrS->Top < 0 ;
}

void Push( Stack *PtrS, ElementType item )
{
    if ( PtrS->Top == MaxVertexNum-1 ) {
        printf("堆栈满");
        return;
    }
    else {
        PtrS->Data[++(PtrS->Top)] = item;
        return;
    }
}

ElementType Pop( Stack *PtrS )
{
    if ( PtrS->Top == -1 ) {
        printf("堆栈空");
        return ERROR; /* ERROR是ElementType的特殊值，标志错误 */
    }
    else 
        return ( PtrS->Data[(PtrS->Top)--] );
}

ElementType Top( Stack *PtrS )
{
    if ( PtrS->Top == -1 ) {
        printf("堆栈空");
        return ERROR; /* ERROR是ElementType的特殊值，标志错误 */
    }
    else 
        return ( PtrS->Data[(PtrS->Top)] );
}

int CreateALGraph( ALGraph *G )
{
    int i,j,k, s;
    EdgeNode *edge,*p,*q;

    /* 读入顶点数和边数，以及起点 */
    scanf( "%d %d %d", &(G->n), &(G->e), &s );      
    for ( i=0; i < G->n; i++ ) {        /* 建立有n个顶点的顶点表 */
        G->adjlist[i].Visited = 0;      /* 用于记录该结点是否已经访问 */
        G->adjlist[i].FirstEdge = NULL; /* 顶点的边表头指针设为空 */
    }
    for ( k=0; k < G->e; k++ ){   /* 建立边表 */
        scanf( "%d %d", &i, &j); /* 读入边<vi,vj>的顶点对应序号*/
        edge = (EdgeNode*) malloc( sizeof( EdgeNode ) );
        /* 生成新边表结点edge，用来表示边（vi, vj） */
        edge->AdjV = j-1; /* 邻接点序号为j */
        if( G->adjlist[i-1].FirstEdge == NULL || 
            G->adjlist[i-1].FirstEdge->AdjV>j-1   )
        { /* 将新边表结点edge插入到顶点vi的边表头部 */
            edge->Next = G->adjlist[i-1].FirstEdge;
            G->adjlist[i-1].FirstEdge = edge;
        }else
        {/* 每个节点对应的所有邻接点编号应该是从小到大, 要采取适当的插入 */
            p=G->adjlist[i-1].FirstEdge; q=p->Next;
            while( q && q->AdjV<j-1 )
            {  /*  寻找适当的插入位置 */
                p = q; q = q->Next;
            }
            edge->Next = q;
            p->Next = edge;
        }
        /* 因为是无向图，还要生成一个结点，用来表示边（vj, vi）  */
        edge = (EdgeNode*) malloc( sizeof( EdgeNode ) );
        edge->AdjV = i-1; /* 邻接点序号为i */
        if( G->adjlist[j-1].FirstEdge == NULL || 
            G->adjlist[j-1].FirstEdge->AdjV>i-1  )
        { /* 将新边表结点edge插入到顶点vj的边表头部 */
            edge->Next = G->adjlist[j-1].FirstEdge;
            G->adjlist[j-1].FirstEdge = edge;
        }else
        {  /* 每个节点对应的所有邻接点编号应该是从小到大, 要采取适当的插入 */
            p=G->adjlist[j-1].FirstEdge; q=p->Next;
            while( q && q->AdjV<i-1 )
            { /*  寻找适当的插入位置 */
                p = q; q = q->Next;
            }
            edge->Next = q;
            p->Next = edge;
        }
    }
    return s;
}

void DFS_non_recursive ( ALGraph *G, ElementType V )
{ /* 图G的非递归深度优先搜索 */
    EdgeNode *edge;
    Stack s; /* 记录访问足迹，相当于放绳路径 */

    Initialize(&s);
    G->adjlist[V].Visited = 1;    /* 标记访问到的结点,相当于点灯操作 */
    printf("%d",V+1);            /* 点灯操作要输出节点号 */
    Push(&s, V);                /* 记录访问路线，相当于放绳操作 */
    while( !Empty(&s) )
    {
        V = Top(&s);
        for (edge=G->adjlist[V].FirstEdge; edge; edge=edge->Next)
        {    if ( !G->adjlist[edge->AdjV].Visited )
            {    /* 将访问到的结点进行标记,相当于点灯操作 */
                G->adjlist[edge->AdjV].Visited = 1;
                printf(" %d",edge->AdjV+1); /* 点灯操作要输出节点号 */
                Push(&s, edge->AdjV); /* 记录访问路线，相当于放绳操作 */
                break;
            }
        }
        if(!edge) /* 邻接点都已经点灯 */
        {    V = Pop(&s);  /* 回撤访问路线，相当于收绳操作 */
            if(!Empty(&s)) 
                printf(" %d",Top(&s)+1); /* 记录回撤路线，输出节点 */
        }
    }
}

int main()
{
    int i, s;
    ALGraph *G = malloc( sizeof(ALGraph) );

    s = CreateALGraph( G );
    DFS_non_recursive( G, s-1 ); /* 显示点灯路径的足迹 */
    for (i=0; i<G->n; i++)
        if ( !G->adjlist[i].Visited ) break;
    if (i<G->n)    /* 若有结点没被DFS访问到 */
        printf(" 0\n");  /* 则图不连通 */
    else printf("\n");
    
    return 0;
}
