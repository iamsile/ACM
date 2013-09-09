#include <iostream>
using namespace::std;

int main()
{
	char s[1001];
	int i,j;
	while(cin >> s)
	{
		i=strlen(s);
		for(j=0;j<i/2;j++)
		{
			if(s[j]!=s[i-j-1]&&(char)(s[j]+32)!=s[i-j-1]&&s[j]!=(char)(s[i-j-1]+32)
			   &&(char)(s[j]-32)!=s[i-j-1]&&s[j]!=(char)(s[i-j-1]-32))
			{
				cout << "no" << '\n';
				break;
			}
		}
		if(j==i/2)
		{
			cout << "yes" << '\n';
			continue;
		}
	}
	return 0;
}
/*
 Problem description
 Background:
 
 Palindromes are strings that read the same both forwards and backwards. `Eye' is one such example (ignoring case). In this problem, you get to write a program to determine if a given word is a palindrome or not. 
 
 Input
 Each line of input contains one word with no embedded spaces. Each word will have only alphabetic characters (either upper or lower case). 
 
 Output
 For each line of input, output either `yes' if the word is a palindrome or `no' otherwise. Don't print the quotes. Case should be ignored when checking the words. 
 
 Sample Input
 eyE
 laLAlal
 Foof
 foobar
 Sample Output
 yes
 yes
 yes
 no
*/