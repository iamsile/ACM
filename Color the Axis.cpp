#include <cstdio>

int f[1000002];

int find(int x)
{
    if(f[x] != x) 
        f[x] = find(f[x]);
    return f[x];
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i = 1; i <= n+1; ++i)
        f[i] = i;
    for(int i = 0; i < m; ++i)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        if(l > r)
        {
            int t = r;
            r = l;
            l = t;
        }
        for(int x = find(l); x <= r; x = find(x))
        {
            n--;
            f[x] = x+1;
        }
        printf("%d\n",n);
    }
    return 0;
}
/*
在一条数轴上有N个点,分别是吱~N。一开始所有的点都被染成黑色。接着我们进 行呍次操作,第呩次操作将呛Li, Ri呝这些点染成白色。请输出每个操作执行后剩余黑色点的个 数。
 输入格式 输入一行为N和M。下面呍行每行两个数Li、Ri。
 输出格式 输出呍行,为每次操作后剩余黑色点的个数。
 input
 10 3
 3 3
 5 7
 output
 9
 6
 3
*/