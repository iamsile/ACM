#include <iostream>
#include<algorithm>
using namespace std;

void HeapAdjust(unsigned *a,unsigned i,unsigned size)
{
    unsigned lchild=2*i;
    unsigned rchild=2*i+1; 
    unsigned max=i;
    if(i<=size/2)
    {
        if(lchild<=size&&a[lchild]>a[max])
            max=lchild;
        if(rchild<=size&&a[rchild]>a[max])
            max=rchild;
        if(max!=i)
        {
            swap(a[i],a[max]);
            HeapAdjust(a,max,size);
        }
    }        
}

void BuildHeap(unsigned *a,unsigned size) 
{
    unsigned i;
    for(i=size/2;i>=1;i--)
        HeapAdjust(a,i,size);     
} 

void HeapSort(unsigned *a,unsigned size)
{
    unsigned i;
    BuildHeap(a,size);
    for(i=size;i>=1;i--)
    {
        swap(a[1],a[i]);
        HeapAdjust(a,1,i-1);
    }
} 

int main()
{
    unsigned a[1000010],size;
    while(scanf("%d",&size)!=EOF)
    {
        unsigned i;
        for(i=1;i<=size;i++)
            cin>>a[i];
        HeapSort(a,size);
        for(i=1;i<=size;i++) {
            if (i>1)
                cout << ' ';
            cout<<a[i];
        }
        cout<<endl;
    }
    return 0;
}
/*
Description
Give a set of numbers, output them after sort. You may use any algorithm you like to solve it.
Input
Each input file contains only one case. 
Each test case begins with an integer N(0<N<=1,000,000), the size of the set.
The Next line contains N numbers, represent the elements of the set. Each number range in [0..2147483647]
Output
Output the set in one line after sort.
Sample Input
4
4 15 8 5
Sample Output
4 5 8 15
Hint
O(n2) algorithm may get Time Limit Exceed. Try O(nlogn) to avoid TLE.
*/