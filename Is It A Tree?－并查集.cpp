#include <iostream>
using namespace std;
#define maxn 100001
int main()
{
    int n,m,cnt=1;
    while (~scanf("%d%d",&n,&m)) {
        if (n<0&&m<0)
            break;
        int i,e=0,flag=0,p[maxn],v[maxn];
        for (i=1; i<maxn; i++) {
            p[i]=0;
            v[i]=0;
        }
        while (n&&m) {
            if (!v[n]) {
                v[n]=1;
                e++;
            }
            if (!v[m]) {
                v[m]=1;
                e++;
            }
            e--;
            if (p[m]==0)
                p[m]=1;
            else {
                flag=1;
                break;
            }
            scanf("%d%d",&n,&m);
        }
        while (n&&m)
            scanf("%d%d",&n,&m);
        printf("Case %d",cnt++);
        if (!flag&&e==1)
            printf(" is a tree.\n");
        else printf(" is not a tree.\n");
    }
    return 0;
}
/*
#include"iostream"
using namespace std;
int a[1001];

int find(int x) //找祖先
{
    int i,j,r,k;
    r=x;
    while(a[r]!=r)
        r=a[r];
    i=x,k=r;
    while(i!=r) //路径压缩
    {
        j=a[i];
        a[i]=r;
        i=j;
    }
    return k;    
}

void merge(int x,int y)//合并
{
    int t=find(x);
    int h=find(y);
    if(t<h)
        a[h]=t;
    else
        a[t]=h;
}

int  main()
{
    int n=0,m=0,s=0,i,b,c,k=0;
    memset(a,0,sizeof(a));
    while(scanf("%d %d",&b,&c))
    {
        if(b<0) break;
        else if(n==0&&m==0&&b==0&&c==0)
        {printf("Case %d is a tree.\n",++k);continue;}
        else  if(b==0&&c==0)
        {
            k++;
            for(i=1;i<1001;i++)
            {
                if(a[i])
                    m++;
                if(a[i]==i)
                    s++;
            }
            if(s==1 && n==m-1)
                printf("Case %d is a tree.\n",k);
            else
                printf("Case %d is not a tree.\n",k);
            n=0,m=0,s=0;
            memset(a,0,sizeof(a));
        }
        else
        {
            if(!a[b])
                a[b]=b;
            if(!a[c])
                a[c]=c;
            merge(b,c);
            n++;
        }
    }
    return 0;
}
*/
/*
 Problem Description
 A tree is a well-known data structure that is either empty (null, void, nothing) or is a set of one or more nodes connected by directed edges between nodes satisfying the following properties. 
 There is exactly one node, called the root, to which no directed edges point. 
 
 Every node except the root has exactly one edge pointing to it. 
 
 There is a unique sequence of directed edges from the root to each node. 
 
 For example, consider the illustrations below, in which nodes are represented by circles and edges are represented by lines with arrowheads. The first two of these are trees, but the last is not.
 
 
 
 
 In this problem you will be given several descriptions of collections of nodes connected by directed edges. For each of these you are to determine if the collection satisfies the definition of a tree or not. 
 
 
 
 Input
 The input will consist of a sequence of descriptions (test cases) followed by a pair of negative integers. Each test case will consist of a sequence of edge descriptions followed by a pair of zeroes Each edge description will consist of a pair of integers; the first integer identifies the node from which the edge begins, and the second integer identifies the node to which the edge is directed. Node numbers will always be greater than zero. 
 
 
 Output
 For each test case display the line ``Case k is a tree." or the line ``Case k is not a tree.", where k corresponds to the test case number (they are sequentially numbered starting with 1). 
 
 
 Sample Input
 6 8 5 3 5 2 6 4
 5 6 0 0
 8 1 7 3 6 2 8 9 7 5
 7 4 7 8 7 6 0 0
 3 8 6 8 6 4
 5 3 5 6 5 2 0 0
 -1 -1
 
 
 Sample Output
 Case 1 is a tree.
 Case 2 is a tree.
 Case 3 is not a tree.
*/