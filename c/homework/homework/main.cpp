// p-61 队的链式表示
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
typedef int Status;

typedef char Info;

struct QNode{
	Info  data;    //信息
    struct QNode  *next;   //下一结点指针
} ;
typedef QNode  *QueuePrt;
typedef struct {
	QueuePrt front;  //队头指针
	QueuePrt rear;   //队尾指针
} LinkQueue;

Status InitQueue(LinkQueue &Q,QNode a[]) {//构造一个空队列

	Q.front=Q.rear=&a[0];
}

Status DestroyQueue(QNode a[]){//销毁队列
	for(int i=0;i<LENTH;++i)
		free(&a[i]);
	return OK;
}

Status EnQueue(LinkQueue &Q, Info e) {//把e的值放队尾（进队）
	if(Q.rear->next=Q.front)
		return OVERFLOW;
	Q.rear->data=e;
	Q.rear=Q.rear->next;
	return OK;
}

Status DeQueue(LinkQueue &Q, Info &e) {//取队头元素给e，队头下移（出队）
	if(Q.front==Q.rear) return ERROR;//队列为空
	e=Q.front->data;
	Q.front=Q.front->next;
	return OK;
}

void PrintQueue(LinkQueue &Q){//打印队列的内容
	QueuePrt  p=Q.front;
    printf("现在队列的内容: ");
    while(p!=Q.rear) {
		printf("%c ",p->data);
		p=p->next;
    }
	printf("\n");
}

int main(){
   Info c,d;
   LinkQueue Q;
   QNode a[LENTH];
	for(int i=0;i<9;++i)
		a[i].next=&a[i+1];
	a[9].next=&a[0];
   InitQueue(Q,a);
   for(int j=0;j<2;j++){
   		for(int i=0;i<7;i++){
   			cin>>c;    EnQueue(Q, c);  PrintQueue(Q);
  		 }
		cout<<endl;
   		for(int i=0;i<5;i++){
   			DeQueue(Q,d);
   			printf("出队列的数据: ");  cout<<d<<endl;   PrintQueue(Q);
   		}
   }


}



