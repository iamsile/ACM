#include <iostream>
#include <string.h>
using namespace std;
bool l[10];
int r[10];
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        memset(l,0,sizeof(l));
        memset(r,0,sizeof(r));
        unsigned long n;
        cin>>n;
        int a=n%10;
        int b=a;
        int i=1;
        l[b]=true;r[0]=b;
        b=(b*a)%10;
        while(!l[b])
        {
            l[b]=true;
            r[i++]=b;
            b=(b*a)%10;
        }
        cout<<r[(n-1)%i]<<endl;
    }
    return 0;
}
/*
 Problem Description
 Given a positive integer N, you should output the most right digit of N^N.
 
 
 Input
 The input contains several test cases. The first line of the input is a single integer T which is the number of test cases. T test cases follow.
 Each test case contains a single positive integer N(1<=N<=1,000,000,000).
 
 
 Output
 For each test case, you should output the rightmost digit of N^N.
 
 
 Sample Input
 2
 3
 4
 
 
 Sample Output
 7
 6
*/