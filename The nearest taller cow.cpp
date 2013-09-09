#include <iostream>
using namespace::std;
#define NIL 0x01010101//int的大小
int *a=new int[1000001],f[1000001],*q=new int[1000001];

int main()
{
    int n,i,max,l;
    double num;
    while(cin >> n&&n)
    {
        memset(f,1,sizeof(f));
        for(max=i=0;i<n;i++ )
        {
            scanf("%d",&a[i]);
            if(max<a[i]) 
				max=a[i];
        }
        l=-1;
        for(i=0;i<n;++i)
        {
            while(l>=0&&a[i]>=a[q[l]])
            {
                /*如果当前值等于栈中元素，则它最近距离为它到与它相等的距离+那个相等的数的最近距离*/
                if(a[i]==a[q[l]])
                {
                    f[i]=f[q[l]]+i-q[l];
                    break;
                }
                /*如果最短距离可以更新*/
                if(f[q[l]]>i-q[l])
                    f[q[l]]=i-q[l];
                l--;
            }
            /*找到栈中比a[i]大的数，记录距离*/
            if(l!=-1&&a[i]!=a[q[l]]) 
				f[i]=i-q[l];
            /*入栈*/
            q[++l]=i;
        }
        num=0;
        for(i=0;i<n;++i)
        {
            if(a[i]==max||f[i]==NIL) 
				f[i]=n;
            num+=f[i];
        }
        /*注意进位*/
        printf("%.2f\n",(num*100+0.5)/100/n);
    }
    return 0;
}
/*
 用一个栈进行扫描，维护栈内元素的单调性
 分别求出每个元素左边和右边的最近的更高元素，再取最大值，最后再求和取均值。
 以求左边的为例，先从左往右扫描，遇到小于等于栈顶元素的数就将这个数入栈，继续向后扫；
 如果大于则弹出栈顶元素，并设置其左边最近元素为此新元素。
*/
/*
 Problem description
 Farmer Zhao's N cows (1 ≤ N ≤ 1,000,000) are lined up in a row. So each cow can see the nearest cow which is taller than it. You task is simple, given the height (0 < height ≤ 109) of each cow lined up in the row, to calculate the distance between each cow and its nearest taller cow, if it is the tallest cow in the row, such distance is regarded as n. You should output the average distance.
 
 
 Input
 For each test case:
 Line 1: One integers, N
 Lines 2: N integers. The ith integer is the height of the ith cow in the row.
 
 
 Output
 The average distance to their nearest taller cow, rounded up to 2 decimals.
 
 
 Sample Input
 7
 7 6 5 8 6 4 10
 Sample Output
 2.43
 Judge Tips
 a. In the sample case, the distances to their nearest cow are 3 1 1 3 1 1 7. Then the answer is (3+1+1+3+1+1+7) / 7 = 2.43. Huge input.
*/