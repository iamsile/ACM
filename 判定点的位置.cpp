#include <iostream>
#include <math.h>
using namespace::std;

int main()
{
	int i,j,l,k,lab;
	char a[1001]={0};
	float b[1001]={0},c[1001]={0},d[1001]={0},e[1001]={0},x[1001]={0},y[1001]={0};
	l=0;
	while(cin >> a[l])
	{
		if(a[l]=='*')
			break;
		else
		{
			if(a[l]=='r')
				cin >> b[l] >> c[l] >> d[l] >> e[l];
			if(a[l]=='c')
				cin >> b[l] >> c[l] >> d[l];
			l++;
		}
	}
	lab=0;
	while(cin >> x[lab] >> y[lab])
	{
		if(fabs(x[lab]-9999.9)<0.01&&fabs(y[lab]-9999.9)<0.01)
			break;
		else 
			lab++;
	}
	for(i=0;i<lab;i++)
	{
		k=0;
		for(j=0;j<l;j++)
		{
			if(a[j]=='r'&&x[i]>=b[j]&&x[i]<=d[j]&&y[i]>=c[j]&&y[i]<=e[j])
			{
				printf("point %d is contained in figure %d\n",i+1,j+1);
				k++;
			}
			else if(a[j]=='c'&&((x[i]-b[j])*(x[i]-b[j])+(y[i]-c[j])*(y[i]-c[j]))<=d[j]*d[j])
				{
					printf("point %d is contained in figure %d\n",i+1,j+1);
					k++;
				}
		}
		if(k==0)
			printf("point %d is not contained in any figure\n",i+1);
	}
	return 0;
}
/*
 Problem description
 
 给出一组图形（矩形和圆）和一组点的数据，判定点的位置。
 
 Input
 
 输入一组图形的数据，其中“c”开头表示圆，”r”开头表示矩形，矩形依次给出左下角和右上角的坐标，圆是给出圆心坐标和半径，图形数据以一行“*”结束，接下来是给出点的坐标（x,y），整个输入文件以9999.9 9999.9结束，每个数据间用空格分割。 
 
 Output
 
 如某点在图形上，则输出所有图形上的信息：Point i is contained in figure j；如某点不在任一图形内，则输出：Point i is not contained in any figure。
 
 Sample Input
 r 0.0 0.0 5.5 10.3
 c -5.0 -5.0 3.7
 r 2.5 2.5 12.5 12.5
 *
 2.0 2.0
 4.7 5.3
 9999.9 9999.9
 Sample Output
 point 1 is contained in figure 1
 point 2 is contained in figure 1
 point 2 is contained in figure 3
 */
