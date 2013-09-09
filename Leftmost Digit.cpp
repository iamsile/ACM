#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        long double n,k,l,m;
        cin >> n;
        k=n*log10(n);
        l=k-floor(k);
        m=(int)(floor(pow(10, l)));
        cout << m << '\n';
    }
    return 0;
}
/*
 Problem Description
 Given a positive integer N, you should output the leftmost digit of N^N.
 
 
 Input
 The input contains several test cases. The first line of the input is a single integer T which is the number of test cases. T test cases follow.
 Each test case contains a single positive integer N(1<=N<=1,000,000,000).
 
 
 Output
 For each test case, you should output the leftmost digit of N^N.
 
 
 Sample Input
 2
 3
 4
 
 
 Sample Output
 2
 2
 */