#include <iostream>
using namespace std;
#define infi 1<<29
int n,m,a[101][101];

int floyd()
{
    int i,j,k;
    for (k=0; k<n; k++)
        for (i=0; i<n; i++)
            for (j=0; j<n; j++) {
                if (a[i][k]==infi||a[k][j]==infi)
                    continue;
                if (a[i][j]>a[i][k]+a[k][j])
                    a[i][j]=a[i][k]+a[k][j];
            }
    int min=infi;
    for (i=0; i<n; i++) {
        if (a[i][i]==infi)
            continue;
        if (a[i][i]<min)
            min=a[i][i];
    }
    if (min==infi)
        return -1;
    return min;
}

int main()
{
    int i,j,k,s,e,t,ans;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (i=0; i<n; i++)
            for (j=0; j<n; j++)
                a[i][j]=infi;
        for (i=0; i<m; i++) {
            cin >> s >> e >> k;
            a[s][e]=k;
        }
        ans=floyd();
        cout << ans << '\n';
    }
    return 0;
}
/*
 Problem description
 zfy lives in a city where has n crossings (0 < n ≤ 100, the crossings are labeled as 0, 1, 2 ... n-1. And we can regard each crossing as a vertex of a graph.), m roads (0 ≤ m ≤ n*(n-1), every road connects two crossings, and for some reason all the roads are one-way -roads, thus they can be regarded as directed edges of a graph).
 
 Now comes the problem: zfy wants to locate his new home to one of the crossings which is included in the circle that has the minimum total length so that it could be convenient to go somewhere outside and back to home. But the problem seems a little complex to him, so he turns to you for helping him calculate the length of the minimum circle by programming.
 
 
 Input
 The first line of the input file contains a single integer T: the number of test cases.
 The first line for each test case contains two integers: n and m, followed by m lines. Each of the m lines has three integers u, v, w (0 ≤ u, v < n; 0 < w < 107), described a road of length w which connect the uth crossing and the vth crossing of the city. 
 
 
 Output
 For each test case, output one line contains exactly one integer, which is the length of the minimum circle of the city. If there is no circle in the city, just output -1.
 
 
 Sample Input
 1
 4 6
 0 1 3
 2 0 5
 1 2 3
 2 1 2
 1 3 1
 3 2 1
 
 Sample Output
 4
*/