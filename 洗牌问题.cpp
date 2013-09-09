#include<iostream>
using namespace std;

int main()
{
    int n;
    while(cin>>n&&n)
	{
		int i=1,k=2;
		n*=2;
		while(k!=1)
		{
			k=(k*2)%(n+1);
			i++;
			if(k==n)
			{
				i*=2;
				break;
			}
		}
		cout<<i<<'\n';
    }
    return 0;
}
/*
 题目n<=10000，限制时间为1s，所以肯定不可能模拟，一定会TLE。
 因此尝试列出一些n及所需要的最少洗牌次数来观察。
 当n=3时共有6张牌，此时需要3回合。
 1    2    3    4    5    6  回合数
 a    b    c    d    e    f    0
 d    a    e    b    f    c    1
 b    d    f    a    c    e    2
 a    b    c    d    e    f    3
 当n=5时，共有10张牌，需要10回合。
 0    1    2    3    4    5    6    7    8    9    0
 a    b    c    d    e    f    g    h    i    j    0
 f    a    g    b    h    c    i    d    j    e    1
 c    f    i    a    d    g    j    b    e    h    2
 g    c    j    f    b    i    e    a    h    d    3
 i    g    e    c    a    j    h    f    d    b    4
 j    i    h    g    f    e    d    c    b    a    5
 e    j    d    i    c    h    g    b    a    f    6
 h    e    g    j    b    d    a    i    f    c    7
 d    h    a    e    i    g    f    j    c    b    8
 g    d    f    h    j    a    c    e    b    i    9
 a    b    c    d    e    f    g    h    i    j    10    
 再列举一个，n=10时牌数为20，按SAMPLE OUTPUT需要6回合，列列看：
 1    2    3    4    5    6    7    8    9    10    11    12    13    14    15    16    17    18    19    20
 a    b    c    d    e    f    g    h    i    j    k    l    m    n    o    p    q    r    s    t    0
 k    a    l    b    m    c    n    d    o    e    p    f    q    g    r    h    s    i    t    j    1
 p    k    f    a    q    l    g    b    r    m    h    c    s    n    i    d    t    o    j    e    2
 h    p    c    k    s    f    n    a    i    q    d    l    t    g    o    b    j    r    e    m    3
 d    h    l    p    t    c    g    k    o    s    b    f    j    n    r    a    e    i    m    q    4
 b    d    f    h    j    l    n    p    r    t    a    c    e    g    i    k    m    o    q    s    5
 a    b    c    d    e    f    g    h    i    j    k    l    m    n    o    p    q    r    s    t    6
 不难看出，元素移动的规律，即在第i回合，任意一个元素所在的位置都是上一回合所在的位置*2%(2*n+1)。
 其实我们只用考虑一个元素，因为所有的元素都按同一规则移动。
 这里默认考虑第一个元素（i=0时位置为1）。
 假定位置为a[i]，则有a[i]=a[i]*2%(2*n+1)，当a[i]==1时，说明已经回到初始位置，即已得出最少洗牌次数。
*/
/*
 Problem description
 给你2N张牌，编号为1,2,3..n,n+1,..2n。这也是最初的牌的顺序。
 
 一次洗牌是把序列变为n+1,1,n+2,2,n+3,3,n+4,4..2n,n。可以证明，对于任意自然数N，都可以在经过M次洗牌后第一次重新得到初始的顺序。编程对于小于10000的自然数N，求出M的值。 
 
 
 Input
 输入有N个测试数据，N从1到10000。
 
 Output
 每一行输出M的值。
 
 Sample Input
 20
 4
 Sample Output
 20
 6
*/