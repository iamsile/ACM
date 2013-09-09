#include <iostream>
using namespace::std;

int main()
{
	int n,max,i,j,lab=0,a[100]={0},b[100]={0};
	cin >> n;
	for(i=0;i<n;i++)
		cin >> a[i];
	for(i=n-1;i>=0;i--)
	{
		max=0;
		for(j=i+1;j<n;j++)
			if(a[i]<a[j]&&b[j]>max)
				max=b[j];
		b[i]=max+1;
		if(b[i]>lab)
			lab=b[i];
	}
	cout << lab;
	return 0;
}

/*
 定义f(m, n)为Xm和Yn之间最长的子字符串的长度并且该子字符串结束于Xm & Yn。
 因为要求是连续的，所以定义f的时候多了一个要求字符串结束于Xm & Yn
 于是有f(m, 0) = f(0, m) = 0
 如果xm != yn, 则f(m, n) = 0
 如果xm = yn, 则f(m, n) = f(m-1, n-1) + 1
 因为最长字符串不一定结束于Xm / Yn末尾，所以这里必须求得所有可能的f(p, q) | 0 < p < m, 0 < q < n, 
 最大的f(p, q)就是解。依照公式用Bottom-up Dynamic Programming可解 
 */