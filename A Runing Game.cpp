#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

typedef struct node{            
    int m;
    int rank;
}mat;
mat a[105];

int cmp(mat a,mat b)
{
    return a.rank<b.rank;
}

int main()
{
    int t,n,m,i;
    scanf("%d",&t);
    while(t--)
    {
        int count=0;
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)
            scanf("%d%d",&a[i].m,&a[i].rank);
        sort(a,a+n,cmp);
        for(i=n-1;i>0;i--)
            if(a[i].m>a[i-1].m)
                count++;
        count=count*400+a[0].m;
        if(count<=m)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
/*
#include <cstdio>
#include <cstdlib>

struct Player
{
    int x;
    int rank;
};

inline int cmp(const void *a,const void *b)
{
    return ((Player *)b)->rank-((Player *)a)->rank;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        Player player[n];
        for(int i=0;i<n;i++)
            scanf("%d%d",&player[i].x,&player[i].rank);
        qsort(player,n,sizeof(Player),cmp);
        int lap=0;
        for(int i=1;i<n;i++)
            if(player[i].x<player[i-1].x) lap++;      //如果名次靠前的米数比靠后的小，肯定是套圈了
        puts(player[n-1].x+lap*400>m ? "NO" : "YES");      //把总的米数和实际的米数比一下，出结果
    }
    return 0;
}

Problem Description
HDU hosts sporting meeting every year. One of the most exciting events is the 10000M-running.During the match many students are running on the track. So, how about the rank list now?

As we know, in a running , we rank the player according to the length everyone has passed . So if one player run 400M(one lap) farther than another player , it looks like they are running at the same position on the track , but the rank of the former is much better than the latter. Now given everyone’s position on the track , and one rank list , can you tell me whether the rank list is possible.


Input
The first line of input gives the number of cases, T (at most 110). the first line of each case has two intergers, n,m. (1 <= n <= 100,1 <= m <= 40000,n <= m),represents there’re n players in the m-meter running.
then n lines describe every player.

Each line have two intergers , Xi , Ri .Representing the i-th player is running at xi[0 , 399] meter in his recent lap, and ranks Ri in the ranklist .And the data make sure that no pair of the students have the same Xi or Ri. And the start point is at 0 in their first lap.


Output
If the rank list is possible, output “YES” ,output “NO” otherwise.


Sample Input
2
3 400
100 1
49 2
28 3
3 800
100 1
150 2
154 3


Sample Output
YES
NO
*/