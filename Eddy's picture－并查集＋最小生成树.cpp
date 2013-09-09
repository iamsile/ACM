#include <iostream>
#include <math.h>
using namespace std;
struct node {
    int s,t;
    double l;
};
int f[500];
double sum;
int cmp(const void *a,const void *b)
{
    struct node *c=(struct node *)a;
    struct node *d=(struct node *)b;
    if (c->l > d->l)
        return 1;
    else return -1;
}

int find(int x)
{
    return f[x]==x ? x : find(f[x]);
}

void Union(int x,int y,double w)
{
    if (x==y)
        return;
    f[y]=x;
    sum+=w;
}

int main()
{
    int n;
    while (~scanf("%d",&n)) {
        int i,j,cnt=0;
        node path[10100];
        double x[110],y[110];
        memset(f, 0, sizeof(f));
        for (i=1; i<=n; i++)
            cin >> x[i] >> y[i];
        for (i=1; i<=n; i++)
            for (j=i+1; j<=n; j++) {
                path[cnt].s=i;
                path[cnt].t=j;
                path[cnt++].l=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
            }
        qsort(path, cnt, sizeof(path[0]), cmp);
        for (i=1; i<=n; i++)
            f[i]=i;
        sum=0.0;
        for (i=0; i<cnt; i++)
            Union(find(path[i].s),find(path[i].t),path[i].l);
        printf("%.2f\n",sum);
    }
    return 0;
}
/*
#include <iostream>
#include <math.h>
using namespace std;
const int inf=999999;
double dis[110][110];
int n;

double prim()
{
    int i,j,lab,v[110]={0};
    double min,lowcost[110],ans=0;
    for (i=0; i<n; i++)
        lowcost[i]=dis[0][i];
    v[0]=1;
    for (i=1; i<n; i++) {
        min=inf;
        lab=0;
        for (j=0; j<n; j++)
            if (!v[j]&&lowcost[j]<min) {
                min=lowcost[j];
                lab=j;
            }
        ans+=min;
        v[lab]=1;
        for (j=0; j<n; j++)
            if(!v[j]&&lowcost[j]>dis[lab][j])
                lowcost[j]=dis[lab][j];
    }
    return ans;
}

int main()
{
    while (~scanf("%d",&n)) {
        int i,j;
        double x[110],y[110];
        for (i=0; i<n; i++)
            for (j=0; j<n; j++)
                dis[i][j]=inf;
        for (i=0; i<n; i++)
            cin >> x[i] >> y[i];
        for (i=0; i<n; i++)
            for (j=0; j<n; j++)
                dis[i][j]=dis[j][i]=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
        printf("%.2lf\n",prim());
    }
    return 0;
}
*/
/*
 Problem Description
 Eddy begins to like painting pictures recently ,he is sure of himself to become a painter.Every day Eddy draws pictures in his small room, and he usually puts out his newest pictures to let his friends appreciate. but the result it can be imagined, the friends are not interested in his picture.Eddy feels very puzzled,in order to change all friends 's view to his technical of painting pictures ,so Eddy creates a problem for the his friends of you.
 Problem descriptions as follows: Given you some coordinates pionts on a drawing paper, every point links with the ink with the straight line, causes all points finally to link in the same place. How many distants does your duty discover the shortest length which the ink draws?
 
 
 Input
 The first line contains 0 < n <= 100, the number of point. For each point, a line follows; each following line contains two real numbers indicating the (x,y) coordinates of the point. 
 
 Input contains multiple test cases. Process to the end of file.
 
 
 Output
 Your program prints a single real number to two decimal places: the minimum total length of ink lines that can connect all the points. 
 
 
 Sample Input
 3
 1.0 1.0
 2.0 2.0
 2.0 4.0
 
 
 Sample Output
 3.41
*/