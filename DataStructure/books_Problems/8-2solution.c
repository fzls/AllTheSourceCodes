#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define MaxProc 60        /* 最长事务处理时间（分钟） */
#define MAXTEAM 100        /* 最多朋友圈个数           */
#define MAXCHAR 3        /* 名字最多3个大写英文字母 */
#define MAXNAME 26426    /* ZZZ可被转换的整数+1    */

struct People { /* 顾客信息 */
    char Name[MAXCHAR+1];    /* 名字 */
    int T;    /* 到达时间 */
    int P;    /* 处理时间 */
};

struct TeamQueueRecord { /* 分支队列结构 */
    int Tfront;
    int Trear;
    int Tsize;
    struct People *Customer; /* 存储实际顾客信息 */
};
typedef struct TeamQueueRecord *TeamQueue;

struct QueueRecord { /* 总队列结构 */
    int front;
    int rear;
    int size;
    TeamQueue TeamQ; /* 存储分支队列的头指针 */
};
typedef struct QueueRecord *Queue;

int Team[MAXNAME];    /* Team[名字] = 这个名字所属于的朋友圈编号 */
struct TeamNode {
    int Position;    /* 该朋友圈在Queue中的位置，夹塞专用   */
    int Size;        /* 目前该朋友圈中排在Queue中的人数     */
} TeamInfo[MAXTEAM];    /* 记录朋友圈信息 */


int NameHash( char name[] )
{   /* 将3字母用哈希映射转换成整数 */
    int i, j;

    /* 每个字母占5位 */
    i = name[0] - 'A';
    j = 1;
    while (name[j]!='\0')
        i = (i<<5) + name[j++] - 'A';

    return i;
}

int Read_and_Set_Teams( int M )
{   /* 读入并初始化朋友圈信息，返回最大朋友圈里的人数 */
    int L, MaxL;
    int i, j;
    char name[MAXCHAR+1];

    /* 首先默认所有人都没有朋友 */
    for (i=0; i<MAXNAME; i++)
        Team[i] = -1;

    MaxL = 0; /* MaxL记录最大朋友圈里的人数 */
    for (i=0; i<M; i++) {
        scanf("%d ", &L);
        if (L > MaxL) MaxL = L; /* 更新MaxL */
        for (j=0; j<L; j++) {
            scanf("%s", name);
            /* 将name转成数字，并记录其所属朋友圈的编号 */
            Team[NameHash(name)] = i;
        }
    }
    for (i=0; i<M; i++) /* 初始状态无人在排队 */
        TeamInfo[i].Size = 0;

    return MaxL;
}

Queue CreateQueue( int MaxQSize, int MaxTSize )
{   /* 建立总队列及分支队列结构 */
    Queue Q;
    int i;

    Q = malloc( sizeof( struct QueueRecord ) );
    Q->TeamQ = malloc( sizeof( struct TeamQueueRecord ) * MaxTSize );
    Q->size = 0;
    Q->front = 0;
    Q->rear = -1;
    for ( i=0; i<MaxTSize; i++ ) {
        Q->TeamQ[i].Customer = 
malloc( sizeof( struct People ) * MaxQSize );
        Q->TeamQ[i].Tsize = 0;
        Q->TeamQ[i].Tfront = 0;
        Q->TeamQ[i].Trear = -1;
    }

    return Q;
}

void AddQ( Queue Q, struct People X )
{   /* 向队列Q中插入X */
    int i, pos, r;

    if ( X.P > MaxProc )  X.P = MaxProc; /* 控制最大事务处理时间 */
    i = Team[NameHash(X.Name)]; /* 找到X所属的朋友圈 */
    if ( (i == -1) || (!TeamInfo[i].Size) ) {
        /* 如果没有朋友，或者前面没有朋友在排队           */
        /* 则新插入一个分支队列到Q中，且将X插入该分支队列 */
        Q->rear++;
        r = ++Q->TeamQ[Q->rear].Trear;
        Q->TeamQ[Q->rear].Customer[r].T = X.T;
        Q->TeamQ[Q->rear].Customer[r].P = X.P;
        strcpy(Q->TeamQ[Q->rear].Customer[r].Name, X.Name);
        Q->TeamQ[Q->rear].Tsize++;
        Q->size++;
        if ( i != -1 ) { /* 如果有朋友圈，但是没有朋友在前面排队 */
            TeamInfo[i].Position = Q->rear; /* 记住这个圈子在Q中的位置 */
            TeamInfo[i].Size++; /* 当前多了一人在排队 */
        }
    }
    else { /* 如果可以夹塞 */
        pos = TeamInfo[i].Position; /* 获得前面朋友的位置 */
        /* 将X插入pos位置的分支队列中 */
        r = ++Q->TeamQ[pos].Trear;
        Q->TeamQ[pos].Customer[r].T = X.T;
        Q->TeamQ[pos].Customer[r].P = X.P;
        strcpy(Q->TeamQ[pos].Customer[r].Name, X.Name);
        Q->TeamQ[pos].Tsize++;
        TeamInfo[i].Size++; /* 当前多了一人在排队 */
    }
}

