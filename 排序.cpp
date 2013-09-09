#include <iostream>
using namespace::std;

int main()
{
	int n,a[1001]={0};
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> a[i];
	sort(a+0,a+n);
	for(int i=0;i<n;i++)
	{
		if(i>0)
			cout << " ";
		cout << a[i];
	}
	cout << '\n';
	return 0;
}
/*
 Problem description
 
 
 对输入的数字从小到大进行排序。
 
 Input
 
 第一行为输入的数字个数，第二行为需要进行排序的数字，每一个数字用空格隔开。 
 
 Output
 
 排好序的数字，每个数字用空格隔开。
 
 Sample Input
 10
 9 12 4 8 32 7 2 94 78 10
 Sample Output
 2 4 7 8 9 10 12 32 78 94
*/