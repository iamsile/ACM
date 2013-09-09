#include <iostream>
using namespace std;
int p[2011],s[2011];

int find(int x)
{
    return p[x]==x ? x :p[x]=find(p[x]);
}

int main()
{
    int t,lab=1;
    scanf("%d",&t);
    while (t--) {
        int n,m,i,x,y,pathx,pathy,ans=0;
        scanf("%d%d",&n,&m);
        memset(s, 0, sizeof(s));
        for (i=1; i<=n; i++)
            p[i]=i;
        for (i=1; i<=m; i++) {
            scanf("%d%d",&x,&y);
            if (ans)
                continue;
            pathx=find(x);
            pathy=find(y);
            if (pathx==pathy)
                ans=1;
            if (s[x])
                p[y]=find(s[x]);
            else s[x]=y;
            if (s[y])
                p[x]=find(s[y]);
            else s[y]=x;
        }
        printf("Scenario #%d:\n",lab++);
        if (ans) printf("Suspicious bugs found!\n");
        else printf("No suspicious bugs found!\n");
        printf("\n");
    }
    return 0;
}
/*
 Problem Description
 Background 
 Professor Hopper is researching the sexual behavior of a rare species of bugs. He assumes that they feature two different genders and that they only interact with bugs of the opposite gender. In his experiment, individual bugs and their interactions were easy to identify, because numbers were printed on their backs. 
 
 Problem 
 Given a list of bug interactions, decide whether the experiment supports his assumption of two genders with no homosexual bugs or if it contains some bug interactions that falsify it.
 
 
 Input
 The first line of the input contains the number of scenarios. Each scenario starts with one line giving the number of bugs (at least one, and up to 2000) and the number of interactions (up to 1000000) separated by a single space. In the following lines, each interaction is given in the form of two distinct bug numbers separated by a single space. Bugs are numbered consecutively starting from one.
 
 
 Output
 The output for every scenario is a line containing "Scenario #i:", where i is the number of the scenario starting at 1, followed by one line saying either "No suspicious bugs found!" if the experiment is consistent with his assumption about the bugs' sexual behavior, or "Suspicious bugs found!" if Professor Hopper's assumption is definitely wrong.
 
 
 Sample Input
 2
 3 3
 1 2
 2 3
 1 3
 4 2
 1 2
 3 4
 
 
 Sample Output
 Scenario #1:
 Suspicious bugs found!
 
 Scenario #2:
 No suspicious bugs found!
*/