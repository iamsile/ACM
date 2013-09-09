#include <iostream>
using namespace std;

int s,t,n,m,k;
int map[101][101],v[101],flag[101];

int cal(int s)
{
    for (int i=0; i<m; i++)
        if (!v[i]&&map[s][i]) {
            v[i]=1;
            if (flag[i]==-1||cal(flag[i])) {
                flag[i]=s;
                return 1;
            }
        }
    return 0;
}

int main()
{
    while (~scanf("%d%d%d",&n,&m,&k)) {
        int i,sum=0;
        memset(map, 0, sizeof(map));
        for (i=0; i<k; i++) {
            scanf("%d%d",&s,&t);
            map[s][t]=1;
        }
        memset(flag, -1, sizeof(flag));
        for (i=0; i<n; i++) {
            memset(v, 0, sizeof(v));
            if (cal(i))
                sum++;
        }
        printf("%d\n",sum);
    }
    return 0;
}
/*
 二分图的最小顶点覆盖=二分图的最大匹配数
 二分图的最大独立集=顶点数-二分图的最大匹配数
 二分图的最小路径覆盖=顶点数-二分图的最大匹配数
 Problem description
 There are two materials A and B, material A has n kinds of types, which is called type_0, type _1, …, type _n-1, likewise material B has m kinds of types, type _0, type _1, … , type _m-1. A room can be built by a kind of type of A and a kind of type of B.Each kind of type of each material can be used only once. Please write a program which calculate maximal number of building rooms.
 
 Input
 The first line contains three positive integers: n, m (n, m < =100) and k (k <= 1000). The following k lines give the constrains of the k possibilities, each line is a pair: x, y, which means a room could be built by type_x of A material and type_y of B material.
 
 Output
 The output should be one integer per line, which means the maximal number of building rooms.
 
 Sample Input
 5 4 8
 0 0
 1 0
 1 1
 2 2
 2 3
 3 3
 4 1
 4 3
 Sample Output
 4
*/