#include <iostream>
#include <string.h>
using namespace std;
int t[500],vi[500],gi[500],r[500][500];
int main()
{
    int v,g,i,j,k,n;
    cin >> v >> g;
    memset(r, 0, sizeof(r));
    cin >> n;
    for (i=0; i<n; i++)
        cin >> t[i] >> vi[i] >> gi[i];
    for (i=0; i<n; i++)
        for (j=v; j>=vi[i]; j--)
            for (k=g; k>=gi[i]; k--)
                if (r[j-vi[i]][k-gi[i]]+t[i]>r[j][k])
                    r[j][k]=r[j-vi[i]][k-gi[i]]+t[i];
    cout << r[v][g] << '\n';
    return 0;
}
/*
 Problem description
 你现在拿到了许多的礼物，你要把这些礼物放进袋子里。你只有一个最多装下V 体积物品的袋子，你不能全部放进去。你也拿不动那么重的东西。你估计你能拿的最大重量为 G。现在你了解了每一个物品的完美值、重量和体积，你当然想让袋子中装的物品的完美值总和最大，你又得计划一下了。
 
 Input
 第一行：V 和 G 表示最大重量和体积。 第二行：N 表示拿到 N 件礼物。 第三到N+2行：每行3个数 Ti Vi Gi 表示各礼物的完美值、体积和重量 
 
 Output
 输出共一个数，表示可能获得的最大完美值。
 
 Sample Input
 6 5
 4
 10 2 2
 20 3 2
 40 4 3
 30 3 3
 Sample Output
 50
 Judge Tips
 对于20%的数据 N，V，G，Ti，Vi，Gi≤10
 对于50%的数据 N，V，G，Ti，Vi，Gi≤100
 对于80%的数据 N，V，G，Ti，Vi，Gi≤300
 
 
 80%到100%的数据是N，V，G，Ti，Vi，Gi≤380 的离散随机数据。 

*/