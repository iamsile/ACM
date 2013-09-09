#include <iostream>
#include <math.h>
using namespace::std;

int main()
{
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF)
	{
		int sum=1,l=b;
		if(a==1)
			printf("1.0000\n");
		else 
		{
			while(b>1)
				sum*=b--;
			printf("%.4f\n",sum/pow(a, l));
		}
	}
	return 0;
}
/*
 Problem description
 
 
 福彩公司准备举办一次抽奖活动，这次抽奖规则如下：福彩公司将发行一批刮奖卡，每张刮奖卡刮开上面的涂层后，会出现几种图案中的一种，各种图案出现的几率相同，只要筹齐这n中图案就算中奖，某人买了m张卡片，问他能中奖的概率P是多少？
 
 Input
 
 输入一行包含两个整数n,m(1<=n,m<=20),分别表示图案的种类数和某人买的卡片张数。
 
 Output
 
 输出一行，一个实数P为中奖的概率，答案保留4为小数。
 
 Sample Input
 2 3
 1 2
 Sample Output
 0.7500
 1.0000
*/