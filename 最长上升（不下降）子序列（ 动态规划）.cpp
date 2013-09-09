#include <iostream>
using namespace::std;

int main()
{
	
	int n,max,i,j,m,lab;
	int a[1001]={0},b[1001]={0};
	scanf("%d",&m);
	while(m)
	{
		lab=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(i=n-1;i>=0;i--)
		{
			max=0;
			for(j=i+1;j<n;j++)
				if(a[i]<=a[j]&&b[j]>max)
					max=b[j];
			b[i]=max+1;
			if(b[i]>lab)
				lab=b[i];
		}
		printf("%d\n",lab);
		m--;
	}
	return 0;
}

/*
 对于num[n]来说，由于它是最后一个数，所以当从num[n]开始查找时，只存在长度为1的不下降
 子序列；
 若从num[n-1]开始查找，则存在下面的两种可能性:
 1.若num[n-1]<num[n],则存在长度为2的不下降子序列num[n-1],num[n];
 2.若num[n-1]>num[n]，则存在长度为1的不下降子序列num[n-1]或者num[n];
 一般若从num[j]开始，此时最长不下降子序列应该是按下列方法求出：
 在a[j+1],a[j+2],....a[n]中，找出一个比a[t]大的且最长不下降子序列，作为它的后继 
 */