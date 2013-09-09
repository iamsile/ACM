#include<iostream>
using namespace::std;

int MaxSum(int *a,int n)
{
    int i,sum,b;
    sum=a[0];
    b=0;
    for(i=0;i<n;i++)
    {
        if(b>0)
            b+=a[i];
        else
            b=a[i];
        if(b>sum)
            sum=b;
    }
    return sum;
}

int main()
{
    int n;
    int a[100][100];
    int max,lab,sum[102],o,i,j,k;
    while(cin >> n&&n)
    {
        memset(a,0,sizeof(a));
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
				cin >> a[i][j];
        max=0;
        for(i=0;i<n;i++)
        {
            for(j=i;j<n;j++)
            {
                memset(sum,0,sizeof(sum));
                for(o=0;o<n;o++)
                    for(k=i; k<=j; k++)
                        sum[o]+=a[k][o];
                lab=MaxSum(sum,n);
                if(lab>max)
					max=lab;
            }
        }
        cout << max << '\n';
    }
}
/*
#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int n;
    while (~scanf("%d",&n)) {
        int i,j,k,maxn=0,a[110][110]={0},b[110][110]={0},dp[110]={0};
        for (i=1; i<=n; i++)
            for (j=1; j<=n; j++)
                cin >> a[i][j];
        for (i=1; i<=n; i++)
            b[1][i]=a[1][i];
        for (i=2; i<=n; i++) 
            for (j=1; j<=n; j++) 
                b[i][j]=b[i-1][j]+a[i][j];
        for (i=1; i<=n; i++)
            for (j=i; j<=n; j++) {
                dp[1]=b[j][1]-b[i-1][1];
                for (k=2; k<=n; k++) {
                    if (dp[k-1]>0)
                        dp[k]=dp[k-1]+b[j][k]-b[i-1][k];
                    else dp[k]=b[j][k]-b[i-1][k];
                    if (dp[k]>maxn)
                        maxn=dp[k];
                }
            }
        cout << maxn << '\n';
    }
    return 0;
}
*/
/*这个问题可以看做一维的延伸，求子矩阵的元素和的最大值，就是求二维中几列连续元素和的最大值；
 
 思路:在这里的N行中先选定对应的行
 for(i=0;i<n;i++)
 for(j=i;j<n;j++)
 选定了行之后，将一列中的元素全部相加，作为一个数字看待，这时就是一维求最大值的问题了；
 例子：
 2      5      6      3
 5      6      9      1 
 2     -5     -9      6 
 4     -1      6      8 
 假设选定了第一到三行：则简化为：11（5+2+4），0（6-5-1），6（9-9+6），15（1+6+8）
 则求这一列的最大连续元素和的最大值，（此处可以有很多方法求解，我这里采用了函数法，方便以后重用。）其余行同方法可解；
 */
/*
 Problem description
 Given a two-dimensional array of positive and negative integers, a sub-rectangle is any contiguous sub-array of size 1*1 or greater located within the whole array. The sum of a rectangle is the sum of all the elements in that rectangle. In this problem the sub-rectangle with the largest sum is referred to as the maximal sub-rectangle. 
 As an example, the maximal sub-rectangle of the array: 
 
 0 -2 -7 0 
 9 2 -6 2 
 -4 1 -4 1 
 -1 8 0 -2 
 is in the lower left corner: 
 
 9 2 
 -4 1 
 -1 8 
 and has a sum of 15. 
 
 Input
 The input consists of an N * N array of integers. The input begins with a single positive integer N on a line by itself, indicating the size of the square two-dimensional array. This is followed by N^2 integers separated by whitespace (spaces and newlines). These are the N^2 integers of the array, presented in row-major order. That is, all numbers in the first row, left to right, then all numbers in the second row, left to right, etc. N may be as large as 100. The numbers in the array will be in the range [-127,127].
 
 Output
 Output the sum of the maximal sub-rectangle.
 
 Sample Input
 4
 0 -2 -7 0
 9 2 -6 2
 -4 1 -4  1
 -1 8  0 -2
 Sample Output
 15
 */
