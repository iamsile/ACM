#include <iostream>
using namespace::std;

int cal(int b,int k)
{
	int sum=0;
	while(b)
	{
		sum+=b%k;
		b/=k;
	}
	return sum;
}

int main()
{
	for(int i=2992;i<=9999;i++)
		if(cal(i,10)==cal(i,12)&&cal(i,10)==cal(i,16))
			cout << i << '\n';
	return 0;
}
//求在三种进制下是否相等
/*
 Problem description
 Find and list all four-digit numbers in decimal notation that have the property that the sum of its four digits equals the sum of its digits when represented in hexadecimal (base 16) notation and also equals the sum of its digits when represented in duodecimal (base 12) notation. 
 For example, the number 2991 has the sum of (decimal) digits 2+9+9+1 = 21. Since 2991 = 1*1728 + 8*144 + 9*12 + 3, its duodecimal representation is 189312, and these digits also sum up to 21. But in hexadecimal 2991 is BAF16, and 11+10+15 = 36, so 2991 should be rejected by your program. 
 The next number (2992), however, has digits that sum to 22 in all three representations (including BB016), so 2992 should be on the listed output. (We don't want decimal numbers with fewer than four digits -- excluding leading zeroes -- so that 2992 is the first correct answer.) 
 
 
 Input
 There is no input for this problem
 
 Output
 Your output is to be 2992 and all larger four-digit numbers that satisfy the requirements (in strictly increasing order), each on a separate line with no leading or trailing blanks, ending with a new-line character. There are to be no blank lines in the output. The first few lines of the output are shown below. 
 
 Sample Input
 There is no input for this problem
 Sample Output
 2992
 2993
 2994
 2995
 2996
 2997
 2998
 2999
 ...
*/