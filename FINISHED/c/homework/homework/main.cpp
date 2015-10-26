// p-61 �ӵ���ʽ��ʾ
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
	Info  data;    //��Ϣ
    struct QNode  *next;   //��һ���ָ��
} ;
typedef QNode  *QueuePrt;
typedef struct {
	QueuePrt front;  //��ͷָ��
	QueuePrt rear;   //��βָ��
} LinkQueue;

Status InitQueue(LinkQueue &Q,QNode a[]) {//����һ���ն���

	Q.front=Q.rear=&a[0];
}

Status DestroyQueue(QNode a[]){//���ٶ���
	for(int i=0;i<LENTH;++i)
		free(&a[i]);
	return OK;
}

Status EnQueue(LinkQueue &Q, Info e) {//��e��ֵ�Ŷ�β�����ӣ�
	if(Q.rear->next=Q.front)
		return OVERFLOW;
	Q.rear->data=e;
	Q.rear=Q.rear->next;
	return OK;
}

Status DeQueue(LinkQueue &Q, Info &e) {//ȡ��ͷԪ�ظ�e����ͷ���ƣ����ӣ�
	if(Q.front==Q.rear) return ERROR;//����Ϊ��
	e=Q.front->data;
	Q.front=Q.front->next;
	return OK;
}

void PrintQueue(LinkQueue &Q){//��ӡ���е�����
	QueuePrt  p=Q.front;
    printf("���ڶ��е�����: ");
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
   			printf("�����е�����: ");  cout<<d<<endl;   PrintQueue(Q);
   		}
   }


}



