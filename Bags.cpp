#include<iostream>
using namespace std;

int n, m;
bool vis[101][1001];
double table[101][1001];
double get(int i, int j)
{
	if(i==n||j==m)	
		return 0;			
	if(vis[i][j])
		return table[i][j];
	double p=1.0*(n-i)/(m-j);	
	vis[i][j] = true;
	return table[i][j]=1+p*get(i+1, j+1)+(1-p)*get(i, j+1);
}

int main()
{
	int t; 
	cin >> t;
	while(t--)
	{
		cin >> n >> m;
		memset(vis, 0, sizeof(vis));
		printf("%.6lf\n", get(0, 0));
	}
	return 0;
}
/*
 Problem description
 You are working in the IT department of one of the largest airlines in the world. Due to the economic crisis, your company's revenue is falling seriously and your company is trying to fight back by providing the best service to customers. Recently the IT board has approved a new online service to be delivered to customers which helps them to figure out how long a passenger will have to wait for his entire luggage to come out on the luggage belt at the destination airport. Bags come out on the belt one by one and in a uniformly random fashion. Given the number of bags for a passenger and the total number of bags on the aircraft, you must calculate the expected number of bags the passenger will have to wait (including his own bags) until he is able to pick up his entire luggage off the belt.
 
 Input
 The first line on input contains T (0 ≤ T ≤ 100) the number of test cases, on the next T lines there are two integers N (0 ≤ N ≤ 100) and M (N ≤ M ≤ 1000) representing the number of bags for a single passenger and the total number of bags in the aircraft respectively.
 
 Output
 For each test case, print one line with the expected number of bags the passenger has to wait until he is able to pick up all his bags off the belt. Print the result rounded to 6 decimal places.
 
 Sample Input
 4
 1 1
 1 2
 2 3
 100 1000
 Sample Output
 1.000000
 1.500000
 2.666667
 991.089109
 */
