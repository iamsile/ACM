#include <iostream>
#include <math.h>
using namespace std;
#define inf 0x7fffffff

struct node {
    double x,y;
};
double map[220][220],dp[220][220];

double cal(node a,node b)
{
    double x=a.x-b.x;
    double y=a.y-b.y;
    return sqrt(x*x+y*y);
}

int main()
{
    int n;
    while (~scanf("%d",&n)) {
        node coor[1001];
        int i,j;
        for (i=0; i<n; i++)
            scanf("%lf%lf",&coor[i].x,&coor[i].y);
        for (i=0; i<n; i++)
            for (j=0; j<i; j++)
                map[i][j]=map[j][i]=cal(coor[i],coor[j]);
        memset(dp, 0, sizeof(dp));
        dp[0][1]=map[0][1];
        for (i=2; i<n; i++) {
            for (j=0; j<=i-2; j++)
                dp[j][i]=dp[j][i-1]+map[i-1][i];
            dp[i-1][i]=inf;
            for (j=0; j<=i-2; j++)
                dp[i-1][i]=min(dp[i-1][i], dp[j][i-1]+map[j][i]);
            dp[i][i]=dp[i-1][i]+map[i-1][i];
        }
        printf("%.2lf\n",dp[n-1][n-1]);
    }
    return 0;
}
/*
 一个人从p1严格地增的走到pn，然后再严格递减的回到p1;求总路径的最小值；
 网上看到很多解题报告看的我直冒汗
 对于1 <= i <= j <= n, 我们定义P(i, j)是一条包含了P1, P2, P3 …… Pj的途径; 这条路径可以分成2部分：递减序列与递增序列，起点是Pi(1 <= i <= j)，拐点是P1，终点是Pj, P[i, j]为其最小值；那么状态转移方程为：
 b[1,2] = |P1P2|,
 i < j-1时， b[i,j] = b[i,j-1] + |Pj-1Pj|    点Pj-1在递增序列中，
 i = j-1时， b[i,j] = min{ b[k,j-1] + |PkPj|, 1<= k < j-1 }  点Pj-1在递减序列中
 b[n,n] = b[n-1,n] + |Pn-1Pn|
 Problem Description
 There are n points on the plane, Pi(xi, yi)(1 <= i <= n), and xi < xj (i<j). You begin at P1 and visit all points then back to P1. But there is a constraint:
 Before you reach the rightmost point Pn, you can only visit the points those have the bigger x-coordinate value. For example, you are at Pi now, then you can only visit Pj(j > i). When you reach Pn, the rule is changed, from now on you can only visit the points those have the smaller x-coordinate value than the point you are in now, for example, you are at Pi now, then you can only visit Pj(j < i). And in the end you back to P1 and the tour is over.
 You should visit all points in this tour and you can visit every point only once.
 
 
 Input
 The input consists of multiple test cases. Each case begins with a line containing a positive integer n(2 <= n <= 200), means the number of points. Then following n lines each containing two positive integers Pi(xi, yi), indicating the coordinate of the i-th point in the plane.
 
 
 Output
 For each test case, output one line containing the shortest path to visit all the points with the rule mentioned above.The answer should accurate up to 2 decimal places.
 
 
 Sample Input
 3
 1 1
 2 3
 3 1
 
 
 Sample Output
 6.47
*/