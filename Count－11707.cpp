#include <iostream>
using namespace::std;

int main()
{
    int n,i;
    while(cin >> n&&n!=-1)
    {
        unsigned int a[10002]={1,1};
        for(i=1;i<n+1;i++)
            a[i+1]=(a[i-1]+a[i])%10000007;
        cout << a[i]%10000007 << '\n';
    }
    return 0;
}
/*
 Problem description
 Little Tom is a very clever boy, one day he is paint a 1*n grid. There is only two color: blue and red, but red can't paint in two adjacent grids, little Tom want to known how many different means to paint the grids. 
 
 
 
 Input
 There will be multiple test cases. Each case contain the number of the grid n(0≤n≤10000).If input -1 is the end of the case. 
 
 
 Output
 The different means to paint the grids. The number of the result may be very large, the result should mod 10000007. 
 
 
 Sample Input
 1
 2
 10000
 -1
 Sample Output
 2
 3
 4756634
*/