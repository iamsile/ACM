#include <iostream>
#include <string.h>
using namespace::std;

int main()
{
	int n;
	char a[500];
	string b;
	cin >> n;
	getchar();
	while(n)
	{
		cin.getline(a,500);
		b=a;
		reverse(b.begin(),b.end());
		cout << b << '\n';
		n--;
	}
	return 0;
}
/*
 
 Problem description
 Given a list of words, print the words reversed on separate lines. Each word consists of English letters only.
 
 Input
 The input consists of T test cases. The number of test cases (T) is given in the first line of the input file. Each test case consists of a single line, each line contains a word.
 
 Output
 For each test case, print the word reversed on one line.
 
 Sample Input
 2
 HelloWorld
 Madam
 Sample Output
 dlroWolleH
 madaM
*/