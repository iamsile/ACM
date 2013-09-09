#include <stdio.h>
int fun(int *p,int t)
{
	int i,j;
	if(t==2)
		return 0;
	for(i=j=0;i<t;i+=2,j++)
	{
		*(p+j)=*(p+i);
		if(i+1<t)
			printf("%d ",*(p+i+1));
	}
	fun(p,j);
}
int main()
{
	int n,s[51],i;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
			s[i]=i+1;
		fun(s,n);
		printf("\n%d %d\n",s[0],s[1]);
	}
	return 0;
} 
/*
 Problem description
 n 个人围成一圈, 并依次编号1～n，。从编号为1 的人开始，按顺时针方向每隔一人选出一个， 剩下的人重新围成一圈，如此循环直到剩下两人，这剩下的两人就是幸运儿。如果你想成为最后两个 幸运儿，请问开始时应该站在什么位置？（设3<=n<=50） 
 
 
 
 
 
 Input
 有多个测试序列。每行是开始时的人数n 
 
 Output
 第1 行是选出顺序，第2 行是两名幸运儿的开始位置（按升序排列），位置编号之间用一个空格 分开。 
 
 Sample Input
 12
 Sample Output
 2 4 6 8 10 12 3 7 11 5 
 1 9
*/