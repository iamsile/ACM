#include <iostream>
using namespace std;

int b,g,m,map[505][505],flag[1001];
bool v[1001];
bool find(int s)
{
    int i;
    for (i=1; i<=g; i++) {
        if (!v[i]&&map[s][i]) {
            v[i]=1;
            if (flag[i]==-1||find(flag[i])) {
                flag[i]=s;
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    int n;
    while (scanf("%d",&n)&&n) {
        int i,s,t,sum=0;
        scanf("%d%d",&b,&g);
        memset(map, 0, sizeof(map));
        for (i=0; i<n; i++) {
            scanf("%d%d",&s,&t);
            map[s][t]=1;
        }
        memset(flag, -1, sizeof(flag));
        for (i=1; i<=b; i++) {
            memset(v, 0, sizeof(v));
            if (find(i))
                sum++;
        }
        printf("%d\n",sum);
    }
    return 0;
}
/*
 Problem Description
 RPG girls今天和大家一起去游乐场玩，终于可以坐上梦寐以求的过山车了。可是，过山车的每一排只有两个座位，而且还有条不成文的规矩，就是每个女生必须找个个男生做partner和她同坐。但是，每个女孩都有各自的想法，举个例子把，Rabbit只愿意和XHD或PQK做partner，Grass只愿意和linle或LL做partner，PrincessSnow愿意和水域浪子或伪酷儿做partner。考虑到经费问题，boss刘决定只让找到partner的人去坐过山车，其他的人，嘿嘿，就站在下面看着吧。聪明的Acmer，你可以帮忙算算最多有多少对组合可以坐上过山车吗？
 
 
 Input
 输入数据的第一行是三个整数K , M , N，分别表示可能的组合数目，女生的人数，男生的人数。0<K<=1000
 1<=N 和M<=500.接下来的K行，每行有两个数，分别表示女生Ai愿意和男生Bj做partner。最后一个0结束输入。
 
 
 Output
 对于每组数据，输出一个整数，表示可以坐上过山车的最多组合数。
 
 
 Sample Input
 6 3 3
 1 1
 1 2
 1 3
 2 1
 2 3
 3 1
 0
 
 
 Sample Output
 3
*/