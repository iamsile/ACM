#include <iostream>
using namespace::std;

int main()
{
	int m,n,i,l=1,a[1001]={0},b[1001]={0};
	cin >> m;
	while(m--)
	{
		cin >> n;
		for(i=1;i<=n;i++)
			cin >> a[i];
		for(i=1;i<=n;i++)
			b[i]=a[i]-a[i-1];
		sort(b+1,b+n+1);
		cout << "Case " << l++ << ":" << '\n';
		for(i=1;i<=n;i++)
		{
			if(i>1)
				cout << " ";
			cout << b[i];
		}
		cout << '\n';
	}
}
/*
 Problem description
 An adjacent difference of a sequence is a new sequence formed by replacing every element with the difference between the element and the immediately preceding element. The first value in the new sequence remains unchanged. For example, a sequence such as (1, 3, 2, 4, 5) is transformed into (1, 3-1,2-3, 4-2, 5-4), and in this manner becomes the sequence (1, 2, -1, 2, 1). Then, we want to sort the adjacent difference of the sequence in non-decreasing order. It‘s an easy job for you, isn’t it? So, please solve it quickly. 
 
 Input
 Standard input will contain multiple test cases. The first line of the input is a single integer T(1 <= T <= 50) which is the number of test cases. For each test case, the first line contains an integer N(1 <= N <= 1000), representing the size of the sequence. The second line contains N integers (you are ensured that the absolute value of each integer is less than 2^16), representing the elements of this sequence. 
 
 Output
 Results should be directed to standard output. Start each case with "Case #:" on a single line, where # is the case number starting from 1. Two consecutive cases should be separated by a single blank line. No blank line should be produced after the last test case. For each test case, output one line containing n elements representing the sorted adjacent difference of the sequence. Elements are separated by one blank space. 
 
 Sample Input
 1
 5
 1 3 2 4 5
 Sample Output
 Case 1:
 -1 1 1 2 2
*/