#include <iostream>
using namespace::std;

int main()
{
	int n;
	while(cin >> n&&n)
	{
		int i,j,k,lab,max=0,x[205]={0},y[205]={0};
		for(i=1;i<=n;i++)
			cin >> x[i] >> y[i];
		for(i=1;i<n;i++)
			for(j=i+1;j<=n;j++)
			{
				lab=2;
				for(k=1;k<=n;k++)
					if(k!=i&&k!=j&&(y[i]-y[j])*(x[k]-x[j])==(y[k]-y[j])*(x[i]-x[j]))//三点共线
						lab++;
				if(lab>max)
					max=lab;
			}
		cout << max << '\n';
	}
	return 0;
}
/*
1.选出一个点,计算所有与这个点相连的直线斜率
2.然后对斜率排序
3.依次处理斜率,斜率相同则通过该直线的点数量+1,否则重置通过数量为2(两点确定一条直线)
4.重置前与已记录的最大值比较,记录最大值
这样的复杂度就变成了O(n*n*log(n))了
*/
/*#include<iostream>
using namespace std;
struct point
{
    float x,y;
};
struct node
{
    float k;  
};
int cmp(const void * a, const void * b)
{
    return((*(float*)a-*(float*)b>0)?1:-1);
}
int main()
{
    node numK[1005 * 1005 / 2];
    int n , maxNum = 2 , tmpNum = 0;
    while(scanf("%d",&n),n)
    {
        point pt[1005];
        for(int i = 0 ; i < n ; i ++)
            scanf("%f %f",&pt[i].x,&pt[i].y);
        for(int i = 0 ; i <  n ; i ++)
        {
            int pos = 0;
            for(int j = i + 1 ; j < n ; j ++)
                if(pt[i].x != pt[j].x)
                    numK[pos ++].k = (pt[j].y - pt[i].y) / (pt[j].x - pt[i].x);
                else
                    numK[pos ++].k = 100000;
            qsort(numK,pos,sizeof(numK[0]),cmp);
            int tmpNum = 2;
            for(int j = 1 ; j < pos ; j ++)
            {
                if(numK[j].k == numK[j - 1].k)
                    tmpNum ++;
                else
                {
                    if(tmpNum > maxNum)
                        maxNum = tmpNum;
                    tmpNum = 2;
                }
            }
            if(tmpNum > maxNum)
                maxNum = tmpNum;
        }				
        printf("%d\n",maxNum);
        maxNum = 2;
    }
    return 0;
}*/
/*
 Problem description
 A good hunter kills two rabbits with one shot. Of course, it can be easily done since for any two points we can always draw a line containing the both. But killing three or more rabbits in one shot is much more difficult task. To be the best hunter in the world one should be able to kill the maximal possible number of rabbits. Assume that rabbit is a point on the plane with integer x and y coordinates. Having a set of rabbits you are to find the largest number K of rabbits that can be killed with single shot, i.e. maximum number of points lying exactly on the same line. No two rabbits sit at one point.
 
 
 Input
 An input contains an integer N (2 <= N <= 200) specifying the number of rabbits. Each of the next N lines in the input contains the x coordinate and the y coordinate (in this order) separated by a space (-1000 <= x,y <= 1000). 
 
 Output
 The output contains the maximal number K of rabbits situated in one line.
 
 Sample Input
 6
 7 122
 8 139
 9 156
 10 173
 11 190
 -100 1
 Sample Output
 5
*/