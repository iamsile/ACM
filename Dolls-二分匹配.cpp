#include <iostream>
using namespace std;
#define N 510
int n,w[N],l[N],h[N],map[N][N],flag[N],v[N];

int dfs(int s)
{
    int i;
    for (i=1; i<=n; i++)
        if (!v[i]&&map[s][i]) {
            v[i]=1;
            if (flag[i]==-1||dfs(flag[i])) {
                flag[i]=s;
                return 1;
            }
        }
    return 0;
}

int main()
{
    while (scanf("%d",&n),n) {
        int i,j,sum=0;
        for (i=1; i<=n; i++)
            scanf("%d%d%d",&w[i],&l[i],&h[i]);
        memset(map, 0, sizeof(map));
        for (i=1; i<=n; i++)
            for (j=1; j<=n; j++)
                if (i!=j)
                    if (w[i]<w[j]&&l[i]<l[j]&&h[i]<h[j])
                        map[i][j]=1;
        memset(flag, -1, sizeof(flag));
        for (i=1; i<=n; i++) {
            memset(v, 0, sizeof(v));
            if (dfs(i))
                sum++;
        }
        printf("%d\n",n-sum);
    }
    return 0;
}
/*
 Problem Description
 Do you remember the box of Matryoshka dolls last week? Adam just got another box of dolls from Matryona. This time, the dolls have different shapes and sizes: some are skinny, some are fat, and some look as though they were attened. Specifically, doll i can be represented by three numbers wi, li, and hi, denoting its width, length, and height. Doll i can fit inside another doll j if and only if wi < wj , li < lj , and hi < hj .
 That is, the dolls cannot be rotated when fitting one inside another. Of course, each doll may contain at most one doll right inside it. Your goal is to fit dolls inside each other so that you minimize the number of outermost dolls.
 
 
 Input
 The input consists of multiple test cases. Each test case begins with a line with a single integer N, 1 ≤ N ≤ 500, denoting the number of Matryoshka dolls. Then follow N lines, each with three space-separated integers wi, li, and hi (1 ≤ wi; li; hi ≤ 10,000) denoting the size of the ith doll. Input is followed by a single line with N = 0, which should not be processed.
 
 
 Output
 For each test case, print out a single line with an integer denoting the minimum number of outermost dolls that can be obtained by optimally nesting the given dolls.
 
 
 Sample Input
 3
 5 4 8
 27 10 10
 100 32 523
 3
 1 2 1
 2 1 1
 1 1 2
 4
 1 1 1
 2 3 2
 3 2 2
 4 4 4
 0
 
 
 Sample Output
 1
 3
 2
*/