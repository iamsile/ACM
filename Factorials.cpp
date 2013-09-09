#include <iostream>
#include <deque>
using namespace::std;

int main()
{
    deque<int> a;
    int n;
    while(cin >> n&&n>=0)
    {
        a.push_back(1);
        a.push_back(1);
        int top=1;
		if(n==0)
		{
			cout << "1" << '\n';
			continue;
		}
       for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=top;j++)
                a[j]*=i;
            for(int j=1;j<=top;j++)
            {
                if(a[j]>10)
                {
                    for(int r=1;r<=top;r++)
                    {
                        int tmp=a[r]/10;
                        a[r]=a[r]%10;
                        if(r+1==a.size())
                        {
                            if(tmp==0)
                                break;
                            else 
                            {
                                a.push_back(tmp);
                                top++;
                                break;
                            }
                        }
                        a[r+1]+=tmp;
                    }
                }
            }
		}
        for(int j=top;j>0;j--)
            cout << a[j];
        cout << '\n';
        a.clear();
    }
    return 0;
}
/*
 Problem description
 The factorial of n, (written as n!) is n * (n - 1) * (n - 2) * ... * 2 * 1. 0! = 1 (go lookup the Gamma function to find out why). In this problem, you'll be calculating the factorial of an integer between 0 and 100. 100! has no more than 200 digits. 
 
 Input
 There are 1 or more lines of input. Each line has a single integer, N, on it, such that 0 <= N <= 100. 
 
 Output
 For each line of input, your program should print out N!. 
 
 Sample Input
 8
 50
 Sample Output
 40320
 30414093201713378043612608166064768844377641568960512000000000000
*/