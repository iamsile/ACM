#include <iostream>
using namespace std;
int sum,map[40][40];

bool judge(int x,int y)
{
    for (int i=0; i<x; i++)
        if (map[i][y]==2)
            return false;
    return true;
}

void dfs(int n,int m,int num,int begin)
{
    if (num==m) {
        sum++;
        return;
    }
    for (int i=begin; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (map[i][j]&&judge(i,j)) {
                map[i][j]=2;
                dfs(n, m, num+1, i+1);
                map[i][j]=1;
            }
        }
    }
}

int main()
{
    int n,m;
    while (cin >> n >> m) {
        if (n==-1&&m==-1)
            return 0;
        char c;
        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++) {
                cin >> c;
                if (c=='#')
                    map[i][j]=1;
                else map[i][j]=0;
            }
        sum=0;
        dfs(n,m,0,0);
        cout << sum << '\n';
    }
    return 0;
}
/*
 Description
 
 在一个给定形状的棋盘（形状可能是不规则的）上面摆放棋子，棋子没有区别。要求摆放时任意的两个棋子不能放在棋盘中的同一行或者同一列，请编程求解对于给定形状和大小的棋盘，摆放k个棋子的所有可行的摆放方案C。
 Input
 
 输入含有多组测试数据。 
 每组数据的第一行是两个正整数，n k，用一个空格隔开，表示了将在一个n*n的矩阵内描述棋盘，以及摆放棋子的数目。 n <= 8 , k <= n 
 当为-1 -1时表示输入结束。 
 随后的n行描述了棋盘的形状：每行有n个字符，其中 # 表示棋盘区域， . 表示空白区域（数据保证不出现多余的空白行或者空白列）。 
 Output
 
 对于每一组数据，给出一行输出，输出摆放的方案数目C （数据保证C<2^31）。
 Sample Input
 
 2 1
 #.
 .#
 4 4
 ...#
 ..#.
 .#..
 #...
 -1 -1
 Sample Output
 
 2
 1
*/