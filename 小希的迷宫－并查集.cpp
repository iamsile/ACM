#include <iostream>
using namespace std;
bool p[100001];
int r[100001];

int find(int x)
{
    while (x!=r[x])
        x=r[x];
    return x;
}

int Union(int x,int y)
{
    x=find(x);
    y=find(y);
    if (x==y)
        return 0;
    r[x]=y;
    return 1;
}

int main()
{
    int i,n,m,num,flag;
    while (~scanf("%d%d",&n,&m)) {
        if (n==-1&&m==-1)
            return 0;
        if (n==0&&m==0) {
            puts("Yes");
            continue;
        }
        memset(p, 0, sizeof(p));
        for (i=0; i<100001; i++)
            r[i]=i;
        Union(n,m);
        p[n]=1;
        p[m]=1;
        num=1;
        flag=1;
        while (~scanf("%d%d",&n,&m)) {
            if (n==0&&m==0)
                break;
            if (p[n]==0) {
                num++;
                p[n]=1;
            }
            if (p[m]==0) {
                num++;
                p[m]=1;
            }
            if (Union(n, m)==0)
                flag=0;
            else num--;
        }
        if (flag&&num==1)
            puts("Yes");
        else puts("No");
    }
    return 0;
}
/*
 Problem Description
 上次Gardon的迷宫城堡小希玩了很久（见Problem B），现在她也想设计一个迷宫让Gardon来走。但是她设计迷宫的思路不一样，首先她认为所有的通道都应该是双向连通的，就是说如果有一个通道连通了房间A和B，那么既可以通过它从房间A走到房间B，也可以通过它从房间B走到房间A，为了提高难度，小希希望任意两个房间有且仅有一条路径可以相通（除非走了回头路）。小希现在把她的设计图给你，让你帮忙判断她的设计图是否符合她的设计思路。比如下面的例子，前两个是符合条件的，但是最后一个却有两种方法从5到达8。 
 
 
 
 Input
 输入包含多组数据，每组数据是一个以0 0结尾的整数对列表，表示了一条通道连接的两个房间的编号。房间的编号至少为1，且不超过100000。每两组数据之间有一个空行。 
 整个文件以两个-1结尾。
 
 
 Output
 对于输入的每一组数据，输出仅包括一行。如果该迷宫符合小希的思路，那么输出"Yes"，否则输出"No"。
 
 
 Sample Input
 6 8  5 3  5 2  6 4
 5 6  0 0
 
 8 1  7 3  6 2  8 9  7 5
 7 4  7 8  7 6  0 0
 
 3 8  6 8  6 4
 5 3  5 6  5 2  0 0
 
 -1 -1
 
 
 Sample Output
 Yes
 Yes
 No
*/