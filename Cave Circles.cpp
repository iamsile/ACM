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
 huicpc217 likes Geometric.One day, he use a paper to draw circles.He draws n circles on the paper.every two circles have two intersections, every three circles have no intersection. huicpc217 thinks a problem: how many fields is the paper cut into by the n circles?
 
 
 Input
 Tthere are several test cases.
 each case is an interger n( 0 ≤ n < 2 31 ). 
 
 Output
 each case you should output the fields is cut into by the n circles. 
 
 Sample Input
 1
 2
 Sample Output
 2
 4
*/