#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int i,y,n;
        cin >> y >> n;
        for (i=0;i<=n ;) 
        {
            if ((y%4==0&&y%100!=0)||y%400==0)
            {
                i++;
                if (i==n)
                    break;
            }
            y++;
        }
        cout << y << '\n';
    }
    return 0;
}
/*
 Problem Description
 Ignatius was born in a leap year, so he want to know when he could hold his birthday party. Can you tell him?
 
 Given a positive integers Y which indicate the start year, and a positive integer N, your task is to tell the Nth leap year from year Y.
 
 Note: if year Y is a leap year, then the 1st leap year is year Y.
 
 
 Input
 The input contains several test cases. The first line of the input is a single integer T which is the number of test cases. T test cases follow.
 Each test case contains two positive integers Y and N(1<=N<=10000).
 
 
 Output
 For each test case, you should output the Nth leap year from year Y.
 
 
 Sample Input
 3
 2005 25
 1855 12
 2004 10000
 
 
 Sample Output
 2108
 1904
 43236
 
 Hint
 
 We call year Y a leap year only if (Y%4==0 && Y%100!=0) or Y%400==0.
*/