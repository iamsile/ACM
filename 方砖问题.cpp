#include <iostream>
using namespace::std;

int main() 
{
	int x,y,m,res,k,n,a[101][101];;
	cin >> m;
	while(m--)
	{
		cin >> n;
		for(x=1;x<=n;x++)
			for(y=1;y<=n;y++) 
			{
				if((x==y)&&(x<n))
					a[x][y]=1;
				else 
				{
					res=100;
					for(k=(x/2);k<x;k++)
						if(res>(a[k][y]+a[x-k][y]))
							res=a[k][y]+a[x-k][y];
					a[x][y]=res;
				}
				a[y][x]=a[x][y];
			} 
		cout << a[n][n] << '\n';
		memset(a, 0, sizeof(a));
	}
	return 0;
}
/*
 Problem description
 用边长小于N的正方形方砖（注意，不要求所有的方砖大小相同，请看样例说明）不重叠地铺满N*N的正方形房间，最少要几块方砖。
 
 Input
 第一行是一个整数T,表示测试数据的组数,接下来的T 行，每一行是一个N(2<=N<=100) 
 
 Output
 对于每一组测试数据输出一行，为最少需要的块数。
 
 Sample Input
 2
 4
 5
 Sample Output
 4
 8
 */

