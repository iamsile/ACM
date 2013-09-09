#include <iostream>
#include <string.h>
using namespace::std;

int v1(int a,int b)
{
	int temp;
	if (a) {
		temp=a;
		a=b;
		b=temp;
	}
	while (b) {
		temp=a%b;
		a=b;
		b=temp;
	}
	return a;
}

int v2(int c,int d,int f)
{
	int e;
	if(c>d)
		e=d/f*c;
	else 
		e=c/f*d;
	return e;
}

int main()
{
    char a[30];
    while (cin >> a) 
    {
        int i,m,n,sum=1,flag=0;
        if (a[0]=='*')
            return 0;
        for (i=1; i<=strlen(a); i++) 
            if (a[i-1]=='Y')
            {
                m=v1(i, sum);
                n=v2(i, sum, m);
                sum=n;
            }
        for (i=1; i<=strlen(a); i++)
            if (a[i-1]=='N'&&sum%i==0) 
            {
                flag=1;
                break;
            }
        if (flag)
            cout << "-1\n";
        else 
            cout << sum << '\n';
    }
    return 0;
}
/*
 Problem description
 You are playing the funny game "Guess the number" with a friend. In this game, one of the players choose a positive integer and the other has to guess it by using the clues that are revealed. The i-th clue is either "Y" or "N" indicating whether the hidden number is a multiple of i or not, respectively. For instance, if the clues so far are "YYNYY" it means that the number is a multiple of 1, 2, 4 and 5, but it is not a multiple of 3. Given the clues of the game so far, you have to guess the minimum possible number according to them, or call your friend a cheater if there is no number such that the clues were correctly given.
 
 Input
 The input contains several test cases. Each test case is described in a single line that contains a non-empty string of at most 20 characters. The string is formed entirely of uppercase letters "Y" and "N", and represents the clues given so far, in order from left to right. The last line of the input contains a single asterisk and should not be processed as a test case.
 
 Output
 For each test case output a single line with the minimum positive integer that satisfies all the clues, or -1 if there is no such a number.
 
 Sample Input
 YYNYY
 YYYNNN
 *
 Sample Output
 20
 -1
*/