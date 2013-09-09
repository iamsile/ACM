#include <iostream>
using namespace std;

typedef struct {
    int ave,id,s1,s2,r;
    char a[50];
}st;
st stu[1010];

int cmp(const void *c,const void *d)
{
    return ((st *)c)->ave - ((st *)d)->ave;
}

int cmp1(const void *c,const void *d)
{
    return ((st *)c)->id - ((st *)d)->id;
}

int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m)!=EOF) {
        int i,j;
        for (i=0; i<n; i++) {
            cin >> stu[i].id >> stu[i].a
            >> stu[i].s1 >> stu[i].s2;
            stu[i].ave=m*stu[i].s1+(100-m)*stu[i].s2;
        }
        qsort(stu, n, sizeof(stu[0]), cmp);
        stu[n-1].r=1;
        j=0;
        for(i=n-1;i>=0;i--)
        {
            if(i<n-1)
            {
                if(stu[i].ave==stu[i+1].ave)stu[i].r=stu[i+1].r;
                else stu[i].r=j+1;
            }
            j++;
        }
        qsort(stu, n, sizeof(stu[0]), cmp1);
        cout << "ID\\NAME\\SCOR1\\SCOR2\\COMSCOR\\RANK\n";
        for (i=0; i<n; i++)
            printf("%d\\%s\\%d\\%d\\%.3f\\%d\n",stu[i].id,stu[i].a,stu[i].s1,
                   stu[i].s2,(double)stu[i].ave/100,stu[i].r);
    }
    return 0;
}
/*
 Problem description
 Xiao Lei is a student cadre working in student union . Every day he has many works to do , so he is always the last one go to bed and the first one wake up. Especially in middle test and final test he must compute all of student’s comprehensive score(COMSCOR) and give their rank(RANK). So,he must do it and check it very carefully . You can imagine how bored and tired it is . One day , Xiao Lei hears that your ACM funs can do that very easy . He is uncertain and want to make it sure. If that’s true ,he will also join in ,because it is so useful for his work and study. So, the next day he bring some data papers to test you. The data paper contains many students’ informations. Each student has a given number(ID), name(NAME) , score of studying (SCOR1) and score of practice (SCOR2) . Each information in a line but may not in the order of their ID. And he tells you how many students and how to compute the COMSCOR. That is: COMSCOR=( k%)*SCOR1 + (1-k%)* SCOR2. (k is a integer and 0<=k<=100) Your task is to write a program to compute the comprehensive score (COMSCOR) of each student and give each student a rank ,then output the list in the order of ID. If A’s COMSCOR == B’s COMSCOR, their rank is the same .As a ACM fun can you complete this useful task? 
 
 Input
 The input contains only one test case . The first line contain two integer N and K , N is the number of students(1<=N<=1000) , K is the proportion( 0<=K<=100) Of SCOR1. Next N line ,each line contains four data :ID, NAME , SCOR1 , SCOR2 separator by one or more blanks. Suppose that the ID is from 1 to N and different student has different ID. The NAME only contains alpha characters and the length not exceed 30 . The SCOR1 and SCOR2 are both integer between 0 and 100. 
 
 Output
 The output should first output the head title“NAME” ,”SCOR1” , “SCOR2”, “COMSCOR” and “RANK” separator by a ‘\’ character . Then output each student’s corresponding information below in the order of their ID also separator by a \’ character. Each in a line . The value of COMSCOR should be rounded to three digits after the decimal point.
 
 Sample Input
 3 50
 1 zhangsan 80 90
 2 lisi 90 80
 3 wangwu 100 10
 Sample Output
 ID\NAME\SCOR1\SCOR2\COMSCOR\RANK
 1\zhangsan\80\90\85.000\1
 2\lisi\90\80\85.000\1
 3\wangwu\100\10\55.000\3
*/