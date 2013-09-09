#include <iostream>
using namespace std;
const int inf=10000000;
int map[211][211],dis[1001],v[1001];

int main()
{
    int n;
    while (scanf("%d",&n)&&n) {
        int s,t,i,j,m,min,flag,ndis;
        scanf("%d%d",&s,&t);
        memset(dis, 0, sizeof(dis));
        memset(v, 0, sizeof(v));
        for (i=1; i<=n; i++)
            for (j=1; j<=n; j++)
                map[j][i]=map[i][j]=inf;
        for (i=1; i<=n; i++) {
            scanf("%d",&m);
            if (i-m>=1)
                map[i][i-m]=1;
            if (m+i<=n)
                map[i][m+i]=1;
        }
        for (i=1; i<=n; i++)
            dis[i]=map[s][i];
        dis[s]=0;
        v[s]=1;
        for (i=2; i<=n; i++) {
            min=inf;
            flag=s;
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
        if (dis[t]<inf)
            printf("%d\n",dis[t]);
        else printf("-1\n");
        
    }
    return 0;
}
/*
#include <iostream>
#include <queue>
using namespace std;

struct node {
    int v,step;
};

int main()
{
    int n;
    while (scanf("%d",&n)&&n) {
        int i,s,t,flag=0,a[1001];
        bool v[1001];
        scanf("%d%d",&s,&t);
        for (i=1; i<=n; i++) {
            scanf("%d",&a[i]);
            v[i]=0;
        }
        node cur,nex;
        queue<node> q;
        cur.v=s;
        cur.step=0;
        v[cur.v]=1;
        q.push(cur);
        while (!q.empty()) {
            cur=q.front();
            q.pop();
            if (cur.v==t) {
                flag=1;
                break;
            }
            nex.v=cur.v+a[cur.v];
            nex.step=cur.step+1;
            if (nex.v<=t&&!v[nex.v]) {
                v[nex.v]=1;
                q.push(nex);
            }
            nex.v=cur.v-a[cur.v];
            if (nex.v>0&&!v[nex.v]) {
                v[nex.v]=1;
                q.push(nex);
            }
        }
        if (flag)
            printf("%d\n",cur.step);
        else printf("-1\n");
    }
    return 0;
}
*/
/*
 Problem Description
 There is a strange lift.The lift can stop can at every floor as you want, and there is a number Ki(0 <= Ki <= N) on every floor.The lift have just two buttons: up and down.When you at floor i,if you press the button "UP" , you will go up Ki floor,i.e,you will go to the i+Ki th floor,as the same, if you press the button "DOWN" , you will go down Ki floor,i.e,you will go to the i-Ki th floor. Of course, the lift can't go up high than N,and can't go down lower than 1. For example, there is a buliding with 5 floors, and k1 = 3, k2 = 3,k3 = 1,k4 = 2, k5 = 5.Begining from the 1 st floor,you can press the button "UP", and you'll go up to the 4 th floor,and if you press the button "DOWN", the lift can't do it, because it can't go down to the -2 th floor,as you know ,the -2 th floor isn't exist.
 Here comes the problem: when you is on floor A,and you want to go to floor B,how many times at least he havt to press the button "UP" or "DOWN"?
 
 
 Input
 The input consists of several test cases.,Each test case contains two lines.
 The first line contains three integers N ,A,B( 1 <= N,A,B <= 200) which describe above,The second line consist N integers k1,k2,....kn.
 A single 0 indicate the end of the input.
 
 
 Output
 For each case of the input output a interger, the least times you have to press the button when you on floor A,and you want to go to floor B.If you can't reach floor B,printf "-1".
 
 
 Sample Input
 5 1 5
 3 3 1 2 5
 0
 
 
 Sample Output
 3
*/