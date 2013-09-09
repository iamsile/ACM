#include <iostream>
#include <math.h>
using namespace::std;

int main()
{
	int m;
	cin >> m;
	while(m--)
	{
		int n,a[30000],sum=0;
		cin >> n;
		for(int i=0;i<n;i++)
			cin >> a[i];
		sort(a+0, a+n);
		for(int i=0;i<n;i++)
			sum+=abs(a[n/2]-a[i]);
		cout << sum << '\n';
	}
	return 0;
}
/*
 Problem description
 阿毛在国外留学2年，今年假期他终于买了机票回国探亲了。想想2年没见的父母兄弟，还有八大姨，七大婶，阿毛那是相当兴奋。但是假期时间有限，所以他想走尽量少的路，而且把所有的亲戚家都跑一趟。
 
 Input
 输入几组测试例子，第一行是测试例子的数量。
 每一个测试例子你要给出亲戚的数量r( 0 < r < 500)和每个亲戚所住的街道编号S1，S2……Si……Sr（0 < Si < 30000），r和S都是整数，多个亲戚可能住在同一街区。 
 
 Output
 对每一个测试例子，你要给出从阿毛住地到每一个亲戚家的距离之和的最小值（阿毛可以住在任意一个亲戚家），街道si 和 sj 之间的距离是dij= |si-sj|.
 
 Sample Input
 2
 2 2 4 
 3 2 4 6
 Sample Output
 2
 4
*/