#include <iostream>
using namespace std;
int mark[300];

typedef struct {
    int l,r,v,cnt;
}node;
node a[300],b[300];

int cmp(node x,node y) 
{
    return x.v<y.v;
}

int main() 
{
    int n,i,j,sum,lk,rk,k;
    while(scanf("%d",&n)!=EOF) {
        for(i=0;i<n;i++) {
            cin >> a[i].v;
            b[i].v=a[i].v;
            a[i].l=a[i].r=i;
            a[i].cnt=1;
        }
        sort(b,b+n,cmp);
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                if(a[j].v==b[i].v && a[j].cnt) {
                    a[j].cnt=0;
                    mark[i]=j;
                    b[i].l=b[i].r=j;
                    break;
                }
        for(i=0,sum=0;i<n-1;i++) {
            lk=a[mark[i]].l;
            rk=a[mark[i]].r;
            k=mark[i];
            if(lk==0) {
                if(a[n-1].v>a[rk+1].v) {
                    sum+=(a[rk+1].v-a[k].v);
                    a[rk+1].l=a[k].l;
                    mark[i]=rk+1;
                } else {
                    sum+=(a[n-1].v-a[k].v);
                    a[n-1].r=a[k].r;
                    mark[i]=n-1;
                }
            } else if(rk==n-1) {
                if(a[lk-1].v>a[0].v) {
                    sum+=(a[0].v-a[k].v);
                    a[0].l=a[k].l;
                    mark[i]=0;
                } else {
                    sum+=(a[lk-1].v-a[k].v);
                    a[lk-1].r=a[k].r;
                    mark[i]=lk-1;
                }
            } else {
                if(a[lk-1].v>a[rk+1].v) {
                    sum+=(a[rk+1].v-a[k].v);
                    a[rk+1].l=a[k].l;
                    mark[i]=rk+1;
                } else {
                    sum+=(a[lk-1].v-a[k].v);
                    a[lk-1].r=a[k].r;
                    mark[i]=lk-1;
                }
            }
        }
        cout << sum << '\n';
    }
    return 0;
}
/*
 Description
 
 一年一度的天下第一比武大会又开始了。按照惯例，参赛者们围成一个圆圈，每个人可以跟他相邻的人决斗，胜利者留在原地，而失败者立刻淘汰出局。
 大 会的组织者已经算出每位选手的能力值，能力值大的一定可以战胜能力值小的（能力值相同时，不会有平局，必有一方被淘汰）。同时为了让比赛更加激烈，他们倾 向于让能力值接近的两名选手打斗。所以他们想安排一个比武的顺序，在不改变参赛者现在的位置的条件下，使得所有比赛中两名选手能力值差别的总和最小。
 
 Input
 
 第1行1个整数n，表示参赛的人数（2<=n<=200）
 第2行有n个整数，依次表示圆上第1，2，...，n个人的能力值（能力值为不超过10000的非负数）。显然，第n个人和第1个人相邻。
 
 Output
 
 一个整数，为n-1场比赛双方能力值差的绝对值之和的最小值。
 
 Sample Input
 
 3
 2 3 1
 Sample Output
 
 2
*/