struct People FrontQ( Queue Q )
{   /* 返回Q队首顾客的信息 */
    struct People X;
    int f;

    f = Q->TeamQ[Q->front].Tfront;
    X.T = Q->TeamQ[Q->front].Customer[f].T;
    X.P = Q->TeamQ[Q->front].Customer[f].P;
    strcpy(X.Name, Q->TeamQ[Q->front].Customer[f].Name);

    return X;

}

void DeleteQ( Queue Q )
{   /* 删除Q队首顾客 */
    int i, f;

    /* 从Q->front所指的分支队列中删除 */
    f = Q->TeamQ[Q->front].Tfront;
    Q->TeamQ[Q->front].Tfront++;
    Q->TeamQ[Q->front].Tsize--;
    /* 得到该顾客所属的朋友圈 */
    i = Team[NameHash(Q->TeamQ[Q->front].Customer[f].Name)];
    /* 如果有朋友，则当前该圈排队减少一人 */
    if ( i != -1 ) TeamInfo[i].Size--;
    /* 如果该圈已经没人排队了，则彻底从总队列Q中删除该分支队列 */
    if ( !Q->TeamQ[Q->front].Tsize ) {
        Q->front++;
        Q->size--;
    }
}

int IsEmpty( Queue Q )
{
    return ( Q->size == 0 );
}

struct People Enter( int *i )
{   /* 读入一位顾客信息 */
    struct People X;
    char c; /* 处理行输入末尾的回车符 */

    if ((*i)) { 
        scanf("%s %d %d%c", X.Name, &X.T, &X.P, &c);
        (*i)--;
    }
    else X.T = -1; /* 标记输入数据已经读完 */

    return X;
}

double QueueingAtBank( Queue Q, int N )
{   /* 模拟排队并计算平均等待时间 */
    struct People Next, Wait;
    int TotalTime, CurrentTime;
    int i = N;

    TotalTime = CurrentTime = 0;

    Wait = Enter( &i ); /* 至少可以读入一位顾客信息 */
    AddQ( Q, Wait );    /* 该顾客排队 */
    if (!i) { /* 如果只有1位顾客，则无须等待，直接返回 */
        Next = FrontQ(Q);
        printf("%s\n", Next.Name);
        return 0.0;
    }
    else Wait = Enter( &i ); /* 否则读入下一位顾客信息 */
    while ( !IsEmpty(Q) || (Wait.T >= 0) ) {
        if ( !IsEmpty(Q) ) {  /* 如果有人排队 */
            Next = FrontQ(Q); /* 下一位顾客准备接受服务 */
            printf("%s\n", Next.Name);
            if ( CurrentTime >= Next.T )  /* 如果Next有等待，累计时间 */
                TotalTime += (CurrentTime - Next.T);
            else /* 否则窗口空闲一段时间，更新当前时间到顾客Next的到达时间 */
                CurrentTime = Next.T; 
/* 更新当前时间到顾客Next处理完事务的时间 */
            CurrentTime += Next.P; 
            while ( (Wait.T >= 0) && (Wait.T <= CurrentTime) ) {
                /* 将输入中所有在顾客Next离开前到达的人入列 */
                AddQ( Q, Wait );
                Wait = Enter( &i );
            }
            DeleteQ(Q); /* 顾客Next办理完毕离开 */
        }
        else { /* 如果没人排队，读入下面2位顾客的输入信息，并令第1人入列 */
            AddQ( Q, Wait );
            Wait = Enter( &i );
        }
    }

    return ((double)TotalTime/(double)N);
}


int main()
{
    int N, M, MaxQSize;
    Queue Q;

    scanf("%d %d\n", &N, &M);
    /* 读入并初始化朋友圈信息，得到最大朋友圈里的人数 */
    MaxQSize = Read_and_Set_Teams(M);
    /* 建立总队列及分支队列结构 */
    Q = CreateQueue( MaxQSize, N );
    /* 模拟排队并计算、输出平均等待时间 */
    printf("%.1f\n", QueueingAtBank( Q, N ));

    return 0;
}

