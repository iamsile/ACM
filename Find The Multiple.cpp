#include <iostream>
#include <string>
using namespace std;

bool multiple(string str,int n)
{
    int i,len=str.size(),mul=10,temp=0;
    for (i=0; i<len; i++) {
        temp=temp*mul+(str[i]-'0');
        if (temp<n)
            continue;
        else {
            temp%=n;
            if (temp==0)
                return true;
        }
    }
    return false;
}

int main()
{
    int n;
    string q[10001];
    char l[2]={'0','1'};
    while (cin >> n&&n) {
        int i,now=0,total=1;
        q[now]="1";
        while (now!=total) {
            if (multiple(q[now%10001],n)) {
                cout << q[now%10001] << '\n';
                break;
            }
            for (i=0; i<2; i++)
                q[(total++)%10001]=q[now%10001]+l[i];
            ++now;
        }
    }
    return 0;
}
/*
 Description
 
 Given a positive integer n, write a program to find out a nonzero multiple m of n whose decimal representation contains only the digits 0 and 1. You may assume that n is not greater than 200 and there is a corresponding m containing no more than 100 decimal digits.
 Input
 
 The input file may contain multiple test cases. Each line contains a value of n (1 <= n <= 200). A line containing a zero terminates the input.
 Output
 
 For each value of n in the input print a line containing the corresponding value of m. The decimal representation of m must not contain more than 100 digits. If there are multiple solutions for a given value of n, any one of them is acceptable.
 Sample Input
 
 2
 6
 19
 0
 Sample Output
 
 10
 100100100100100100
 111111111111111111
*/