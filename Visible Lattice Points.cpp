#include<iostream>
using namespace::std;
int result[1010];

int gcd(int a, int b){
    int k;
    while(a%b){
        k=a%b;a=b;b=k;
    }
    return b;
}

void Init(){
	result[0]=0;result[1]=3;int sum=0;
	for(int i=2; i<=1000; i++)
	{
		for(int j=1; j<i; j++)
            if(gcd(i,j)==1)sum++;
		result[i]=sum*2+3;
	}
}

int main(){
	int t,lab=1,n;
	Init();
	cin >> t;
	while(t--)
	{
		cin >> n;
		cout << lab++ << ' ' << n << ' ' << result[n] << '\n';
	}
	return 0;
}
/*#include <iostream>
#include <math.h>
using namespace::std;

unsigned cal(unsigned x)
{
    unsigned i,res=x,tmp;
    tmp=(int)sqrt(x*1.0)+1;
    for (i=2;i<tmp;i++)
        if(x%i==0)
        {
            res=res/i*(i-1);
            while(x%i==0)
                x/=i;
        }
    if (x>1) 
        res=res/x*(x-1);
	return res;
}

int main()
{
	int i,n,t,sum,lab=1;
	cin >> t;
	while(t--)
	{
		sum=0;
		cin >> n;
		for(i=2;i<=n;i++)
			sum+=cal(i);
		printf("%d %d %d\n",lab++,n,sum*2+3);
	}
	return 0;
}*/
/*
 先画一条(0, 0)到(n, n)的线，把图分成两部分，两部分是对称的，只需算一部分就好。
 取右下半，这一半里的点(x, y)满足x >= y
 可以通过欧拉函数计算第k列有多少点能够连到(0, 0)
 若x与k的最大公约数d > 1，则(0, 0)与(x, k)点的连线必定会通过(x/d, k/d)，就被挡住了
 所以能连的线的数目就是比k小的、和k互质的数的个数，然后就是欧拉函数。
 */
/*
 Problem description
 A lattice point (x, y) in the first quadrant (x and y are integers greater than or equal to 0), other than the origin, is visible from the origin if the line from (0, 0) to (x, y) does not pass through any other lattice point. For example, the point (4, 2) is not visible since the line from the origin passes through (2, 1). The figure below shows the points (x, y) with 0 ≤ x, y ≤ 5 with lines from the origin to the visible points.
 
 
 
 Write a program which, given a value for the size, N, computes the number of visible points (x,y) with 0 ≤ x, y ≤ N.
 
 Input
 The first line of input contains a single integer C, (1 ≤ C ≤ 1000) which is the number of datasets that follow.
 
 Each dataset consists of a single line of input containing a single integer N, (1 ≤ N ≤ 1000), which is the size.
 
 Output
 For each dataset, there is to be one line of output consisting of: the dataset number starting at 1, a single space, the size, a single space and the number of visible points for that size.
 
 Sample Input
 4
 2
 4
 5
 231
 Sample Output
 1 2 5
 2 4 13
 3 5 21
 4 231 32549
 Problem Source
*/