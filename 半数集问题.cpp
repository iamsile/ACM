#include <iostream>
using namespace::std;

int f(int n)
{
	if(n==0)
		return 0;
	if(n==1)
		return 1;
	int i,k,sum=0,sum1;
	for(i=1;i<=n/2;i++)
	{  
		if(i<=9)
		{
			sum1=0;
			for(k=1;k<=i/2;k++)
				if(k*10+i>n/2)
					sum1+=f(k);
			sum1+=1;
			sum+=sum1;
			continue;
		}
		sum+=f(i);
	}
	sum+=1;
	return sum;
}

int main()
{
	int n;
	while(cin >> n&&n)
	{
		cout << f(n) << '\n';
	}
	return 0;
}
/* 这题难在不是多重集
 设f(n)=f(1)+f(2)+f(3)+......+f(n/2)+1;
 这里f(i)(1<=i<=9)可能会跟后面重复所以对f(i)先直接计算
 f(i)=f(1)+f(2)+..+f(k)..+f(i/2)+1;如果有k*10+i<=n/2;
 说明该元素是重复的,直接f(k)=0不用计算,如果k*10+i>n/2;
 说明该元素不是重复的,再递归调用f(k);
 而对于f(i)(i>=10)肯定不会重复,直接递归.
*/
/*
 Problem description
 给定一个自然数n，由n开始可以依次产生半数集set(n)中的数如下。
 （1）	n∈set(n)；
 （2）	在n的左边加上一个自然数，但该自然数不能超过最近添加的数的一半；
 （3）	按此规则进行处理，直到不能再添加自然数为止。
 例如，set(6)={6,16,26,126,36,136}。半数集set(6)中有6个元素。
 注意半数集不是多重集。集合中已经有的元素不再添加到集合中。
 
 
 Input
 输入只有1行，给出整数n。(0 < n < 201) 
 
 Output
 输出文件只有1行，给出半数集set(n)中的元素个数。
 
 Sample Input
 6
 Sample Output
 6
*/