#include <iostream>
using namespace std;

int main() {
	int t,l=1;
	cin >> t;
	while (t--) {
		int i,j=1,n,sum=0,m,x,y,max=-3000;
		cin >> n;
		cout << "Case " << l++ << ":\n";
		for (i=1; i<=n; i++) {
			cin >> m;
			sum+=m;
			if(max<sum) {
				max=sum;
				y=i;
				x=j;
			}
			if(sum<0) {
				sum=0;
				j=i+1;
			}
		}
		cout << max << ' ' << x << ' ' << y << '\n';
		if(t)
			cout << '\n';
	}
	return 0;
}
/*
Problem Description
Given a sequence a[1],a[2],a[3]......a[n], your job is to calculate the max sum of a sub-sequence. For example, given (6,-1,5,4,-7), the max sum in this sequence is 6 + (-1) + 5 + 4 = 14.
 

Input
The first line of the input contains an integer T(1<=T<=20) which means the number of test cases. Then T lines follow, each line starts with a number N(1<=N<=100000), then N integers followed(all the integers are between -1000 and 1000).
 

Output
For each test case, you should output two lines. The first line is "Case #:", # means the number of the test case. The second line contains three integers, the Max Sum in the sequence, the start position of the sub-sequence, the end position of the sub-sequence. If there are more than one result, output the first one. Output a blank line between two cases.
 

Sample Input
2
5 6 -1 5 4 -7
7 0 6 -1 1 -6 7 -5
 

Sample Output
Case 1:
14 1 4

Case 2:
7 1 6
*/