#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;

int main()
{
    unsigned n,m;
    while (~scanf("%u%u",&n,&m)) {
        while (m--) {
            unsigned x,y,h1,h2,sum1=0,sum2=0;
            scanf("%u%u",&x,&y);
            if (x*2+1==y||x*2+2==y||y*2+1==x||y*2+2==x) {
                cout << "1\n";
                continue;
            }
            h1=floor(log(x+1)/log(2))+1;
            h2=floor(log(y+1)/log(2))+1;
            if (h1>h2&&x&&y) {
                while (h1!=h2) {
                    if (x%2==0&&x)
                        x--;
                    x/=2;
                    sum1++;
                    h1--;
                }
            }
            else if (h1<h2&&x&&y) {
                while (h1!=h2) {
                    if (y%2==0&&y)
                        y--;
                    y/=2;
                    sum2++;
                    h2--;
                }
            }
            if (x==y&&h1==h2)
                printf("%u\n",sum1+sum2);
            else {
                while (1) {
                    if (x%2==0&&x)
                        x--;
                    if (y%2==0&&y)
                        y--;
                    if (x) {
                        x/=2;
                        sum1++;
                    }
                    if (y) {
                        y/=2;
                        sum2++;
                    }
                    if ((x==0&&y==0)||(x==y))
                        break;
                }
                printf("%u\n",sum1+sum2);
            }
            
        }
    }
    return 0;
}
/*
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n,m;
    int m1,m2;
    int a[31];
    int i,s=1;
    a[0]=0;
    a[1]=1;
    for(i=2;i<31;i++)
    {
        s=s*2;
        a[i]=a[i-1]+s;
    }
    while(scanf("%d%d",&n,&m)!=EOF)
        while(m--)
        {
            scanf("%d%d",&m1,&m2);
            if(m1>m2)
                swap(m1,m2);
            int i1,i2;
            int k=0;
            for(i1=0;i1<30;i1++)
                if(m1>=a[i1]&&m1<a[i1+1])
                    break;
            for(i2=0;i2<30;i2++)
                if(m2>=a[i2]&&m2<a[i2+1])
                    break;
            k=i2-i1;
            for(;i2!=i1;i2--)
            {
                if(m2%2==0)
                    m2=(m2-2)/2;
                else
                    m2=(m2-1)/2;
            }
            for(i=0;m1!=m2;i++)
            {
                if(m2%2==0)
                    m2=(m2-2)/2;
                else
                    m2=(m2-1)/2;
                if(m1%2==0)
                    m1=(m1-2)/2;
                else
                    m1=(m1-1)/2;
            }
            cout<<i*2+k<<endl;
        }
    return 0;
}
*/
/*
 Problem description
 Binary tree is a useful data structure in programming. A n-depth Full Binary Tree is a binary tree which all leaves are at the same depth n or same level n, and in which every parent has two children. Follow picture will tell us Full Binary Tree more clearly. 
 
 
 For a n-depth full binary tree, there are 2n-1 nodes. We'd like to find the distance of some pairs of nodes. The distance of node a and node b is the least number of edges that node a can go to node b. For example, the distance of node 1 and node 2 is 2. 
 
 
 Input
 There are several test cases end with EOF. 
 For each test case, the first line is an integer n(0< n ≤ 30),m(0< m < 50000), n means the depth of the full binary tree, m is the number of query. Follow m lines represent m pairs of nodes,each line contain two nonnegative integer less than 2n-1. 
 
 
 Output
 For each query of every case, output the distance described above.
 
 
 Sample Input
 3 4 
 0 3
 3 6
 1 2
 1 5 
 4 5
 1 2
 0 4
 4 7
 6 7
 8 10
 Sample Output
 2
 4
 2
 3
 2
 2
 3
 5
 4
*/