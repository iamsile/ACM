#include<iostream>
using namespace std;

int main()
{
	int n,m;
	while(cin >> n >>m&&n&&m)
	{
		int i=0,j,l,k=1;
		while(n>=m)
		{
			n=n/m;
			i++;
		}
		cout << n <<'\n';
		for(l=1;l<=i;l++)
			k*=m;
		for(j=1;j<=n;j++)
		{
			if(j>1)
				cout << " ";
			cout << j*k;
		}
		cout << '\n';
	}
	return 0;
}
/*
 Problem description
 There are N soldiers standing in one line. They are marked from 1 to N, from right to left. And they are given a number m. Then the soldiers numbered off, straight from the right-hand man. The one who reported a number that is the multiple of m was kept in the line. Others have to leave the line. They continue doing this till the number of people in the line is less than m. For example, if there are 10 soldiers, and m = 3. For the first time the soldiers who are marked 3, 6, 9 remain in the line. For the second time the soldier who is marked 9 remains in the line. Because the number of soldiers in the line is less than m, so the soldier marked 9 was the only one to remain in the line.
 Now we want to know who will be the ones to remain, can you tell us ?
 
 
 Input
 There are several test cases in the input. Each test cases is only one line, contains two integers n and m.(3 <= n <= 109, 2 <= m <= n). The input ends when n = 0 and m = 0.
 
 Output
 For each test case, output two lines. The first line contains one integer x, the number of soldiers to remain. The second line contains x integers, the numbers marked on the soldiers who remain in the line. You should output them in increasing order.
 
 Sample Input
 10 3
 8 3
 0 0
 Sample Output
 1
 9
 2
 3 6
*/