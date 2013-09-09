#include<iostream>
using namespace std;
#define big long long

int main()
{
	int t,lab=1; 
	cin >> t;
	while(t--)
	{		
		int n,i,j,x[2][10000];
		cin >> n;
		for(i=0;i<n;i++)
			for(j=0;j<2;j++)
				scanf("%d", &x[j][i]);
		big res=0;
		for(i=0;i<2;i++)
		{
			sort(x[i], x[i]+n);
			big sum=0;
			for(j=1;j<n;j++)
			{
				big d=x[i][j];	
				d-=x[i][0];
				res+=j*d-sum;
				sum+=d;
			}
		}
		cout << "Case #" << lab++ << ": " << res << endl;
	}	
	return 0;
}
/*
 Problem description
 One day, my manager was telling me about consistency. He said that throwing all your darts close to one another consistently even if they are far from the dartboard center is better than not having such control, even if you hit the center every now and then.
 
 In this problem you are given the locations of N darts thrown by a player and you have to assess the skill of the player according to my manager's criteria above, in other words you have to calculate the sum S of Manhattan distances among all pairs of darts. The Manhattan distance between two points (x1, y1) and (x2, y2) is defined as |x1-x2|+|y1-y2|. Locations are given as 2-D integer Cartesian coordinates.
 
 Input
 The first line contains T ≤ 50 the number of test cases, T test cases follow. Each test case starts with an integer 1 ≤ N ≤ 104 the number of darts thrown by the player. Each of the next N lines each contains two integers representing the coordinates of the darts.
 
 Output
 For each test case print one line in the format: "Case #t: S" without double quotes, where t is the test case number starting from 1 and S is the sum described above.
 
 Sample Input
 2
 2
 0 0
 1 1
 3
 2 2
 2 2
 2 4
 Sample Output
 Case #1: 2
 Case #2: 4
*/