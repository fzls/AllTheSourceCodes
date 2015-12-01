#include <stdio.h>
#include <stdlib.h>

//���ڵ�Ķ���
struct TNode{
    int value;
    struct TNode *left;
    struct TNode *right;
};

//���нڵ�Ķ���
struct QNode{
    struct TNode *p;
    struct QNode *next;
};

//���еĶ���
struct Queue{
    struct QNode *front;
    struct QNode *rear;
};

//��ʼ������
void InitQueue(struct Queue *Q){
    Q->front=Q->rear=(struct QNode*)malloc(sizeof(struct QNode));
    Q->front->next=NULL;
}

//�����
void EnQueue(struct Queue *Q, struct TNode *node){
    printf("en-node-value:%d\n",node->value);
    struct QNode *nd=(struct QNode*)malloc(sizeof(struct QNode));
    nd->next=NULL;
    nd->p=node;
    Q->rear->next=nd;
    Q->rear=nd;
}

//�����У�ע���ж���Ϊ��ʱ��Ӧ�� rear=front
struct TNode* DeQueue(struct Queue *Q){
    struct QNode *p=Q->front->next;
    Q->front->next=Q->front->next->next;
    struct TNode *t=p->p;
    if(Q->rear==p){
        Q->rear=Q->front;
    }
    free(p);
    printf("de-node-value:%d\n",t->value);
    return t;
}

//����������
void createLR(struct TNode *node){
    if(node->value<20){
        struct TNode *n1=(struct TNode*)malloc(sizeof(struct TNode));
        struct TNode *n2=(struct TNode*)malloc(sizeof(struct TNode));
        node->left=n1;
        n1->value=node->value*2;
        node->right=n2;
        n2->value=node->value*2+1;
        createLR(n1);
        createLR(n2);
    }else{
        node->left=NULL;
        node->right=NULL;
    }
}

//������
int main(int argc, char **argv){

    struct TNode *head=(struct TNode*)malloc(sizeof(struct TNode));
    head->value=1;
    createLR(head);

                //������ұߣ��������Ƿ���ȷ����
    struct TNode *p=head;
    while(p){
        printf("%d\n",p->value);
        p=p->left;
    }
    p=head;
    while(p){
        printf("%d\n",p->value);
        p=p->right;
    }
    printf("\n");

                //��һ�������������У���ȱ�����
    p=head;
    struct Queue *q;
    InitQueue(q);
    printf("%d\n",p->value);
    EnQueue(q,p);
    while(q->front->next!=NULL){
        p=DeQueue(q);
        if(p->left!=NULL){
            printf("%d\n",p->left->value);
            EnQueue(q,p->left);
        }
        if(p->right!=NULL){
            printf("%d\n",p->right->value);
            EnQueue(q,p->right);
        }
    }

                //���´���û�б����˼�����ǲ��������в���
    int i=0;
    for(i=0; i<argc; i++){
        printf("%s\n",argv[i]);
    }

    return 0;
}
