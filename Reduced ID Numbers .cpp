#include <iostream>
using namespace::std;

int main()
{
	int m;
	cin >> m;
	while(m--)
	{
		int n,i,j,k,a[300],b[300];
		memset(b,0,sizeof(b));
		cin >> n;
		for(i=0;i<n;i++)
			cin >> a[i];
		for(i=1;;i++)
		{
			for(j=0;j<n;j++)
				b[j]=a[j]%i;
			for(j=0;j<n;j++)
			{
				for(k=j+1;k<n;k++)
				{
					if(b[k]==b[j])
						break;
				}
				if(k!=n)
					break;
			}
			if(j==n)
				break;
		}
		cout << i << '\n';	
	}
	return 0;
}
/*
 Problem description
 T. Chur teaches various groups of students at university U. Every U-student has a unique Student Identification Number (SIN). A SIN s is an integer in the range 0 ≤ s ≤ MaxSIN with MaxSIN = 106-1. T. Chur finds this range of SINs too large for identification within her groups. For each group, she wants to find the smallest positive integer m, such that within the group all SINs reduced modulo m are unique. 
 
 Input
 On the first line of the input is a single positive integer N, telling the number of test cases (groups) to follow. Each case starts with one line containing the integer G (1 ≤ G ≤ 300): the number of students in the group. The following G lines each contain one SIN. The SINs within a group are distinct, though not necessarily sorted. 
 
 Output
 For each test case, output one line containing the smallest modulus m, such that all SINs reduced modulo m are distinct. 
 
 Sample Input
 2
 1
 124866
 3
 124866
 111111
 987651
 Sample Output
 1
 8
*/