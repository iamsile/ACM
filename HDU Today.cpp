#include <iostream>
#include <map>
#include <string>
using namespace std;
const int inf=0x3fffffff;
int g[155][155],dis[160];
bool v[160];


void init(int n)
{
    int i,j;
    for (i=1; i<=n; i++)
        for (j=1; j<=n; j++)
            g[i][j]=inf;
    for (i=1; i<=n; i++)
        dis[i]=inf;
    memset(v, 0, sizeof(v));
}

int dijkstra(int sx,int ty,int n)
{
    int min,flag,i,j;
    dis[sx]=0;
    for (i=1; i<=n; i++) {
        min=inf;
        for (j=1; j<=n; j++)
            if (!v[j]&&dis[j]<min) {
                min=dis[j];
                flag=j;
            }
        v[flag]=1;
        for (j=1; j<=n; j++)
            if (!v[j]&&dis[j]>dis[flag]+g[flag][j])
                dis[j]=dis[flag]+g[flag][j];
    }
    return dis[ty];
}

int main()
{
    int n;
    while (~scanf("%d",&n)&&n!=-1) {
        int i,c,k=0;
        map<string, int> mp;
        string s,t,x,y;
        init(150);
        cin >> s >> t;
        if (!mp[s])
            mp[s]=++k;
        if (!mp[t])
            mp[t]=++k;
        for (i=0; i<n; i++) {
            cin >> x >> y >> c;
            if (!mp[x])
                mp[x]=++k;
            if (!mp[y])
                mp[y]=++k;
            if (g[mp[x]][mp[y]]>c)
                g[mp[x]][mp[y]]=g[mp[y]][mp[x]]=c;
        }
        int ans=dijkstra(mp[s],mp[t],k);
        if (ans!=inf)
            printf("%d\n",ans);
        else printf("-1\n");
    }
    return 0;
}
/*
 Problem Description
 经过锦囊相助，海东集团终于度过了危机，从此，HDU的发展就一直顺风顺水，到了2050年，集团已经相当规模了，据说进入了钱江肉丝经济开发区500强。这时候，XHD夫妇也退居了二线，并在风景秀美的诸暨市浬浦镇陶姚村买了个房子，开始安度晚年了。
 这样住了一段时间，徐总对当地的交通还是不太了解。有时很郁闷，想去一个地方又不知道应该乘什么公交车，在什么地方转车，在什么地方下车（其实徐总自己有车，却一定要与民同乐，这就是徐总的性格）。
 徐总经常会问蹩脚的英文问路：“Can you help me?”。看着他那迷茫而又无助的眼神，热心的你能帮帮他吗？
 请帮助他用最短的时间到达目的地（假设每一路公交车都只在起点站和终点站停，而且随时都会开）。
 
 
 Input
 输入数据有多组，每组的第一行是公交车的总数N(0<=N<=10000)；
 第二行有徐总的所在地start，他的目的地end；
 接着有n行，每行有站名s，站名e，以及从s到e的时间整数t(0<t<100)(每个地名是一个长度不超过30的字符串)。
 note：一组数据中地名数不会超过150个。
 如果N==-1，表示输入结束。
 
 
 Output
 如果徐总能到达目的地，输出最短的时间；否则，输出“-1”。
 
 
 Sample Input
 6
 xiasha westlake
 xiasha station 60
 xiasha ShoppingCenterofHangZhou 30
 station westlake 20
 ShoppingCenterofHangZhou supermarket 10
 xiasha supermarket 50
 supermarket westlake 10
 -1
 
 
 Sample Output
 50
*/