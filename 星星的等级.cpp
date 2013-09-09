#include<iostream>
using namespace std;
int ans[100001],Limit,n,x[100001],y[100001],z[100001],T[100001];
int sortx(int l,int r)
{
    int i,j,xx,yy;
    i=l;j=r;xx=z[(l+r)/2];
    while (i<j)
    {
		while (x[z[i]]<x[xx]) ++i;
		while (x[z[j]]>x[xx]) --j;
		if (i<=j)
		{
			yy=z[i];
			z[i]=z[j];
			z[j]=yy;
			++i;--j;
		}
    }
    if (i<r) sortx(i,r);
    if (j>l) sortx(l,j); 
    return(0);
}
int sorty(int l,int r)
{
    int i,j,xx,yy;
    i=l;j=r;xx=z[(l+r)/2];
    while (i<j)
    {
		while (y[z[i]]<y[xx]) ++i;
		while (y[z[j]]>y[xx]) --j;
		if (i<=j)
		{
			yy=z[i];
			z[i]=z[j];
			z[j]=yy;
			++i;--j;
		}
    }
    if (i<r) sorty(i,r);
    if (j>l) sorty(l,j); 
    return(0);
}
int BI(int a,int b)
{
    if (x[a]<x[b]) return(-1); else
		if (x[a]>x[b]) return(1); else
			if (y[a]>y[b]) return(-1); else
				if (y[a]<y[b]) return(1); else
					return(0);
}
int sortxy(int l,int r)
{
    int i,j,xx,yy;
    i=l;j=r;xx=z[(l+r)/2];
    while (i<j)
    {
		while (BI(z[i],xx)<0) ++i;
		while (BI(z[j],xx)>0) --j;
		if (i<=j)
		{
			yy=z[i];
			z[i]=z[j];
			z[j]=yy;
			++i;--j;
		}
    }
    if (i<r) sortxy(i,r);
    if (j>l) sortxy(l,j); 
    return(0);
}
int lowbit(int x)
{
    return(x&(x ^ (x-1)));
}
int add(int a)
{
    int now;
    now=a;
    while (now<=Limit)
    {
		T[now]++;
		now=now+lowbit(now);
    }
    return(0);
}
int count(int x)
{
    int now,s;
    s=0;
    now=x;
    while (now>0)
    {
		s+=T[now];
		now=now-lowbit(now);
    }
    return(s);
}
int OUT(int a,int b)
{
    int x,y;
    x=count(a-1);
    y=count(b);
    return(y-x);
}
int main()
{
    while (cin>>n)
    {
		memset(T,0,sizeof(T));
		for (int i=1;i<=n;++i)
			scanf("%d%d",&x[i],&y[i]);
		for (int i=1;i<=n;++i) 
			z[i]=i;
		sortx(1,n);
		int now=-1,last=-1;
		for (int i=1;i<=n;++i)
		{
			if (x[z[i]]!=last) 
			{
				last=x[z[i]];
				++now;
			}
			x[z[i]]=now;
		} 
		sorty(1,n);
		now=0;last=-1;
		for (int i=1;i<=n;++i)
		{
			if (y[z[i]]!=last) 
			{
				last=y[z[i]];
				++now;
			}
			y[z[i]]=now;
		} 
		Limit=now;
		sortxy(1,n);
		int i=1;
		int temp[100001],wu;
		while (i<=n)
		{
			temp[0]=1;
			temp[1]=z[i];
			add(y[z[i]]);
			while ((i<n)&(BI(z[i+1],z[i])==0))
			{
				++temp[0];
				temp[temp[0]]=z[i+1];
				++i;
			}
			wu=OUT(y[z[i]],Limit)-1;
			for (int j=1;j<=temp[0];++j)
				ans[temp[j]]=wu;
			++i;
		}
		printf("%d",ans[1]);
		for (int j=2;j<=n;++j)
			printf(" %d",ans[j]);
		cout<<endl;
    } 
    return(0);      
} 
/*
 Problem description
 天空中有很多星星，我们把天空看作一个二维的平面，则可以将每一个星星按照物理位置给一个坐标值(x,y)。
 并且定义两个星星a，b的等级高低关系可以有如下约束来确定：
 如果 Xa <= Xb 且 Ya >= Yb ,则认为星星a的等级比b高（若两个星星在同一位置，则认为它们等级相同）。
 现在的问题是：假定天空中有N颗星星，并且知道每一颗星星的坐标。你能够很快计算出来对于每一颗星星，有多少星星等级比他高吗？
 我们希望你的计算速度越快越好，同时不希望你用暴力搜索的方法解决该问题，因为天空中的星星很多很多，以现在计算机的速度也要很久的，我们只取了一小部分都有100000个了，暂时就计算这么多。 
 
 Input
 输入将有很多组测试数据，每个测试数据都是以一个整数N(1 <= N <= 100000)开始, 随后有N行， 每行2个整数X, Y (1<=X,Y<=10^9), 则是N颗行星的位置坐标。 一直计算到输入结束为止。
 
 Output
 对于每一组测试数据，输出一行，由N个数字组成，按照输入的星星的顺序，每一个数字表示有多少星星等级大于该星星，数字之间有且只有一个空格，行尾请不要输出多余的空格。
 
 Sample Input
 3
 1 2
 0 3
 3 4
 Sample Output
 1 0 0
*/