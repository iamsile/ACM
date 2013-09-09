#include <iostream>
using namespace std;

int gcd(int a,int b)
{
    if (b==0) 
        return a;
    return gcd(b, a%b);
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int i,n,m,temp=0,ans=1;
        cin >> n;
        for (i=0; i<n; i++) {
            cin >> m;
            temp=gcd(ans,m);
            ans=ans/temp*m;
        }
        cout << ans << '\n';
    }
    return 0;
}
/*
 Problem Description
 The least common multiple (LCM) of a set of positive integers is the smallest positive integer which is divisible by all the numbers in the set. For example, the LCM of 5, 7 and 15 is 105.
 
 
 
 Input
 Input will consist of multiple problem instances. The first line of the input will contain a single integer indicating the number of problem instances. Each instance will consist of a single line of the form m n1 n2 n3 ... nm where m is the number of integers in the set and n1 ... nm are the integers. All integers will be positive and lie within the range of a 32-bit integer.
 
 
 Output
 For each problem instance, output a single line containing the corresponding LCM. All results will lie in the range of a 32-bit integer.
 
 
 Sample Input
 2
 3 5 7 15
 6 4 10296 936 1287 792 1
 
 
 Sample Output
 105
 10296
*/