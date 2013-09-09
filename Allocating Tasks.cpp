#include <iostream>
#include <stdio.h>
using namespace std;
const int inf=0x3f3f3f3f;
int dp[150][203];
int a[150],b[150];

int main()
{
    int m,i,j,n,ha,hb,sum;
    scanf("%d",&m);
    while(m--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%d%d",&a[i],&b[i]);
        for(i=0;i<=n;i++)
            for(j=0;j<202;j++)
                dp[i][j]=inf;
        dp[0][100]=0;
        for(i=1;i<=n;i++)
            for(j=0;j<=200;j++)
            {
                if(dp[i-1][j]==inf)
                    continue;
                if(j<100)
                {
                    ha=dp[i-1][j]-(100-j);
                    hb=dp[i-1][j];
                }
                else
                {
                    ha=dp[i-1][j];
                    hb=dp[i-1][j]-(j-100);
                }
                if(j<100)
                {
                    dp[i][ha+a[i]-hb+100]=min(dp[i][ha+a[i]-hb+100],max(dp[i-1][j],ha+a[i]));
                    dp[i][100-b[i]]=min(dp[i][100-b[i]],dp[i-1][j]+b[i]);
                }
                else
                {
                    dp[i][ha-hb-b[i]+100]=min(dp[i][ha-hb-b[i]+100],max(dp[i-1][j],hb+b[i]));
                    dp[i][100+a[i]]=min(dp[i][100+a[i]],dp[i-1][j]+a[i]);
                }
            }
        sum=inf;
        for(i=0;i<=200;i++)
            sum=min(sum,dp[n][i]);
        printf("%d\n",sum);
    }
    return 0;
}
/*
 There are two men A and B. There are n tasks, namely task 1, task 2, ..., task n. You must assign each task to one person to solve it. There are some facts you must know and comply with:
 1. You must assign each task to only one person to solve.
 2. At any time, one person can solve at most one task.
 3. Task i (0 < i < n) can be solved if and only if each task j (0 < j < i) has been solved or is solving.
 4. If a task is solving by one person, it cannot be interrupted.
 5. The same task maybe cost them different time.
 6. One person can go to solve his task when another person can also do at the same time.

 You want to do finish all the tasks as soon as possible.

 输入
 There are multiple test cases. The first line of the input is an integer T (0 < T < 1000) indicating the number of test cases. Then T test cases follow. Each test case starts with an integer n (0 < n < 100). The ith line of the next n lines contains two integers tA, tB (0 < tA, tB < 100), giving the time to solve the ith task by person A and person B.
 输出
 For each test case, output the minimum time when all the tasks have been solved.
 样例输入
 4
 1
 1 2
 2
 1 2
 2 1
 2
 1 2
 90 95
 3
 1 3
 1 3
 1 3
 样例输出
 1
 1
 90
 3
*/