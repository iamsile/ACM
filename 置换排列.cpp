#include <iostream>
using namespace::std;

int main()
{
	int n,m,i,a[100]={0};
	cin >> n;
	while (n--) {
		cin >> m;
		for(i=1;i<=m;i++)
			cin >> a[i];
		for(i=1;i<=m;i++)
			if(a[a[i]]!=i)
			{
				cout << "no" << '\n';
				break;
			}
		if((i-1)==m)
			cout << "yes" << '\n';
	}
	return 0;
}
/*
 Problem description
 给定一个自然数n 和 1到n的一个排列，比如 4 及 排列 1 4 3 2，我们说1放在第1个位置，第1个位置放了1，4放在第2个位置，第4个位置放2，3放在第3个位置，第3个位置放了3；我们可以输出yes;但是对5 以及 排列 2 3 4 5 1 却不成立，我们输出no。 
 
 Input
 第一行t,表示测试数据的个数 接下来的t行每行是n 和 1到n的一个排列共n+1个自然数,n<=100。 
 
 Output
 对每个测试数据输出yes 或者 no。 
 
 Sample Input
 3
 4 1 4 3 2
 5 2 3 4 5 1
 1 1
 Sample Output
 yes
 no
 yes
*/