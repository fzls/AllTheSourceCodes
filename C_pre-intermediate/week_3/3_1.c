/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <NUMBER54073896@qq.com>
* @FILE NAME:	 TM_FILENAME
* @version:	 1.0
* @Time: 		 2015-07-24 18:21:35
* @Description: 学生成绩简单统计。
写一个程序，读入NUMBER名学生的成绩。每个学生的数据，包含一个不带空格的名字（不超过19个字符），以及三门课的成绩，每门课的成绩是1到5的整数。程序要输出如下的一个列表，对每个学生输出他的录入时的序号、名字、三门课的成绩和平均成绩（浮点表示），最后输出每门课的平均成绩（浮点表示）和最低最高成绩。
no      name    score1  score2  score3  average
1       K.Weng  5       5       5       5
2       T.Dixon 4       3       2       3
3       V.Chu   3       4       5       4
4       L.Tson  4       3       4       3.66667
5       L.Lee   3       4       3       3.33333
6       I.Young 4       2       5       3.66667
7       K.Hiro  4       2       1       2.33333
8       G.Ping  4       4       4       4
9       H.Gu    2       3       4       3
NUMBER      J.Jon   5       4       3       4
       average 3.8     3.4     3.6
       min     2       2       1
       max     5       5       5
因为排版的缘故，你看到的表格也许不够整齐，输出时在所有的输出项之间加\t就可以了。输出格式不是评判的内容。
程序本身并不复杂，只是要求采用结构来表达每个学生的数据，并具有以下代码片段（你的代码中必须含有并使用以下部分）：
typedef struct {
   char name[20];
   int score[3];
} Student;

//    输入一个学生的数据
Student* student_input(Student *pStudent);
//    输出一个学生的数据，包括平均成绩
void student_print(const Student *pStudent);
//    计算一个学生的平均成绩
double student_average(const Student *pStudent);
//    获得学生的一个成绩
int student_get_score(const Student *pStudent, int index);
注意虽然是开放互评的题目，我们并不鼓励对题目要求做任意的扩展，并不会因为做了扩展，比如实现任意的人数或任一的课程或课程名称等而做加分。有关对这道题目的扩展想法可以在讨论区讨论。
*
+----------------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>
#define NUMBER 3
typedef struct {
	char name[20];
	int score[3];
} Student;

//    输入一个学生的数据
Student* student_input(Student *pStudent);
//    输出一个学生的数据，包括平均成绩
void student_print(const Student *pStudent);
//    计算一个学生的平均成绩
double student_average(const Student *pStudent);
//    获得学生的一个成绩
int student_get_score(const Student *pStudent, int index);
int main() {
	Student stu[NUMBER];
	double average_1, average_2, average_3, sum_1, sum_2, sum_3 ;
	int min_1, min_2, min_3, max_1, max_2, max_3;
//sum,min,max分别用于计算均值，最小值，最大值，并初始化
	sum_1 = sum_2 = sum_3 = 0;
	min_1 = min_2 = min_3 = 5;
	max_1 = max_2 = max_3 = 0;
// 输入数据
	for (int i = 0; i < NUMBER; i++) {
		stu[i] = *student_input(&stu[i]);
		fflush( stdout );//将最后输入的回车取消
	}
	printf("no\tname\tscore1\tscore2\tscore3\taverage\n");//输入表头
	// 输入中间部分
	for (int i = 0; i < NUMBER; i++) {
		printf("%d\t", i + 1);
		student_print(&stu[i]);
	}
	// 输入后续部分
	for (int i = 0; i < NUMBER; i++) {
		sum_1 += stu[i].score[0];
		sum_2 += stu[i].score[1];
		sum_3 += stu[i].score[2];

		if (stu[i].score[0] < min_1) {
			min_1 = stu[i].score[0];
		}

		if (stu[i].score[1] < min_2) {
			min_2 = stu[i].score[1];
		}

		if (stu[i].score[2] < min_3) {
			min_3 = stu[i].score[2];
		}

		if (stu[i].score[0] > max_1) {
			max_1 = stu[i].score[0];
		}

		if (stu[i].score[1] > max_2) {
			max_2 = stu[i].score[1];
		}

		if (stu[i].score[2] > max_3) {
			max_3 = stu[i].score[2];
		}

	}
	average_1 = sum_1 / NUMBER;
	average_2 = sum_2 / NUMBER;
	average_3 = sum_3 / NUMBER;
	printf("\taverage\t%.1f\t%.1f\t%.1f\n", average_1, average_2, average_3 );
	printf("\tmin\t%d\t%d\t%d\n", min_1, min_2, min_3);
	printf("\tmax\t%d\t%d\t%d\n", max_1, max_2, max_3);

	//        average 3.8     3.4     3.6
	// 		min     2       2       1
	// 		max     5       5       5
	printf("\n");
	system("pause");
	return 0;
}
Student* student_input(Student *pStudent) {
	scanf("%s%d%d%d", pStudent->name, &pStudent->score[0], &pStudent->score[1], &pStudent->score[2]);
	return pStudent;

}


// index取值为0,1,2分别表示三门课程
int student_get_score(const Student *pStudent, int index) {
	return pStudent->score[index];
}

double student_average(const Student *pStudent)
{
	double average;
	average = 1.0 * (student_get_score(pStudent, 0) + student_get_score(pStudent, 1) + student_get_score(pStudent, 2)) / 3;
	return average;
}

void student_print(const Student *pStudent)
{
	printf("%s\t%d\t%d\t%d\t%lf\t\n", pStudent->name, student_get_score(pStudent, 0), student_get_score(pStudent, 1), student_get_score(pStudent, 2), student_average(pStudent));

}
