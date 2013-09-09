#include <iostream>
using namespace::std;

int main()
{
    int n,i,m;
    while (cin>>n) {
        i=1,m=2;
        if(n%2==0||n==1)
            cout << "2^" << "?" << " mod " << n << " = 1\n";
        else {
            while(m!=1) {
                m=m<<1;
                if(m%n==1)
                    break;
                m%=n;
                i++;
            }
            cout << "2^" << i+1 << " mod " << n << " = 1\n";
        }
    }
    return 0;
}
/*
 Problem description
 Give a number n, find the minimum x that satisfies 2^x mod n = 1. 
 
 Input
 One positive integer on each line, the value of n. 
 
 Output
 If the minimum x exists, print a line with 2^x mod n = 1.
 Print 2^? mod n = 1 otherwise.
 You should replace x and n with specific numbers.
 
 
 Sample Input
 2
 5
 Sample Output
 2^? mod 2 = 1
 2^4 mod 5 = 1
*/