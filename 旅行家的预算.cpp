#include<iostream>
using namespace::std;
double p[101],dist[101];
double c,dic;
int N;
double cost,rest,need;

int main()
{
	double box,dd,pp;
	int j,k,min1,min2;
    scanf("%lf%lf%lf%lf%d",&box,&c,&dic,&p[0],&N);
    dist[N+1]=box;p[N+1]=0;dist[0]=0;
    for(int i=1;i<=N;i++)
    {
        scanf("%lf%lf",&dd,&pp);
        p[i]=pp;dist[i]=dd;
    }	
	rest=cost=k=0;
    while(k<=N)
    {
        j=k;min1=0;min2=0;
        while((dist[j+1]-dist[k]<=c*dic)&&(j<=N))
        {
            j++;
            if(min1==0&&p[j]<p[k]) 
				min1=j;
            if(min2==0||p[j]<p[min2]) 
				min2=j;
        }
        if(j==k)
        {
            printf("No solution\n");
            exit(0);
        }
        if(min1!=0)
        {
            need=(dist[min1]-dist[k])/dic-rest;
            if(need<0) 
				need=0;
            cost+=need*p[k];
            rest=0;
            k=min1;
        }
        else
        {
            need=c-rest;
            cost+=need*p[k];
            rest=c-(dist[min2]-dist[k])/dic;
            k=min2;
        }
    }
    printf("%0.2lf\n",cost);
	return 0;
}
/*
  贪心，记住这种思想。遇见一到题，特别求最优解的题，
 要考虑它是否可以通每步选择最优来达到最后的全局最优，
 对于本题，想想，跑到贵的地方加油就不划算，那现在就一最小的代价，
 跑到最便宜的地方去，所以刚好加够油就行了，
 如果当前站已经很便宜了，那当然不能错过这种好机会了，
 加满它，跑到最远的相对的最便宜的地方，在重复这种抉择过程，
 实际经验告诉我们，这样到最后一定是全局最优的
*/
/*
 Problem description
 一个旅行家想驾驶汽车以最少的费用从一个城市到另一个城市（假设出发时油箱是 空的）。给定两个城市之间的距离D1、汽车油箱的容量C（以升为单位）．每升汽油能行驶的距离D2、出发点每升汽油价格P和沿途油站数N（N可以为零），油站i离出发点的距Di、每升汽油价格 Pi（ i＝l，2，...N）。计算结果四舍五入至小数点后两位。如果无法到达目的地，则输出“No solution”。
 
 Input
 输入数据的第一行是四个实数；
 D1 C D2 P分别表示两个城市之间的距离，汽车油箱的容量，每升汽油能行驶的距离，出发点每升汽油价格；
 第二行是一个整数N,沿途的油站数。
 第三行到第N+2，每一行是一个油站的基本信息描述，包括该油站离出发点的距离，该油站每升汽油的价格。 
 
 Output
 输出到达目的城市的最小费用(四舍五入到两位小数)，若不能到达目的城市则输出 No solution
 
 Sample Input
 275.6  11.9   27.4  2.8
 2
 102.0  2.9
 220.0   2.2 
 Sample Output
 26.95
*/