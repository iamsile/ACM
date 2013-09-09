#include <iostream>
using namespace::std;

int main()
{
	int m;
	cin >> m;
	while(m--)
	{
		unsigned int a[21]={1,1};
		int i,n,j,k;
		cin >> n;
		if(n==1)
			cout << "1\n";
		else 
		{
			for(i=2;i<=n;i++)
			{
				k=0;
				for(j=i;j>0;)
					a[i]+=a[k++]*a[--j];
			}
			cout << a[n] << '\n';
		}
	}
	return 0;
}
/*
 对于由集合{1,2,...,2n-1,2n}构成的矩阵,如果要求从左至右,从上到下都是递增序列,这样的矩阵共有多少个. 
 假设这样的矩阵共有C(n)个,则可得到 
 C(n)=C(0)*C(n-1)+C(1)*C(n-2)+C(2)*C(n-3)+...+C(n-1)*C(0),其中C(0)=1(推导过程见具体数学)
 */
/*
 Problem description
 Given the numbers {1,2,...,2n} ,we can easily put them into a 2*n array so that rows and columns are in increasing order from left ot right and from top to bottom. For example, one solution when n = 5 is  . But how many ways are there forming such a matrix? Now given a number N (N<20), you should compute all matrixes satisfying the above description. For example, when N=3, all feasible ways are  
 
 Input
 The input contains several test cases. The first line of the input is the test case number T. For each test case, there is one positive integer N in a single line.
 
 Output
 For each test case, you should output one number, indicating the total ways feasible.
 
 Sample Input
 3
 1
 2
 5
 Sample Output
 1
 2
 42
*/