#include <iostream>
using namespace std;

int a[100010];

int Find(int x)
{
    int sum=0;
    while (x!=a[x]) {
        sum++;
        x=a[x];
    }
    return sum;
}

int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m),n||m) {
        int i,x,y,k1,k2;
        for (i=1; i<=n; i++)
            a[i]=i;
        for (i=0; i<n-1; i++) {
            scanf("%d%d",&x,&y);
            a[y]=x;
        }
        for (i=0; i<m; i++) {
            scanf("%d%d",&x,&y);
            k1=Find(x);
            k2=Find(y);
            if (k1<=k2)
                printf("lxh\n");
            else printf("pfz\n");
        }
    }
    return 0;
}
/*
#include<stdio.h>
int father[100001];
int main()
{
	int i,j,k,n,m,w,s,x1,x2;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(i=1;i<=n;i++)
			father[i]=i;
		if(n==0&&m==0)break;
		for(i=1;i<n;i++)
		{
			scanf("%d%d",&w,&s);
			father[s]=w;
		}
		while(m--)
		{
			i=0;j=0;
			scanf("%d%d",&x1,&x2);
			while(x1!=father[x1])
			{
				i++;
				x1=father[x1];
			}
			while(x2!=father[x2])
			{
				j++;
				x2=father[x2];
			}
			if(i<=j)printf("lxh\n");
			else printf("pfz\n");
		}
	}
	return 0;
}
 Problem Description
 给一棵树，如果树上的某个节点被某个人占据，则它的所有儿子都被占据，lxh和pfz初始时分别站在两个节点上，谁当前所在的点被另一个人占据，他就输了比赛，问谁能获胜
 
 
 Input
 输入包含多组数据
 每组第一行包含两个数N，M（N，M<=100000），N表示树的节点数，M表示询问数，N=M=0表示输入结束。节点的编号为1到N。
 接下来N-1行，每行2个整数A，B(1<=A,B<=N)，表示编号为A的节点是编号为B的节点的父亲
 接下来M行，每行有2个数，表示lxh和pfz的初始位置的编号X，Y(1<=X,Y<=N,X!=Y)，lxh总是先移动
 
 
 
 Output
 对于每次询问，输出一行，输出获胜者的名字
 
 
 Sample Input
 2 1
 1 2
 1 2
 5 2
 1 2
 1 3
 3 4
 3 5
 4 2
 4 5
 0 0
 
 
 Sample Output
 lxh
 pfz
 lxh
*/