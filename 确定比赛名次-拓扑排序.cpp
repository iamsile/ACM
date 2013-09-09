#include <iostream>
using namespace std;

int main()
{
    int n,m;
    while (~scanf("%d%d",&n,&m)) {
        int i,j,k,x,y,map[501][501]={0},d[1000]={0};
        for (i=0; i<m; i++) {
            scanf("%d%d",&x,&y);
            if (!map[x][y]) {
                map[x][y]=1;
                d[y]++;
            }
        }
        for (i=0; i<n; i++) {
            for (j=1; j<=n; j++)
                if (d[j]==0)
                    break;
            d[j]=-1;
            if (i>0)
                printf(" %d",j);
            else printf("%d",j);
            for (k=1; k<=n; k++)
                if (map[j][k])
                    d[k]--;
        }
        printf("\n");
    }
    return 0;
}
/*
 Problem Description
 有N个比赛队（1<=N<=500），编号依次为1，2，3，。。。。，N进行比赛，比赛结束后，裁判委员会要将所有参赛队伍从前往后依次排名，但现在裁判委员会不能直接获得每个队的比赛成绩，只知道每场比赛的结果，即P1赢P2，用P1，P2表示，排名时P1在P2之前。现在请你编程序确定排名。
 
 
 Input
 输入有若干组，每组中的第一行为二个数N（1<=N<=500），M；其中N表示队伍的个数，M表示接着有M行的输入数据。接下来的M行数据中，每行也有两个整数P1，P2表示即P1队赢了P2队。
 
 
 Output
 给出一个符合要求的排名。输出时队伍号之间有空格，最后一名后面没有空格。
 
 其他说明：符合条件的排名可能不是唯一的，此时要求输出时编号小的队伍在前；输入数据保证是正确的，即输入数据确保一定能有一个符合要求的排名。
 
 
 Sample Input
 4 3
 1 2
 2 3
 4 3
 
 
 Sample Output
 1 2 4 3
*/