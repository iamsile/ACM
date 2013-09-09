#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    while (scanf("%d",&n)!=EOF) {
        int i,l,u,a[10010];
        for (i=0; i<n; i++)
            cin >> a[i];
        sort(a, a+n);
        for (i=0,l=0,u=n-1; i<n; i++) {
            if (i)
                cout << ' ';
            if (i%2==0)
                cout << a[u--];
            else cout << a[l++];
        }
        cout << '\n';
    }
    return 0;
}
/*
 Problem Description
 Acmer in HDU-ACM team are ambitious, especially shǎ崽, he can spend time in Internet bar doing problems overnight. So many girls want to meet and Orz him. But Orz him is not that easy.You must solve this problem first.
 The problem is :
 Give you a sequence of distinct integers, choose numbers as following : first choose the biggest, then smallest, then second biggest, second smallest etc. Until all the numbers was chosen . 
 For example, give you 1 2 3 4 5, you should output 5 1 4 2 3
 
 
 Input
 There are multiple test cases, each case begins with one integer N(1 <= N <= 10000), following N distinct integers.
 
 
 Output
 Output a sequence of distinct integers described above.
 
 
 Sample Input
 5
 1 2 3 4 5
 
 
 Sample Output
 5 1 4 2 3
*/