#include <iostream>
using namespace::std;

int main()
{
	char s[1001];
	int i,j,m;
	cin >> m;
	while(m)
	{
		cin >> s;
		i=strlen(s);
		for(j=0;j<i/2;j++)
		{
			if(s[j]!=s[i-j-1]&&(char)(s[j]+32)!=s[i-j-1]&&s[j]!=(char)(s[i-j-1]+32)
			   &&(char)(s[j]-32)!=s[i-j-1]&&s[j]!=(char)(s[i-j-1]-32))
			{
				cout << "NO" << '\n';
				break;
			}
		}
		if(j==i/2)
			cout << "YES" << '\n';
		m--;
	}
	return 0;
}
/*
 Problem description
 A palindrome is a symmetrical string, that is, a string read the same from left to right as from right to left. You are asked to write a program which, given a string, determines whether it is a palindrome or not.
 
 
 Input
 The first line contain a single integer T, indicates the number of test cases.
 T lines follow, each line contain a string which you should judge. The length of the string is at most 1000.
 
 
 Output
 Print one line for each string, if it is a palindrome, output “YES”, else “NO”.
 
 
 Sample Input
 2
 aba
 ab
 Sample Output
 YES
 NO
 */
