#include <iostream>
#include <math.h>
using namespace std;
int f[1001];
double ans;
struct node {
    int x,y;
    double l;
}path[6001];

int cmp(const void *a,const void *b)
{
    struct node *c=(struct node *)a;
    struct node *d=(struct node *)b;
    return c->l > d->l ? 1 : -1;
}

int find(int x)
{
    return f[x]==x ? x :find(f[x]);
}

void Union(int a,int b,double len)
{
    if (a==b)
        return;
    f[a]=b;
    ans+=len;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n,i,j,k=0,cnt=0,xs[1001],ys[1001];
        double s;
        cin >> n;
        for (i=0; i<n; i++)
            cin >> xs[i] >> ys[i];
        for (i=0; i<n; i++)
            f[i]=i;
        for (i=0,s=0.0; i<n; i++)
            for (j=i+1; j<n; j++) {
                s=sqrt((xs[i]-xs[j])*(xs[i]-xs[j])+(ys[i]-ys[j])*(ys[i]-ys[j]));
                if (s>=10&&s<=1000) {
                    path[cnt].x=i;
                    path[cnt].y=j;
                    path[cnt++].l=s;
                    s=0.0;
                }
            }
        qsort(path, cnt, sizeof(path[0]), cmp);
        for (i=0,ans=0.0; i<cnt; i++)
            Union(find(path[i].x),find(path[i].y),path[i].l);
        for (i=0; i<n; i++)
            if (f[i]==i)
                k++;
        if (k==1)
            printf("%.1f\n",ans*100);
        else cout << "oh!\n";
    }
    return 0;
}
/*
#include <iostream>
#include <math.h>
using namespace std;
const double inf=99999.0;
int n,v[600];
double sum,map[110][110];
bool prim()
{
    memset(v, 0, sizeof(v));
    v[0]=1;
    int i,j,flag;
    double min;
    for (i=1,sum=0.0; i<n; i++) {
        min=inf;
        flag=0;
        for (j=0; j<n; j++)
            if (!v[j]&&map[0][j]<min) {
                min=map[0][j];
                flag=j;
            }
        if (!flag)
            return false;
        sum+=min;
        v[flag]=1;
        for (j=0; j<n; j++)
            if (!v[j]&&map[0][j]>map[flag][j])
                map[0][j]=map[flag][j];
    }
    return true;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int i,j,x[601],y[601];
        double s;
        cin >> n;
        for (i=0; i<n; i++)
            cin >> x[i] >> y[i];
        for (i=0; i<n; i++)
            for (j=i+1; j<n; j++) {
                s=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
                if (s>=10&&s<=1000)
                    map[i][j]=map[j][i]=s;
                else map[i][j]=map[j][i]=inf;
            }
        if(prim())
            printf("%.1f\n",sum*100);
        else cout << "oh!\n";
    }
    return 0;
}
*/
/*
 Problem Description
 相信大家都听说一个“百岛湖”的地方吧，百岛湖的居民生活在不同的小岛中，当他们想去其他的小岛时都要通过划小船来实现。现在政府决定大力发展百岛湖，发展首先要解决的问题当然是交通问题，政府决定实现百岛湖的全畅通！经过考察小组RPRush对百岛湖的情况充分了解后，决定在符合条件的小岛间建上桥，所谓符合条件，就是2个小岛之间的距离不能小于10米，也不能大于1000米。当然，为了节省资金，只要求实现任意2个小岛之间有路通即可。其中桥的价格为 100元/米。
 
 
 Input
 输入包括多组数据。输入首先包括一个整数T(T <= 200)，代表有T组数据。
 每组数据首先是一个整数C(C <= 100),代表小岛的个数，接下来是C组坐标，代表每个小岛的坐标，这些坐标都是 0 <= x, y <= 1000的整数。
 
 
 Output
 每组输入数据输出一行，代表建桥的最小花费，结果保留一位小数。如果无法实现工程以达到全部畅通，输出”oh!”.
 
 
 Sample Input
 2
 2
 10 10
 20 20
 3
 1 1
 2 2
 1000 1000
 
 
 Sample Output
 1414.2
 oh!
*/