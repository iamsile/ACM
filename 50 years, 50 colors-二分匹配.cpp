#include <iostream>
using namespace std;
#define N 110
int n,m,map[N][N],c[N],g[N][N],v[N],flag[N];

bool dfs(int s)
{
    int i,k;
    for (i=1; i<=g[s][0]; i++) {
        k=g[s][i];
        if (!v[k]) {
            v[k]=1;
            if (flag[k]==-1||dfs(flag[k])) {
                flag[k]=s;
                return 1;
            }
        }
    }
    return 0;
}

int cal()
{
    int i,sum=0;
    memset(flag, -1, sizeof(flag));
    for (i=1; i<=n; i++) {
        memset(v, 0, sizeof(v));
        if (dfs(i))
            sum++;
    }
    return sum;
}

int main()
{
    while (scanf("%d%d",&n,&m),n||m) {
        int i,j,k,a[110],cnt=0;
        for (i=1; i<=n; i++)
            for (j=1; j<=n; j++) {
                scanf("%d",&map[i][j]);
                c[map[i][j]]=1;
            }
        for (i=1; i<=50; i++) {
            if (c[i]) {
                for (j=1; j<=n; j++)
                    g[j][0]=0;
                for (j=1; j<=n; j++)
                    for (k=1; k<=n; k++)
                        if (map[j][k]==i)
                            g[j][++g[j][0]]=k;
                if (cal()>m)
                    a[++cnt]=i;
            }
        }
        if (cnt==0)
            printf("-1\n");
        else {
            for (i=1; i<=cnt; i++) {
                if (i>1)
                    printf(" ");
                printf("%d",a[i]);
            }
            printf("\n");
        }
    }
    return 0;
}/*
  Problem Description
  On Octorber 21st, HDU 50-year-celebration, 50-color balloons floating around the campus, it's so nice, isn't it? To celebrate this meaningful day, the ACM team of HDU hold some fuuny games. Especially, there will be a game named "crashing color balloons".
  
  There will be a n*n matrix board on the ground, and each grid will have a color balloon in it.And the color of the ballon will be in the range of [1, 50].After the referee shouts "go!",you can begin to crash the balloons.Every time you can only choose one kind of balloon to crash, we define that the two balloons with the same color belong to the same kind.What's more, each time you can only choose a single row or column of balloon, and crash the balloons that with the color you had chosen. Of course, a lot of students are waiting to play this game, so we just give every student k times to crash the balloons.
  
  Here comes the problem: which kind of balloon is impossible to be all crashed by a student in k times.
  
  
  
  
  
  Input
  There will be multiple input cases.Each test case begins with two integers n, k. n is the number of rows and columns of the balloons (1 <= n <= 100), and k is the times that ginving to each student(0 < k <= n).Follow a matrix A of n*n, where Aij denote the color of the ballon in the i row, j column.Input ends with n = k = 0.
  
  
  Output
  For each test case, print in ascending order all the colors of which are impossible to be crashed by a student in k times. If there is no choice, print "-1".
  
  
  Sample Input
  1 1
  1
  2 1
  1 1
  1 2
  2 1
  1 2
  2 2
  5 4
  1 2 3 4 5
  2 3 4 5 1
  3 4 5 1 2
  4 5 1 2 3
  5 1 2 3 4
  3 3
  50 50 50
  50 50 50
  50 50 50
  0 0
  
  
  Sample Output
  -1
  1
  2
  1 2 3 4 5
  -1
*/