#include <iostream>
using namespace std;
int b[30][30],sum,minx,v[30],l1,l2,map[30][30],c[30][30];

void dfs(int s)
{
    if (s>l2) {
        if (sum<minx) {
            minx=sum;
        for (int i=0; i<6; i++)
            for (int j=0; j<6; j++)
                c[i][j]=map[i][j];
        }
        return;
    }
    for (int i=0; i<l1; i++)
        if (!v[i]) {
            sum+=b[s][i];
            v[i]=1;
            map[s][i]=1;
            dfs(s+1);
            sum-=b[s][i];
            map[s][i]=0;
            v[i]=0;
        }
}

int main()
{
    char a[1001];
    int i,j,k,n;
    l1=0;l2=0;
    while (gets(a)) {
        k=strlen(a);
        n=0;
        l2=0;
        for (i=0; i<k; i++)
            if (a[i]==' '&&n) {
                b[l1][l2++]=n;
                n=0;
            }
            else if (a[i]!=' ')
                n=n*10+a[i]-'0';
        b[l1++][l2]=n;
    }
    minx=99999;
    sum=0;
    memset(v, 0, sizeof(v));
    dfs(0);
    printf("The shortest time is %d hours\n",minx);
    for (i=0; i<6; i++)
        for (j=0; j<6; j++)
            if (c[i][j])
                printf("Task %d is distributed to employee %d\n",i,j);
    printf("\n");
    return 0;
}
/*
 Problem description
 A manager of one company received a emergent project that needs to be completed in shortest time。With considering and analysing, the manager would divide the project into N independent tasks and that needs N employees to complete. Every ernployee can do any one of the N tasks, but the time is different. Please design a allocation scheme for the manager to make the task can be completed in shortest time. 
 
 Input
 The number of the employees N begins with 0, so is the tasks number N. The time of every task done by every employee is stored in a two-dimensional array task_worker[N][N]. For example: task_worker[i][j] means the time of task i completed by employee j.
 
 Output
 The first row show the shortest time to complete the project.(unit: hour)
 Output the situation of the allocation scheme. 
 
 Sample Input
 10  11  12  11  9  11
 11  9   10  13  11  12
 12  10  11  10  13  9
 9   14  9   10  10  11
 10  10  9   11  12  11
 10  7  10   10  10   8
 Sample Output
 The shortest time is 54 hours
 Task 0 is distributed to employee 4
 Task 1 is distributed to employee 1
 Task 2 is distributed to employee 3
 Task 3 is distributed to employee 0
 Task 4 is distributed to employee 2
 Task 5 is distributed to employee 5
*/