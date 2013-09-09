#include <iostream> 
#include <stdlib.h> 

class pos
{ 
public:
    int x,y; 
}; 

int cmp(const void*a,const void*b) 
{ 
    if(((pos*)a)->x!=((pos*)b)->x) 
        return ((pos*)a)->x - ((pos*)b)->x; 
    else 
        return ((pos*)b)->y - ((pos*)a)->y; 
}

int main() 
{ 
    int n;
    pos p[50000]; 
    scanf("%d",&n); 
    for(int i=0;i<n;i++)
        scanf("%d%d",&p[i].x,&p[i].y);
    qsort(p,n,sizeof(p[0]),cmp); 
	int first=p[0].x,last=p[0].y;
    for(int i=1;i<n;i++) 
    { 
        if(p[i].x>last) 
        { 
            printf("%d %d\n",first,last);
            first=p[i].x; 
            last=p[i].y;
        }
        else if(p[i].y>last)
            last=p[i].y;
    } 
    printf("%d %d\n",first,last); 
    return 0; 
}
/*
 Problem description
 现给定n个闭区间[ai, bi]，1<=i<=n。这些区间的并可以表示为一些不相交的闭区间的并。你的任务就是在这些表示方式中找出包含最少区间的方案。你的输出应该按照区间的升序排列。这里如果说两个区间[a, b]和[c, d]是按照升序排列的的，那么我们有a<=b<=d。
 请写一个程序：
 读入这些区间； 计算满足给定条件的不相交闭区间；把这些区间按照升序输出. 
 
 Input
 第一行包含一个整数n，3<=n<=50000，为区间的数目。以下n行为对区间的描述，第i行为对第i个区间的描述，为两个整数
 1<=ai<=bi<=1000000，表示一个区间[ai, bi]。
 
 Output
 你应该输出计算出来的不相交的区间。每一行都是对一个区间的描述，包括两个用空格分开的整数，为区间的上下界。你应该把区间按照升序排序。
 
 Sample Input
 5
 5 6
 1 4
 10 10
 6 9
 8 10
 Sample Output
 1 4
 5 10
*/