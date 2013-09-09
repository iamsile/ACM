#include <iostream>
using namespace std;
int n,map[101][101],v[101][101],dep;
int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};

void dfs(int s,int t)
{
    v[s][t]=1;
    for (int i=0; i<4; i++) {
        int sx=s+dx[i];
        int sy=t+dy[i];
        if (sx>=1&&sx<=n&&sy>=1&&sy<=n&&!v[sx][sy]&&map[s][t]==map[sx][sy])
            dfs(sx, sy);
    }
}

int main()
{
    while (scanf("%d",&n)&&n) {
        int i,j,x,y,sum;
        char c[5];
        memset(map, 0, sizeof(map));
        for (i=1; i<=n-1; i++) {
            for (j=1; j<=n; j++) {
                scanf("%d%d",&x,&y);
                map[x][y]=i;
            }
            gets(c);
        }
        for (i=1; i<=n; i++)
            for (j=1; j<=n; j++)
                if (!map[i][j])
                    map[i][j]=n;
        memset(v, 0, sizeof(v));
        for (i=1,sum=0; i<=n; i++)
            for (j=1; j<=n; j++)
                if (!v[i][j]) {
                    dfs(i,j);
                    sum++;
                }
        if (sum==n)
            printf("good\n");
        else printf("wrong\n");
    }
    return 0;
}
/*
 Problem description
 An equidivision of an n x n square array of cells is a partition of the n2 cells in the array in exactly n sets, each one with n contiguous cells. Two cells are contiguous when they have a common side.
 A good equidivision is composed of contiguous regions. The figures show a good and a wrong equidivision for a 5x5 square:
 
 
 Note that in the second example the cells labeled with 4 describe three non-contiguous regions and cells labeled with 5 describe two non-contiguous regions. You must write a program that evaluates if an equidivision of the cells in a square array is good or not. 
 
 
 Input
 It is understood that a cell in an n x n square array is denoted by a pair (i, j), with 1 <=i, j<= n. The input file contains several test cases. Each test case begins with a line indicating n, 0 < n < 100, the side of the square array to be partitioned. Next, there are n - 1 lines, each one corresponding to one partition of the cells of the square, with some non-negative integer numbers. Consecutive integers in a line are separated with a single blank character. A line of the form
 
 
 a1 a2 a3 a4 ... 
 
 means that cells denoted with the pairs (a1, a2), (a3, a4), ... belong to one of the areas in the partition. The last area in the partition is defined by those cells not mentioned in the n - 1 given lines. If a case begins with n = 0 it means that there are no more cases to analyze. 
 
 Output
 For each test case good must be printed if the equidivision is good, in other case, wrong must be printed. The answers for the different cases must preserve the order of the input. 
 
 Sample Input
 2
 1 2 2 1
 5
 1 1 1 2 1 3 3 2 2 2
 2 1 4 2 4 1 5 1 3 1
 4 5 5 2 5 3 5 5 5 4
 2 5 3 4 3 5 4 3 4 4
 5
 1 1 1 2 1 3 3 2 2 2
 2 1 3 1 4 1 5 1 4 2
 4 5 5 2 5 3 5 5 5 4
 2 4 1 4 3 5 4 3 4 4
 0
 Sample Output
 wrong
 good
 wrong
*/