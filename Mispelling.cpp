#include <iostream>
using namespace::std;

int main()
{
	int m,l=0;
	cin >> m;
	while(m--)
	{
		int n,k,i;
		char a[1001];
		cin >> n;
		cin.getline(a,1001);
		k=strlen(a);
		cout << ++l;
		for(i=0;i<k;i++)
			if(i!=n)
				cout << a[i];
		cout << '\n';
	}
	return 0;
}
/*
 Problem description
 Misspelling is an art form that students seem to excel at. Write a program that removes the nth character from an input string.
 
 Input
 The first line of input contains a single integer N, (1 ≤ N ≤ 1000) which is the number of datasets that follow.
 Each dataset consists of a single line of input containing M, a space, and a single word made up of uppercase letters only. M will be less than or equal to the length of the word. The length of the word is guaranteed to be less than or equal to 80.
 
 Output
 For each dataset, you should generate one line of output with the following values: The dataset number as a decimal integer (start counting at one), a space, and the misspelled word. The misspelled word is the input word with the indicated character deleted.
 
 Sample Input
 4
 4 MISSPELL
 1 PROGRAMMING
 7 CONTEST
 3 BALLOON
 Sample Output
 1 MISPELL
 2 ROGRAMMING
 3 CONTES
 4 BALOON
*/