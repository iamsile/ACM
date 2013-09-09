#include <iostream>
#include <queue>
using namespace std;

struct node {
    int v,cnt;
    node() {
        v=0;cnt=0;
    }
};
int n,m,pri[1005],v[1005];

int bfs(int s)
{
    memset(v, 0, sizeof(v));
    queue<node> q;
    node cur,nex;
    cur.v=s;
    cur.cnt=0;
    q.push(cur);
    while (!q.empty()) {
        cur=q.front();
        q.pop();
        for (int i=2; i<cur.v; i++) {
            nex.v=cur.v+i;
            if (!v[nex.v]&&pri[i]&&nex.v<=m) {
                nex.cnt=cur.cnt+1;
                v[nex.v]=1;
                if (nex.v==m)
                    return nex.cnt;
                q.push(nex);
            }
        }
    }
    return 0;
}

int main()
{
    int i,j;
    for (i=0; i<=1001; i++)
        pri[i]=1;
    for (i=2; i<=34; i++)
        if (pri[i])
            for (j=i; j*i<=1001; j++)
                pri[i*j]=0;
    while (~scanf("%d%d",&n,&m)) {
        int k=bfs(n);
        if (k)
            printf("Need %d step(s)\n",k);
        else printf("No path!\n");
    }
    return 0;
}
/*
 Description
 In this problem, you are given a pair of integers A and B. You can transform any integer number A to B by adding x to A.This x is an integer number which is a prime below A.Now,your task is to find the minimum number of transformation required to transform S to another integer number T.
 Input
 Input contains multiple test cases.Each test case contains a pair of integers S and T(0< S < T <= 1000) , one pair of integers per line. 
 Output
 For each pair of input integers S and T you should output the minimum number of transformation needed as Sample output in one line. If it's impossible ,then print 'No path!' without the quotes.
 Sample Input
 5 7
 3 4
 Sample Output
 Need 1 step(s)
 No path!
*/