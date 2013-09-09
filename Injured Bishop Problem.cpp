#include <iostream>
#include <math.h>
using namespace::std;

int main()
{
	int m,k=1;
	cin >> m;
	while(m--)
	{
		int n,x,y,x1,y1,a,b;
		cin >> n;
		cin >> x >> y;
		cin >> x1 >> y1;
		a=abs(x-x1);
		b=abs(y1-y);
		cout << "Case " << k++ << ":"<< '\n';
		if((a+b)%2==0)
		{
			if(b>a)
				a=b;
		}
		else 
			a=-1;
		cout << a << '\n';
		if(m>0)
			cout << '\n';
	}
	return 0;
}
/*
 Problem description
 Given a chessboard made up of N squares by N squares. An injured bishop is a bishop who can move only one step in diagonal direction from current position. You will have to find the minimal distance for the injured bishop to move from an initial position to the final position. We denotes the position of an injured bishop by (x, y), which represents the bishop in the x-th row, the y-th column. The following figure illustrates that: 
 
 
 Fig: Injured Bishop at (3, 1) can reach the adjacent grey squares. Bishop at (5, 5) can reach adjacent grey squares. The injured bishop positions are black and the reachable places are grey. 
 
 Input
 Standard input will contain multiple test cases. The first line of the input is a single integer T (1 <= T <= 50) which is the number of test cases. For each test case, the first line contains an integer N (1 <= N <= 10000), which denotes the chessboard dimension. The second line contains (x, y) (1 <= x, y <= N) denoting the initial position, while the third line has the same form and it denotes the final position. 
 
 Output
 Results should be directed to standard output. Start each case with "Case #:" on a single line, where # is the case number starting from 1. Two consecutive cases should be separated by a single blank line. No blank line should be produced after the last test case. For each test case, output a single line containing the minimal distance for the injured bishop to move from the initial position to the final position. If the injured bishop can’t move to the final position, just output -1 instead. 
 
 Sample Input
 2
 4
 1 1
 2 2
 8
 3 3
 3 3
 Sample Output
 Case 1:
 1
 
 Case 2:
 0
*/