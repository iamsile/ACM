#include <stdio.h>

int main()
{
	__int64 n;
	while(scanf("%I64d",&n)!=EOF)
	{
		if(n==0)
			printf("1\n");
		else 
			printf("%I64d\n",n*(n-1)+2);
	}
	return 0;
}
/*
 答案是n^2-n+2，(其中n^2表示n的平方)，把n=1,2,3,4分别带入公式算，
 发现答案分别是2,4,8,14与枚举的结果吻合。证明如下：
 著名数学家欧拉(Euler,1707-1783)给出一个公式v-e+f=2，
 其中v是顶点数，e是棱数，f是面数。在本题中，n个圆，两两相交，
 则v=2*Cn2=n(n-1)，其中Cn2是从n个元素中选两个元素的组合，
 e=n*(2(n-1))=2n(n-1)，这个式子的含义是n个圆，每个圆都被其余n-1个
 圆分出2(n-1)条线段，由欧拉公式，f=e-v+2=2n(n-1)-n(n-1)+2=n^2-n+2，
 故答案是n^2-n+2
 */
/*
 Problem description
 The are n closed curves ,every two closed curve intersect in two points, and not exist three of the closed curves intersect in one point. Please calculate how many parts these closed curves cut the plane.
 
 The total parts is 8.
 Input
 
 
 The input contains multiple test case.
 Every test case only contain one integer n (0 ≤ n < 10 9 ) ,represent the number of closed curves.
 The end of input with EOF.
 
 
 Input
 The input contains multiple test case.
 Every test case only contain one integer n (0 ≤ n < 10 9 ) ,represent the number of closed curves.
 The end of input with EOF.
 
 
 Output
 The output only contains one number K, the parts these closed curves cut the plane.
 
 
 Sample Input
 1
 6
 1000
 10063
 Sample Output
 2
 32
 999002
 101253908
*/