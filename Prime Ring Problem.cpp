#include <iostream>
#include <string.h>
using namespace std;
int n,a[25],v[25],p[40];
void dfs(int dep,int num)
{
    int i;
    if (num==n&&p[a[1]+a[num]]) {
        for (i=1; i<=n; i++) {
            if (i>1)
                cout << ' ';
            cout << a[i];
        }
        cout << '\n';
        return;
    }
    for (i=2; i<=n; i++)
        if (p[dep+i]&&v[i]==0) {
            a[num+1]=i;
            v[i]=1;
            dfs(i, num+1);
            v[i]=0;
        }
}

int main()
{
    p[2]=p[3]=p[5]=p[7]=p[11]=p[13]=p[17]=
    p[19]=p[23]=p[29]=p[31]=p[37]=1;
    int t=1;
    while (cin >> n&&n) {
        cout << "Case " << t++ << ":\n";
        a[1]=1;
        dfs(1,1);
        cout << '\n';
        memset(v, 0, sizeof(v));
    }
    return 0;
}
/*
 Problem Description
 A ring is compose of n circles as shown in diagram. Put natural number 1, 2, ..., n into each circle separately, and the sum of numbers in two adjacent circles should be a prime.
 
 Note: the number of first circle should always be 1.
 
 
 
 
 Input
 n (0 < n < 20).
 
 
 Output
 The output format is shown as sample below. Each row represents a series of circle numbers in the ring beginning from 1 clockwisely and anticlockwisely. The order of numbers must satisfy the above requirements. Print solutions in lexicographical order.
 
 You are to write a program that completes above process.
 
 Print a blank line after each case.
 
 
 Sample Input
 6
 8
 
 
 Sample Output
 Case 1:
 1 4 3 2 5 6
 1 6 5 2 3 4
 
 Case 2:
 1 2 3 8 5 6 7 4
 1 2 5 8 3 4 7 6
 1 4 7 6 5 8 3 2
 1 6 7 4 3 8 5 2
*/