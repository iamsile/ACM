#include <iostream>
using namespace std;

int main()
{
    int n;
    while (scanf("%d",&n)!=EOF) {
        int i,j,lab,sum,min,flag,map[100][100],d[1001],v[1001];
        memset(map, 0, sizeof(map));
        memset(d, 0, sizeof(d));
        memset(v, 0, sizeof(v));
        for (i=0; i<n; i++)
            for (j=0; j<n; j++)
                cin >> map[i][j];
        for (i=0; i<n; i++) {
            d[i]=map[0][i];
            v[i]=0;
        }
        for (i=1,sum=0,flag=0,v[0]=1; i<n; i++) {
            for (j=0,min=100000; j<n; j++)
                if (v[j]==0&&d[j]<min) {
                    min=d[j];
                    lab=j;
                }
            v[lab]=1;
            for (j=0; j<n; j++)
                if (v[j]==0&&map[lab][j]<d[j])
                    d[j]=map[lab][j];
            sum+=min;
        }
        printf("%d\n",sum);
    }
    return 0;
}
/*
 Problem Description
 农民约翰被选为他们镇的镇长！他其中一个竞选承诺就是在镇上建立起互联网，并连接到所有的农场。当然，他需要你的帮助。 约翰已经给他的农场安排了一条高速的网络线路，他想把这条线路共享给其他农场。为了使花费最少，他想铺设最短的光纤去连接所有的农场。 你将得到一份各农场之间连接费用的列表，你必须找出能连接所有农场并所用光纤最短的方案。 每两个农场间的距离不会超过100000
 Input
 第一行： 农场的个数，N（3<=N<=100）
 后来的行包含了一个N*N的矩阵,表示每个农场之间的距离。理论上，他们是N行，每行由N个用空格分隔的数组成，实际上，他们限制在80个字符，因此，某些行会紧接着另一些行。当然，对角线将会是0，因为不会有线路从第i个农场到它本身。
 Output
 只有一个输出，其中包含连接到每个农场的光纤的最小长度。
 Sample Input
 4
 0  4  9 21
 4  0  8 17
 9  8  0 16
 21 17 16  0
 Sample Output
 28
*/