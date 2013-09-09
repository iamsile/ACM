#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int f[110];
bool s[110];
struct way {
    int x,y,v;
}a[5100];

bool cmp(way f1,way f2)
{
    return f1.v < f2.v;
}

int findset(int b)
{
    if (f[b]!=b)
        f[b]=findset(f[b]);
    return f[b];
}

int Un(int f1,int f2)
{
    int k1=findset(f1),k2=findset(f2);
    if (k1==k2)
        return 1;
    else {
        f[k1]=k2;
        return 0;
    }
}

int main()
{
    int n,m;
    while (cin >> n >> m) {
        if (n==0)
            break;
        int i,k=0,sum=0;
        memset(s, false, sizeof(s));
        memset(a, 0, sizeof(a));
        for (i=1; i<=m; i++)
            f[i]=i;
        for (i=1; i<=n; i++)
            cin >> a[i].x >> a[i].y >> a[i].v;
        sort(a+1, a+n+1,cmp);
        for (i=1; i<=n; i++)
            if (Un(a[i].x, a[i].y)==0)
                sum+=a[i].v;
        for (i=1; i<=m; i++)
            s[findset(i)]=true;
        for (i=1; i<=m; i++)
            if (s[i])
                k++;
        if (k!=1)
            cout << "?\n";
        else cout << sum << '\n';
    }
    return 0;
}
/*
 Problem Description
 省政府“畅通工程”的目标是使全省任何两个村庄间都可以实现公路交通（但不一定有直接的公路相连，只要能间接通过公路可达即可）。经过调查评估，得到的统计表中列出了有可能建设公路的若干条道路的成本。现请你编写程序，计算出全省畅通需要的最低成本。
 
 
 Input
 测试输入包含若干测试用例。每个测试用例的第1行给出评估的道路条数 N、村庄数目M ( < 100 )；随后的 N 
 行对应村庄间道路的成本，每行给出一对正整数，分别是两个村庄的编号，以及此两村庄间道路的成本（也是正整数）。为简单起见，村庄从1到M编号。当N为0时，全部输入结束，相应的结果不要输出。
 
 
 Output
 对每个测试用例，在1行里输出全省畅通需要的最低成本。若统计数据不足以保证畅通，则输出“?”。
 
 
 Sample Input
 3 3
 1 2 1
 1 3 2
 2 3 4
 1 3
 2 3 2
 0 100
 
 
 Sample Output
 3
 ?
*/