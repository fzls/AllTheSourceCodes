#include <stdio.h>

#define MAXN 30000

typedef int DisjSet[MAXN+1];
typedef int SetType;
typedef int ElementType;

void Initialization( DisjSet S , int N)
{ /* 集合初始化 */
    int i;
    for ( i = N; i > 0; i -- )
        S[i] = -1;
}

int SetUnion( DisjSet S, SetType Root1, SetType Root2 )
{    /* 集合求并，保证小集合并入大集合 */
    /* 要求Root1和Root2必须是集合的根 */
    if ( S[Root2] < S[Root1] ) { /* 如果集合2比较大 */
        S[Root2] += S[Root1];     /* 集合1并入集合2  */
        S[Root1] = Root2;
        return Root2;
    }
    else {                         /* 如果集合1比较大 */
        S[Root1] += S[Root2];     /* 集合2并入集合1  */
        S[Root2] = Root1;
        return Root1;
    }
}

SetType Find( ElementType X, DisjSet S )
{ /* 集合查询 */
    if ( S[X] <= 0 ) /* 找到集合的根 */
        return X;
    else
        return S[X] = Find( S[X], S ); /* 路径压缩 */
}

void Input_connection( DisjSet S )
{ /* 将俱乐部朋友关系加入集合 */
    ElementType u, v;
    SetType Root1, Root2;
    int m, i;

    scanf("%d %d", &m, &u);
    Root1 = Find(u, S); /* 将第1人加入俱乐部 */
    for (i=1; i<m; i++) {
        scanf("%d", &v);        
        Root2 = Find(v, S); 
        if ( Root1 != Root2 )  /* 如果该学生与第1人不属于同一朋友圈 */
            Root1 = SetUnion( S, Root1, Root2 );  /* 合并他们的朋友圈 */
    }
}

void Check_friends( DisjSet S , int N )
{ /* 找出最大朋友圈 */
    int i, max = 1;

    for (i=1; i<=N; i++) { 
        if ( (S[i]<0) && (max < -S[i]) ) /* 检查根结点 */
            max = -S[i];
    }
    printf("%d\n", max);
}

int main()
{
    DisjSet S;
    int N, M, i;

    scanf("%d %d\n", &N, &M);
    Initialization( S, N );
    for (i=0; i<M; i++)
        Input_connection( S );
    Check_friends( S, N );

    return 0;
}

