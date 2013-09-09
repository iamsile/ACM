#include <iostream> 
using namespace std; 
__int64 gcd(__int64 a,__int64 b) 
{ 
	if(a>b) 
		return(gcd(b,a));
	else if(a==0) 
		return(b);
	else return(gcd(b%a,a)); 
} 
int main() 
{ 
    int n; 
    __int64 ans,x,temp; 
    cin>>n; 
    while (n!=0) 
    { 
		ans=1; 
		for (int i=1;i<=n;++i) 
		{ 
			cin>>x; 
			temp=gcd(ans,x); 
			if(temp!=0)
			ans=ans/temp*x;                
		} 
		cout<<ans<<endl; 
		cin>>n; 
    } 
    return(0); 
} 
/*#include <iostream>
using namespace::std;

int main()
{
    int n;
    while(cin >> n&&n)
    {
        unsigned i,lab,max=0,a[102]={0};
        for(i=0;i<n;i++)
        {
            cin >> a[i];
            if(a[i]>max)
                max=a[i];
        }
        lab=max;
        while(1)
        {
            for(i=0;i<n;i++)
                if(lab%a[i]!=0)
                    break;
            if(i>=n)
                break;
            lab+=max;
        }
        cout << lab << '\n';
    }
    return 0;//此代码re
}*/
/*
 Problem description
 In arithmetic and number theory the least common multiple or lowest common multiple (lcm) or smallest common multiple of two integers a and b is the smallest positive integer that is a multiple of both a and b. If there is no such positive integer, e.g., if a = 0 or b = 0, then lcm(a, b) is defined to be zero.
 For example, the least common multiple of the numbers 4 and 6 is 12.
 
 
 Input
 The input contains several cases. Each case has one line containing a non-negative integer N (N<=100), then followed N non-negative integers in the range of 0 and 2147483647. A ZERO terminates the input, which should not be processed.
 
 Output
 For each test case, output the least common multiple of the N integers in seperate lines. It is guaranteed that the lcm would not exceed 231 - 1. 
 
 Sample Input
 2
 12 18
 5
 3 9 27 81 243
 0
 Sample Output
 36
 243
*/