#include <iostream>
#include <string.h>
using namespace std;
int n,m,map[10][10];
int d[8][2]={{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1},{-2,1}};
long long num;

void dfs(int x,int y,int k)
{
    if (y==n) {
        ++x;
        y=0;
    }
    if (k==m) {
        num++;
        return;
    }
    if (x==n)
        return;
    if (!map[x][y]) {
        int i,loc=0,pos[8][2];
        for (i=0; i<8; i++) {
            int dx=x+d[i][0];
            int dy=y+d[i][1];
            if (dx>=0&&dx<n&&dy>=0&&dy<n&&!map[dx][dy]) {
                map[dx][dy]=1;
                pos[loc][0]=dx;
                pos[loc][1]=dy;
                loc++;
            }
        }
        map[x][y]=1;
        dfs(x, y+1, k+1);
        map[x][y]=0;
        for (i=0; i<loc; i++)
            map[pos[i][0]][pos[i][1]]=0;
    }
    dfs(x, y+1, k);
}

int main()
{
    while (cin >> n >> m) {
        num=0;
        memset(map, 0, sizeof(map));
        dfs(0,0,0);
        cout << num << '\n';
    }
    return 0;
}
/*
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#define INF 1000000000
#define MAXN 0

using namespace std;

template <class T> void inline checkMin(T &a, T b)	{if(a > b) a = b;}
template <class T> void inline checkMax(T &a, T b)	{if(a < b) a = b;}
typedef long long LL;

int dir[8][2] = {{-2,1},{-2,-1},{2,1},{2,-1},{1,-2},{1,2},{-1,2},{-1,2}};
int  n, m;
LL ans;
int map[10][10];
void dfs(int r, int c, int k)
{
    if(c == m)
    {
        ++r;  c = 0;
    }
    if(k == n)
    {
        ++ans;
        return;
    }
    if(r == m)  return;
    if(!map[r][c])
    {
        int cnt(0);
        int pos[8][2];
        for(int i = 0; i < 8; ++i)
        {
            int rr = r + dir[i][0];
            int cc = c + dir[i][1];
            if(rr >= 0 && rr < m && cc >=0 && cc < m && !map[rr][cc])
            {
                map[rr][cc] = true;
                pos[cnt][0] = rr;
                pos[cnt++][1] = cc;
            }
        }
        map[r][c] = true;
        dfs(r, c+1, k+1);
        map[r][c] = false;
        for(int i = 0; i < cnt; ++i)
        {
            map[pos[i][0]][pos[i][1]] = false;
        }
    }
    dfs(r, c+1, k);
}
int main()
{
    while(scanf("%d%d",&m,&n) != EOF)
    {
        ans = 0;
        memset(map, 0, sizeof(map));
        dfs(0,0,0);
        printf("%I64d\n",ans);
    }
    return 0;
}
*/
/*
#include<iostream>
using namespace std;
const int N = 7;
int cnt[1<<N];
int dp[N][70][70][40];

inline bool check(int a,int b,int c)
{
    if( (a&(c>>1)) !=0 || (a&(c<<1)) != 0) return 0;
    if( (a&(b>>2)) !=0 || (a&(b<<2)) != 0) return 0;
    return 1;
}

void init()
{
    int i,j,k;
    memset(cnt,0,sizeof(cnt));
    for(i=1;i<=100;i++)
    {
        int  t = i;
        while(t)
        {
            if(t&1) cnt[i]++;
            t >>= 1;
        }
    }
}

int main()
{
    init();
    int i,j,k,n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if( n == 1) printf("%d\n",(m>1)?0:1);
        else
        {
            int s = (1<<n);
            memset(dp,0,sizeof(dp));
            for(i=0;i<s;i++)
                dp[1][i][0][cnt[i]] = 1;
            for(i = 2 ; i <= n; i++)
                for(int l = 0; l<s ;l++ )
                    for(int  p = 0; p<s ; p++)
                        for(k = cnt[l]+cnt[p]; k<= min(m,n*i); k++)
                            for( j = 0 ;j < s ;j++ )
                                if( check(j,p,l) && cnt[j]+k <= min(m,n*i))
                                    dp[i][j][p][cnt[j]+k] += dp[i-1][p][l][k];
            int ans = 0;
            for(i = 0 ;i < (1<<n) ;i++)
                for(j = 0 ; j < (1<<n);j++)
                    ans += dp[n][i][j][m];
            cout<<ans<<endl;
        }
    }
    return 0;
}    
*/
/*
#include<iostream>
using namespace std;
int a[216] =
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    4, 6, 4, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    9, 28, 36, 18, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    16, 96, 276, 412, 340, 170, 48, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    25, 252, 1360, 4436, 9386, 13384, 12996, 8526, 3679, 994, 158, 15, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    36, 550, 4752, 26133, 97580, 257318, 491140, 688946, 716804, 556274, 323476, 141969, 47684, 12488, 2560, 393, 40, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int main()
{
    int n, m;
    while(~scanf("%d %d", &m, &n))
        printf("%d\n", a[(m - 1) * 36 + n - 1]);
    return 0;
}
*/
/*
 Problem description
 Well, I haven't given very many chess problems, so here's one. In chess, a knight (the horsehead piece) moves quite differently than any other piece. It moves in an L-type shape. That is, it can move two squares in one direction, then one square in the perpendicular direction (knights can not move diagonally). As an example, consider this:
 .	.	.	.	.	.	.	.
 .	.	.	.	.	.	.	.
 .	.	.	*	.	*	.	.
 .	.	*	.	.	.	*	.
 .	.	.	.	K	.	.	.
 .	.	*	.	.	.	*	.
 .	.	.	*	.	*	.	.
 .	.	.	.	.	.	.	.
 The knight is in the square marked by a `K'. The `*' around it are the possible positions the knight can move on the next turn. The `.' are empty squares.
 
 If you place two knights on the board, things get a little more complicated. We say that a knight can not be taken if there is not knight that can land on it's square on the next turn. This condition has to hold reguardless of what order the knights move (ie, the knights can't `move' out of the way).
 
 
 Input
 Each line of input will have two integers, M, N, separated by exactly one space. The chessboard has size M x M. We're interested in placing N knights on the board such that no knight can take any other knight. The number of knights will be in the range 1 to 36 (inclusive). M will be in the range 1 to 6 (inclusive).
 
 Output
 For each line of input, your program should print out the number of ways that we can place N knights on an M x M chessboard. The answer will always fit in an unsigned, 32 bit integer. 
 
 Sample Input
 2 2
 3 2
 6 4
 6 15
 Sample Output
 6
 28
 26133
 2560
*/