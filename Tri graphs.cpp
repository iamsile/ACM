#include <iostream>
using namespace std;
int a[100001][3],dp[100001][3];

int main()
{
    int i,n,k1,k2,lab=1;
    while (cin >> n&&n) {
        cin >> a[0][0] >> a[0][1] >> a[0][2];
        dp[0][0]=a[0][0];dp[0][1]=a[0][1];
        dp[0][2]=a[0][1]+a[0][2];
        cin >> a[1][0] >> a[1][1] >> a[1][2];
        dp[1][0]=a[0][1]+a[1][0];
        k1=min(dp[0][1], dp[0][2]);
        dp[1][1]=min(k1, dp[1][0])+a[1][1];
        dp[1][2]=min(k1, dp[1][1])+a[1][2];
        for (i=2; i<n; i++) {
            cin >> a[i][0] >> a[i][1] >> a[i][2];
            k2=min(dp[i-1][0], dp[i-1][1]);//楼上1,2较小 
            k1=min(dp[i-1][1], dp[i-1][2]);//楼上2,3较小
            dp[i][0]=k2+a[i][0];
            dp[i][1]=min(k2, dp[i-1][2]);
            dp[i][1]=min(dp[i][1], dp[i][0])+a[i][1];
            dp[i][2]=min(k1, dp[i][1])+a[i][2];
        }
        cout << lab++ << ". " << dp[n-1][1] << '\n';
    }
    return 0;
}
/* source code of submission 736533, Zhongshan University Online Judge System
#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;
const int MAX = 100002;
long long dp[MAX][4];
int d1,d2,d3,n;

long long min1(long long x,long long y)
{
    if(x < y) return x;
    else return y;
}

long long min2(long long a,long long b,long long c)
{
    long long _min = a;
    if(_min > b) _min = b;
    if(_min > c) _min = c;
    
    return _min;
}

long long min3(long long a,long long b,long long c,long long d)
{
    long long _min = a;
    if(_min > b) _min = b;
    if(_min > c) _min = c;
    if(_min > d) _min = d;
    
    return _min;
}

int main()
{
    int i,ca = 0;
    
    while(scanf("%d",&n) && n)
    {
        scanf("%d %d %d",&d1,&d2,&d3);
        dp[0][0] = 0; dp[0][1] = d2; dp[0][2] = d2 + d3;
        
        for(i = 1;i < n;++i)
        {
            scanf("%d %d %d",&d1,&d2,&d3);
            
            if(i == 1)
            {
                dp[i][0] = d1 + dp[i-1][1];
                dp[i][1] = d2 + min2(dp[i][0],dp[i-1][1],dp[i-1][2]);
                dp[i][2] = d3 + min2(dp[i][1],dp[i-1][1],dp[i-1][2]);
            }
            else
            {
                dp[i][0] = d1 + min1(dp[i-1][0],dp[i-1][1]);
                dp[i][1] = d2 + min3(dp[i][0],dp[i-1][0],dp[i-1][1],dp[i-1][2]);
                dp[i][2] = d3 + min2(dp[i][1],dp[i-1][1],dp[i-1][2]);
            }
        }
        
        printf("%d. %d\n",++ca,dp[n-1][1]);
    }
    
    return 0;
}
*/
/*
 基本的dp,比较简单。注意第一行右边的格子只能从中间走过去：dp[0][2] = d2 + d3;
 　　第二行左边格子只能从第一行中间格子走到:dp[1][0] = d1 + dp[0][1];
 　　第二行中间格子从第一行的中间,右边和第二行的左边格子走到:dp[1][1] = min2(dp[1][0],dp[0][1],dp[0][2]);
 Problem description
 Here’s a simple graph problem: Find the shortest path from the top-middle vertex to the bottom-middle vertex in a given tri-graph. A tri-graph is an acyclic graph of (N ≥ 2) rows and exactly 3 columns. Unlike regular graphs, the costs in a tri-graph are associated with the vertices rather than the edges. So, considering the example on the right with N = 4, the cost of going straight down from the top to bottom along the middle vertices is 7+13+3+6 = 29. The layout of the directional edges in the graph are always the same as illustrated in the figure. 
 
 
 Input
 Your program will be tested on one or more test cases. Each test case is specified using N + 1 lines where the first line specifies a single integer (2 ≤ N ≤ 100, 000) denoting the number of rows in the graph. N lines follow, each specifying three integers representing the cost of the vertices on the ith row from left to right. The square of each cost value is less than 1,000,000.
 The last case is followed by a line with a single zero. 
 
 
 Output
 For each test case, print the following line:
 k.n
 Where k is the test case number (starting at one,) and n is the least cost to go from the top-middle vertex to the bottom-middle vertex. 
 
 
 Sample Input
 4
 13 7 5
 7 13 6
 14 3 12
 15 6 16
 0
*/