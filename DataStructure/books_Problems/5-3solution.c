#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define MAXS 11 /* 最大字符串长度 */
#define MAXD 5 /* 参与散列映射计算的字符个数 */

/*--- 简化版散列表定义及初始化 ---*/

typedef struct HashEntry *List;
struct HashEntry {
    char PhoneNo[MAXS+1];
    int Cnt;
    List Next;
};

struct HashTbl {
    int TableSize;
    List TheLists;
};

typedef struct HashTbl *HashTable;

int NextPrime ( int N )
{
    int i;

    if (!(N%2)) N++; /* 保证N是奇数*/
    for ( ; ; N+=2) {
        for (i=(int)sqrt(N); i>2; i--)
            if (!(N%i)) break;
        if ( i==2 ) break;
    }
    return N;
}

HashTable InitializeTable ( int N )
{
    int i;
    HashTable H = malloc( sizeof(struct HashTbl) );
    H->TableSize = NextPrime(N); /* 不小于N的最小素数 */
    H->TheLists = malloc( sizeof(struct HashEntry)
                          * H->TableSize );
    for (i=0; i<H->TableSize; i++) {
        H->TheLists[i].PhoneNo[0] = '\0';
        H->TheLists[i].Cnt = 0;
        H->TheLists[i].Next = NULL;
    }
    return H;
}

/*---------------------------------*/

int Hash ( int Key, int P )
{ /* 除留余数法法散列函数 */
    return Key%P;
}

void InsertAndCount ( char *Key, HashTable H )
{
    List Ptr, NewCell, L;

    /* 先找到散列映射后的位置 */
    L = &( H->TheLists[ Hash(atoi(Key+6), H->TableSize) ] );
    /* 在相应链表中查找 */
    Ptr = L->Next;
    while ( Ptr && strcmp(Ptr->PhoneNo, Key) )
        Ptr = Ptr->Next;

    if (Ptr) /* 若找到 */
        Ptr->Cnt++; /* 累计通话次数 */
    else { /* 未找到 */
        NewCell = malloc( sizeof(struct HashEntry) );
        strcpy( NewCell->PhoneNo, Key );
        NewCell->Cnt = 1;
        /* 作为头结点插入 */
        NewCell->Next = L->Next;
        L->Next = NewCell;
    }
}

void Output( HashTable H )
{
    int i, MaxCnt, PCnt;
    List Ptr;
    char MinPhone[MAXS+1];

    MaxCnt = PCnt = 0;
    MinPhone[0] = '\0';

    for (i=0; i<H->TableSize; i++) { /* 扫描链表 */
        Ptr = H->TheLists[i].Next;
        while (Ptr) {
            if (Ptr->Cnt > MaxCnt) { /* 更新最大通话次数 */
                MaxCnt = Ptr->Cnt;
                strcpy(MinPhone, Ptr->PhoneNo);
                PCnt = 1;
            }
            else if (Ptr->Cnt == MaxCnt) {
                PCnt ++; /* 狂人计数 */
                if ( strcmp(MinPhone, Ptr->PhoneNo)>0 )
                    /* 更新狂人的最小手机号码 */
                    strcpy(MinPhone, Ptr->PhoneNo);
            }
            Ptr = Ptr->Next;
        }
    }
    printf("%s %d", MinPhone, MaxCnt);
    if (PCnt>1) printf(" %d", PCnt);
    printf("\n");
}

int main()
{
    int N, i;
    char Key[MAXS+1];
    HashTable H;

    scanf("%d", &N);
    H = InitializeTable (N); /* 创建一个散列表 */

    for (i=0; i<N; i++) {
        scanf("%s", Key);
        InsertAndCount(Key, H);
        scanf("%s", Key);
        InsertAndCount(Key, H);
    }
    Output( H );

    return 0;
}
