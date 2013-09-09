#include <iostream>
using namespace::std;

int main()
{
	int n,m,k;
	while(cin >> n >> m >> k&&n&&m&&k)
	{
		int i,sum,lab=0,a[101]={0};
		for(i=0;i<k;i++)
			cin >> a[i];
		sum=n;
		for(i=1;i<m;i++)
		{
			n+=a[lab];
			lab=(lab+1)%k;
			sum+=n;
		}
		cout << sum << '\n';
	}
	return 0;
}
/*
 Problem description
 Marcia loves to knit. As she knits, she wonders how many stitches the project she is working on will take to complete. 
 On every project, she starts with a row of a given number of stitches, and then adds more rows. Sometimes the next row will have the same number of stitches as the previous row and other times the next row will have more or less stitches than the previous row. 
 For example, a pattern for a triangular shawl may begin with just 3 stitches and add 2 stitches on each row. So, the first row will have 3 stitches, the second row will have 5 stitches, the third will have 7 stitches, and so on. If the project has a total of 3 rows, then it has a total of 15 stitches. 
 A more complex scarf project may have a 4 row repeating pattern that increases 6 stitches on the first row of the pattern, decreases 2 stitches on each of the next two rows, and has no change on the final row of the pattern. So, a scarf that has 50 stitches on the first row will have 56 on the second row, 54 on the third row, 52 on the fourth row, and 52 on the fifth row. On the sixth row, the pattern repeats, so there will be an increase of 6 stitches for a total of 58 stitches on that row. If the project stops there at 6 rows, then it will have a total of 322 stitches. 
 You will write a program to help Marcia figure out how many stitches a project will take to complete. 
 
 
 Input
 The input to your program will be information about one or more projects. Each project's description will take up 2 lines. The first line contains three integers: 
 N M K 
 Where N (1 ≤ N ≤ 100) represents the number of stitches in the first row of the project, M (1 ≤ M ≤ 1000) represents the total number of rows in the project, and K (1 ≤ K ≤ 100) represents the number of rows in the repeating pattern. On the following line will be exactly K integers, each one in the range from -100 to 100 (inclusive), indicating the repeating pattern, where negative values indicate a number of stitches to decrease, positive values indicate a number of stitches to increase, and 0 indicates no change. In any project, the pattern will never cause any row to have 0 or fewer stitches. End of input is indicated by a line with three 0's. 
 
 
 Output
 For each project, give the total number of stitches in the completed project. Print each integer answer on its own line, with no blank lines between answers. 
 
 
 Sample Input
 3 3 1 
 2 
 50 6 4 
 6 -2 -2 0 
 0 0 0 
 Sample Output
 15 
 322 
*/