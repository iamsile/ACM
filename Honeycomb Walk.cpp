#include <iostream>
using namespace::std;
int cell[30][30][15]={0};

int walk(int x,int y,int s)
{
	int ways=0;
	if(cell[x][y][s])
		return cell[x][y][s];
	if(s==0)
		return (x==15&&y==15);
	ways+=walk(x-1,y-1,s-1);
	ways+=walk(x+1,y+1,s-1);
	ways+=walk(x-1,y,s-1);
	ways+=walk(x+1,y,s-1);
	ways+=walk(x,y-1,s-1);
	ways+=walk(x,y+1,s-1);
	cell[x][y][s]=ways;
	return ways;
}

int main()
{
	int n,k;
	cin >> k;
	while(k--)
	{
		cin >> n;
		cout << walk(15,15,n) << '\n';
	}
	return 0;
}
/*Problem description

A bee larva living in a hexagonal cell of a large honeycomb decides to creep for a walk. In each “step” the larva may move into any of the six adjacent cells and after n steps, it is to end up in its original cell.

Your program has to compute, for a given n, the number of different such larva walks.


Input
The first line contains an integer giving the number of test cases to follow. Each case consists of one line containing an integer n, where 1 ≤ n ≤ 14.

Output
For each test case, output one line containing the number of walks. Under the assumption 1 ≤ n ≤ 14, the answer will be less than 231.

Sample Input
2
2
4
Sample Output
6
90
*/