#include <iostream>
using namespace::std;

void cal1(long n)
{
	if(n==0)
		return ;
	else if(n%3==2)
	{
		cal1(n/3+1);
		cout << '-';
	}
	else 
	{
		cal1(n/3);
		cout << n%3;
	}
}

void cal2(long n)
{
	if(n==0)
		return ;
	else if(n%3==-2)
	{
		cal2(n/3-1);
		cout << '1';
	}
	else 
	{
		cal2(n/3);
		if(n%3==-1)
			cout << '-';
		else 
			cout << '0';
	}
}

int main()
{
	long n;
	while(cin >> n)
	{
		if(n>=0)
			cal1(n);
		else 
			cal2(n);
		cout << '\n';
	}
	return 0;
}
/*
 Problem 10471 : No special judgement
 Problem description
 也许是因为有10 个手指的原因，所以我们把0～9 十个数字组合起来表达任意的数值，但这 并不是唯一可能的记数法。在某个外星球居住着一种智慧生物，他们的手跟我们的手构造不同，他们 的记数法也很奇特。他们用三个记号’0’,’1’,’-’的组合来表达数值，这三个记号分别对应数值0,1,-1 。在 他们的数值系统中，每个数位是右边相邻数位的3 倍。因此数’10-’表示数值8（因为8＝1×9＋0×3 ＋－1×1），数’-1’表示数值-2（因为-2= -1×3＋1×1）。
 编写程序，读入一组-2^31 至2^31 －1 之间的数值，输出对应的外星球数值表示。
 
 Input
 每行一个10 进制数值
 
 Output
 每行一个与输入文件对应的外星球数值表示
 
 Sample Input
 10 
 2 
 -17 
 42 
 1024 
 -2147483648
 Sample Output
 101 
 1-
 -101 
 1---0 
 111-0-1 
 -10110100011---1-1--1 
*/