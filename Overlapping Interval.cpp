#include <iostream>
#include <stdlib.h>
using namespace::std;
struct st
{
    int x,y;
}t[10001];
int cmp(const void *a,const void *b)
{
    return ((struct st *)a)->x>((struct st *)b)->x?1:-1;
}
int main()
{
    int n;
    cin >> n;
    while(n--)
    {
		int k,i=0,lab=0,max;
        while(cin >> t[i].x >> t[i].y&&t[i].x&&t[i].y)
        {
            if(t[i].x>t[i].y)
                swap(t[i].x,t[i].y);
            i++;
        }
        k=i;
        qsort(t,k,sizeof(t[0]),cmp);
        max=t[0].y;
		for(i=1;i<k;i++)
			if(t[i].y>max)
			{
				if(lab<max-t[i].x)
					lab=max-t[i].x;
				max=t[i].y;
			}
			else 
			{
				if(lab<t[i].y-t[i].x)
					lab=t[i].y-t[i].x;
			}
		cout << lab+1 << '\n';
    }
    return 0;
}
/*
 给定一些区间,要求这些区间中最长的一段相交的区间. 
 用暴力的话,两两比较,时间复杂度O(n^2). 
 用动态规划,先将所有的区间按区间的下限排序,然后按区间下限从小到大扫描各个区间,
 定义一个lim,初始为0,每扫完一个区间,若区间的上限大于lim,则令lim等于此区间的上限.
 这样,lim减去所扫描区间的下限+1就得出该段区间所能取到的最大交区间,在O(n)的时间内可以扫描完所有的区间并得出最大值.  
 */
/*
 Problem description
 In the X- axes, if an interval [a, b](a<=b) have some points same with another interval [c, d](c<=d), then we call interval [a, b] overlaps with interval [c, d], and the overlapping distance is c-b+1(suppose c>=b) . For example, intervals [10 20], [12, 25] have the distance 9 , and [10, 20], [20, 30] have got 1. And now given a series of intervals, you are to find the maximum distance between them all.
 
 Input
 The input contains several test cases. The first line of the input is the test case number T. For each test case, there are multiple lines each containing two positive integer numbers a, b (0=<a, b<=10000, a may be larger than b) which indicate an interval. A line with 0 0 signals the end of the case, and should not be processed. You can believe that in each case the total number of the intervals will not exceed 10000.
 
 Output
 For each test case, you should output one number in a line, which is the maximum distance of the given intervals.
 
 Sample Input
 3
 10 20
 12 25
 0 0
 10 20
 15 26
 30 20
 0 0
 10 20
 20 30
 10 40
 30 50
 40 60
 30 80
 0 0
 Sample Output
 9
 7
 21
*/