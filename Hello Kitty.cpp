#include <iostream>
using namespace::std;

int main()
{
	char a[30];
	while(cin >> a&&a[0]!='.')
	{
		int n,i,j,k=0;
		char *p=a;
		cin >> n;
		for(i=0;i<strlen(a);i++)
		{
			j=0;
			if(i>0)
				k++;
			while(j<n*strlen(a))
			{
				cout << *(p+k);
				k++;
				j++;
				if(k==strlen(a))
					k=0;
			}
			cout << '\n';
		}
	}
	return 0;
}
/*
 Problem description
 Kitty sends a kind of original email messages to her friend Garf. To write a message, she chooses a word W and a number n and replicates W n times horizontally. Then she repeats this string in the next line, but rotating the characters once to the left. And she repeats this ‘rotateand- output’ process until the word W appears displayed as the first column of the rectangular pattern that she produces.
 
 As an example, when she chooses the word Hello and the number 3, she gets the pattern: 
 HelloHelloHello
 elloHelloHelloH
 lloHelloHelloHe
 loHelloHelloHel
 oHelloHelloHell
 
 Kitty has been sending such emails during the last three years. Recently, Garf told her that perhaps her work may be automatized with a software to produce Kitty’s patterns. Could you help her?
 
 Input
 The input file contains several test cases, each one of them in a separate line. Each test case has a word and a positive integer that should generate the corresponding rectangular pattern. The word is a string of alphabetic characters (a..z). The number is less than 10.
 
 A line whose contents is a single period character means the end of the input (this last line is not to be processed).
 
 
 
 Output
 Output texts for each input case are presented in the same order that input is read. For each test case the answer must be a left aligned Kitty pattern corresponding to the input.
 The output must be written to standard output. 
 
 Sample Input
 Love 1
 Kitty 2
 .
 Sample Output
 Love
 oveL
 veLo
 eLov
 KittyKitty
 ittyKittyK
 ttyKittyKi
 tyKittyKit
 yKittyKitt
 */
