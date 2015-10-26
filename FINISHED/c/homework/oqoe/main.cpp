// 循环队列
#include <iostream.h>
#include <stdio.h>
#include <stdlib.h>
#define  TRUE 1
#define  FALQE 0
#define  NULL 0
#define  OVERFLOW -2
#define  OK    1
#define  ERROR 0
#define  LENTH 10

typedef struct TNode{
	char data;
	struct TNode *left;
	struct TNode *right;
}TNode;


typedef struct {
	TNode *base;
	int FR;  //队头指针
	int rear;   //队尾指针
} Queue;

int InitQueue(Queue &Q) {//构造一个空队列
	Q.base = (TNode *)malloc(LENTH*sizeof(TNode));
	if(!Q.base)exit(OVERFLOW);
	Q.FR=Q.rear=0;
	return OK;
}

int DestroyQueue(Queue &Q){//销毁队列
	free(Q.base);
	return OK;
}

int QueueLenth(Queue Q){
	return(Q.rear-Q.FR+LENTH)%LENTH;
}

int EnQueue(Queue &Q, TNode e) {//把e的值放队尾（进队）
	if((Q.rear+1)%LENTH == Q.FR)
		return ERROR;
	Q.base[Q.rear]=e;
	Q.rear=(Q.rear+1)%LENTH;
	return OK;
}

TNode* DeQueue(Queue &Q) {//取队头元素给e，队头下移（出队）
	if(Q.FR==Q.rear) return ERROR;//队列为空
	TNode *e;
	e=&Q.base[Q.FR];
	Q.FR=(Q.FR+1)%LENTH;
	return e;
}

void PrintQueue(Queue &Q){//打印队列的内容
    printf("现在队列的内容: ");
    int p = Q.FR;
    while(p!=Q.rear) {
		printf("%c ",Q.base[p]);
		p=(p+1)%LENTH;
    }
	printf("\n");
}

int PreOrder_Creat_BinTree(TNode *Root){
	char ch;
	scanf("%c",&ch);
	if(ch == '\n')return 2;
	if(ch == ' ') Root =NULL;
	else {
	Root =(TNode *)malloc(sizeof(TNode));
	Root->data=ch;
	Root->left=Root->right=NULL;
	PreOrder_Creat_BinTree(Root->left);
	PreOrder_Creat_BinTree(Root->right);
	}
return 1;
}

int main(){
	TNode *Root = NULL;
	PreOrder_Creat_BinTree(Root);

	TNode *p =Root;
	Queue q;
	InitQueue(q);
	EnQueue(q,*p);
	while(q.FR!=q.rear){
		p=DeQueue(q);
		if(p->left!=NULL){
			printf("%c ",p->left->data );
			EnQueue(q,*(p->left));
		}
		if(p->right!=NULL){
			printf("%c ",p->right->data);
			EnQueue(q,*(p->right));
		}


	}

}



