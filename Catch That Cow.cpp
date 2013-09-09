#include <iostream>
using namespace std;
#define max 200005
int n,m,step[max],que[max],v[max];

void bfs(int s)
{
    int front=1,rear=1;
    que[front]=s;
    v[s]=1;
    step[s]=0;
    if (s==m)
        return;
    while (front<=rear) {
        int start=que[front];
        if (start==m)
            return;
        if (start-1>=0&&!v[start-1]) {
            que[++rear]=start-1;
            step[start-1]=step[start]+1;
            v[start-1]=1;
        }
        if (start+1<=m&&!v[start+1]) {
            que[++rear]=start+1;
            step[start+1]=step[start]+1;
            v[start+1]=1;
        }
        if (start<=m&&!v[2*start]) {
            que[++rear]=2*start;
            step[2*start]=step[start]+1;
            v[2*start]=1;
        }
        front++;
    }
}
int main()
{
    while (scanf("%d%d",&n,&m)!=EOF) {
        bfs(n);
        cout << step[m] << '\n';
    }
    return 0;
}
/*
 Description
 
 Farmer John has been informed of the location of a fugitive cow and wants to catch her immediately. He starts at a point N (0 ≤ N ≤ 100,000) on a number line and the cow is at a point K (0 ≤ K ≤ 100,000) on the same number line. Farmer John has two modes of transportation: walking and teleporting.
 
 * Walking: FJ can move from any point X to the points X - 1 or X + 1 in a single minute
 * Teleporting: FJ can move from any point X to the point 2 × X in a single minute.
 
 If the cow, unaware of its pursuit, does not move at all, how long does it take for Farmer John to retrieve it?
 
 Input
 
 Line 1: Two space-separated integers: N and K
 Output
 
 Line 1: The least amount of time, in minutes, it takes for Farmer John to catch the fugitive cow.
 Sample Input
 
 5 17
 Sample Output
 
 4
*/