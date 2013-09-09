#include <iostream>
using namespace std;
int a[1100],dp[130][70][1100];

int main()
{
    int tt;
    scanf("%d",&tt);
    while(tt--) {
        int i,j,k,n,m,t,flag,num=0;
        scanf("%d%d%d",&n,&m,&t);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(i=0;i<=m;i++)
            for(j=0;j<=t;j++)
                for(k=0;k<=n;k++)
                    dp[i][j][k]=-1;
        dp[0][0][0]=0;
        for(i=0;i<n;i++)
            for(j=0;j<=m;j++)
                for(k=0;k<=t;k++)
                    if(dp[j][k][i]>-1) {
                        if(j<m&&k<t) {
                            num=dp[j][k][i]+(k+1)*a[i];
                            if(dp[j+1][k+1][i+1]<num)
                                dp[j+1][k+1][i+1]=num;
                        }
                        if(dp[j][0][i+1]<dp[j][k][i])
                            dp[j][0][i+1]=dp[j][k][i];
                    }
        for(flag=-1,i=0;i<=t;i++)
            if(flag<dp[m][i][n])
                flag=dp[m][i][n];
        if(flag<0)
            printf("impossible\n");
        else printf("%d\n",flag);
    }
    return 0;
}
/*
 Problem description
 You are at work. Unfortunately, there is a programming competition immediately after your working hours. In order to perform well, you need some sleep at work to regain as much energy as possible. Your workday is N minutes long, and each minute has an energy value, e0,e1...eN-1. Your sleep requirement is exactly M minutes, but you can only sleep for a maximum of R minutes in a row before your boss notices. There is a bonus if you sleep for several minutes in a row; the i-th minute in a row will have its energy value multiplied by i. For instance, if you sleep for three minutes having energy values of 10, 10 and 9, you will gain 10 + 2-10 + 3-9 = 57 energy. After you have slept for M minutes, you are fully rested and cannot sleep any more that day. You have decided to write a computer program which calculates the maximum amount of energy you can gain during a given workday.
 
 Input
 The first line of input contains a single integer T, the number of test cases to follow. Each test case begins with a line containing three integer numbers, N, the number of minutes in your workday, M, the sleep requirement in number of minutes, and R, the maximum number of minutes in a row you can sleep before your boss notices. Then follows a line containing N numbers, e0,e1,...,eN-1, each minute's energy value.
 
 Output
 For each test case output one line containing a single number, the highest amount of energy that can be gained by sleeping a total of M minutes, or output impossible if it is not possible to get the required amount of sleep.
 
 Sample Input
 2
 10 3 3
 10 10 9 6 5 4 2 1 4 4
 10 6 1
 1 2 3 4 5 6 7 8 9 10
 Sample Output
 57
 impossible
*/