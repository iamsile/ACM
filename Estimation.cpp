#include <iostream>
using namespace std;

long long qmod(long long a,long long b,long long m)
{
    if (b==0)
        return 1%m;
    if (b==1)
        return a%m;
    long long c=qmod(a, b/2, m);
    if (b%2==0)
        return ((c%m)*(c%m))%m;
    else return (((c%m)*(c%m))%m*(a%m))%m;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        long long n,m;
        cin >> n >> m;
        long long k=qmod(2,n,m);
        long long j=(((((((n*n)%m-(4*n)%m)+6%m)%m)*(k%m))%m-6%m)%m);
        j=j>=0?j:j+m;
        cout << j << '\n';
    }
    return 0;
}
//(N^2-4*N+6)*2^N-6
/*
Problem description
Let us define a sequence SN in the following way:

Sn=求和(k=0&&k<=n-1)k^2*2^k

Input
The first line contains an integer T, there will be T test cases in the data file. 
Each test case will contains integer N and M,0 < N ≤ 1000000000, 0 < M ≤ 1000000000. 


Output
For each test case, output a line containing single integer, representing SN modulo M. 


Sample Input
2
1  1000
2  1000
Sample Output
0
2
*/