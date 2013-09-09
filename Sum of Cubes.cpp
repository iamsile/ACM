#include <iostream>
using namespace::std;
int a[1000009];

int main()
{
    int i,j,n,m,x,y;
    while(cin >> n&&n)
    {
        m=1;
        for(i=1000;i>=0&&m;i--)
        {
            for(j=i-1;j>=0;j--)
            {
                if(i*i*i-j*j*j>n)
                    break;
                if(i*i*i-j*j*j==n)
                {
                    x=-j;
                    y=i;
                    m=0;
                    break;
                }
            }
        }
        if(m)
        {
			for(i=1;i<=100;i++)
				a[i*i*i]=i;
            for(i=0;;i++)
            {
                j=i*i*i;
                if(n-j<0)
                    break;
                if(a[n-j]>0)
                {
                    x=i;
                    y=a[n-j];
                    m=0;
                    break;
                }
            }
        }
        if(m)
            cout << "impossible\n";
        else 
            cout << x << " " << y << '\n';
    }
    return 0;
}
/*
 Problem description
 
 
 According to Goldbach’s conjecture, every even number can be expressed as a sum of two odd primes. Which numbers can be expressed as the sum of two cubes? 
 
 Input
 For each test case, a line will contain a positive integer n which will be at most one million. 
 The last line will contain the integer 0, which should not be processed. 
 
 Output
 For each test case, output two integers x and y such that x3 + y3 = n. If there are many such pairs of numbers, hoose x to be as small as possible. If there are no such pairs, output “impossible”.
 
 Sample Input
 1
 2
 3
 1000000
 0
 Sample Output
 0 1
 1 1
 impossible
 0 100
*/