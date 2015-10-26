#include<stdio.h>
#include<string.h>
#include <stdlib.h>

#define MaxName 4
#define MaxC 20

typedef  struct  ListNode  *List;
struct ListNode {
    char Name[MaxName+1];  /*学生姓名*/
    List Next;               /*指针域*/
};  /*链表结点*/

struct StudentNode {
    char Name[MaxName+1];  /*学生姓名*/
    int nC;                   /*该生选课门数*/
    int C[MaxC];             /*该生选择的课程编号*/
} *Student; /*输入的学生信息*/

struct CourseNode {
    int Counter; /*该课程的选课人数*/
    List Ptr;     /*链表头指针*/
} *Course; /*课程链表的表头*/

int CmpName(const void *a, const void *b) 
{   /* 调用qsort 对学生姓名按字典序排序时用到的比较函数 */
    return strcmp(((const struct StudentNode*)a)->Name,
((const struct StudentNode*)b)->Name);
}

void Read_and_Sort( int *N, int *K )
{   /* 读入并存储输入数据，再按学生姓名排序 */
    int i, j;

    scanf("%d %d\n", N, K);
    /* 为学生记录和课程链表表头开辟相应空间 */
    Student = malloc( sizeof( struct StudentNode ) * (*N) );
    Course = malloc( sizeof( struct CourseNode ) * (*K) );
    /* 初始化课程链表表头 */
    for (i=0; i<(*K); i++) {
        Course[i].Counter = 0;
        Course[i].Ptr = NULL;
    }
    /*读入并存储输入数据 */
    for (i=0; i<(*N); i++) {
        scanf("%s %d", Student[i].Name, &Student[i].nC);
        for (j=0; j<Student[i].nC; j++)
            scanf("%d", &Student[i].C[j]);
    }
    /* 按学生姓名排序 */
    qsort(Student, (*N), sizeof(struct StudentNode), CmpName);
}

List NewNode( char *name )
{   /* 建立链表结点 */
    List temp;

    temp = (List)malloc(sizeof(struct ListNode));
    strcpy(temp->Name, name);
    temp->Next = NULL;

    return temp;
}

void InsertCourse( int N, int K )
{   /* 按姓名倒序，将学生的选课记录插入相应链表 */
    List Node;
    int i, j, CourseIndex;

    for (i=N-1; i>=0; i--) /*按姓名倒序*/
        for (j=Student[i].nC-1; j>=0; j--) { /*对该生选的每门课*/
            CourseIndex = Student[i].C[j]-1; /*记录课程编号*/
            Node = NewNode(Student[i].Name); /*建立新结点*/
            /*插入链表的表头*/
            Node->Next = Course[CourseIndex].Ptr;
            Course[CourseIndex].Ptr = Node;
            Course[CourseIndex].Counter ++;
        }
}

void Output( int K )
{   /*对K门课，输出选课学生名单*/
    List Ptr;
    int i;

    for (i=0; i<K; i++) {
        printf("%d %d\n", i+1, Course[i].Counter);
        for (Ptr = Course[i].Ptr; Ptr; Ptr = Ptr->Next)
            printf("%s\n", Ptr->Name);
    }
}

int main()
{
    int N, K;

    Read_and_Sort( &N, &K ); /* 读入并存储输入数据，再按学生姓名排序 */
    InsertCourse( N, K ); /* 按姓名倒序，将学生的选课记录插入相应链表 */
    Output( K ); /*对K门课，输出选课学生名单*/

    return 0;
}
