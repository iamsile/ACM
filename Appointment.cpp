#include<iostream>
using namespace std;

int main()
{
	int n,x,y;
	double result,mid,z;
	cin >> n;
	while(n--)
	{
		cin >> x >> y >> z;
		if(x>y)
			swap(x,y);
		mid=60*(y-x);
		if((mid-z)<=1e-7)
			printf("1.0000000\n"); 
		else
		{
			result=(1-z/mid)*(z/mid)+z/mid;
			printf("%.7lf\n",result);
		}
	}
	return 0;
}
/*
 Problem description
 小A和小B是两位参赛队员，他们约好星期天一起去机房参加训练，如果他们碰的上的话。他们约好见面的时间是x点，y点之间，并且约定先到的人最多等待的z分钟（他们两个人都非常懒惰，从来不会准时到）。 
 
 Input
 输入数据会包括两个部分
 第一部分数字是c，表示以下测试数据的个数（0<=c<=10,000）
 第二部分是c组测试数据，每组数据前都有一个空行分隔。
 每一组数据包括1行，该行有三个数字，依次是两个整数x，y和一个实数z，其中 0<=x，y<24，z>0 
 
 Output
 每一组测试数据输出一行，只包含一个数字p，表示两个人碰面的概率，同时四舍五入保留7位小数。 
 
 Sample Input
 2
 
 11 12 20.0
 
 12 12 3.08
 Sample Output
 0.5555556
 1.0000000
*/