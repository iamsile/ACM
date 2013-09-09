#include <iostream>
using namespace std;
#define N 105
int r,c,m,map[N][N],v[N],flag[N],e[N*N][3];

int dfs(int s)
{
    for (int i=1; i<=c; i++)
        if (!v[i]&&map[s][i]) {
            v[i]=1;
            if (flag[i]==-1||dfs(flag[i])) {
                flag[i]=s;
                return 1;
            }
        }
    return 0;
}

int cal()
{
    int sum=0,i;
    memset(v, 0, sizeof(v));
    memset(flag, -1, sizeof(flag));
    for (i=1; i<=r; i++) {
        memset(v, 0, sizeof(v));
        if (dfs(i)) {
            sum++;
        }
    }
    return sum;
}

int main()
{
    int t=1;
    while (~scanf("%d%d%d",&r,&c,&m)) {
        int i,x,y,lab,ans,num=0;
        memset(map, 0, sizeof(map));
        for (i=1; i<=m; i++) {
                scanf("%d%d",&x,&y);
                map[x][y]=1;
                e[i][0]=x;;
                e[i][1]=y;
            }
        ans=cal();
        for (i=1; i<=m; i++) {
            map[e[i][0]][e[i][1]]=0;
            lab=cal();
            if (lab<ans) {
                num++;
            }
            map[e[i][0]][e[i][1]]=1;
        }
        printf("Board %d have %d important blanks for %d chessmen.\n",t++,num,ans);
    }
    return 0;
}
/*
 题意：
 在一个棋盘中求二分图最大匹配。
 棋盘中的一个点，代表二分图中两个集合之间的一条边。最大匹配就满足了题目中任意两个“车”不会互相吃到的
 条件，因为匹配结果，会使得棋盘中的匹配点（也就是二分图中的匹配边），不在同一列且不再同一行。关键在于，
 求完匹配后，依次删去一条匹配边，然后再找增广路径，如果发现还有，则说明删除的匹配边不是关键边，如果找
 不到增广路径，说明删除此条匹配边，会使得匹配数下降，则删除的是关键边
 （删除一条边后，再删除第二条边时，需把之前删除的补回）。
 图示：
 点<1,3><1,2><2,1><2,2>表示成二分图的边,其中很显然的显示出了点<1,3><1,2>
 点在同一行,点<2,1><2,2>点在同一行,点<1,2><2,2>在同一列,所以找到该二分图的
 最大匹配,也就找到了最大的不在同行同列的“车”的个数了
 Problem Description
 小希和Gardon在玩一个游戏：对一个N*M的棋盘，在格子里放尽量多的一些国际象棋里面的“车”，并且使得他们不能互相攻击，这当然很简单，但是Gardon限制了只有某些格子才可以放，小希还是很轻松的解决了这个问题（见下图）注意不能放车的地方不影响车的互相攻击。
 所以现在Gardon想让小希来解决一个更难的问题，在保证尽量多的“车”的前提下，棋盘里有些格子是可以避开的，也就是说，不在这些格子上放车，也可以保证尽量多的“车”被放下。但是某些格子若不放子，就无法保证放尽量多的“车”，这样的格子被称做重要点。Gardon想让小希算出有多少个这样的重要点，你能解决这个问题么？
 
 
 
 Input
 输入包含多组数据，
 第一行有三个数N、M、K(1<N,M<=100 1<K<=N*M)，表示了棋盘的高、宽，以及可以放“车”的格子数目。接下来的K行描述了所有格子的信息：每行两个数X和Y，表示了这个格子在棋盘中的位置。
 
 
 Output
 对输入的每组数据，按照如下格式输出：
 Board T have C important blanks for L chessmen.
 
 
 Sample Input
 3 3 4
 1 2
 1 3
 2 1
 2 2
 3 3 4
 1 2
 1 3
 2 1
 3 2
 
 
 Sample Output
 Board 1 have 0 important blanks for 2 chessmen.
 Board 2 have 3 important blanks for 3 chessmen.

*/