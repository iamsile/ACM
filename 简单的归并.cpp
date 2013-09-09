#include <iostream>
using namespace::std;

int main()
{
	int m;
	cin >> m;
	while(m--)
	{
		int n1,n2,i,a[5001];
		cin >> n1;
		for(i=0;i<n1;i++)
			cin >> a[i];
		cin >> n2;
		for(i=n1;i<n2+n1;i++)
			cin >> a[i];
		sort(a, a+n1+n2);
		for(i=0;i<n1+n2;i++)
		{
			if(i>0)
				cout << ' ';
			cout << a[i];
		}
		cout << '\n';
	}
	return 0;
}
/*
 Problem description
 已知线性表LA和LB中的数据元素按值非递减，现要求把LA和LB归并为一个新的线性表LC，且LC中的数据元素扔按值非递减。例:
 
 LA=(3,5,8,11)
 LB=(2,6,8,9,11,15,20)
 则
 LC=(2,3,5,6,8,8,9,11,11,15,20);
 
 Input
 第一行是测试数据的组数n。
 每组测试数据占两行，其中第2i+1行(i = 0,1,2,...)首先是LA中的元素个数na,之后是na个元素。第2i+2行首先是LB中的元素个数nb，之后是nb个元素。
 
 Output
 n行，每行输出LA、LB合并后的LC。LC的数据之间以空格区分，LC最后一个数据之后没有空格。
 
 建议用两种方式实现，
 1)线性表的顺序存储
 2)线性表的链式存储
 
 Sample Input
 2
 2 1 2
 1 3
 4 3 5 8 11
 7 2 6 8 9 11 15 20
 Sample Output
 1 2 3
 2 3 5 6 8 8 9 11 11 15 20
*/