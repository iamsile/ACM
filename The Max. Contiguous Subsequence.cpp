#include <iostream>
using namespace::std;

int main()
{
	int n;
	while(cin >> n&&n)
	{
		int i,a[11],b[11]={0},first=0,last=0,max=0,flag=0,lab=0,l2=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]<0)
				flag++;
		}
		if(flag==n)
		{
			printf("0 %d %d\n",a[0],a[n-1]);
			continue;
		}
		for(i=1;i<=n;i++)
		{
			b[i]=a[i-1]+b[i-1];
			if(b[i-1]==0&&lab>=l2)
				first=a[i-1];
			if(b[i]>max)
			{
				last=a[i-1];
				max=b[i];
			}
			else 
				lab++;
			if(b[i]<0)
			{
				b[i]=0;
				l2=lab;
				lab=1;
			}
		}
		printf("%d %d %d\n",max,first,last);
	}
	return 0;
}
/*
 //网上的代码没自己的短，但值得学习下
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int i,j,sum[10005],a[10005],head[10005];
	int k,g,bi,b;
	int su;
	while(scanf("%d",&k)!=EOF)
	{
		if(!k)break;
		g=0;                      
		for(i=1;i<=k;i++)
		{
			cin>>a[i];
			if(a[i]<0)
				++g;     
		}///记录下负数的个数 ，如果全部是负数 如下做
		if(g==k) cout<<"0"<<" "<<a[1]<<" "<<a[k]<<endl;
		else
		{
			sum[1]=a[1];//sum[i]存的是以第i项结束的最大子段和
			head[1]=1;//h［i］存的是以第i项为最后一项的最大子段的第一项的座标
			for(i=2;i<=k;i++)
			{
				head[i]=i; //先把每个数当成是自己开始自己结束的序列
				sum[i]=a[i];//它的最大序列和为自己，
				if(sum[i]<sum[i-1]+a[i])//如果它自己的值小于以它前一项为尾的序列 的和//时 ，那么这一项就可以连到以它的前一项为结尾的序列中去了，
				{
					sum[i]=sum[i-1]+a[i];
					head[i]=head[i-1]; //些时它的第一项就是它此时所在序列的第一项                                               
				}                                    
			}
			su=-9999;
			for(i=1;i<=k;i++)
			{////找出最大的序列和
				if(sum[i]>su)
				{
					su=sum[i];
					bi=i;
				}              
			}                     
			cout<<su<<" "<<a[head[bi]]<<" "<<a[bi]<<endl;                                   
		}              
	}           
	return 0;               
}*/
/*
 Problem description
 You are given an array which could be positive and negative. Please write down a function to return the max subsequence sum.If you get this subset,you should also print the head and tail element.
 
 Input
 Standard input will contain multiple test cases. The first line of each test case contains one integers N(1 <= N <= 10) which is the number of integer.N integer follow.The input ends with a zero.
 
 Output
 For each testcase，output three integers in one line:Maximum Subsequence Sum,the head and tail element, separated with a single space.If Maximum Subsequence Sum is not unique，output the minimum position of head and tail（Sample 2,3）。If all the integer are negative,the maximum subsequence sum is zero ,output first and last element of the original set（Sample 5）.
 
 Sample Input
 6
 -2 11 -4 13 -5 -2
 10
 -10 1 2 3 4 -5 -23 3 7 -21
 6
 5 -8 3 2 5 0
 1
 10
 3
 -1 -5 -2
 3
 -1 1 -2
 0
 Sample Output
 20 11 13
 10 1 4
 10 3 5
 10 10 10
 0 -1 -2
 1 1 1
*/