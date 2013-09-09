#include <iostream>
using namespace std;
const int inf=0x4fffffff;
#define N 2002

int dp[N][N],v[N][N],sum[N][N],a[N];
//dp[i][j]表示第i个猴子到第j个猴子认识的总代价
//v[i][j]标示最小分割点处的k值  用于四边形加速
//sum[i][j]i到j花费总和
int main()
{
    int n;
    while (~scanf("%d",&n)) {
        int i,j,k,l,ans=inf;
        for (i=1; i<=n; i++) {
            scanf("%d",&a[i]);
            a[i+n]=a[i];
        }
        memset(sum, 0, sizeof(sum));
        for (i=1; i<2*n; i++) {
            dp[i][i]=0;
            v[i][i]=i;
            for (j=i; j<=n+i; j++)
                sum[i][j]=sum[i][j-1]+a[j];
        }
        for (k=2; k<=n; k++) {
            for (i=1; i+k<=2*n+1; i++) {
                j=i+k-1;
                dp[i][j]=inf;
                for (l=v[i][j-1]; l<=v[i+1][j]; l++)
                    if (dp[i][j]>dp[i][l]+dp[l+1][j]+sum[i][j]) {
                        dp[i][j]=dp[i][l]+dp[l+1][j]+sum[i][j];
                        v[i][j]=l;
                    }
            }
        }
        for (i=1; i<=n; i++)
            ans=min(ans, dp[i][i+n-1]);
        printf("%d\n",ans);
    }
    return 0;
}
/*
 一群猴子围成圈，每个猴子互相不认识，猴王要给大家互相认识，每个猴子认识别人需要一个时间花费，而且A猴子认识B猴子，则A猴子认识的所有猴子和B猴子认识的所有猴子都能认识，这个代价为所有AB猴子认识的猴子的时间花费和。   说的很绕，可以读下题，题目意思就是这样的。
 思路：运用动态规划，枚举每个区间的分割点，从而找到最小花费。因为题目中给出的是环，解决的方法就是设一个长度为2*n的数组可以将环转化为线性。
 转移方程：dp[i][j]=min(dp[i][k]+dp[k+1][j]+sum[i][j]    i<k<j)
 Problem Description
 Far away from our world, there is a banana forest. And many lovely monkeys live there. One day, SDH(Song Da Hou), who is the king of banana forest, decides to hold a big party to celebrate Crazy Bananas Day. But the little monkeys don't know each other, so as the king, SDH must do something.
 Now there are n monkeys sitting in a circle, and each monkey has a making friends time. Also, each monkey has two neighbor. SDH wants to introduce them to each other, and the rules are:
 1.every time, he can only introduce one monkey and one of this monkey's neighbor.
 2.if he introduce A and B, then every monkey A already knows will know every monkey B already knows, and the total time for this introducing is the sum of the making friends time of all the monkeys A and B already knows;
 3.each little monkey knows himself;
 In order to begin the party and eat bananas as soon as possible, SDH want to know the mininal time he needs on introducing.
 
 
 Input
 There is several test cases. In each case, the first line is n(1 ≤ n ≤ 1000), which is the number of monkeys. The next line contains n positive integers(less than 1000), means the making friends time(in order, the first one and the last one are neighbors). The input is end of file.
 
 
 Output
 For each case, you should print a line giving the mininal time SDH needs on introducing.
 
 
 Sample Input
 8
 5 2 4 7 6 1 3 9
 
 
 Sample Output
 105
*/