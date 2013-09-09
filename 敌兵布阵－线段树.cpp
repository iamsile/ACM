#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int t,lab=1;
    cin >> t;
    while (t--) {
        int i,n,x,y,flag=1,a[50010];
        char b[10];
        unsigned sum=0;
        cin >> n;
        for (i=1; i<=n; i++)
            cin >> a[i];
        getchar();
        while (cin >> b) {
            if (strcmp(b, "End")==0)
                break;
            cin >> x >> y;
            if (strcmp(b, "Query")==0) {
                sum=0;
                for (i=x; i<=y; i++)
                    sum+=a[i];
                if (flag) {
                    cout << "Case " << lab++ << ":\n";
                    flag=0;
                }
                cout << sum << '\n';
            }
            if (strcmp(b, "Add")==0)
                a[x]+=y;
            if (strcmp(b, "Sub")==0)
                a[x]-=y;
        }
    }
    return 0;
}
/*
#include <iostream>
#include <string.h>
using namespace std;

struct node {
    int l,r,cnt;
}t[400000];

void build(int cur,int left,int right)
{
    t[cur].l=left;
    t[cur].r=right;
    t[cur].cnt=0;
    if (left==right)
        return;
    build(cur*2, left, (left+right)/2);
    build(cur*2+1, (left+right)/2+1, right);
}

void update(int cur,int q,int num)
{
    if (q<=t[cur].r&&q>=t[cur].l) {
        t[cur].cnt+=num;
        update(cur*2, q, num);
        update(cur*2+1, q, num);
    }
}

int sum;
void query(int cur,int left,int right)
{
    int mid=(t[cur].l+t[cur].r)/2;
    if (t[cur].l==left&&t[cur].r==right)
        sum+=t[cur].cnt;
    else if (right<=mid)
        query(cur*2, left, right);
    else if (left>mid)
        query(cur*2+1, left, right);
    else {
        query(cur*2, left, mid);
        query(cur*2+1, mid+1, right);
    }
}

int main()
{
    int tt,lab=1;
    cin >> tt;
    while (tt--) {
        int i,n,m,x,y;
        char a[10]={0};
        cin >> n;
        memset(&t, 0, sizeof(t));
        build(1,1,n);
        for (i=1; i<=n; i++) {
            cin >> m;
            update(1,i,m);
        }
        printf("Case %d:\n",lab++);
        while (cin >> a&&a[0]!='E') {
            cin >> x >> y;
            if (a[0]=='Q') {
                sum=0;
                query(1,x,y);
                cout << sum << '\n';
            }
            if (a[0]=='A')
                update(1, x, y);
            if (a[0]=='S')
                update(1, x, 0-y);
        }
    }
    return 0;
}
*/
/*
 Font Size: ← →
 Problem Description
 C国的死对头A国这段时间正在进行军事演习，所以C国间谍头子Derek和他手下Tidy又开始忙乎了。A国在海岸线沿直线布置了N个工兵营地,Derek和Tidy的任务就是要监视这些工兵营地的活动情况。由于采取了某种先进的监测手段，所以每个工兵营地的人数C国都掌握的一清二楚,每个工兵营地的人数都有可能发生变动，可能增加或减少若干人手,但这些都逃不过C国的监视。
 中央情报局要研究敌人究竟演习什么战术,所以Tidy要随时向Derek汇报某一段连续的工兵营地一共有多少人,例如Derek问:“Tidy,马上汇报第3个营地到第10个营地共有多少人!”Tidy就要马上开始计算这一段的总人数并汇报。但敌兵营地的人数经常变动，而Derek每次询问的段都不一样，所以Tidy不得不每次都一个一个营地的去数，很快就精疲力尽了，Derek对Tidy的计算速度越来越不满:"你个死肥仔，算得这么慢，我炒你鱿鱼!”Tidy想：“你自己来算算看，这可真是一项累人的工作!我恨不得你炒我鱿鱼呢!”无奈之下，Tidy只好打电话向计算机专家Windbreaker求救,Windbreaker说：“死肥仔，叫你平时做多点acm题和看多点算法书，现在尝到苦果了吧!”Tidy说："我知错了。。。"但Windbreaker已经挂掉电话了。Tidy很苦恼，这么算他真的会崩溃的，聪明的读者，你能写个程序帮他完成这项工作吗？不过如果你的程序效率不够高的话，Tidy还是会受到Derek的责骂的.
 Input
 第一行一个整数T，表示有T组数据。
 每组数据第一行一个正整数N（N<=50000）,表示敌人有N个工兵营地，接下来有N个正整数,第i个正整数ai代表第i个工兵营地里开始时有ai个人（1<=ai<=50）。
 接下来每行有一条命令，命令有4种形式：
 (1) Add i j,i和j为正整数,表示第i个营地增加j个人（j不超过30）
 (2)Sub i j ,i和j为正整数,表示第i个营地减少j个人（j不超过30）;
 (3)Query i j ,i和j为正整数,i<=j，表示询问第i到第j个营地的总人数;
 (4)End 表示结束，这条命令在每组数据最后出现;
 每组数据最多有40000条命令
 Output
 对第i组数据,首先输出“Case i:”和回车,
 对于每个Query询问，输出一个整数并回车,表示询问的段中的总人数,这个数最多不超过1000000。
 Sample Input
 1
 10
 1 2 3 4 5 6 7 8 9 10
 Query 1 3
 Add 3 6
 Query 2 7
 Sub 10 2
 Add 6 3
 Query 3 10
 End 
 Sample Output
 Case 1:
 6
 33
 59
*/