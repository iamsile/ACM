#include<iostream>
using namespace std;
int n,A[4001],B[4001],C[4001],D[4001],E[16000001],F[16000001];
long long ans,Last,p,q,Ta,Tb;

int sortE(int l,int r)
{
    int i,j,x,y;
    i=l;j=r;x=E[(l+r)/2];
    while(i<j)
    {
		while(E[i]<x)
			++i;
		while(E[j]>x)
			--j;
		if(i<=j)
		{
			y=E[i];
			E[i]=E[j];
			E[j]=y;
			++i;--j;
		}
    }
    if(i<r) 
		sortE(i,r);
    if(j>l) 
		sortE(l,j);
	return 0;
}
int sortF(int l,int r)
{
    int i,j,x,y;
    i=l;j=r;x=F[(l+r)/2];
    while(i<j)
    {
		while(F[i]<x) 
			++i;
		while(F[j]>x) 
			--j;
		if (i<=j)
		{
			y=F[i];
			F[i]=F[j];
			F[j]=y;
			++i;--j;
		}
    }
    if (i<r) 
		sortF(i,r);
    if (j>l) 
		sortF(l,j); 
	return 0;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
        scanf("%d%d%d%d\n",&A[i],&B[i],&C[i],&D[i]);
    for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			E[(i-1)*n+j]=A[i]+B[j];
    for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			F[(i-1)*n+j]=C[i]+D[j];
    sortE(1,n*n);
    sortF(1,n*n);
    Last=2000000000;
    Ta=0;
    q=n*n;Tb=0;ans=0;
    for(p=1;p<=n*n;++p)
		if(E[p]!=Last)
		{
			ans+=Ta*Tb;
			Last=E[p];
			Ta=1;Tb=0;
			while((q>0)&&(F[q]>=-E[p]))
			{
				if(F[q]==-E[p]) ++Tb;
				--q;
			}
		} 
		else ++Ta;
    ans+=Ta*Tb;
    cout<<ans;
	return 0;
}
/*
 四组数，每组4000个，取其中四个使之和为0的方案有多少种。题意很明了，但方法就不是那么简单了。数字的大小高达2^28，
 背包问题式的动态规划直接出局。枚举也达到了4000^4，根本就不可能。看来只能另寻他法了。
 突破口在哪呢，就在四组数，这个四上，既然不是N组，就应该在这个4上做文章。考虑将4组数又分别分成两部分，A，B一部分，
 C，D一部分，第一部分A与B就有4000^2种组成方式，同理第二部分也是一样。现在考虑从A，B中任取两个数，其和为K，
 那么我就必须从CD中取得两个数，使他们的和为-K。从n^2个数中找-k，我们为什么不将其排序后，用二分查找呢？
 于是我们就得到了一个n^2 log (n^2)的算法。将A，B之和枚举出来，排序。同样将CD之和也枚举出来排序，
 然后对应AB的每一个和，二分查找CD段。参考程序如下
 */
/*
 Problem description
 The SUM problem can be formulated as follows: given four lists A, B, C, D of integer values, compute how many quadruplet (a, b, c, d ) ∈ A x B x C x D are such that a + b + c + d = 0 . In the following, we assume that all lists have the same size n . 
 
 Input
 The first line of the input file contains the size of the lists n (this value can be as large as 4000). We then have n lines containing four integer values (with absolute value as large as 2^28) that belong respectively to A, B, C and D.
 
 Output
 For each input file, your program has to write the number quadruplets whose sum is zero. A valid output corresponding to the sample input file above is:
 
 Sample Input
 6
 -45 22 42 -16
 -41 -27 56 30
 -36 53 -37 77
 -36 30 -75 -46
 26 -38 -10 62
 -32 -54 -6 45
 Sample Output
 5
*/