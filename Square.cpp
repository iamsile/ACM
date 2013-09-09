#include <iostream>
#include <string.h>
using namespace std;
int n,sum,ave,a[100],v[100];

int cmp(const void *a,const void *b)
{
    return *(int *)b - *(int *)a;
}

bool dfs(int num,int len,int m)
{
    if (num==3)
        return true;
    for (int i=m; i<n; i++) {
        if (!v[i]) {
            v[i]=1;
            if (len+a[i]==ave) {
                if (dfs(num+1, 0, 0))
                    return true;
            }
            else if (len+a[i]<ave) {
                if (dfs(num,len+a[i],i+1))
                    return true;
            }
            v[i]=0;
        }
    }
    return false;
}

int main()
{
    int i,t;
    cin >> t;
    while (t--) {
        memset(a, 0, sizeof(a));
        cin >> n;
        sum=0;
        for (i=0; i<n; i++) {
            cin >> a[i];
            sum+=a[i];
        }
        ave=sum/4;
        qsort(a, n, sizeof(a[0]), cmp);
        if (ave<a[0]||n<4||sum%4) {
            cout << "no\n";
            continue;
        }
        memset(v, 0, sizeof(v));
        if (dfs(0,0,0))
            cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}
/*
 Problem Description
 Given a set of sticks of various lengths, is it possible to join them end-to-end to form a square?
 
 
 Input
 The first line of input contains N, the number of test cases. Each test case begins with an integer 4 <= M <= 20, the number of sticks. M integers follow; each gives the length of a stick - an integer between 1 and 10,000.
 
 
 Output
 For each case, output a line containing "yes" if is is possible to form a square; otherwise output "no".
 
 
 Sample Input
 3
 4 1 1 1 1
 5 10 20 30 40 50
 8 1 7 2 6 4 4 3 5
 
 
 Sample Output
 yes
 no
 yes
*/