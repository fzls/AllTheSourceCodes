#include "stdio.h"
#include "stdlib.h"
#define ERROR -1

typedef struct TNode_type{
	char data;
	struct TNode_type *left;
	struct TNode_type *right;
}TNode;

typedef struct QNode_type{
	TNode *nd;
	struct QNode_type *next;
}QNode;

typedef struct {
	QNode *front;
	QNode *rear;
}Queue;

void InitQueue(Queue *Q){
	Q->front=Q->rear=(QNode *)malloc(sizeof(QNode));
	Q->rear->next=NULL;
}

void EnQueue(Queue *Q, TNode *node){
	QNode *p =(QNode *)malloc(sizeof(QNode));
	p->next=NULL;
	p->nd=node;
	Q->rear->next=p;
	Q->rear=p;

}

TNode * DeQueue(Queue *Q){
	TNode *node;
	if(Q->front!=Q->rear){
		node=Q->front->next->nd;
		Q->front->next=Q->front->next->next;
	}
return node;
}

int PreOrder_Creat_BinTree(TNode *Root){
	char ch;
	scanf("%c",&ch);
	if(ch == '\n')return 1;
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
	Queue *q;
	InitQueue(q);
	EnQueue(q,p);
	while(q->front!=q->rear){
		p=DeQueue(q);
		if(p->left!=NULL){
			printf("%c ",p->left->data );
			EnQueue(q,p->left);
		}
		if(p->right!=NULL){
			printf("%c ",p->right->data);
			EnQueue(q,p->right);
		}


	}
printf("END");
}
