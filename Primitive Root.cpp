#include <iostream>
using namespace std;

int qmod(int r,int p)
{
    int i,ans=1;
    r%=p;
    for(i=1;i<p-1;i++) {
        ans=(ans*r)%p;
        if (ans==1) {
            return 0;
        }
    }
    ans=(ans*r)%p;
    return ans==1;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int m,n;
        cin >> n;
        for (m=1; ; m++) {
            if (qmod(m,n)) {
                cout << m << '\n';
                break;
            }
        }
    }
    return 0;
}
/*
 Problem description
 Consider the following calculations :
 31(mod 7) = 3, 32(mod 7) = 2, 33(mod 7) = 6, 34(mod 7) = 4, 35(mod 7) = 5, 36(mod 7) = 1 Let p be a prime. Then r is a primitive root for p if the powers of r :
 r1, r2, r3, ... include all of the residue classes mod p (except 0). 3 is the smallest primitive root for 7. For a given prime number p (1 < p < 20000), calculate the smallest primitive root for p. 
 
 Input
 The first line contains an integer t (0 < t < 2000) which indicates the number of testcases, then followed t lines, each line contains a prime number p.
 
 Output
 For each testcase, output the smallest primitive root for p in separate lines.
 
 Sample Input
 2
 7
 13
 Sample Output
 3
 2
*/