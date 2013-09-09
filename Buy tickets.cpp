#include <iostream>
using namespace::std;

int main()
{
    int n,m;
    while (cin >> n >> m) 
    {
        if (n==0&&m==0)
            return 0;
        int i,lab=0,sum=0,a[1010]={0};
        for (i=0; i<n; i++)
            cin >> a[i];
        sort(a, a+n);
        lab=n;
        while (n>=0) {
            n=lab-m;
            lab=n;
            for (i=0; i<n; i++)
                sum+=a[i];
        }
        cout << sum << '\n';
    }
    return 0;
}
/*
 Problem description
 There are N people who want to buy some tickets, and there are M places to serve them. These people are numbered from 1 to N , and person i will be served in Ti minites. If N > M, some people will have to wait. Now we want to rearrange the sequence of these people so that the sum of the waiting time of all the people will be minimized, and your task is to calculate the minimum sum of waiting time. 
 
 Input
 The first line is two integers N(1 <= N <= 1000) and M(1 <= M <= 100), which is the number of the people and the number of places to serve them. The following n lines is the time which the N people need to be served.
 
 Output
 Only one integer, the minimum sum of waiting time. 
 
 Sample Input
 5 3
 3
 4
 2
 8
 4
 Sample Output
 5
*/