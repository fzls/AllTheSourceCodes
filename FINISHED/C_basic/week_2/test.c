/*
+----------------------------------------------------------
*
* @authors: ��֮���� (1054073896@qq.com)
* @FILE NAME :4_2.c
* @version��v1.0
* @Time: 2015-07-18 23:15:44
* @Description:
* ��ĳ���Ҫ����һ����������Χ��[-100000,100000]��Ȼ���ú���ƴ�������������ÿһλ���������
������1234���������
yi er san si
ע�⣬ÿ���ֵ�ƴ��֮����һ���ո񣬵��������ֺ���û�пո񡣵���������ʱ��������Ŀ�ͷ���ϡ�fu������-2341���Ϊ��
fu er san si yi

�����ʽ:
һ����������Χ��[-100000,100000]��

�����ʽ��
��ʾ���������ÿһλ���ֵĺ���ƴ����ÿһλ���ֵ�ƴ��֮���Կո�ָ���ĩβû�пո�

����������
-30

���������
fu san ling
ʱ�����ƣ�500ms�ڴ����ƣ�32000kb
*
+----------------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>
void print_final(int x);
void print_part(int x);
void print(int x);

int main()
{
    int x;
    scanf("%d", &x);
    while(!(x >= -100000 && x <= 100000))
    {
        printf("������������������һ����������Χ��[-100000,100000]��\n");
        scanf("%d", &x);
    }
    if (x < 0)
    {
        printf("fu ");
        x = -x;
    }
    print(x);
    printf("\n");
    system("pause");
    return 0;
}

void print_final(int x)
{
    switch(x)
    {
    case 0:
        printf("ling");
        break;
    case 1:
        printf("yi");
        break;
    case 2:
        printf("er");
        break;
    case 3:
        printf("san");
        break;
    case 4:
        printf("si");
        break;
    case 5:
        printf("wu");
        break;
    case 6:
        printf("liu");
        break;
    case 7:
        printf("qi");
        break;
    case 8:
        printf("ba");
        break;
    case 9:
        printf("jiu");
        break;

    }
}
void print_part(int x)
{
    if(x > 0)
    {
        print_part(x / 10);
        switch(x % 10)
        {
        case 0:
            printf("ling ");
            break;
        case 1:
            printf("yi ");
            break;
        case 2:
            printf("er ");
            break;
        case 3:
            printf("san ");
            break;
        case 4:
            printf("si ");
            break;
        case 5:
            printf("wu ");
            break;
        case 6:
            printf("liu ");
            break;
        case 7:
            printf("qi ");
            break;
        case 8:
            printf("ba ");
            break;
        case 9:
            printf("jiu ");
            break;
        }
    }

}

void print(int x) //�������Ҷ����������ִ��������ͬ�����Էֱ�дһ������Ϊ��ʵ����Ӧ����
{
    print_part(x / 10);
    print_final(x % 10);
}
