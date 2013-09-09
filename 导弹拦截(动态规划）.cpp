#include <iostream>
using namespace::std;

int main()
{
	int n,i=0,j,k,lab=0,lab1=0,max,min,a[1001]={0},b[1001]={0},c[1001]={0};
	while(scanf("%d",&n)!=EOF)
	{
		a[i]=n;
		i++;
	}
	for(j=i-1;j>=0;j--)
	{
		max=0;
		for(k=j+1;k<i;k++){
			if(a[j]>=a[k]&&b[k]>max)
				max=b[k];
		}
		b[j]=max+1;
		if(b[j]>lab)
			lab=b[j];
	}
	for(j=i-1;j>=0;j--)
	{
		min=0;
		for(k=j+1;k<i;k++){
			if(a[j]<=a[k]&&c[k]>min)
				min=c[k];
		}
		c[j]=min+1;
		if(c[j]>lab1)
			lab1=c[j];
	}
	printf("%d %d\n",lab,lab1);
	return 0;
}
/*
 Problem description
 某国为了防御敌国的导弹袭击，发展出一种导弹拦截系统。但是这种导弹拦截系统有一个缺陷：虽然它的第一发炮弹能够到达任意的高度，但是以后每一发炮弹都不能高于前一发的高度。某天，雷达捕捉到敌国的导弹来袭。由于该系统还在试用阶段，所以只有一套系统，因此有可能不能拦截所有的导弹。
 
 Input
 输入数据为导弹依次飞来的高度，所有高度值均为不大于30000的正整数。
 
 Output
 输出只有一行是这套系统最多能拦截的导弹数和要拦截所有导弹最少要配备这种导弹拦截系统的套数。两个数据之间用一个空格隔开.
 
 Sample Input
 389 207 155 300 299 170 158 65
 Sample Output
 6 2
*/