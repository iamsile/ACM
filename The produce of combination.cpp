#include <iostream>
using namespace std;
int n,m,a[40],b[40];

void cal(int k,int len)
{
    int i;
    if (k==m+1) {
        for (i=1; i<=m; i++) {
            if (i>1)
                cout << ' ';
            cout << a[i];
        }
        cout << '\n';
        return;
    }
    for (i=len; i<=n; i++) {
        a[k]=b[i];
        cal(k+1, i+1);
    }
}

int main()
{
    int t,i,flag=1;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (i=1; i<=n; i++)
            b[i]=i;
        cout << "Case " << flag++ << ":\n";
        cal(1,1);
    }
    return 0;
}
/*
 Problem description
 Give the number n and k, please enumerate all the combinations of k numbers which waer chosen from the number 1, 2 ,.....and n.
 
 Input
 The first line contains the number of test cases T, then the following T lines each contains two integer numbers n and k，(1 <= n <= 16, 1 <= k <= n).
 
 Output
 Results should be directed to standard output. Start each case with "Case #:" on a single line, where # is the case number starting from 1. Two consecutive cases should be separated by a single blank line. For each combination sort the numbers lexicographically/alphabetically and the numbers should separated with a space, please do not output space after the last number.For each test case, sort the different combinations lexicographically/alphabetically .
 
 Sample Input
 2
 3 2
 5 4
 Sample Output
 Case 1:
 1 2
 1 3
 2 3
 
 Case 2:
 1 2 3 4
 1 2 3 5
 1 2 4 5
 1 3 4 5
 2 3 4 5
*/