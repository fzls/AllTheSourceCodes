//p-147 �շ������ͺշ�������Ĵ洢��ʾ
#include <iostream.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define  TRUE 1
#define  FALSE 0
#define  NULL 0
#define  OVERFLOW -2
#define  OK    1
#define  ERROR 0

typedef int Status;

typedef struct {
	unsigned int weight;
	unsigned int parent,lchild,rchild;
} HTNode, *HuffmanTree;  //�ṹ�ͽṹָ�룬���ڶ�̬����ṹ����洢�շ�����

typedef char **HuffmanCode; //�ַ�ָ���ָ�룬���ڶ�̬����ָ������洢�շ��������

void HuffmanCoding(HuffmanTree &HT, HuffmanCode &HC, int *w, int n)
{  // wָ���� n ���ַ���Ȩֵ(��>0)������
   // HT Ϊ����ĺշ�������HC Ϊ�����n���ַ��ĺշ������롣
   int m,i,s1,s2,start,f,t,k=0;
   unsigned int c;
   char *cd;
   HuffmanTree p;

   if(n<=1) return;
   m=2*n-1;
   HT = (HuffmanTree)malloc((m+1)*sizeof(HTNode)); //0�ŵ�Ԫ����

   // �շ�������ʼ
   for(p=HT+1,i=1;i<=n;++i,++p,++w)  //��ʼ��
           //  �൱��{  *P={*w,0,0,0};   }
   { p->weight=*w; p->parent=0; p->lchild=0; p->rchild=0;}
   for(;i<=m;++i,++p)  //��ʼ��n����Ԫ�����ֵ,��Ϊ��֧��㸳��ֵ
          //   �൱��{  *P={0,0,0,0};   }
   { p->weight=0; p->parent=0; p->lchild=0; p->rchild=0;}
   printf(" N weight parent lchild rchild\n");//��ʾ��ʼ�շ�����
   for(i=1; i<=m; i++)
     printf("%2u     %2u     %2u     %2u     %2u   \n",i,HT[i].weight,HT[i].parent,HT[i].lchild,HT[i].rchild);

   // ���շ�����
   for(i=n+1;i<=m;++i)
   {  // Select(HT,i-1,s1,s2);
      // ��HT[1..i-1]ѡ��parentΪ0��weight��С��������㣬����ŷֱ�s1Ϊs2�͡�
	  unsigned int min1=99, min2=99;

	  for(int j=1;j<=i-1;j++)
		{  if ((HT[j].parent==0 )&& (HT[j].weight < min1))
			{ min1=HT[j].weight; s1=j; }
		}
	  HT[s1].parent=i;
	  // �����ҵ���һ�����,����ѭ���ҵڶ���
	  for(int j=1;j<=i-1;j++)
		{  if ((HT[j].parent==0) && (HT[j].weight < min2))
			{ min2=HT[j].weight; s2=j; }
		}
	  printf("s1=%d,s2=%d\n",s1,s2);getchar();
	  HT[s2].parent=i;
	  HT[i].lchild=s1; HT[i].rchild=s2;//�ڱ������У�������������ȨֵС�������������Ȩֵ
	  HT[i].weight=HT[s1].weight+HT[s2].weight;
   }

   printf(" N weight parent lchild rchild\n");//��ʾ���ɺշ�����
   for(i=1; i<=m; i++)
     printf("%2d     %2d     %2d     %2d     %2d   \n",i,HT[i].weight,HT[i].parent,HT[i].lchild,HT[i].rchild);

   //-------��Ҷ�ӵ���������ÿ���ַ��ĺշ�������ȷ--------
   HC = (HuffmanCode)malloc((n+1)*sizeof(char *));//����n���ַ������ͷָ��������0�ŵ�Ԫδ��
   cd = (char *)malloc(n*sizeof(char));             //���������Ĺ����ռ�

   cd[n-1]='\0';                                    //���������
   for(i=1; i<=n; ++i)                              //����ַ���շ�������
   {  start=n-1;                                    //���������λ��
      for(c=i,f=HT[i].parent; f!=0; c=f,f=HT[f].parent)//��Ҷ�ӵ������������
      {		  if(HT[f].lchild==c) cd[--start]='0';
		  else cd[--start]='1';
      }
	  HC[i] = (char *)malloc((n-start)*sizeof(char));//Ϊ��I���ַ��������ռ�
	  strcpy(HC[i],&cd[start]);                      //��cd���Ʊ��루������HC
   }
   free(cd);                                         //�ͷŹ����ռ�


// --------��ջ�ǵݹ�����շ���������շ�������---------
  /* HC = (HuffmanCode)malloc((n+1)*sizeof(char *));
   cd = (char *)malloc(n*sizeof(char));
   int p1=m;  int cdlen=0;
   for(i=1; i<=m; ++i) HT[i].weight=0;//���������շ�����ʱ�������״̬��־
   while(p1)
   {  if(HT[p1].weight==0)                    //����
      {  HT[p1].weight=1;
		 if (HT[p1].lchild!=0) { p1=HT[p1].lchild; cd[cdlen++]='0'; }
		 else if(HT[p1].rchild==0)            //�Ǽ�Ҷ�ӽ����ַ��ı���
		 {	 HC[p1]=(char *)malloc((cdlen+1)*sizeof(char));
			 cd[cdlen]='\0';strcpy(HC[p1],cd);//���Ʊ��루����
         }
      }
      else if(HT[p1].weight==1)               //����
	       {  HT[p1].weight=2;
	         if(HT[p1].rchild!=0) { p1=HT[p1].rchild; cd[cdlen++]='1'; }
	       }
	       else
		   {                                  // HT[p].weight==2���˻�
              HT[p1].weight=0; p1=HT[p1].parent; --cdlen;//�˵�����㣬���볤�ȼ�1
		   }
   }*/
}

void DeCipherHuffmanCode(HuffmanCode &HC,HuffmanTree &HT, int *w, int n){
    int m=2*n-1,k,l;
    HuffmanTree p = (HuffmanTree)malloc((m+1)*sizeof(HTNode));

    p=HT;p++;
  for(k=1;p->parent!=0;p++,k++);
  for(int i=1;i<=n;i++){
    l=k;
    for(int j=0;HC[i][j]!='\0';j++)
      if(HC[i][j]=='0')
        l=HT[l].lchild;
      else if(HC[i][j]=='1')
        l=HT[l].rchild;
    w[i-1]=HT[l].weight;
  }


}

int main()
{   int i;
	HuffmanTree HHT;
    HuffmanCode HHC;
	int a[8]={5,29,7,8,14,23,3,11};
    HuffmanCoding(HHT, HHC, a, 8);
	for (i=1;i<=8;i++)
    { printf("HC[%d]=%s\n",i,HHC[i]); }
  int w[8];
  DeCipherHuffmanCode(HHC,HHT,w,8);
  for(i=0;i<8;i++)
    printf("w[%d]= %d\n",i,w[i] );
}
