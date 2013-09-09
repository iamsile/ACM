#include <iostream>
using namespace::std;

int main()
{
	int m,n;
	while(cin >> m >> n&&m&&n)
	{
		int i,j,hash[205]={0},num=0;
		char a[205][205]={0};
		for(i=1;i<=m;i++)
			for(j=1;j<=n;j++)
				cin >> a[i][j];
		getchar();
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				if(a[j][i]=='0'&&a[j-1][i]=='0')
					num++;
				else if(a[j][i]=='0'&&a[j-1][i]!='0')
				{
					hash[num]++;
					num=1;
				}
				if(j==m)
					hash[num]++;
			}
			num=0;
		}
		for(i=1;i<=m;i++)
			if(hash[i])
				cout << i << ' ' << hash[i] << '\n';
	}
	return 0;
}
/*
 Problem description
 Because of its age, the City Hall has suffered damage to one of its walls. A matrix with M rows and N columns represents the encoded image of that wall, where 1 represents an intact wall and 0 represents a damaged wall (like in Figure-1).
 
 1110000111
 1100001111
 1000000011
 1111101111
 1110000111
 
 To repair the wall, the workers will place some blocks vertically into the damaged area. They can use blocks with a fixed width of 1 and different heights of {1,2, ..., M}. 
 
 For a given image of the City Hall’s wall, your task is to determine how many blocks of different heights are needed to fill in the damaged area of the wall, and to use the least amount of blocks. 
 
 Input
 There is only one test case. The case starts with a line containing two integers M and N (1 <= M, N <= 200). Each of the following M lines contains a string with length of N, which consists of “1”s and/or “0”s. These M lines represent the wall.
 
 Output
 You should output how many blocks of different heights are needed. Use separate lines of the following format:
 
 k Ck
 
 where k{1,2, ..., M} means the height of the block, and Ck means the amount of blocks of height k that are needed. You should not output the lines where Ck = 0. The order of lines is in the ascending order of k. 
 
 Sample Input
 5 10
 1110000111
 1100001111
 1000000011
 1111101111
 1110000111
 Sample Output
 1 7
 2 1
 3 2
 5 1
*/