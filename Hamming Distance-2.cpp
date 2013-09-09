#include <iostream>
using namespace::std;

int main()
{
	char a[101]={0},b[101]={0};
	while(cin >>a)
	{
		if(a[0]=='X')
			break;
		cin >> b;
		int i,num=0;
		for(i=0;i<strlen(a);i++)
			if(a[i]!=b[i])
				num++;
		printf("Hamming distance is %d.\n",num);
	}
	return 0;
}
/*
 Problem description
 Have you ever heard of the Hamming distance? It is the number of positions for which the corresponding digits differ. Your task is to write a program that computes this distance for two binary strings.
 
 Input
 The input contains several test cases. Each test case consists of two lines. Each line contains one binary number. Any two numbers given in one test case have the same length, which is at most 100 binary digits. The last test case is followed by a line containing the uppercase letter “X”.
 
 Output
 Your program must output a single line for each test case. The line should contain the statement “Hamming distance is X.”, where X is the number of positions where the two numbers have different digits.
 
 Sample Input
 0
 1
 000
 000
 1111111100000000
 0000000011111111
 101
 000
 X
 Sample Output
 Hamming distance is 1.
 Hamming distance is 0.
 Hamming distance is 16.
 Hamming distance is 2.
*/