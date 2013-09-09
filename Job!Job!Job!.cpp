#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct info {
    int t,v;
    bool operator <(const info &a)const {
        return v > a.v;
    }
}w[100011];

priority_queue <info> q;
int n,m;

bool cmp(info a,info b)
{
    return a.t < b.t;
}

int main()
{
    while (scanf("%d%d",&n,&m)!=EOF) {
        int i;
        for (i=0; i<n; i++)
            scanf("%d%d",&w[i].t,&w[i].v);
        sort(w, w+n,cmp);
        int cur=1;
        for (i=0; i<n; i++) {
            if(cur<=m&&w[i].t>=cur) {
                cur++;
                q.push(w[i]);
            }
            else if (w[i].v>q.top().v) {
                q.pop();
                q.push(w[i]);
            }
        }
        int ans=0;
        while (!q.empty()) {
            ans+=q.top().v;
            q.pop();
        }
        printf("%d\n",ans);
    }
    return 0;
}
/*
 Problem description
 Foreverlin is working in a company. In order to make boss happier, he must work as hard as possible, there are n projects on the todolist. Now is time 1, after time m ,foreverlin has to go back to the school .each project has two properties , the finally completion time and the value you can make if you finish this project . At every unit of time ,he can choose a project to finish . However, he can only change one project to do in one unit time, that means in one unit time ,he can choose a project to do and finish in this unit time. As the best friend of him ,can you help him to find out how to arrange these projects so that he can make the biggest values. 
 
 Input
 There are several test cases, in each test case, there are two numbers n,m(1<=n<=100000,1<=m<=1000000) . The next n lines each contains two number D[i],V[i] (1 <= D[i] <= 100000,1<=V[i]<=10000) (1<=i<=n ,D[i] means if you choose to do project i ,you can not do this after time D[i],V[i] means the value of project i ) The input will finish with the end of file.
 
 Output
 For each the case ,ouput a number means the biggest values.
 
 Sample Input
 4 10
 1 8
 1 3
 2 10
 5 12
 Sample Output
 30
*/