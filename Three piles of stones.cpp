#include <iostream>
#include <math.h>
using namespace::std;

int main()
{
	long long a,b,c;
	while(cin >> a >> b >> c)
	{
		unsigned k1=abs(a-b),k2=abs(b-c),k3=abs(a-c);
		if((k1%3==0&&k2%3==0)||(k1%3==0&&k3%3==0)||(k2%3==0&&k3%3==0))
			cout << "YES\n";
		else if(k1%3==0||k2%3==0||k3%3==0)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}
/*
 Problem description
 There are three piles of stones; these three piles contain a, b, c stones respectively. We call the procedure below an operation:
 we choose two non-empty piles.
 we take one stone from each of the piles we choose.
 we put the two stones into the pile we did not choose in procedure 1.
 Some times, we can merge three piles of stones into just one pile through finite operations, for example, if(a,b,c)=(1,1,1), we just need one operation; some times we can’t, for example, if(a,b,c)=(1,2,3).
 Now the question has come, we give you three piles of stone, you are asked to check if these three can be merged into one pile through finite operations.
 
 
 Input
 The input contains multi-test cases. Each test case contains three integers a, b, c in a line.0<=a,b,c<231-1. 
 
 Output
 If we can merge these piles into just one pile, output ‘YES’, otherwise output ‘NO’.
 
 Sample Input
 1 1 1
 1 2 3
 Sample Output
 YES
 NO
*/