#include <iostream>
using namespace::std;

int main()
{
	int a[25]={1,1,2};
	int i,n,m;
	cin >> n;
	while(cin >> m&&n)
	{
		if(m<3)
			cout << a[m] << endl;
		else 
		{
			for(i=3;i<=m;i++)
				a[i]=a[i-1]+a[i-2]+a[i-3];
			cout << a[i-1] << endl;
		}
		n--;
	}
	return 0;
}
/*算法：f[i]=f[i-1]+f[i-2]+f[i-3];*/
/*#include<iostream>
using namespace std;

int f[25]={1,1,2};

void GetList()
{
    for(int i=3;i<25;i++)
        f[i]=f[i-1]+f[i-2]+f[i-3];
}

int main()
{
    GetList();
    int N;
    int n;
    cin>>N;
    for(int i=1;i<=N;i++)
    {
        cin>>n;
        cout<<f[n]<<endl;
    }
    return 0;
}*/
/*
 Problem description
 Integer 4 can be expressed as a sum of 1s, 2s, and 3s in seven different ways as follows:
 1+1+1+1, (1)
 1+1+2, (2)
 1+2+1, (3)
 2+1+1, (4)
 2+2, (5)
 1+3, (6)
 3+1. (7)
 Write a program that determines the number of ways in which a given integer can be expressed as a sum of 1s, 2s, and 3s. You may assume that the integer is positive and less than 20.
 
 Input
 The input consists of T test cases. The number of test cases (T ) is given in the first line of the input file. Each test case consists of an integer written in a single line.
 
 Output
 Print exactly one line for each test case. The line should contain an integer representing the number of ways.
 
 Sample Input
 3
 4
 7
 10
 Sample Output
 7
 44
 274
*/