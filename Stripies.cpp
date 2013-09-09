#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	int n,i,c;
	double a[110];
	while(cin>>n&&n)
	{
		for(i=0;i<n;i++) 
			cin>>a[i];
		sort(a,a+n);
		c=n-1;
		while(1)
		{
			if(c==0)
			{
				printf("%.3lf\n",a[0]);
				break;
			}
			a[c-1]=2*sqrt(a[c]*a[c-1]);
			c--;
		}
	}
	return 0;
}
/*
为什么每次都要找两个最大的用公式算得出的最后的结果会是最小的： 
把结果的表达式写出来就知道了 （目的是把大的数多开几次方）
结果是2^(s-1)*a1^t1*a2^t2*...as^ts   且t1+t2+...ts=1（这个是关键）
所以要让t1尽量小（设ai>aj 当 i>j时）   所以每次都要让a1 参与运算    然后尽量让a2参与运算 然后是a3, a4...
*/
/*
 Problem description
 Our chemical biologists have invented a new very useful form of life called stripies (in fact, they were first called in Russian - polosatiki, but the scientists had to invent an English name to apply for an international patent). The stripies are transparent amorphous amebiform creatures that live in flat colonies in a jelly-like nutrient medium. Most of the time the stripies are moving. When two of them collide a new stripie appears instead of them. Long observations made by our scientists enabled them to establish that the weight of the new stripie isn't equal to the sum of weights of two disappeared stripies that collided; nevertheless, they soon learned that when two stripies of weights m1 and m2 collide the weight of resulting stripie equals to 2*sqrt(m1*m2). Our chemical biologists are very anxious to know to what limits can decrease the total weight of a given colony of stripies.
 
 You are to write a program that will help them to answer this question. You may assume that 3 or more stipies never collide together.
 
 
 Input
 The first line of the input file contains one integer N (1 <= N <= 100) - the number of stripies in a colony. Each of next N lines contains one integer ranging from 1 to 10000 - the weight of the corresponding stripie.
 
 Process to the end of file.
 
 
 Output
 The output file must contain one line with the minimal possible total weight of colony with the accuracy of three decimal digits after the point.
 
 
 Sample Input
 2
 72
 50
 3
 72
 30
 50
 Sample Output
 120.000
 120.000
*/