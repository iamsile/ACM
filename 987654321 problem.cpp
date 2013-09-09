#include <iostream> 
using namespace std; 
long n; 
int main() 
{ 
    while(cin>>n)
	{
		if(n<=8)
			cout<<"no solution\n";
		else if(n==9) 
			cout<<"111111111\n"; 
		else 
		{
			for(int i=1;i<=n;++i) 
				cout<<1; 
			cout << '\n';
		}
	}
    return 0; 
} 
/*
 Problem description
 For given number N you must output a N-digit numbers, such, that last digits of the number square is equal to 987654321. 
 
 Input
 Input contains several test cases,each test case contains an integer number N (1≤N≤106)in a line;
 N=0 indicates the end of input,and need not to be processed.
 
 Output
 For each test case, output "no solution" in a single line if there is no solution,otherwise,write answer to the output.
 If there are more than one solutions,output any of them.
 
 Sample Input
 8
 Sample Output
 no solution
*/