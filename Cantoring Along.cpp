#include <iostream>
#include <math.h>
using namespace::std;

void cal(int n)
{
	long i,k;
	if(n==0)
		cout << '-';
	else if(n==1)
		cout << "- -";
	else 
	{
		cal(n-1);
		k=pow(3.0, n-1);
		for(i=0;i<k;i++)
			cout << ' ';
		cal(n-1);
	}
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		cal(n);
		cout << '\n';
	}
	return 0;
}
/*
 Problem description
 The Cantor set was discovered by Georg Cantor. It is one of the simpler fractals. It is the result of an infinite process, so for this program, printing an approximation of the whole set is enough.
 
 The following steps describe one way of obtaining the desired output for a given order Cantor set:
 
 1. Start with a string of dashes, with length 3order
 
 2. Replace the middle third of the line of dashes with spaces. You are left with two lines of dashes at each end of the original string.
 
 3. Replace the middle third of each line of dashes with spaces. Repeat until the lines consist of a single dash.
 
 For example, if the order of approximation is 3, start with a string of 27 dashes:
 
 ---------------------------
 Remove the middle third of the string:
 
 ---------         ---------
 and remove the middle third of each piece:
 
 ---   ---         ---   ---
 and again:
 
 - -   - -         - -   - -
 The process stops here, when the groups of dashes are all of length 1. You should not print the intermediate steps in your program. Only the final result, given by the last line above, should be displayed.
 
 
 
 Input
 Each line of input will be a single number between 0 and 12, inclusive, indicating the order of the approximation. The input stops when end-of-file is reached.
 
 Output
 You must output the approximation of the Cantor set, followed by a newline. There is no whitespace before or after your Cantor set approximation. The only characters that should appear on your line are '-' and ' '. Each set is followed by a newline, but there should be no extra newlines in your output.
 
 Sample Input
 0
 1
 3
 2
 Sample Output
 -
 - -
 - -   - -         - -   - -
 - -   - -
*/