#include <iostream>
using namespace::std;

int main()
{
	int n,lab=0;
	cin >> n;
	while(n--)
	{
		char a[1001],b[1001];
		int l,l1,i,c[1001]={0},d[1001]={0},e[1010]={0};
		cin >> a >> b;
		l=strlen(a);
		for(i=0;i<l;i++)
			c[l-i-1]=a[i]-'0';
		l1=strlen(b);
		for(i=0;i<l1;i++)
			d[l1-i-1]=b[i]-'0';
		if(l<l1)
			l=l1;
		for(i=0;i<l;i++)
		{
			e[i]+=c[i]+d[i];
			if(e[i]==2)
			{
				e[i+1]+=1;
				e[i]=0;
			}
			else if(e[i]==3)
			{
				e[i+1]+=1;
				e[i]=1;
			}
		}
		if(e[i-1]==2)
		{
			e[i]+=1;
			e[i-1]=0;
			l++;
		}
		else if(e[i-1]==3)
		{
			e[i]+=1;
			e[i]=1;
			l++;
		}
		else if(e[i]==1)
			l++;
		cout << ++lab << ' ';
		for(i=l-1;i>=0;i--)
		{
			if(e[i]==0&&i==l-1)
			{
				l--;
				continue;
			}
			cout << e[i];
		}
		if(l==0)
			cout << "0";
		cout << '\n';
	}
	return 0;
}
/*
 此题注意在输入000和0000时，是0,在输入000和0001时是1
 */
/*
 Problem description
 Adding binary numbers is a very simple task, and very similar to the longhand addition of decimal numbers. As with decimal numbers, you start by adding the bits (digits) one column at a time, from right to left. Unlike decimal addition, there is little to memorize in the way of rules for the addition of binary bits: 
 0 + 0 = 0
 1 + 0 = 1
 0 + 1 = 1
 1 + 1 = 10
 1 + 1 + 1 = 11
 Just as with decimal addition, when the sum in one column is a two-bit (two- digit) number, the least significant figure is written as part of the total sum and the most significant figure is "carried" to the next left column. Consider the following examples:
 11  1  <-- Carry bits --> 1   11
 1001101              1001001                     1000111
 + 0010010            + 0011001                   + 1010110
 ---------            ---------                   ---------
 1011111              1100010                    10011101
 The addition problem on the left did not require any bits to be carried, since the sum of bits in each column was either 1 or 0, not 10 or 11. In the other two problems, there definitely were bits to be carried, but the process of addition is still quite simple. 
 
 Input
 The first line of input contains an integer N, (1 ≤ N ≤ 1000), which is the number of binary addition problems that follow. Each problem appears on a single line containing two binary values separated by a single space character. The maximum length of each binary value is 80 bits (binary digits). Note: The maximum length result could be 81 bits (binary digits). 
 
 Output
 For each binary addition problem, print the problem number, a space, and the binary result of the addition. Extra leading zeroes must be omitted. 
 
 Sample Input
 3
 1001101 10010
 1001001 11001
 1000111 1010110
 
 Sample Output
 1 1011111
 2 1100010
 3 10011101
*/