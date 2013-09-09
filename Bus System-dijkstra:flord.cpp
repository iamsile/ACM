#include <iostream>
#include <math.h>
using namespace std;
const long long inf=99999999999LL;//11ge 9
int l1,l2,l3,l4,c1,c2,c3,c4;
__int64 map[110][110];

int main()
{
    int t,lab=1;
    scanf("%d",&t);
    while (t--) {
        scanf("%d%d%d%d%d%d%d%d",&l1,&l2,&l3,&l4,&c1,&c2,&c3,&c4);
        int n,m,i,j,k,xx,x[110];
        scanf("%d%d",&n,&m);
        for (i=1; i<=n; i++)
            scanf("%d",&x[i]);
        for (i=1; i<=n; i++)
            for (j=1; j<=n; j++)
                if (i==j)
                    map[i][j]=0;
                else map[i][j]=inf;
        for (i=1; i<=n; i++)
            for (j=i+1; j<=n; j++) {
                xx=abs(x[i]-x[j]);
                if (xx>0&&xx<=l1)
                    map[i][j]=map[j][i]=c1;
                else if (xx>l1&&xx<=l2)
                    map[i][j]=map[j][i]=c2;
                else if (xx>l2&&xx<=l3)
                    map[i][j]=map[j][i]=c3;
                else if (xx>l3&&xx<=l4)
                    map[i][j]=map[j][i]=c4;
            }
        for (k=1; k<=n; k++)
            for (i=1; i<=n; i++)
                for (j=1; j<=n; j++)
                    if (map[i][j]>map[i][k]+map[k][j])
                        map[i][j]=map[i][k]+map[k][j];
        printf("Case %d:\n",lab++);
        while (m--) {
            int s,t;
            scanf("%d%d",&s,&t);
            if (map[s][t]!=inf)
                printf("The minimum cost between station %d and station %d is %I64d.\n",s,t,map[s][t]);
            else printf("Station %d and station %d are not attainable.\n",s,t);
        }
    }
    return 0;
}
/*#include <iostream>
#include <math.h>
using namespace std;
const int inf=0x7fffffff;
int l1,l2,l3,l4,c1,c2,c3,c4;

int cal(int y)
{
    if (y>0&&y<=l1)
        return c1;
    else if (y>l1&&y<=l2)
        return c2;
    else if (y>l2&&y<=l3)
        return c3;
    else if (y>l3&&y<=l4)
        return c4;
    return inf;
}

int main()
{
    int t,lab=1;
    scanf("%d",&t);
    while (t--) {
        scanf("%d%d%d%d%d%d%d%d",&l1,&l2,&l3,&l4,&c1,&c2,&c3,&c4);
        int n,m,i,j,xx,x[101],map[110][110];
        scanf("%d%d",&n,&m);
        for (i=1; i<=n; i++)
            scanf("%d",&x[i]);
        for (i=1; i<=n; i++)
            for (j=i+1; j<=n; j++) {
                xx=abs(x[i]-x[j]);
                map[i][j]=map[j][i]=cal(xx);
            }
        printf("Case %d:\n",lab++);
        while (m--) {
            int s,t,min,flag,ndis,dis[1001],v[1001];
            scanf("%d%d",&s,&t);
            int xs=s,xt=t;
            if (s>t)
                swap(s, t);
            memset(dis, 0, sizeof(dis));
            memset(v, 0, sizeof(v));
            for (i=1; i<=n; i++)
                dis[i]=map[s][i];
            v[s]=1;
            dis[s]=0;
            for (i=1; i<=n; i++) {
                min=inf;
                flag=0;
                for (j=1; j<=n; j++)
                    if (!v[j]&&dis[j]<min) {
                        min=dis[j];
                        flag=j;
                    }
                v[flag]=1;
                for (j=1; j<=n; j++)
                    if (!v[j]&&map[flag][j]<inf) {
                        ndis=dis[flag]+map[flag][j];
                        if (ndis<dis[j])
                            dis[j]=ndis;
                    }
            }
            if (dis[t])
                printf("The minimum cost between station %d and station %d is %d.\n",xs,xt,dis[t]);
            else printf("Station %d and station %d are not attainable.\n",xs,xt);
        }
    }
    return 0;
}

 Problem Description
 Because of the huge population of China, public transportation is very important. Bus is an important transportation method in traditional public transportation system. And it’s still playing an important role even now.
 The bus system of City X is quite strange. Unlike other city’s system, the cost of ticket is calculated based on the distance between the two stations. Here is a list which describes the relationship between the distance and the cost.
 
 
 
 
 Your neighbor is a person who is a really miser. He asked you to help him to calculate the minimum cost between the two stations he listed. Can you solve this problem for him?
 To simplify this problem, you can assume that all the stations are located on a straight line. We use x-coordinates to describe the stations’ positions.
 
 
 Input
 The input consists of several test cases. There is a single number above all, the number of cases. There are no more than 20 cases.
 Each case contains eight integers on the first line, which are L1, L2, L3, L4, C1, C2, C3, C4, each number is non-negative and not larger than 1,000,000,000. You can also assume that L1<=L2<=L3<=L4.
 Two integers, n and m, are given next, representing the number of the stations and questions. Each of the next n lines contains one integer, representing the x-coordinate of the ith station. Each of the next m lines contains two integers, representing the start point and the destination.
 In all of the questions, the start point will be different from the destination.
 For each case,2<=N<=100,0<=M<=500, each x-coordinate is between -1,000,000,000 and 1,000,000,000, and no two x-coordinates will have the same value.
 
 
 Output
 For each question, if the two stations are attainable, print the minimum cost between them. Otherwise, print “Station X and station Y are not attainable.” Use the format in the sample.
 
 
 Sample Input
 2
 1 2 3 4 1 3 5 7
 4 2
 1
 2
 3
 4
 1 4
 4 1
 1 2 3 4 1 3 5 7
 4 1
 1
 2
 3
 10
 1 4
 
 
 Sample Output
 Case 1:
 The minimum cost between station 1 and station 4 is 3.
 The minimum cost between station 4 and station 1 is 3.
 Case 2:
 Station 1 and station 4 are not attainable.
*/