#include <iostream>
using namespace std;

int n,map[1100][1100],v[1100],flag[1100];

int dfs(int s)
{
    for (int i=0; i<n; i++) {
        if (!v[i]&&map[s][i]) {
            v[i]=1;
            if (flag[i]==-1||dfs(flag[i])) {
                flag[i]=s;
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    while (~scanf("%d",&n)) {
        int i,j,m,s,t,sum=0;
        for (i=0; i<n; i++)
            for (j=0; j<n; j++)
                map[i][j]=0;
        for (i=0; i<n; i++) {
            scanf("%d: (%d)",&s,&m);
            for (j=0; j<m; j++) {
                scanf("%d",&t);
                map[s][t]=1;
            }
        }
        memset(flag, -1, sizeof(flag));
        memset(v, 0, sizeof(v));
        for (i=0; i<n; i++) {
            memset(v, 0, sizeof(v));
            if (dfs(i))
                sum++;
        }
        printf("%d\n",n-sum/2);
    }
    return 0;
}
/*
 最大独立集指的是两两之间没有边的顶点的集合，顶点最多的独立集成
 为最大独立集。二分图的最大独立集=节点数-（减号）最大匹配数。
 For the study reasons it is necessary to find out the maximum set satisfying
 the condition: there are no two students in the set who have been "romantically involved"。
 
 由于本题是要找出最大的没有关系的集合，即最大独立集。而求最大独立集重点在于求最大匹配数,
 本题中给出的是同学之间的亲密关系，并没有指出哪些是男哪些是女，所以求出的最大匹配数
 要除以2才是真正的匹配数。
 Problem Description
 the second year of the university somebody started a study on the romantic relations between the students. The relation “romantically involved” is defined between one girl and one boy. For the study reasons it is necessary to find out the maximum set satisfying the condition: there are no two students in the set who have been “romantically involved”. The result of the program is the number of students in such a set.
 
 The input contains several data sets in text format. Each data set represents one set of subjects of the study, with the following description:
 
 the number of students
 the description of each student, in the following format
 student_identifier:(number_of_romantic_relations) student_identifier1 student_identifier2 student_identifier3 ...
 or
 student_identifier:(0)
 
 The student_identifier is an integer number between 0 and n-1, for n subjects.
 For each given data set, the program should write to standard output a line containing the result.
 
 
 Sample Input
 7
 0: (3) 4 5 6
 1: (2) 4 6
 2: (0)
 3: (0)
 4: (2) 0 1
 5: (1) 0
 6: (2) 0 1
 3
 0: (2) 1 2
 1: (1) 0
 2: (1) 0
 
 
 Sample Output
 5
 2
*/