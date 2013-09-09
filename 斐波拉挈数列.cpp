#include <iostream>
using namespace::std;
int a[100]={0,1};

int find(int c)
{
	int j;
	if(c==0)
	{
		cout << a[0] << endl;
		return 0;
	}
	if(c==1)
	{
		cout << a[1] << endl;
		return 0;
	}
	for(j=2;j<=c;j++)
		a[j]=a[j-1]+a[j-2];
	cout << a[j-1] << endl;
	return 0;
}

int main()
{
	int line,b[100]={0};
	cin >> line;
	for(int i=0;i<line;i++)
		cin >> b[i];
	for(int i=0;i<line;i++)
		find(b[i]);
	return 0;
}
/*Problem description
 The Fibonacci Numbers {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, ...} are defined by the recurrence:
 F0 = 0
 F1 = 1
 Fi = Fi-1 + Fi-2 for all i >= 2
 Write a program to calculate the Fibonacci Numbers.
*/