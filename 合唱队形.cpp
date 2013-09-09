#include <iostream>
using namespace::std;
int a[110],up[110],down[110];

int Up(int i)
{
	int j,max=0;
	for(j=i-1;j>=0;j--)
		if(a[i]>a[j]&&up[j]>max)
			max =up[j];
	return max;
}

int Down(int i)
{
	int j,max=0;
	for(j=i-1;j>=0;j--)
	{
		if(a[i]<a[j])
		{
			if(up[j]>max)
				max=up[j];
			if(down[j]>max)
				max=down[j];
		}
	}
	return max;
}

int main()
{
	int max,i,n;
	cin >> n;
	cin >> a[0];
	max=up[0]=down[0]=1;
	for(i=1;i<n;i++)
	{
		cin >> a[i];
		up[i]=Up(i)+1;
		if(up[i]>max)
			max=up[i];
		down[i]=Down(i)+1;
		if(down[i] > max)
			max=down[i];
	}
	printf("%d\n",n-max);
	return 0;
}
/*
 解题方法：Dp 设三个数组，其中一个用于保存身高，另外两个保存子状态。 up[n]表示身高一直按升序排列时，
 从第一个人到 第 n 个人合法排列的最大人数。down[n]表示混合的即可以从中间某个位置降序。
 */
/*
 Problem description
 N位同学站成一排，音乐老师要请其中的(N-K)位同学出列，使得剩下的K位同学排成合唱队形。 
 合唱队形是指这样的一种队形：设K位同学从左到右依次编号为1, 2, …, K，他们的身高分别为T1, T2, …, TK，则他们的身高满足T1 < T2 < … < Ti , Ti > Ti+1 > … > TK (1 <= i <= K)。 
 你的任务是，已知所有N位同学的身高，计算最少需要几位同学出列，可以使得剩下的同学排成合唱队形。 
 
 
 Input
 输入的第一行是一个整数N（2 <= N <= 100），表示同学的总数。第一行有n个整数，用空格分隔，第i个整数Ti（130 <= Ti <= 230）是第i位同学的身高（厘米）。
 
 Output
 输出包括一行，这一行只包含一个整数，就是最少需要几位同学出列。
 
 Sample Input
 8
 186 186 150 200 160 130 197 220
 Sample Output
 4
 */
