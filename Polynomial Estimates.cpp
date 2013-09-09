#include <iostream>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while (t--) {
        int i,n,cur,lab,flag=1,a[550],b[550];
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        scanf("%d",&n);
        for (i=1; i<=n; i++)
            scanf("%d",&a[i]);
        for (i=1,cur=1; i<n; i++)
            b[cur++]=a[i+1]-a[i];
        lab=1;
        for (i=1; i<cur-1; i++)
            a[lab++]=b[i+1]-b[i];
        for (i=1,cur=1; i<lab-1; i++)
            b[cur++]=a[i+1]-a[i];
        for (i=1; i<cur-1; i++)
            if (b[i+1]!=b[i]) {
                flag=0;
                break;
            }
        if (flag)
            puts("YES");
        else puts("NO");
    }
    return 0;
}
/*
 Problem description
 The number of spectators at the FIFA World Cup increases year after year. As you sell the adver- tisement slots during the games for the coming years, you need to come up with the price a company has to pay in order to get an advertisement slot. For this, you need a good estimate for the number of spectators in the coming games, based on the number of spectators in the past games.
 Your intuition tells you that maybe the number of spectators could be modeled precisely by a polynomial of degree at most 3. The task is to check if this intuition is true.
 
 
 Input
 The input starts with a positive integer N, the number of test cases. Each test case consists of one line. The line starts with an integer 1 <= n <= 500, followed by n integers x1, ... , xn with 0 <= xi <= 50000000 for all i, the number of spectators in past games.
 
 Output
 For each test case, print "YES" if there is a polynomial p (with real coecients) of degree at most 3 such that p(i) = xi for all i. Otherwise, print "NO".
 
 Sample Input
 3
 1 3
 5 0 1 2 3 4
 5 0 1 2 4 5
 Sample Output
 YES
 YES
 NO
*/