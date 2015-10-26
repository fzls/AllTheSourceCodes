#include<stdio.h>
#include<stdlib.h>

typedef struct PolyNode *Polynomial;
struct PolyNode {
    int coef;
    int expon;
    Polynomial link;
};

void Attach( int c, int e, Polynomial *pRear )
{   /* 将由(c, e)构成的新项插入到pRear间接指向的结点后面 */
    Polynomial P;

    P = (Polynomial)malloc(sizeof(struct PolyNode));  /* 申请一新结点 */
    P->coef = c;    /* 对新结点赋值  */
    P->expon = e;
    P->link = NULL;
    (*pRear)->link = P; /* 将P指向的新项插入到当前结果表达式尾项的后面 */
    *pRear = P;         /* 修改pRear值 */
}

Polynomial ReadPoly()
{   /* 读入并建立多项式 */
    Polynomial  P, Rear, t;
    int c, e;

    /* 为了程序处理方便起见，先构造一个链表头空结点 */
    P = (Polynomial)malloc(sizeof(struct PolyNode));    
    Rear = P;
    while ( scanf("%d %d", &c, &e) != EOF ) /*读入当前项系数和指数，直到文件结尾 */
        Attach(c, e, &Rear); /* 将当前项插入多项式尾部 */
    /* 删除临时生成的头结点 */
    t = P;  P = P->link;  free(t);
    return P;
}

Polynomial PolyDifferentiation( Polynomial P )
{   /* 求多项式P的导函数，返回结果多项式 */
    /* 原多项式在求导后即被导函数取代    */
    Polynomial P1, P2;

    P2 = P;  P1 = NULL; /* P1总指向P2的前一项 */
    while ( P2 && P2->expon ) {   
        /* 还有多项式非零项，并且当前项指数不为零 */
        P2->coef *= P2->expon;  /* 求当前项导数的系数 */
        P2->expon--;            /* 求当前项导数的指数 */
        P1 = P2; P2 = P2->link; /* P1和P2后移 */
    } 
    if ( P2 ) { /* 处理最后的常数项 */
        if ( P1 ) { /* 如果常数项不是唯一项（前一项非0）*/
            free( P2 ); /* 求导后为0项略去 */
            P1->link = NULL;
        }
        else /* 多项式只有常数项 */
            P2->coef = 0; /* 存为零多项式 */
    }
    return P;
}

void PrintPoly( Polynomial P )
{   /* 输出多项式 */
    int flag = 0; /* 辅助调整输出格式用 */

    while ( P ) {
        if (!flag)
            flag = 1;
        else
            printf(" ");
        printf("%d %d", P->coef, P->expon);
        P = P->link;
    }
    printf("\n");
}

int main()
{
    Polynomial P;

    P = ReadPoly(); /* 读输入多项式 */
    P = PolyDifferentiation( P ); /* 求导函数 */
    PrintPoly( P ); /* 输出多项式 */

    return 0;
}
