#include<stdio.h>
#include<stdlib.h> 

#define MAXN 50

typedef struct TreeNode *BinTree;
struct TreeNode
{
    char Data;
    BinTree Left;
    BinTree Right;
};

BinTree CreateBinTree( char *Pre, char *In, int Len ) 
{ /* 根据先序遍历序列和中序遍历序列构造二叉树 */
    BinTree T;
    int i;

    if ( !Len ) return NULL; /* 递归终止 */

    /* 建立当前根结点 */
    T = malloc(sizeof(struct TreeNode));
    T->Data = Pre[0]; 
    for (i=0; i<Len; i++) /* 在中序里找根结点 */
        if (Pre[0]==In[i]) break;
    /* 递归生成左右子树 */
    T->Left = CreateBinTree(Pre+1, In, i);
    T->Right = CreateBinTree(Pre+i+1, In+i+1, Len-i-1);

    return T;
}

int Height( BinTree T )
{ /* 求树的高度 */
    int THeight, LHeight, RHeight;

    if( !T ) /* 递归终止条件 */
        THeight=0; 
    else { /* 后序遍历 */
        LHeight = Height(T->Left);
        RHeight = Height(T->Right);
        THeight = (LHeight>RHeight)? LHeight : RHeight;
        THeight++; /* 树高为左右树高较大者加1 */
    }
    return THeight;
}

int main()
{
    int N;
    char Pre[MAXN+1], In[MAXN+1];
    BinTree T = NULL;
    
    scanf("%d", &N);
    scanf("%s\n%s", Pre, In);
    T = CreateBinTree(Pre, In, N);
    printf("%d\n", Height(T));

    return 0;
}
